#ifndef CENIGMA_JK2714_PLUGBOARD_HPP
#define CENIGMA_JK2714_PLUGBOARD_HPP

#include "Encoder.hpp"
#include "Alphabet.hpp"
#include <vector>

class Plugboard : public Encoder {

    public:
        Plugboard();
        ~Plugboard();
        int encode(int letter);
        int encodeBackwards(int letter);
        void populatePlugboard(std::vector<int> &mapping);

    private:
        int mappingPlugboard [NUMBER_OF_LETTERS];
};

#endif