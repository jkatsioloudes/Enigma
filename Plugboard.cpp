#include "Plugboard.hpp"

Plugboard::Plugboard() {

    for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
        mappingPlugboard[i] = i;
    }
}

Plugboard::~Plugboard() {}

int Plugboard::encode(int letter) {

    return mappingPlugboard[letter];
}

int Plugboard::encodeBackwards(int letter) {

    for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
        if (mappingPlugboard[i] == letter)  {
            return i;
        }
    }
    return letter;
}

void Plugboard::populatePlugboard(std::vector<int> &mapping) {

    for (int i = 0; i < mapping.size(); i++) {
        int value = mapping[i++];
        int index = mapping[i];
        mappingPlugboard[index] = value;
        mappingPlugboard[value] = index;
    }
}
