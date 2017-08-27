CPPC = g++
CPPFLAGS = -O3 -g -std=c++0x -c 

all: enigma

enigma: Main.o Machine.o Rotor.o Reflector.o Plugboard.o Encoder.o Alphabet.o
	$(CPPC) -o enigma $^

Main.o: Main.cpp Machine.hpp Alphabet.hpp Plugboard.hpp Reflector.hpp Rotor.hpp
	$(CPPC) $(CPPFLAGS) $^
	
Machine.o: Machine.cpp Machine.hpp Reflector.hpp Plugboard.hpp Rotor.hpp
	$(CPPC) $(CPPFLAGS) $^
	
Rotor.o: Rotor.cpp Rotor.hpp Encoder.hpp Alphabet.hpp
	$(CPPC) $(CPPFLAGS) $^
	
Reflector.o: Reflector.cpp Reflector.hpp Alphabet.hpp
	$(CPPC) $(CPPFLAGS) $^
	
Plugboard.o: Plugboard.cpp Plugboard.hpp Alphabet.hpp Encoder.hpp
	$(CPPC) $(CPPFLAGS) $^

Alphabet.o: Alphabet.cpp Alphabet.hpp
	$(CPPC) $(CPPFLAGS) $^

clean:
	rm -rf enigma *.o *.gch

.PHONY: all clean
