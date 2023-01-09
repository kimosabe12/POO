//
// Created by diogo on 22/11/2022.
//

#include "le_constantes.h"
std::map<std::string, int> le_constantes::constantes;

bool le_constantes::ler_ficheiro(string path) {
    ifstream leDados(path);
    if(!leDados){
        return false;
    }
    string linha;

    while (getline(leDados, linha)){
        istringstream aux (linha);
        string palavra;
        int numero;
        aux >> palavra >> numero;
        constantes[palavra]=numero;
    }
    return true;

}
int le_constantes::obterValor(string nome) {
    if (constantes.count(nome)>0){//contar o nº de vezes que o nome aparece
        return constantes[nome];
    }else
        return -1;
}