#include <string>
#include <map>
#include <vector>
#include "fim_de_jogo.hpp"

extern std::string PALAVRA_SECRETA;
extern std::map<char,bool> chutou;
extern std::vector<char> chutes_errados;

bool nao_acertou() {
    for(char letra: PALAVRA_SECRETA) {
        if(!chutou[letra]) {
            return true;
        }
    }

    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}