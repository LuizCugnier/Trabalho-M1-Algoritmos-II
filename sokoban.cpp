#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include "config.h"


using namespace std;

int main(){
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    //Para utilizar portugues 
    //setlocale(LC_ALL, "Portuguese");

    //Variavel do mapa
    int mj[13][13] = {   1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,1,1,1,1,1,1,1,1,1,1,1,1 };

    //Escolha do mapa
    int eMapa = 0;

    //Variavel mapa aleatorio
    //int eMapa_random = 0;

    //Posi��o inicial do personagem no console
    int x = 5, y = 5;

    //Vari�vel para tecla precionada
    char tecla = 0;

    //Variavel do mapa para finalizar um mapa
    bool jogo = false;

    //Variavel para verificar se existe um jogo em andamento
    bool verifica_jogo = false;

    //Variavel do menu para finalizar o jogo
    bool menu = false;

    //Variavel opcao do jogador
    char opcao = 0;

    //Imprime as boas vindas e opções do menu 
    imprime_menu();

    //Loop do menu
    while (!menu) {
        //Posiciona a escrita no início do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        
        //Recebe a opção escolhida
        if (_kbhit()) {
            opcao = _getch();

            switch (opcao)
            {
                case '0': //Opção que volta para o menu
                    imprime_menu();
                    break;
                case '1'://Opção cria novo jogo
                    novo_jogo(tecla, x, y, jogo, mj, eMapa, coord, verifica_jogo);
                    break;
                case '2'://Opção para continuar um jogo ja existente
                    if (verifica_jogo) {
                        continua_jogo(tecla, x, y, jogo, mj, eMapa, coord, verifica_jogo);
                    }
                    break;
                case '3'://Opção para mais informções do jogo
                    sobre();
                    break;
                case '4'://Opção para terminar o jogo
                    fim_jogo(menu);
                default:
                    /*system("cls");
                    cout << "Opcao invalida tente outra." << endl;
                    system("cls");
                    imprime_menu();
                    */
                    break;
            }
        }
        
        
    }//fim do laço do jogo 
    

    return 0;
} //fim main
    