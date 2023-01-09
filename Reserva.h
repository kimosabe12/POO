//
// Created by diogo on 22/11/2022.
//

#ifndef TRABALHO_POO_RESERVA_H
#define TRABALHO_POO_RESERVA_H
#include "Utils.h"
#include "Animais.h"
#include "Alimento.h"

class Reserva{
private:
    int instante;
    string guardaNome;
    vector<Reserva *> reservas;
public:
    vector<Coelho*> coelhos;
    vector<Ovelha*> ovelhas;
    vector<Lobo*> lobos;
    vector<Canguru*> cangurus;
    vector<Abelha*> abelhas;
    vector<Relva*> relvas;
    vector<Cenoura*> cenouras;
    vector<Corpo*> corpos;
    vector<Bife*> bifes;
    vector<Alface*> alfaces;
    int curlinhas, curcolunas;      // falta fazer setter
    int nlinhas, ncolunas;
    Reserva(Reserva *pReserva);
    string getGuardaNome() const {return guardaNome;};
    void mostraReserva();
    bool validaComandos(Window& janelaComandos, istringstream &comando);
};
extern Reserva* reserva;
#endif //TRABALHO_POO_RESERVA_H
