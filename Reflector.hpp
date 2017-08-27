#ifndef CENIGMA_JK2714_REFLECTOR_HPP
#define CENIGMA_JK2714_REFLECTOR_HPP

#include "Alphabet.hpp"

const int NUMBER_OF_SHIFTS = 13;

class Reflector {

    public:

        Reflector();
        ~Reflector();

        // For Letters in the range 0..25.
        int encode(int letter);
};

#endif
