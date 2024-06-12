#include "Vigenere.h"

char Vigenere::charInRange(char c){
	if(c >= 'a' && c <= 'z'){
		return 1;
	}
	else if(c >= 'A' && c <= 'Z'){
		return 0;
	}
	return -1;
}

char Vigenere::cryptoChar(char plaintextChar, char keyChar, Vigenere::MODE modeIn, Vigenere::CASE caseIn){
	int validPlaintextChar = charInRange(plaintextChar);
	int validKeyChar = charInRange(keyChar);
	int diff;
	char caseLetter = 'A'; // default
	
	if(validKeyChar >= 0 && validPlaintextChar >= 0){
		switch(caseIn){
			case Vigenere::CASE::NORMAL:
				if(validPlaintextChar == 0){
					caseLetter = 'A';
					plaintextChar = toupper(plaintextChar) - caseLetter;
					diff = toupper(keyChar) - caseLetter;
				}
				else{
					caseLetter = 'a';
					plaintextChar = tolower(plaintextChar) - caseLetter;
					diff = tolower(keyChar) - caseLetter;
				}
				break;
			case Vigenere::CASE::LOWER:
				caseLetter = 'a';
				plaintextChar = tolower(plaintextChar) - caseLetter;
				diff = tolower(keyChar) - caseLetter;
				break;
			case Vigenere::CASE::UPPER:
				caseLetter = 'A';
				plaintextChar = toupper(plaintextChar) - caseLetter;
				diff = toupper(keyChar) - caseLetter;
				break;
			default: // wie VIGENERE::CASE::NORMAL
				if(validPlaintextChar == 0){
					caseLetter = 'A';
					plaintextChar = toupper(plaintextChar) - caseLetter;
					diff = toupper(keyChar) - caseLetter;
				}
				else{
					caseLetter = 'a';
					plaintextChar = tolower(plaintextChar) - caseLetter;
					diff = tolower(keyChar) - caseLetter;
				}
				break;
		}
		if(modeIn == Vigenere::MODE::DECRYPT){
			return (char) (caseLetter + (plaintextChar - diff +26*2) % 26);
		}
		else if(modeIn == Vigenere::MODE::ENCRYPT){
			return (char) (caseLetter + (plaintextChar + diff) % 26); 
		}
		else{
			std::__throw_invalid_argument("Invalid Mode!");
		}

	}
	return -1;
}

std::ostringstream Vigenere::cryptoStream(std::istringstream & stream, std::string key, Vigenere::MODE modeIn, Vigenere::CASE caseIn, Vigenere::FLAGS flagsIn){
	std::size_t keyCounter = 0; // loop through key over and over again and need current position of char of key until EOF of stream
	char currentChar, newChar;
	std::ostringstream encryptedString;
	if(key.size() == 0){
		std::__throw_invalid_argument("Key string should have at least one char!");
		return encryptedString;
	}
	if(!(modeIn == Vigenere::MODE::ENCRYPT || modeIn == Vigenere::MODE::DECRYPT)){
		std::__throw_invalid_argument("Invalid Mode!");
		return encryptedString;
	}
	for(std::size_t i = 0; i < key.size(); i++){
		if(Vigenere::charInRange(key[i]) == -1){
			std::__throw_invalid_argument("Invalid characters in key string!");
			return encryptedString;
		}
	}
	while(stream.good() && stream.peek() != EOF){
		stream.get(currentChar);
		if((newChar = Vigenere::cryptoChar(currentChar, key[keyCounter], modeIn, caseIn)) != -1){
			if(key.size() > keyCounter + 1){
				keyCounter++;
			}
			else{
				keyCounter = 0;
			}
			encryptedString << newChar;
		}
		else{
			if(flagsIn == Vigenere::FLAGS::NONE){
				encryptedString << currentChar;
			}
		}
	}
	return encryptedString;
}