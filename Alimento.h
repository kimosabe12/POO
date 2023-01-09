//
// Created by diogo on 22/11/2022.
//

#ifndef TRABALHO_POO_ALIMENTO_H
#define TRABALHO_POO_ALIMENTO_H
#include "Utils.h"
class Alimento{
protected:
    int id;
    char sigla;
    int duracao=0;
    int valor_nutritivo;
    int toxicidade;
    vector<string> cheira;
    int linha;
    int coluna;
public:
    int getId() const{return id;}
    char getSigla() const{return sigla;}
    int getDuracao() const{return duracao;}
    int getValor_Nutritivo() const{return valor_nutritivo;}
    int getToxicidade() const{return toxicidade;}
    vector<string> getCheira() const{return cheira;}
    int getLinha() const {return linha;}
    int getColuna() const {return coluna;}
    void Atualiza_coordenadas(int linha, int coluna);
    void setValor_Nutritivo(int valor_nutritivo){
        this->valor_nutritivo=valor_nutritivo;
    }
    void setToxicidade(int toxicidade){
        this->toxicidade=toxicidade;
    }
};

class Relva : public Alimento{
private:

public: Relva();
};

class Cenoura : public Alimento{
private:

public: Cenoura();
};

class Corpo : public Alimento{
private:

public: Corpo();
};

class Bife : public Alimento{
private:

public: Bife();
};

class Alface : public Alimento{
private:

public: Alface();
};

class alimento_misterio : public Alimento{
private:

public: alimento_misterio();
};

#endif //TRABALHO_POO_ALIMENTO_H
