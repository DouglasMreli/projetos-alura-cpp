#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "impressao.hpp"

extern std::string PALAVRA_SECRETA;
extern std::map<char,bool> chutou;
extern std::vector<char> chutes_errados;

void imprimir_cabecalho() {
    std::cout << "*********************" << std::endl;
    std::cout << "*** JOGO DA FORCA ***" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
}

void imprime_erros() {
    std::cout << "Chutes errados: ";
        for(char letra: chutes_errados) {
            std::cout << letra << " - ";
        }
        std::cout << std::endl;
}

void imprime_palavra() {
    for(char letra: PALAVRA_SECRETA) {
                if(chutou[letra]) {
                    std::cout << letra << " ";
                }else {
                    std::cout << "_";
                }
            }
}