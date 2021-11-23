#include <iostream>
#include <vector>
#include <fstream>
#include <vector>
#include <string>
#include "arquivo.hpp"

extern std::vector<char> chutes_errados;

std::vector<std::string> le_arquivo() {
    std::ifstream arquivo;
    arquivo.open("palavras.txt");
    
    if(!arquivo.is_open()) {
        std::cout << "Não foi possivel acessar o arquivo de palavras" << std::endl;
        exit(0);
    }

    int quantiade_palavras;
    arquivo >> quantiade_palavras;
    if(!(quantiade_palavras > 0)) {
        std::cout << "Não há palavras no arquivo." << std::endl;
        exit(0);
    }

    std::vector<std::string> palavras_do_arquivo;

    for(int i = 0; i < quantiade_palavras; i++) {
        std::string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }

    arquivo.close();
    return palavras_do_arquivo;
}

void salva_arquivo(std::vector<std::string> lista) {
    std::ofstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()) {
        arquivo << lista.size() <<std:: endl;
        for(std::string palavra : lista) {
            arquivo << palavra << std::endl;
        }

        arquivo.close();
    }else {
        std::cout << "Não foi possivel acessar o arquivo de palavras" << std::endl;
        exit(0);
    }
}

void adicionar_ao_banco() {
    std::cout << "Digite a palavra que deseja adicionar: (somente letras maisculas) ";
    std::string nova_palavra;
    std::cin >> nova_palavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}