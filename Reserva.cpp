//
// Created by diogo on 22/11/2022.
//

#include <algorithm>
#include <unistd.h>
#include <ctime>
#include "Reserva.h"
#include "le_constantes.h"
#include "Alimento.h"

Reserva* reserva = new Reserva(nullptr);

Reserva::Reserva(Reserva *pReserva) {
    /*
     string input;
    do{
        cout<<"Introduza o numero de linhas: ";
        getline(cin, input);
        stringstream (input)>>nlinhas;
    }while(nlinhas<16||nlinhas>500);
    do{
        cout<<"Introduza o numero de colunas: ";
        getline(cin, input);
        stringstream (input)>>ncolunas;
    }while(ncolunas<16||ncolunas>500);
*/
    srand((unsigned) time(nullptr));

    nlinhas=16+(rand()%500);
    ncolunas=16+(rand()%500);

    curcolunas=0;
    curlinhas=0;
}

void Reserva::mostraReserva() {
    static Window janelaReserva = Window(0,0, 120, 15);
    janelaReserva<<term::move_to(0,0);

    for (int i = curlinhas; i < curlinhas + 10; i++) {
        for (int j = curcolunas; j < curcolunas + 14; j++) {
           int letras = 0;
            janelaReserva << "|";
                for (auto& coelho : coelhos)
                    if (coelho->getLinha() == i && coelho->getColuna()==j) {
                        janelaReserva << coelho->getSigla();
                        letras++;
                    }
                for(auto& ovelha : ovelhas)
                    if(ovelha->getLinha()==i && ovelha->getColuna()==j){
                        janelaReserva<<ovelha->getSigla();
                        letras++;
                    }
                for(auto& lobo : lobos)
                    if(lobo->getLinha()==i && lobo->getColuna()==j){
                        janelaReserva<<lobo->getSigla();
                        letras++;
                    }
                for(auto& canguru : cangurus)
                    if(canguru->getLinha()==i && canguru->getColuna()==j){
                        janelaReserva<<canguru->getSigla();
                        letras++;
                    }
                for(auto& abelha : abelhas)
                    if(abelha->getLinha()==i && abelha->getColuna()==j){
                        janelaReserva<<abelha->getSigla();
                        letras++;
                    }
                for (auto& relva : relvas)
                    if (relva->getLinha() == i && relva->getColuna()==j) {
                        janelaReserva << relva->getSigla();
                        letras++;
                    }
                for(auto& cenoura : cenouras)
                    if(cenoura->getLinha()==i && cenoura->getColuna()==j){
                        janelaReserva<<cenoura->getSigla();
                        letras++;
                    }
                for(auto& corpo : corpos)
                    if(corpo->getLinha()==i && corpo->getColuna()==j){
                        janelaReserva<<corpo->getSigla();
                        letras++;
                    }
                for(auto& bife : bifes)
                    if(bife->getLinha()==i && bife->getColuna()==j){
                        janelaReserva<<bife->getSigla();
                        letras++;
                    }
                for(auto& alface : alfaces)
                    if(alface->getLinha()==i && alface->getColuna()==j){
                        janelaReserva<<alface->getSigla();
                        letras++;
                    }
            if (letras == 0) // se nao houver animal/alimento aqui
                janelaReserva << "-------";
            else
                for (int k=letras; k < 7; k++ )
                    janelaReserva << "-";

            if (j == (curcolunas + 13)) {
                janelaReserva << "|";
            }
        }
        janelaReserva << "\n";
    }

}

