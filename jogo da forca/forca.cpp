#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "letra_existe.hpp"
#include "fim_de_jogo.hpp"
#include "impressao.hpp"
#include "chuta.hpp"
#include "arquivo.hpp"
#include "sorteia_palavra.hpp"

using namespace std;

string PALAVRA_SECRETA;
map<char,bool> chutou;
vector<char> chutes_errados;


int main() {
    imprimir_cabecalho();

    sorteia_palavra();

    while(nao_enforcou() && nao_acertou()) {

        imprime_erros();
        
        imprime_palavra();

        chuta();

        cout << endl;
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou()) {
        cout << "Você perdeu! A palavra secreta era: " << PALAVRA_SECRETA;
        cout << endl; 
    }else {
        cout << "Parabés! Você acertou." << endl;
        cout << "Você deseja adicionar uma nova palavra ao banco de palavras? (S/N)";
        char resposta;
        cin >> resposta;

        if(resposta == 'S') {
            adicionar_ao_banco();
        }
    }
}