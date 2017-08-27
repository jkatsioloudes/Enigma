#include "Reflector.hpp"
#include "Alphabet.hpp"

Reflector::Reflector() {}

Reflector::~Reflector() {}

// The letter should be between 0 and 25.
int Reflector::encode(int letter) {
    return (letter + NUMBER_OF_SHIFTS) % NUMBER_OF_LETTERS;
}