bool Reserva::validaComandos(Window& janelaComandos, istringstream &comando){
    vector<string> args;
    while(comando){
        string subs;
        comando>>subs;
        args.push_back(subs);
    }
    janelaComandos << term::move_to(0, 2);
    args.pop_back();
    if (args[0] == "load" && args.size() == 2){
        string line;
        ifstream input_file(args[1]); //declarar e abrir o ficheiro
        if (!input_file) {
            cout << "Ocorreu um erro ao abrir o ficheiro" << endl;
            return false;  //ocorreu um erro
        }

        while (getline(input_file, line)) {
            istringstream lineFich(line);
            validaComandos(janelaComandos, lineFich);
        }

        // Close the file
        input_file.close();
        return true;

    }
    else if(args[0]=="animal"&&args.size()==4){
        if(args[1]=="c"||args[1]=="o"||args[1]=="l"||args[1]=="g"||args[1]=="m"){
            int linha=std::stoi(args[2])-1;
            int coluna=std::stoi(args[3])-1;
            if(linha<0||linha>nlinhas||coluna<0||coluna>ncolunas) {
                janelaComandos << "Invalido \n";
                return false;
            }
            if(args[1]=="c"){
                auto coelho = new Coelho();
                coelho->Atualiza_coordenadas(linha,coluna);
                this->coelhos.push_back(coelho);
            }else if(args[1]=="o"){
                auto ovelha=new Ovelha();
                ovelha->Atualiza_coordenadas(linha,coluna);
                this->ovelhas.push_back(ovelha);
            }else if(args[1]=="l"){
                auto lobo = new Lobo();
                lobo->Atualiza_coordenadas(linha, coluna);
                this->lobos.push_back(lobo);
            }else if(args[1]=="g"){
                auto canguru=new Canguru();
                canguru->Atualiza_coordenadas(linha, coluna);
                this->cangurus.push_back(canguru);
            }else if(args[1]=="m"){
                auto abelha=new Abelha();
                abelha->Atualiza_coordenadas(linha, coluna);
                this->abelhas.push_back(abelha);
            }
            janelaComandos<<"O animal "<<args[1]<<" foi adicionado na posicao "<<args[2]<<" "<<args[3]<<"\n";
        }
    }
    else if(args[0]=="animal"&&args.size()==2){
        if(args[1]=="c"||args[1]=="o"||args[1]=="l"||args[1]=="g"||args[1]=="m"){
            int linha=1+(rand()%nlinhas);
            int coluna=1+(rand()%ncolunas);
            if(args[1]=="c"){
                auto coelho = new Coelho();
                coelho->Atualiza_coordenadas(linha,coluna);
                this->coelhos.push_back(coelho);
            }else if(args[1]=="o"){
                auto ovelha=new Ovelha();
                ovelha->Atualiza_coordenadas(linha,coluna);
                this->ovelhas.push_back(ovelha);
            }else if(args[1]=="l"){
                auto lobo = new Lobo();
                lobo->Atualiza_coordenadas(linha, coluna);
                this->lobos.push_back(lobo);
            }else if(args[1]=="g"){
                auto canguru=new Canguru();
                canguru->Atualiza_coordenadas(linha, coluna);
                this->cangurus.push_back(canguru);
            }else if(args[1]=="m"){
                auto abelha=new Abelha();
                abelha->Atualiza_coordenadas(linha, coluna);
                this->abelhas.push_back(abelha);
            }
            janelaComandos<<"O animal "<<args[1]<<" foi adicionado na posicao aleatoria "<<linha<<" "<<coluna<<"\n";
        }
    }
    else if(args[0]=="kill"&&args.size()==3){
        int linha=std::stoi(args[1])-1;
        int coluna=std::stoi(args[2])-1;
        coelhos.erase(std::remove_if(coelhos.begin(), coelhos.end(), [linha, coluna](Coelho* coelho){
            return coelho->getLinha()==linha && coelho->getColuna()==coluna;
        }), coelhos.end());
        ovelhas.erase(std::remove_if(ovelhas.begin(), ovelhas.end(), [linha, coluna, this](Ovelha* ovelha){
            if (ovelha->getLinha()==linha && ovelha->getColuna()==coluna) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(ovelha->getLinha(),ovelha->getColuna());
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), ovelhas.end());
        lobos.erase(std::remove_if(lobos.begin(), lobos.end(), [linha, coluna, this](Lobo* lobo){
            if (lobo->getLinha()==linha && lobo->getColuna()==coluna) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(lobo->getLinha(),lobo->getColuna());
                corpo->setToxicidade(0);
                corpo->setValor_Nutritivo(10);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), lobos.end());
        cangurus.erase(std::remove_if(cangurus.begin(), cangurus.end(), [linha, coluna, this](Canguru* canguru){
            if (canguru->getLinha()==linha && canguru->getColuna()==coluna) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(canguru->getLinha(),canguru->getColuna());
                corpo->setValor_Nutritivo(15);
                corpo->setToxicidade(5);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), cangurus.end());
        abelhas.erase(std::remove_if(abelhas.begin(), abelhas.end(), [linha, coluna, this](Abelha* abelha){
            if (abelha->getLinha()==linha && abelha->getColuna()==coluna) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(abelha->getLinha(),abelha->getColuna());
                corpo->setToxicidade(3);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), abelhas.end());
        janelaComandos<<"Um animal foi morto na posicao "<<args[1]<<" "<<args[2]<<"\n";
    }
    else if(args[0]=="kill"&&args.size()==2){
        int id = std::stoi(args[1]);
        int peso_coelho=0;
        coelhos.erase(std::remove_if(coelhos.begin(), coelhos.end(), [id](Coelho* coelho){
            return coelho->getId() == id;
        }), coelhos.end());
        ovelhas.erase(std::remove_if(ovelhas.begin(), ovelhas.end(), [id, this](Ovelha* ovelha){
            if (ovelha->getId() == id) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(ovelha->getLinha(),ovelha->getColuna());
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), ovelhas.end());
        lobos.erase(std::remove_if(lobos.begin(), lobos.end(), [id, this](Lobo* lobo){
            if (lobo->getId() == id) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(lobo->getLinha(),lobo->getColuna());
                corpo->setToxicidade(0);
                corpo->setValor_Nutritivo(10);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), lobos.end());
        cangurus.erase(std::remove_if(cangurus.begin(), cangurus.end(), [id, this](Canguru* canguru){
            if (canguru->getId() == id) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(canguru->getLinha(),canguru->getColuna());
                corpo->setValor_Nutritivo(15);
                corpo->setToxicidade(5);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), cangurus.end());
        abelhas.erase(std::remove_if(abelhas.begin(), abelhas.end(), [id, this](Abelha* abelha){
            if (abelha->getId()==id) {
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(abelha->getLinha(),abelha->getColuna());
                corpo->setToxicidade(3);
                this->corpos.push_back(corpo);
                return true;
            }
            return false;
        }), abelhas.end());
        janelaComandos<<"O animal com o ID "<<args[1]<<" foi morto"<<"\n";
    }
    else if (args[0]=="food"&&args.size()==4){
        if(args[1]=="r"||args[1]=="t"||args[1]=="b"||args[1]=="p"||args[1]=="a"){
            int linha=std::stoi(args[2])-1;
            int coluna=std::stoi(args[3])-1;
            if(linha<0||linha>nlinhas||coluna<0||coluna>ncolunas) {
                janelaComandos << "Invalido \n";
                return true;
            }
            for (auto& relva : relvas)
                if (relva->getLinha() == linha && relva->getColuna()==coluna) {
                    janelaComandos << "Invalido \n";
                    return true;
                }
            for(auto& cenoura : cenouras)
                if(cenoura->getLinha()==linha && cenoura->getColuna()==coluna){
                    janelaComandos << "Invalido \n";
                    return true;
                }
            for(auto& corpo : corpos)
                if(corpo->getLinha()==linha && corpo->getColuna()==coluna){
                    janelaComandos << "Invalido \n";
                    return true;
                }
            for(auto& bife : bifes)
                if(bife->getLinha()==linha && bife->getColuna()==coluna){
                    janelaComandos << "Invalido \n";
                    return true;
                }
            for(auto& alface : alfaces)
                if(alface->getLinha()==linha && alface->getColuna()==coluna){
                    janelaComandos << "Invalido \n";
                    return true;
                }
            if(args[1]=="r"){
                auto relva = new Relva();
                relva->Atualiza_coordenadas(linha,coluna);
                this->relvas.push_back(relva);
            }else if(args[1]=="t"){
                auto cenoura=new Cenoura();
                cenoura->Atualiza_coordenadas(linha,coluna);
                this->cenouras.push_back(cenoura);
            }else if(args[1]=="b"){
                auto bife = new Bife();
                bife->Atualiza_coordenadas(linha, coluna);
                this->bifes.push_back(bife);
            }else if(args[1]=="p"){
                auto corpo=new Corpo();
                corpo->Atualiza_coordenadas(linha, coluna);
                this->corpos.push_back(corpo);
            }else if(args[1]=="a"){
                auto alface=new Alface();
                alface->Atualiza_coordenadas(linha, coluna);
                this->alfaces.push_back(alface);
            }
            janelaComandos<<"O alimento "<<args[1]<<" foi adicionado na posicao "<<args[2]<<" "<<args[3]<<"\n";
        }
    }
    else if (args[0]=="food"&&args.size()==2){
            if(args[1]=="r"||args[1]=="t"||args[1]=="p"||args[1]=="b"||args[1]=="a"){
                int linha, coluna;
                while (true){
                    linha=1+(rand()%nlinhas);
                    coluna=1+(rand()%ncolunas);
                    bool existe=false;
                    for (auto& relva : relvas)
                        if (relva->getLinha() == linha && relva->getColuna()==coluna) {
                            existe=true;
                            break; //se houver relva neste sitio da break
                        }
                    if(existe){
                        continue;//caso exista volta para o inicio do while e gera novos numeros aleatorios
                    }
                    for(auto& cenoura : cenouras)
                        if(cenoura->getLinha()==linha && cenoura->getColuna()==coluna){
                            existe=true;
                            break; //se houver relva neste sitio da break
                        }
                    if(existe){
                        continue;//caso exista volta para o inicio do while e gera novos numeros aleatorios
                    }
                    for(auto& corpo : corpos)
                        if(corpo->getLinha()==linha && corpo->getColuna()==coluna){
                            existe=true;
                            break; //se houver relva neste sitio da break
                        }
                    if(existe){
                        continue;//caso exista volta para o inicio do while e gera novos numeros aleatorios
                    }
                    for(auto& bife : bifes)
                        if(bife->getLinha()==linha && bife->getColuna()==coluna){
                            existe=true;
                            break; //se houver relva neste sitio da break
                        }
                    for(auto& alface : alfaces)
                        if(alface->getLinha()==linha && alface->getColuna()==coluna){
                            existe=true;
                            break; //se houver relva neste sitio da break
                        }
                    if(!existe){
                        break;//caso exista volta para o inicio do while e gera novos numeros aleatorios
                    }

                }
                if(args[1]=="r"){
                    auto relva = new Relva();
                    relva->Atualiza_coordenadas(linha,coluna);
                    this->relvas.push_back(relva);
                }else if(args[1]=="t"){
                    auto cenoura=new Cenoura();
                    cenoura->Atualiza_coordenadas(linha,coluna);
                    this->cenouras.push_back(cenoura);
                }else if(args[1]=="p"){
                    auto corpo = new Corpo();
                    corpo->Atualiza_coordenadas(linha, coluna);
                    this->corpos.push_back(corpo);
                }else if(args[1]=="b"){
                    auto bife=new Bife();
                    bife->Atualiza_coordenadas(linha, coluna);
                    this->bifes.push_back(bife);
                }else if(args[1]=="a"){
                    auto alface=new Alface();
                    alface->Atualiza_coordenadas(linha, coluna);
                    this->alfaces.push_back(alface);
                }
            janelaComandos<<"O alimento "<<args[1]<<" foi adicionado numa posicao aleatoria "<<linha<<" "<<coluna<<"\n";
        }
    }
    else if(args[0]=="feed"&&args.size()==5){
        int linha=std::stoi(args[1])-1;
        int coluna=std::stoi(args[2])-1;
        int vida=std::stoi(args[3])-std::stoi(args[4]);
        for (auto& coelho : coelhos)
            if (coelho->getLinha() == linha && coelho->getColuna()==coluna) {
                coelho->setSaude(coelho->getSaude()+vida);
            }
        for (auto& ovelha : ovelhas)
            if (ovelha->getLinha() == linha && ovelha->getColuna()==coluna) {
                ovelha->setSaude(ovelha->getSaude()+vida);
            }
        for (auto& lobo : lobos)
            if (lobo->getLinha() == linha && lobo->getColuna()==coluna) {
                lobo->setSaude(lobo->getSaude()+vida);
            }
        for (auto& canguru : cangurus)
            if (canguru->getLinha() == linha && canguru->getColuna()==coluna) {
                canguru->setSaude(canguru->getSaude()+vida);
            }
        for (auto& abelha : abelhas)
            if (abelha->getLinha() == linha && abelha->getColuna()==coluna) {
                abelha->setSaude(abelha->getSaude()+vida);
            }
        janelaComandos<<"O animal que esta na posicao "<<args[1]<<args[2]<<"foi alimentado com "<<args[3]<<"pontos nutritivos e intoxicado com "
                                                                                                 <<args[4]<<"\n";
    }
    else if(args[0]=="feedid"&&args.size()==4){
        int id=std::stoi(args[1]);
        int vida=std::stoi(args[2])-std::stoi(args[3]);
        for (auto& coelho : coelhos)
            if (coelho->getId()==id) {
                coelho->setSaude(coelho->getSaude()+vida);
            }
        for (auto& ovelha : ovelhas)
            if (ovelha->getId()==id) {
                ovelha->setSaude(ovelha->getSaude()+vida);
            }
        for (auto& lobo : lobos)
            if (lobo->getId()==id) {
                lobo->setSaude(lobo->getSaude()+vida);
            }
        for (auto& canguru : cangurus)
            if (canguru->getId()==id) {
                canguru->setSaude(canguru->getSaude()+vida);
            }
        for (auto& abelha : abelhas)
            if (abelha->getId()==id) {
                abelha->setSaude(abelha->getSaude()+vida);
            }
        janelaComandos<<"O animal com o ID "<<args[1]<<"foi alimentado com "<<args[2]<<"pontos nutritivos e intoxicado com "
                                                                                                    <<args[3]<<"\n";
    }
    else if (args[0]=="nofood"&&args.size()==3){
        int linha=std::stoi(args[1])-1;
        int coluna=std::stoi(args[2])-1;
        relvas.erase(std::remove_if(relvas.begin(), relvas.end(), [linha, coluna](Relva* relva){
            return relva->getLinha()==linha && relva->getColuna()==coluna;
        }), relvas.end());
        cenouras.erase(std::remove_if(cenouras.begin(), cenouras.end(), [linha, coluna](Cenoura* cenoura){
            return cenoura->getLinha()==linha && cenoura->getColuna()==coluna;
        }), cenouras.end());
        corpos.erase(std::remove_if(corpos.begin(), corpos.end(), [linha, coluna](Corpo* corpo){
            return corpo->getLinha()==linha && corpo->getColuna()==coluna;
        }), corpos.end());
        bifes.erase(std::remove_if(bifes.begin(), bifes.end(), [linha, coluna](Bife* bife){
            return bife->getLinha()==linha && bife->getColuna()==coluna;
        }), bifes.end());
        alfaces.erase(std::remove_if(alfaces.begin(), alfaces.end(), [linha, coluna](Alface* alface){
            return alface->getLinha()==linha && alface->getColuna()==coluna;
        }), alfaces.end());
        janelaComandos<<"O alimento foi removido da posicao "<<args[1]<<args[2]<<"\n";
    }
    else if (args[0]=="nofood"&&args.size()==2){
        int id = std::stoi(args[1]);
        relvas.erase(std::remove_if(relvas.begin(), relvas.end(), [id](Relva* relva){
            return relva->getId()==id;
        }), relvas.end());
        cenouras.erase(std::remove_if(cenouras.begin(), cenouras.end(), [id](Cenoura* cenoura){
            return cenoura->getId()==id;
        }), cenouras.end());
        corpos.erase(std::remove_if(corpos.begin(), corpos.end(), [id](Corpo* corpo){
            return corpo->getId()==id;
        }), corpos.end());
        bifes.erase(std::remove_if(bifes.begin(), bifes.end(), [id](Bife* bife){
            return bife->getId()==id;
        }), bifes.end());
        alfaces.erase(std::remove_if(alfaces.begin(), alfaces.end(), [id](Alface* alface){
            return alface->getId()==id;
        }), alfaces.end());
        janelaComandos<<"O alimento com o ID "<<args[1]<<"foi removido"<<"\n";
    }
    else if (args[0]=="empty"&&args.size()==3){
        int linha=std::stoi(args[1])-1;
        int coluna=std::stoi(args[2])-1;
        coelhos.erase(std::remove_if(coelhos.begin(), coelhos.end(), [linha, coluna](Coelho* coelho){
            return coelho->getLinha()==linha && coelho->getColuna()==coluna;
        }), coelhos.end());
        ovelhas.erase(std::remove_if(ovelhas.begin(), ovelhas.end(), [linha, coluna](Ovelha* ovelha){
            return ovelha->getLinha()==linha && ovelha->getColuna()==coluna;
        }), ovelhas.end());
        lobos.erase(std::remove_if(lobos.begin(), lobos.end(), [linha, coluna](Lobo* lobo){
            return lobo->getLinha()==linha && lobo->getColuna()==coluna;
        }), lobos.end());
        cangurus.erase(std::remove_if(cangurus.begin(), cangurus.end(), [linha, coluna](Canguru* canguru){
            return canguru->getLinha()==linha && canguru->getColuna()==coluna;
        }), cangurus.end());
        abelhas.erase(std::remove_if(abelhas.begin(), abelhas.end(), [linha, coluna](Abelha* abelha){
            return abelha->getLinha()==linha && abelha->getColuna()==coluna;
        }), abelhas.end());
        relvas.erase(std::remove_if(relvas.begin(), relvas.end(), [linha, coluna](Relva* relva){
            return relva->getLinha()==linha && relva->getColuna()==coluna;
        }), relvas.end());
        cenouras.erase(std::remove_if(cenouras.begin(), cenouras.end(), [linha, coluna](Cenoura* cenoura){
            return cenoura->getLinha()==linha && cenoura->getColuna()==coluna;
        }), cenouras.end());
        corpos.erase(std::remove_if(corpos.begin(), corpos.end(), [linha, coluna](Corpo* corpo){
            return corpo->getLinha()==linha && corpo->getColuna()==coluna;
        }), corpos.end());
        bifes.erase(std::remove_if(bifes.begin(), bifes.end(), [linha, coluna](Bife* bife){
            return bife->getLinha()==linha && bife->getColuna()==coluna;
        }), bifes.end());
        alfaces.erase(std::remove_if(alfaces.begin(), alfaces.end(), [linha, coluna](Alface* alface){
            return alface->getLinha()==linha && alface->getColuna()==coluna;
        }), alfaces.end());
        janelaComandos<<"A celula "<<args[1]<<" "<<args[2]<<" foi limpa"<<"\n";
    }
    else if(args[0]=="see"&&args.size()==3){
        int linha=std::stoi(args[1])-1;
        int coluna=std::stoi(args[2])-1;
        for (auto& coelho : coelhos)
            if (coelho->getLinha() == linha && coelho->getColuna()==coluna) {
                janelaComandos<<"Id: " << coelho->getId()<<"\n";
                janelaComandos<<"Sigla: " << coelho->getSigla()<<"\n";
                janelaComandos << "Saude: " << coelho->getSaude() << "\n";
                janelaComandos<<"Peso: "<< coelho->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< coelho->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: "<<coelho->getTempo_vivo()<<"\n";
            }
        for(auto& ovelha : ovelhas)
            if(ovelha->getLinha()==linha && ovelha->getColuna()==coluna){
                janelaComandos<<"Id: " << ovelha->getId()<<"\n";
                janelaComandos<<"Sigla: " << ovelha->getSigla()<<"\n";
                janelaComandos << "Saude: " << ovelha->getSaude() << "\n";
                janelaComandos<<"Peso: "<< ovelha->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< ovelha->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<ovelha->getTempo_vivo()<<"\n";
            }
        for(auto& lobo : lobos)
            if(lobo->getLinha()==linha && lobo->getColuna()==coluna){
                janelaComandos<<"Id: " << lobo->getId()<<"\n";
                janelaComandos<<"Sigla: " << lobo->getSigla()<<"\n";
                janelaComandos << "Saude: " << lobo->getSaude() << "\n";
                janelaComandos<<"Peso: "<< lobo->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< lobo->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<lobo->getTempo_vivo()<<"\n";
            }
        for(auto& canguru : cangurus)
            if(canguru->getLinha()==linha && canguru->getColuna()==coluna){
                janelaComandos<<"Id: " << canguru->getId()<<"\n";
                janelaComandos<<"Sigla: " << canguru->getSigla()<<"\n";
                janelaComandos << "Saude: " << canguru->getSaude() << "\n";
                janelaComandos<<"Peso: "<< canguru->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< canguru->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<canguru->getTempo_vivo()<<"\n";
            }
        for(auto& abelha : abelhas)
            if(abelha->getLinha()==linha && abelha->getColuna()==coluna){
                janelaComandos<<"Id: " << abelha->getId()<<"\n";
                janelaComandos<<"Sigla: " << abelha->getSigla()<<"\n";
                janelaComandos << "Saude: " << abelha->getSaude() << "\n";
                janelaComandos<<"Peso: "<< abelha->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< abelha->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<abelha->getTempo_vivo()<<"\n";
            }
        for (auto& relva : relvas)
            if (relva->getLinha() == linha && relva->getColuna()==coluna) {
                janelaComandos <<"Id: "<< relva->getId()<<"\n";
                janelaComandos <<"Sigla: "<<relva->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< relva->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< relva->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< relva->getToxicidade()<<"\n";
            }
        for(auto& cenoura : cenouras)
            if(cenoura->getLinha()==linha && cenoura->getColuna()==coluna){
                janelaComandos <<"Id: "<< cenoura->getId()<<"\n";
                janelaComandos <<"Sigla: "<<cenoura->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< cenoura->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< cenoura->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< cenoura->getToxicidade()<<"\n";
            }
        for(auto& corpo : corpos)
            if(corpo->getLinha()==linha && corpo->getColuna()==coluna){
                janelaComandos <<"Id: "<< corpo->getId()<<"\n";
                janelaComandos <<"Sigla: "<<corpo->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< corpo->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< corpo->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< corpo->getToxicidade()<<"\n";
            }
        for(auto& bife : bifes)
            if(bife->getLinha()==linha && bife->getColuna()==coluna){
                janelaComandos <<"Id: "<< bife->getId()<<"\n";
                janelaComandos <<"Sigla: "<<bife->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< bife->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< bife->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< bife->getToxicidade()<<"\n";
            }
        for(auto& alface : alfaces)
            if(alface->getLinha()==linha && alface->getColuna()==coluna){
                janelaComandos <<"Id: "<< alface->getId()<<"\n";
                janelaComandos <<"Sigla: "<<alface->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< alface->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< alface->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< alface->getToxicidade()<<"\n";
            }
    }
    else if(args[0]=="info"&&args.size()==2){
        int id = std::stoi(args[1]);
        for (auto& coelho : coelhos)
            if (coelho->getId()==id) {
                janelaComandos<<"Id: " << coelho->getId()<<"\n";
                janelaComandos<<"Sigla: " << coelho->getSigla()<<"\n";
                janelaComandos << "Saude: " << coelho->getSaude() << "\n";
                janelaComandos<<"Peso: "<< coelho->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< coelho->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<coelho->getTempo_vivo()<<"\n";
            }
        for (auto& ovelha : ovelhas)
            if (ovelha->getId()==id) {
                janelaComandos<<"Id: " << ovelha->getId()<<"\n";
                janelaComandos<<"Sigla: " << ovelha->getSigla()<<"\n";
                janelaComandos << "Saude: " << ovelha->getSaude() << "\n";
                janelaComandos<<"Peso: "<< ovelha->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< ovelha->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<ovelha->getTempo_vivo()<<"\n";
            }
        for (auto& lobo : lobos)
            if (lobo->getId()==id) {
                janelaComandos<<"Id: " << lobo->getId()<<"\n";
                janelaComandos<<"Sigla: " << lobo->getSigla()<<"\n";
                janelaComandos << "Saude: " << lobo->getSaude() << "\n";
                janelaComandos<<"Peso: "<< lobo->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< lobo->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<lobo->getTempo_vivo()<<"\n";
            }
        for (auto& canguru : cangurus)
            if (canguru->getId()==id) {
                janelaComandos<<"Id: " << canguru->getId()<<"\n";
                janelaComandos<<"Sigla: " << canguru->getSigla()<<"\n";
                janelaComandos << "Saude: " << canguru->getSaude() << "\n";
                janelaComandos<<"Peso: "<< canguru->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< canguru->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<canguru->getTempo_vivo()<<"\n";
            }
        for (auto& abelha : abelhas)
            if (abelha->getId()==id) {
                janelaComandos<<"Id: " << abelha->getId()<<"\n";
                janelaComandos<<"Sigla: " << abelha->getSigla()<<"\n";
                janelaComandos << "Saude: " << abelha->getSaude() << "\n";
                janelaComandos<<"Peso: "<< abelha->getPeso()<<"\n";
                janelaComandos<<"Fome: "<< abelha->getFome()<<"\n";
                janelaComandos <<"Tempo Vivo: " <<abelha->getTempo_vivo()<<"\n";
            }
        for (auto& cenoura : cenouras)
            if (cenoura->getId()==id) {
                janelaComandos <<"Id: "<< cenoura->getId()<<"\n";
                janelaComandos <<"Sigla: "<<cenoura->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< cenoura->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< cenoura->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< cenoura->getToxicidade()<<"\n";
            }
        for (auto& relva : relvas)
            if (relva->getId()==id) {
                janelaComandos <<"Id: "<< relva->getId()<<"\n";
                janelaComandos <<"Sigla: "<<relva->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< relva->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< relva->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< relva->getToxicidade()<<"\n";
            }
        for (auto& corpo : corpos)
            if (corpo->getId()==id) {
                janelaComandos <<"Id: "<< corpo->getId()<<"\n";
                janelaComandos <<"Sigla: "<<corpo->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< corpo->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< corpo->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< corpo->getToxicidade()<<"\n";
            }
        for (auto& bife : bifes)
            if (bife->getId()==id) {
                janelaComandos <<"Id: "<< bife->getId()<<"\n";
                janelaComandos <<"Sigla: "<<bife->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< bife->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< bife->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< bife->getToxicidade()<<"\n";
            }
        for (auto& alface : alfaces)
            if (alface->getId()==id) {
                janelaComandos <<"Id: "<< alface->getId()<<"\n";
                janelaComandos <<"Sigla: "<<alface->getSigla()<<"\n";
                janelaComandos <<"Instantes: "<< alface->getDuracao()<<"\n";
                janelaComandos <<"Valor Nutritivo: "<< alface->getValor_Nutritivo()<<"\n";
                janelaComandos <<"Toxicidade: "<< alface->getToxicidade()<<"\n";
            }
    }
    else if(args[0]=="n"&&args.size()==1){
        for(auto& coelho: coelhos)
            coelho->mexe();
        for(auto& ovelha: ovelhas)
            ovelha->mexe();
        for(auto& lobo: lobos)
            lobo->mexe();
        for(auto& canguru: cangurus)
            canguru->mexe();
        for(auto& abelha: abelhas)
            abelha->mexe();
        this->mostraReserva();
        janelaComandos<<"Avancou 1 instante"<<"\n";
    }
    else if(args[0]=="n"&&args.size()==2){
        int nInstantes = std::stoi(args[1]);
        for (int i = 0; i < nInstantes; i++)
        {
            for(auto& coelho: coelhos)
                coelho->mexe();
            for(auto& ovelha: ovelhas)
                ovelha->mexe();
            for(auto& lobo: lobos)
                lobo->mexe();
            for(auto& canguru: cangurus)
                canguru->mexe();
            for(auto& abelha: abelhas)
                abelha->mexe();
            this->mostraReserva();
        }
        janelaComandos<<"Avancou "<<args[1]<<"instantes"<<"\n";
    }
    else if(args[0]=="n"&&args.size()==3){
        int nInstantes = std::stoi(args[1]);
        int atraso = std::stoi(args[2]);
        for (int i = 0; i < nInstantes; i++)
        {
            for(auto& coelho: coelhos)
                coelho->mexe();
            for(auto& ovelha: ovelhas)
                ovelha->mexe();
            for(auto& lobo: lobos)
                lobo->mexe();
            for(auto& canguru: cangurus)
                canguru->mexe();
            for(auto& abelha: abelhas)
                abelha->mexe();



            this->mostraReserva();
            sleep(atraso);
        }
        janelaComandos<<"Avancou "<<args[1]<<"instantes e requereu "<<args[2]<<"segundos para recolher informacoes"<<"\n";
    }
    else if(args[0]=="anim"&&args.size()==1){
        janelaComandos<<"Lista de animais da reserva: "<<"\n";

        for(auto& coelho: coelhos) {
            janelaComandos << coelho->getId()<<" Coelho "<<coelho->getSaude()<<"\n";
        }
        for(auto& ovelha: ovelhas) {
            janelaComandos << ovelha->getId()<<" ovelha "<<ovelha->getSaude()<<"\n";
        }
        for(auto& lobo: lobos) {
            janelaComandos << lobo->getId()<<" Lobo "<<lobo->getSaude()<<"\n";
        }
        for(auto& canguru: cangurus) {
            janelaComandos << canguru->getId()<<" canguru "<<canguru->getSaude()<<"\n";
        }
        for(auto& abelha: abelhas) {
            janelaComandos << abelha->getId()<<" canguru "<<abelha->getSaude()<<"\n";
        }
    }
    else if (args[0]=="visanim"&&args.size()==1){
        janelaComandos<<"Lista de animais visiveis: "<<"\n";

        // deixar as frases mais informativas e fazer para os outros animais
        for(auto& coelho: coelhos) {
            if ( curlinhas <= coelho->getLinha() && curlinhas+10 >= coelho->getLinha() &&
                    curcolunas <= coelho->getColuna() && curcolunas+14 >= coelho->getColuna()) {
                janelaComandos << "Animal " << coelho->getSigla() << "\n";
            }
        }
        for(auto& ovelha: ovelhas) {
            if ( curlinhas <= ovelha->getLinha() && curlinhas+10 >= ovelha->getLinha() &&
                 curcolunas <= ovelha->getColuna() && curcolunas+14 >= ovelha->getColuna()) {
                janelaComandos << ovelha->getId() << " ovelha " << ovelha->getSaude() << "\n";
            }
        }
        for(auto& lobo: lobos) {
            if ( curlinhas <= lobo->getLinha() && curlinhas+10 >= lobo->getLinha() &&
                 curcolunas <= lobo->getColuna() && curcolunas+14 >= lobo->getColuna()) {
                janelaComandos << lobo->getId() << " Lobo " << lobo->getSaude() << "\n";
            }
        }
        for(auto& canguru: cangurus) {
            if ( curlinhas <= canguru->getLinha() && curlinhas+10 >= canguru->getLinha() &&
                 curcolunas <= canguru->getColuna() && curcolunas+14 >= canguru->getColuna()) {
                janelaComandos << canguru->getId() << " canguru " << canguru->getSaude() << "\n";
            }
        }
        for(auto& abelha: abelhas) {
            if ( curlinhas <= abelha->getLinha() && curlinhas+10 >= abelha->getLinha() &&
                 curcolunas <= abelha->getColuna() && curcolunas+14 >= abelha->getColuna()) {
                janelaComandos << abelha->getId() << " canguru " << abelha->getSaude() << "\n";
            }
        }
    }
    else if(args[0]=="store"&&args.size()==2){
        guardaNome=args[1];
        for(unsigned int i = 0; i < reservas.size(); i++){
            if(reservas[i]->getGuardaNome() == guardaNome){
                janelaComandos << "Já existe um store com o nome " << guardaNome << "\n";
                return false;
            }
        }
        Reserva *tmp = new Reserva(this);
        reservas.push_back(tmp);
        janelaComandos << "Store com o nome " << args[1] << " guardado com sucesso!" << "\n" << "\n" << "Stores existentes: " << "\n";
        for(unsigned int i = 0; i < reservas.size(); i++){
            janelaComandos << reservas[i]->getGuardaNome() << "\n";
        }
        return true;
    }else if(args[0]=="restore"&&args.size()==2){
        for(unsigned int i = 0; i < reservas.size(); i++){
            if(reservas[i]->getGuardaNome() == args[1]){
                reservas.erase(reservas.begin() + i);
                janelaComandos << "Store " << args[1] << " apagado com sucesso!" << "\n";
                return true;
            }
        }
        janelaComandos << "Não existe nenhum save com o nome " << args[1] << "\n";
        return false;
        janelaComandos<<"Reativar estado de uma reserva"<<"\n";
    }else if(args[0]=="load"&&args.size()==2){
        for(unsigned int i = 0; i < reservas.size(); i++){
            if(reservas[i]->getGuardaNome() == args[1]){
                *this = Reserva(reservas[i]);
                janelaComandos << "Save " << args[1] << " carregado com sucesso!" << "\n";
                return true;
            }
        }
        janelaComandos << "Não existe nenhum Store com o nome: " << args[1] << "\n";
        return false;
    }


    //else if(args[0])


    if(args[0]=="exit"&&args.size()==1){
        janelaComandos<<"A sair do jogo"<<"\n";
        exit(0);
    }
    return true;
}