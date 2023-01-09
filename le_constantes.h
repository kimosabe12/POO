//
// Created by diogo on 22/11/2022.
//

#ifndef TRABALHO_POO_LE_CONSTANTES_H
#define TRABALHO_POO_LE_CONSTANTES_H
#include "Utils.h"
namespace le_constantes{
    extern std::map<std::string, int> constantes;
    bool ler_ficheiro(string path);//localizacao do ficheiro
    int obterValor(string nome);
};
#endif //TRABALHO_POO_LE_CONSTANTES_H
