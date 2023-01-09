//
// Created by diogo on 22/11/2022.
//

#include "Animais.h"
#include "Utils.h"
#include "Reserva.h"
#include "le_constantes.h"
#include <algorithm>
int id_disponivel=1;
Coelho::Coelho() {
    id=id_disponivel;
    id_disponivel++;
    sigla='C';
    saude=le_constantes::obterValor("SCoelho");
    peso=1+(rand()%4);
    tempo_vivo= le_constantes::obterValor("VCoelho");
    cheiro.emplace_back("verdura");
}

Ovelha::Ovelha() {
    id=id_disponivel;
    id_disponivel++;
    sigla='O';
    saude=le_constantes::obterValor("SOvelha");
    peso=4+(rand()%8);
    tempo_vivo=le_constantes::obterValor("VCoelho");
    cheiro.emplace_back("erva");
}
Lobo::Lobo() {
    id=id_disponivel;
    id_disponivel++;
    sigla='L';
    saude=le_constantes::obterValor("SLobo");
    peso=15;
    tempo_vivo=le_constantes::obterValor("VLobo");
    cheiro.emplace_back("carne");
}
Canguru::Canguru() {
    id=id_disponivel;
    id_disponivel++;
    sigla='G';
    saude=le_constantes::obterValor("SCanguru");
    peso=10;
    tempo_vivo=le_constantes::obterValor("VCanguru");
}
Abelha::Abelha(){
    id=id_disponivel;
    id_disponivel++;
    sigla='M';
    saude=le_constantes::obterValor("SAbelha");
    peso=3;
    tempo_vivo=le_constantes::obterValor("VAbelha");
}
void Animais::Atualiza_coordenadas(int linha, int coluna){
    this->linha=linha;
    this->coluna=coluna;
}
void Coelho::mexe() {
    if(idade==8){
        auto coelho = new Coelho();
        coelho->Atualiza_coordenadas(linha,coluna);
        reserva->coelhos.push_back(coelho);
    }
    idade++;
    saude--;
    fome++;
    if(idade==tempo_vivo){
        reserva->coelhos.erase(std::remove_if(reserva->coelhos.begin(), reserva->coelhos.end(), [this](Coelho* coelho){
            return coelho->getId()==id;
        }), reserva->coelhos.end());
    }
    if (fome <= 10) {
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else if (fome >= 20) {
        this->linha += -1 + (rand() % 4);
        this->coluna += -1 + (rand() % 4);
    } else{
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    }
}
void Ovelha::mexe() {
    idade++;
    saude--;
    fome++;
    if(idade==35 || saude==0)
        reserva->ovelhas.erase(std::remove_if(reserva->ovelhas.begin(), reserva->ovelhas.end(), [this](Ovelha* ovelha){
                if (ovelha->getId() == id) {
                    auto corpo=new Corpo();
                    corpo->Atualiza_coordenadas(ovelha->getLinha(),ovelha->getColuna());
                    corpo->setValor_Nutritivo(peso);
                    reserva->corpos.push_back(corpo);
                    return true;
                }
                return false;
            }), reserva->ovelhas.end());
    if (fome <= 10) {
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else if (fome >= 20) {
        this->linha += -1 + (rand() % 4);
        this->coluna += -1 + (rand() % 4);
    } else{
        this->linha += -1 + (rand() % 1);
        this->coluna += -1 + (rand() % 1);
    }
}

void Lobo::mexe() {
    idade++;
    fome+=2;

    if (fome <= 25) {
        saude-=2;
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else if (fome >= 10) {
        saude--;
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else{
        this->linha += -5 + (rand() % 5);
        this->coluna += -5 + (rand() % 5);
    }

    if (saude==0) {
        reserva->lobos.erase(std::remove_if(reserva->lobos.begin(), reserva->lobos.end(), [this](Lobo *lobo) {
            if (lobo->getId() == id) {
                auto corpo = new Corpo();
                corpo->Atualiza_coordenadas(lobo->getLinha(), lobo->getColuna());
                corpo->setValor_Nutritivo(10);
                corpo->setToxicidade(0);
                reserva->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), reserva->lobos.end());
    }
}
void Canguru::mexe() {
    idade++;
    fome+=2;
    if (fome <= 25) {
        saude-=2;
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else if (fome >= 10) {
        saude--;
        this->linha += -2 + (rand() % 2);
        this->coluna += -2 + (rand() % 2);
    } else{
        this->linha += -5 + (rand() % 5);
        this->coluna += -5 + (rand() % 5);
    }
    if(saude==0) {
        reserva->cangurus.erase(std::remove_if(reserva->cangurus.begin(), reserva->cangurus.end(), [this](Canguru *canguru) {
                    if (canguru->getId() == id) {
                        auto corpo = new Corpo();
                        corpo->Atualiza_coordenadas(canguru->getLinha(), canguru->getColuna());
                        corpo->setValor_Nutritivo(5);
                        corpo->setToxicidade(15);
                        reserva->corpos.push_back(corpo);
                        return true;
                    }
                    return false;
                }), reserva->cangurus.end());
    }
}
void Abelha::mexe() {
    idade++;
    fome++;
    if(fome>=7){
        saude--;
    }
    if(saude==0||idade==10){
        reserva->abelhas.erase(std::remove_if(reserva->abelhas.begin(), reserva->abelhas.end(), [this](Abelha *abelha) {
            if (abelha->getId() == id) {
                auto corpo = new Corpo();
                corpo->Atualiza_coordenadas(abelha->getLinha(), abelha->getColuna());
                corpo->setValor_Nutritivo(0);
                corpo->setToxicidade(3);
                reserva->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), reserva->abelhas.end());
    }
}























