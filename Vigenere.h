#if !defined(VIGENERE_H)
#define VIGENERE_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace Vigenere{

    enum MODE {ENCRYPT, DECRYPT};
    enum CASE{NORMAL, LOWER, UPPER};
    enum FLAGS{NONE, IGNORE_SPECIAL_CHAR};

    std::ostringstream cryptoStream(std::istringstream & stream, std::string key, MODE modeIn, CASE caseIn = CASE::NORMAL, FLAGS flagsIn = FLAGS::NONE);
    char cryptoChar(char unencryptedChar, char keyChar, MODE modeIn, CASE caseIn = CASE::UPPER);
    char charInRange(char c);    //> Check if char is between a-z or A-Z

}
#endif