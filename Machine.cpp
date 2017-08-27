#include "Machine.hpp"

Machine::Machine(std::vector<Rotor *> &rotorsVector,
                 Plugboard &plugboard,
                 Reflector &reflector)
                 : rotors(rotorsVector),
                   plugboard(plugboard),
                   reflector(reflector) {}

/* Passes letter to plugboard, then rotors and reflector.
   Does the same backwards.
   Then, rotors are rotated, cascading some rotations if necessary. */
int Machine::encode(int letter) {

    int encodedLetter = plugboard.encode(letter);

    for (Rotor * rotor : rotors)    {
        encodedLetter = rotor->encode(encodedLetter);
    }
    encodedLetter = reflector.encode(encodedLetter);

    for (int i = rotors.size() - 1; i >= 0; i--)    {
        encodedLetter = rotors[i]->encodeBackwards(encodedLetter);
    }
    encodedLetter = plugboard.encodeBackwards(encodedLetter);

    bool nextToRotate = true;
    for (Rotor * rotor : rotors)    {
        if (!nextToRotate)  { break; }
        nextToRotate = rotor->rotate();
    }
    return encodedLetter;
}