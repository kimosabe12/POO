#include <iostream>
#include "Utils.h"
#include "Interface.h"
#include "Terminal.h"
#include "le_constantes.h"
#include "Reserva.h"
int main() {
    le_constantes::ler_ficheiro("constantes.txt");
    if(!le_constantes::ler_ficheiro("constantes.txt")){
        cout<<"Erro a ler o ficheiro"<<endl;
        return 1;
    }

    menu();
    return 0;
}