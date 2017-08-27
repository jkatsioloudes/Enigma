#ifndef CENIGMA_JK2714_MACHINE_HPP
#define CENIGMA_JK2714_MACHINE_HPP

#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include <vector>

class Machine : public Encoder {

    public:
        Machine(std::vector<Rotor *> &rotorsVector,
                Plugboard &plugboard,
                Reflector &reflector);

        int encode(int letter);

    private:
        Plugboard &plugboard;
        std::vector<Rotor *> &rotors;
        Reflector &reflector;
};

#endif
