#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Vigenere.cpp"
#include <iostream>
#include <string>
#include <sstream>

// Note similar tests were reduced because of similar behaviour

SCENARIO("Test Vigenere"){
    GIVEN("Tests for single chars (charInRange() and cryptoChar())"){ // Variables used multiple times -> wrap it
        
        char lowerA, lowerZ, upperA, upperZ;
        char borderLowerUp, borderLowerDown, borderUpperUp, borderUpperDown;

        // Valid
        lowerA = 'a';
        lowerZ = 'z';
        upperA = 'A';
        upperZ = 'Z';

        // not Valid
        borderLowerUp = 'z' + 1;
        borderLowerDown = 'a' - 1;
        borderUpperUp = 'Z' + 1;
        borderUpperDown = 'A' -1;

        WHEN("Test charInRange()"){
            THEN("checks valid range of input of char"){
                CHECK(Vigenere::charInRange(lowerA) == 1);
                CHECK(Vigenere::charInRange(lowerZ) == 1);
                CHECK(Vigenere::charInRange(upperA) == 0);
                CHECK(Vigenere::charInRange(upperZ) == 0);

                CHECK(Vigenere::charInRange(borderLowerUp) == -1);
                CHECK(Vigenere::charInRange(borderLowerDown) == -1);
                CHECK(Vigenere::charInRange(borderUpperUp) == -1);
                CHECK(Vigenere::charInRange(borderUpperDown) == -1);
            }
        }
        WHEN("Test cryptoChar()"){

            char lowerKeyA, lowerKeyZ, upperKeyA, upperKeyZ;
            char borderLowerKeyUp, borderLowerKeyDown, borderUpperKeyUp, borderUpperKeyDown;
            Vigenere::MODE encryptionFlag;

            // Valid
            lowerKeyA = 'a';
            lowerKeyZ = 'z';
            upperKeyA = 'A';
            upperKeyZ = 'Z';

            // not Valid
            borderLowerKeyUp = 'z' + 1;
            borderLowerKeyDown = 'a' - 1;
            borderUpperKeyUp = 'Z' + 1;
            borderUpperKeyDown = 'A' -1;

            THEN("encryption"){
                encryptionFlag = Vigenere::MODE::ENCRYPT;

                // Successful tests
                CHECK(Vigenere::cryptoChar(lowerA, lowerKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(lowerA, lowerKeyZ, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(lowerA, upperKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(lowerA, upperKeyZ, encryptionFlag) == 'Z');

                CHECK(Vigenere::cryptoChar(upperA, lowerKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(upperA, lowerKeyZ, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(upperA, upperKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(upperA, upperKeyZ, encryptionFlag) == 'Z');

                CHECK(Vigenere::cryptoChar(lowerZ, lowerKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(lowerZ, lowerKeyZ, encryptionFlag) == 'Y');
                CHECK(Vigenere::cryptoChar(lowerZ, upperKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(lowerZ, upperKeyZ, encryptionFlag) == 'Y');

                CHECK(Vigenere::cryptoChar(upperZ, lowerKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(upperZ, lowerKeyZ, encryptionFlag) == 'Y');
                CHECK(Vigenere::cryptoChar(upperZ, upperKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(upperZ, upperKeyZ, encryptionFlag) == 'Y');

                // Failing tests for plaintextchar
                
                CHECK(Vigenere::cryptoChar(borderLowerDown, lowerKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerDown, lowerKeyZ, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerDown, upperKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerDown, upperKeyZ, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(borderLowerUp, lowerKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerUp, lowerKeyZ, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerUp, upperKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderLowerUp, upperKeyZ, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(borderUpperDown, lowerKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperDown, lowerKeyZ, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperDown, upperKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperDown, upperKeyZ, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(borderUpperUp, lowerKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperUp, lowerKeyZ, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperUp, upperKeyA, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(borderUpperUp, upperKeyZ, encryptionFlag) == -1);

                // failing tests for keychar
                CHECK(Vigenere::cryptoChar(lowerA, borderLowerKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerA, borderLowerKeyDown, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerA, borderUpperKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerA, borderUpperKeyDown, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(upperA, borderLowerKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperA, borderLowerKeyDown, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperA, borderUpperKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperA, borderUpperKeyDown, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(lowerZ, borderLowerKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerZ, borderLowerKeyDown, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerZ, borderUpperKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(lowerZ, borderUpperKeyDown, encryptionFlag) == -1);

                CHECK(Vigenere::cryptoChar(upperZ, borderLowerKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperZ, borderLowerKeyDown, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperZ, borderUpperKeyUp, encryptionFlag) == -1);
                CHECK(Vigenere::cryptoChar(upperZ, borderUpperKeyDown, encryptionFlag) == -1);
            }
            THEN("decryption"){
                encryptionFlag = Vigenere::MODE::DECRYPT;

                // Successful tests
                CHECK(Vigenere::cryptoChar(lowerA, lowerKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(lowerA, lowerKeyZ, encryptionFlag) == 'B');
                CHECK(Vigenere::cryptoChar(lowerA, upperKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(lowerA, upperKeyZ, encryptionFlag) == 'B');

                CHECK(Vigenere::cryptoChar(upperA, lowerKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(upperA, lowerKeyZ, encryptionFlag) == 'B');
                CHECK(Vigenere::cryptoChar(upperA, upperKeyA, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(upperA, upperKeyZ, encryptionFlag) == 'B');

                CHECK(Vigenere::cryptoChar(lowerZ, lowerKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(lowerZ, lowerKeyZ, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(lowerZ, upperKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(lowerZ, upperKeyZ, encryptionFlag) == 'A');

                CHECK(Vigenere::cryptoChar(upperZ, lowerKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(upperZ, lowerKeyZ, encryptionFlag) == 'A');
                CHECK(Vigenere::cryptoChar(upperZ, upperKeyA, encryptionFlag) == 'Z');
                CHECK(Vigenere::cryptoChar(upperZ, upperKeyZ, encryptionFlag) == 'A');
            }
        }
    }
    GIVEN("Tests for hole streams (encryptStream())"){
        std::istringstream analyzer;
        std::string key;
        Vigenere::MODE modeIn;

        WHEN("Test cryptoStream minimum encrypt with default Flags and default case"){

            modeIn = Vigenere::MODE::ENCRYPT;
            analyzer.clear();
            analyzer.seekg(0);
            THEN("empty Stream is ok"){
                key = "Passwort";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn).str() == "");
            }
            THEN("key is not allow to be empty"){
                analyzer = std::istringstream("Test text");

                CHECK_THROWS_AS(Vigenere::cryptoStream(analyzer, key, modeIn), std::invalid_argument);
            }
            THEN("key is not allow to have special chars"){
                analyzer = std::istringstream("Test text");
                key = ". #4,";

                CHECK_THROWS_AS(Vigenere::cryptoStream(analyzer, key, modeIn), std::invalid_argument);
            }
            THEN("Mode have to be set else encrypt"){
                analyzer = std::istringstream("Test text");
                key = "Passwort";
                Vigenere::MODE modeInEmpty; // same as ENCRYPT
                std::string result1 = Vigenere::cryptoStream(analyzer, key, modeInEmpty).str();
                analyzer.seekg(0);
                std::string result2 = Vigenere::cryptoStream(analyzer, key, Vigenere::MODE::ENCRYPT).str();
                CHECK(modeInEmpty == Vigenere::MODE::ENCRYPT);
                CHECK(result1 == result2);
            }
            THEN("Happy path with string"){
                analyzer = std::istringstream("CRYPTOISSHORTFORCRYPTOGRAPHY");
                key = "abcd";
                std::string result = "CSASTPKVSIQUTGQUCSASTPIUAQJB";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn).str() == result);
            }
            
        }
        WHEN("Test cryptoStream minimum decrypt with default Flags and default case"){

            modeIn = Vigenere::MODE::DECRYPT;
        
            THEN("Happy path with string"){
                analyzer = std::istringstream("CSASTPKVSIQUTGQUCSASTPIUAQJB");
                key = "abcd";
                std::string result = "CRYPTOISSHORTFORCRYPTOGRAPHY";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn).str() == result);
            }
        }
        WHEN("Test cryptoStream with Flags and only in lower case"){
            Vigenere::CASE caseIn;
            std::string result;

            key = "abcd";
            modeIn = Vigenere::MODE::ENCRYPT;
            caseIn = Vigenere::CASE::LOWER;

            analyzer.clear();
            analyzer.seekg(0);

            THEN("flag ignore special characters only"){
                analyzer = std::istringstream("- .1+");
                result = "";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::IGNORE_SPECIAL_CHAR).str() == result);
            }
            THEN("flag none"){
                analyzer = std::istringstream("- .1+");
                result = "- .1+";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::NONE).str() == result);
            }
            THEN("flag ignore special characters mixed with letters"){
                analyzer = std::istringstream("CRYPTO IS-SHORT.FOR#CRYPTOGRAPHY");
                result = "csastpkvsiqutgqucsastpiuaqjb";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::IGNORE_SPECIAL_CHAR).str() == result);
            }
            THEN("flag none mixed with letters"){
                analyzer = std::istringstream("CRYPTO IS-SHORT.FOR#CRYPTOGRAPHY");
                result = "csastp kv-siqut.gqu#csastpiuaqjb";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::NONE).str() == result);
            }
        }
        WHEN("Test cryptoStream with Flags and only in upper case"){
            Vigenere::CASE caseIn;
            std::string result;

            key = "abcd";
            modeIn = Vigenere::MODE::ENCRYPT;
            caseIn = Vigenere::CASE::UPPER;

            analyzer.clear();
            analyzer.seekg(0);

            THEN("flag ignore special characters mixed with letters"){
                analyzer = std::istringstream("CRYPTO IS-SHORT.FOR#CRYPTOGRAPHY");
                result = "CSASTPKVSIQUTGQUCSASTPIUAQJB";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::IGNORE_SPECIAL_CHAR).str() == result);
            }
            THEN("flag none mixed with letters"){
                analyzer = std::istringstream("CRYPTO IS-SHORT.FOR#CRYPTOGRAPHY");
                result = "CSASTP KV-SIQUT.GQU#CSASTPIUAQJB";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::NONE).str() == result);
            }
        }
        WHEN("Test cryptoStream with Flags and normal case"){
            Vigenere::CASE caseIn;
            std::string result;

            key = "abcd";
            modeIn = Vigenere::MODE::ENCRYPT;
            caseIn = Vigenere::CASE::NORMAL;

            THEN("flag none mixed with letters"){
                analyzer = std::istringstream("CRYPtO IS-SHORT.FOR#CryPTOGRapHY");
                result = "CSAStP KV-SIQUT.GQU#CsaSTPIUaqJB";

                CHECK(Vigenere::cryptoStream(analyzer, key, modeIn, caseIn, Vigenere::FLAGS::NONE).str() == result);
            }
        }
    }
}