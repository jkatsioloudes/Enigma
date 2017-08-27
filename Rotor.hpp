#ifndef CENIGMA_JK2714_ROTOR_HPP
#define CENIGMA_JK2714_ROTOR_HPP

#include "Alphabet.hpp"
#include "Encoder.hpp"
#include <vector>

const int ZERO_ROTATIONS = 0;
const int MAX_ROTATIONS = 26;

class Rotor : public Encoder {

    public:
        Rotor (std::vector<int> &mapping);
        ~Rotor();
        int encode (int letter);
        int encodeBackwards (int letter);
        bool rotate();

    private:
        int rotations;
        int mappingFront[NUMBER_OF_LETTERS];
        int mappingBack[NUMBER_OF_LETTERS];
        void resetRotations();
        int handleNegatives(int a);
};

#endif
