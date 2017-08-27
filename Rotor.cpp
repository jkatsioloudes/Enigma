#include "Rotor.hpp"

Rotor::Rotor(std::vector<int> &mapping) {

    for (int i = 0; i < mapping.size(); i++)    {
        int mapValue = mapping[i];
        mappingFront[i] = mapValue;
        mappingBack[mapValue] = i;
    }
    rotations = ZERO_ROTATIONS;
}

Rotor::~Rotor() {}

int Rotor::encode(int letter) {
    int n = (letter + rotations) % NUMBER_OF_LETTERS;
    return handleNegatives(mappingFront[n] - rotations);
}

int Rotor::encodeBackwards(int letter) {
    int n = (letter + rotations) % NUMBER_OF_LETTERS;
    return handleNegatives(mappingBack[n] - rotations);
}

bool Rotor::rotate() {
    rotations++;
    if (rotations == MAX_ROTATIONS) {
        resetRotations();
        return true;
    } else {
        return false;
    }
}

void Rotor::resetRotations() {
    rotations = ZERO_ROTATIONS;
}

int Rotor::handleNegatives(int a) {
    return (a + NUMBER_OF_LETTERS) % NUMBER_OF_LETTERS;
}