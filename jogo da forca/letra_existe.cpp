#include <string>
#include "letra_existe.hpp"

extern std::string PALAVRA_SECRETA;

bool letra_existe(char chute) {
    for(char letra: PALAVRA_SECRETA) {
        if(letra == chute) {
            return true; 
        }
    }

    return false;
}