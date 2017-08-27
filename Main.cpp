#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"
#include "Machine.hpp"
#include "Alphabet.hpp"

using namespace std;

void LoadMachine(int argc, char ** argv, vector<Rotor *> &rotors,
                 Reflector &reflector, Plugboard &plugboard);
void LoadRotor(ifstream &file, vector<Rotor *> &rotors);
void LoadPlugboard(ifstream &file, Plugboard &plugboard);

int main(int argc, char **argv) {

    Plugboard plugboard;
    vector<Rotor *> rotors;
    Reflector * reflector;

    LoadMachine(argc, argv, rotors, *reflector, plugboard);

    Machine enigma(rotors, plugboard, *reflector);

    char cASCII;
    int cINT;

    while (cin >> cASCII)   {

        cINT = Alphabet::fromASCIItoInt(cASCII);
        cINT = enigma.encode(cINT);
        cASCII = Alphabet::fromIntToASCII(cINT);
        cout << cASCII;
    }

    for (Rotor * rotor : rotors)    {
        delete rotor;
    }

    return 0;
}

// Loads enigma with plugboards and rotors.
void LoadMachine(int argc, char ** argv, vector<Rotor *> &rotors,
                 Reflector &reflector, Plugboard &plugboard)    {

    for (int i = 1; i < argc; i++)  {
        string fileName = argv[i];
        ifstream file;
        file.open(fileName);

        if (!file)  {
            cerr << "File can't be opened";
        }

        // Checks if it's plugboard else it's a rotor.
        if (i == (argc - 1))    {
            LoadPlugboard(file, plugboard);
        }   else    {
            LoadRotor(file, rotors);
        }
        file.close();
    }
}

// Creates a new rotor and is playing it in the rotors vector.
void LoadRotor(ifstream &file, vector<Rotor *> &rotors) {

    int value;
    vector <int> rotorMapping;

    while (file >> value)   {
        rotorMapping.push_back(value);
    }

    Rotor *rotor = new Rotor(rotorMapping);
    rotors.push_back(rotor);
}

// Checks if even number of numbers are in file or if it's empty.
void LoadPlugboard(ifstream &file, Plugboard &plugboard)    {

    int value1;
    int value2;
    vector<int> plugboardMapping;

    while ((file >> value1) && (file >> value2))    {
        plugboardMapping.push_back(value1);
        plugboardMapping.push_back(value2);
    }
    plugboard.populatePlugboard(plugboardMapping);
}