cmake_minimum_required(VERSION 3.6)
project(cenigma_jk2714)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    plugboards/I.pb
    plugboards/II.pb
    plugboards/III.pb
    plugboards/IV.pb
    plugboards/null.pb
    plugboards/V.pb
    rotors/I.rot
    rotors/II.rot
    rotors/III.rot
    rotors/IV.rot
    rotors/V.rot
    rotors/VI.rot
    rotors/VII.rot
    Main.cpp
    makefile
    moby.txt.gz
    README.txt
    tests.py Encoder.hpp Alphabet.cpp Alphabet.hpp Reflector.cpp Reflector.hpp Plugboard.cpp Plugboard.hpp Rotor.cpp Rotor.hpp Machine.cpp Machine.hpp)

add_executable(cenigma_jk2714 ${SOURCE_FILES})