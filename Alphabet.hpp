#ifndef CENIGMA_JK2714_ALPHABET_HPP
#define CENIGMA_JK2714_ALPHABET_HPP

const int NUMBER_OF_LETTERS = 26;

class Alphabet {

    public:
        static int fromASCIItoInt (char letter);
        static char fromIntToASCII (int letter);
};

#endif
