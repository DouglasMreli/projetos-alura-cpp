#include <ctime>
#include <cstdlib>
#include <string>
#include "arquivo.hpp"
#include "sorteia_palavra.hpp"

extern std::string PALAVRA_SECRETA;

void sorteia_palavra() {
    std::vector<std::string> palavras = le_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    
    PALAVRA_SECRETA = palavras[indice_sorteado];
}