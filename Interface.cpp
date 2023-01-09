//
// Created by diogo on 22/11/2022.
//

#include <iostream>
#include <string.h>
#include "Utils.h"
#include "Interface.h"
#include "le_constantes.h"
#include "Reserva.h"
void menu(){
    Terminal& t = Terminal::instance();
    Window janelaPrincipal = Window(0, 0, 70, 20, false);
    Window janelaComando = Window(0,16,120,13,false);

    string opcao_menu;
    do{
        janelaPrincipal << "\n1- Novo Jogo\n";
        janelaPrincipal << "2- Carregar Jogo(em desenvolvimento)\n";
        janelaPrincipal << "3- Sair\n";

        janelaPrincipal << "\n>";
        janelaPrincipal >> opcao_menu;
        if(opcao_menu == "1"){
            Terminal::instance().clear();
          //  Reserva NovaReserva=Reserva();
            janelaComando<<term::move_to(0, 2)<<"A Reserva contem "<<reserva->nlinhas << " linhas e " << reserva->ncolunas << " colunas\n";
            string comando;
            while(true){
                reserva->mostraReserva();
                janelaComando<<term::move_to(0, 0)<<"Introduza um comando: ";
                janelaComando>>comando;
                janelaComando.clear();
                if (comando == "KEY_UP")
                    reserva->curlinhas--;
                else if (comando == "KEY_DOWN")
                    reserva->curlinhas++;
                else if (comando == "KEY_LEFT")
                {
                    reserva->curcolunas--;
                }
                else if (comando == "KEY_RIGHT")
                {
                    reserva->curcolunas++;
                }
                else if (comando == "KEY_RESIZE")
                {
                    continue;
                }
                else
                {
                    istringstream stream(comando);
                    if(!reserva->validaComandos(janelaComando, stream))
                        break;
                }
            }
        }
        else if(opcao_menu == "2")
            janelaPrincipal << "\nEm desenvolvimento!\n";
        else if(opcao_menu == "3")
            exit(1);
        else if( opcao_menu == "KEY_UP"||opcao_menu == "KEY_DOWN"||opcao_menu == "KEY_LEFT"||opcao_menu == "KEY_RIGHT"||opcao_menu == "KEY_RESIZE")
            continue;
        else
            janelaPrincipal << "\nIntroduza uma opção válida!\n";
    } while (opcao_menu!="3");
}