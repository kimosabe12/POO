//
// Created by diogo on 22/11/2022.
//

#ifndef TRABALHO_POO_ANIMAIS_H
#define TRABALHO_POO_ANIMAIS_H
#include "Utils.h"
class Animais{
protected:
    int id;
    char sigla;
    int saude;
    int peso;
    int tempo_vivo;
    int fome = 0;
    int linha;
    int coluna;
    int idade;
    vector<string> cheiro;

public:
    int getId() const{return id;}
    int getSaude() const{return saude;}
    int getPeso() const{return peso;}
    int getTempo_vivo() const{return tempo_vivo;}
    int getFome() const{return fome;}
    char getSigla() const{ return sigla;}
    int getLinha() const {return linha;}
    int getColuna() const {return coluna;}
    vector<string> getCheiro() const{return cheiro;}
    void Atualiza_coordenadas(int linha, int coluna);
    void setSaude(int saude) {
        this->saude = saude;
    }
};

class Coelho : public Animais{
private:

public: Coelho();
    void mexe();
};
class Ovelha : public Animais{
private:

public: Ovelha();
    void mexe();

};
class Lobo : public Animais{
private:

public: Lobo();
    void mexe();

};
class Canguru : public Animais{
private:

public: Canguru();
    void mexe();

};
class Abelha : public Animais{
private:

public: Abelha();
    void mexe();

};

#endif //TRABALHO_POO_ANIMAIS_H