//
// Created by diogo on 22/11/2022.
//

#include "Alimento.h"
#include "le_constantes.h"
Relva::Relva() {
    id=id_disponivel;
    id_disponivel++;
    sigla='r';
    duracao=le_constantes::obterValor("VRelva");
    valor_nutritivo=3;
    toxicidade=0;
    cheira.emplace_back("erva");
    cheira.emplace_back("verdura");
}
Cenoura::Cenoura() {
    id=id_disponivel;
    id_disponivel++;
    sigla='t';
    valor_nutritivo=4;
    toxicidade=3;
    cheira.emplace_back("verdura");
}
Corpo::Corpo() {
    id=id_disponivel;
    id_disponivel++;
    sigla='p';
    valor_nutritivo=0;
    toxicidade=0;
    cheira.emplace_back("carne");
}
Bife::Bife() {
    id=id_disponivel;
    id_disponivel++;
    sigla='b';
    valor_nutritivo=10;
    toxicidade=2;
    cheira.emplace_back("carne");
    cheira.emplace_back("ketchup");
}
Alface::Alface() {
    id=id_disponivel;
    id_disponivel++;
    sigla='a';
    valor_nutritivo=1+(rand()%15);
    toxicidade=0;
    cheira.emplace_back("verdura");
}
void Alimento::Atualiza_coordenadas(int linha, int coluna){
    this->linha=linha;
    this->coluna=coluna;
}