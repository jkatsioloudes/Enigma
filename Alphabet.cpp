#include "Alphabet.hpp"

// Transforms an ASCII into an integer.
int Alphabet::fromASCIItoInt(char letter) {
    return letter - 'A';
}

// Transforms an integer to its ASCII representation.
char Alphabet::fromIntToASCII(int letter) {
    return letter + 'A';
}
