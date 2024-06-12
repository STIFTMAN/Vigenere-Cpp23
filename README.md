# Vigenere V1.1 (C++23)

> This is a encryption and decrpytion library based on Vigenere algorithm.
> Just import it to use it

## Import
> You need `Vigenere.cpp` and also `Vigenere.h` in your folder

> `Vigenere.cpp` includes `Vigenere.h` so you just need one import statement

## Use case
> All is inside a namepspace called `Vigenere.cpp`

> Example:
```
#include "Vigenere.cpp"
#include <iostream>
#include <string>
#include <sstream>

int main(){
  std::istringstream analyzer  = std::istringstream("CRYPTOISSHORTFORCRYPTOGRAPHY");
  
  std::string key = "abcd";
  
  std::string result = Vigenere::cryptoStream(analyzer, key, Vigenere::MODE::ENCRYPT).str();
  
  // result = "CSASTPKVSIQUTGQUCSASTPIUAQJB"

  return 0;
}
```

### ENUMs

| Name | Values |
|-|-|
| `MODE` | `ENCRYPT`,`DECRYPT` |
| `CASE` | `NORMAL`,`LOWER`, `UPPER` |
| `FLAGS` | `NONE`,`IGNORE_SPECIAL_CHAR` |


### Main Function
| name | returntype |
| - | - |
| `cryptoStream` | `std::ostringstream` |

| Parametername (of `cryptoStream`) | Type | optional |
| - | - | - |
|  `stream` | `std::istringstream &`| false |
| `key` | `std::string`| false |
| `modeIn` | `MODE`| false |
| `caseIn` | `CASE`| true  (default: `CASE::NORMAL`)|
| `flagsIn` | `FLAGS`| true (default: `FLAGS::NONE`) |

## Tests (with Catch2)

### Windows
```
g++ -std=c++23 -I. ./testVigenere.cpp -o runTests; if ($?) { ./runTests }
```

### Unix (Linux / MacOs)

```
g++ -std=c++23 -I. ./testVigenere.cpp -o runTests && ./runTests
```

## Information about Vigenere algorithm

> https://en.wikipedia.org/wiki/Vigenère_cipher
