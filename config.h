using namespace std;

//Função para imprimir o menu principal
void imprime_menu() {
    system("cls");
    cout << "=======================\n";
    cout << "Bem Vindo ao Sokoban\n";
    cout << "=======================\n";
    cout << "[1] Novo Jogo\n";
    cout << "[2] Continuar\n";
    cout << "[3] Sobre\n";
    cout << "[4] Fim\n";
}

//Função para o menu de escolha dos mapas
void escolhe_mapa(int& eMapa, bool& jogo) {
    jogo = false;
    system("cls");
    cout << "=======================\n";
    cout << "  Escolha um nivel\n";
    cout << "=======================\n";
    cout << "[1] 1 - Primeiro mapa\n";
    cout << "[2] 2 - Segundo mapa\n";
    cout << "[3] 3 - Terceiro mapa\n";
    //cout << "[4] 4 - Mapa aleatorio\n";
    cout << "Aperte ENTER para confirmar: ";

    cin >> eMapa;
    system("cls");

}

//Função que carrega o mapa escolhido na matriz principal do jogo
void carrega_mapa(int mj[13][13], int eMapa) {

    int m1[13][13] = {   2,1,1,1,1,1,1,1,2,2,2,2,2,
                         2,1,0,0,0,0,0,1,1,1,1,2,2,
                         2,1,0,1,1,1,3,0,0,0,1,2,2,
                         1,1,0,0,0,0,1,0,1,0,1,2,2,
                         1,0,3,1,4,0,4,0,1,0,1,2,2,
                         1,0,1,0,0,4,0,0,1,0,1,2,2,
                         1,0,1,0,4,0,4,1,3,0,1,2,2,
                         1,0,1,0,1,0,0,0,0,1,1,2,2,
                         1,0,0,0,3,1,1,1,0,1,1,2,2,
                         1,1,1,1,0,0,0,0,0,0,1,2,2,
                         2,2,2,1,1,1,1,1,0,0,1,2,2,
                         2,2,2,2,2,2,2,1,0,0,1,2,2,
                         2,2,2,2,2,2,2,1,1,1,1,2,2 };

    int m2[13][13] = {   1,1,1,1,1,1,1,1,1,2,2,2,2,
                         1,3,3,3,3,3,0,0,1,2,2,2,2,
                         1,1,1,0,4,0,1,0,1,1,2,2,2,
                         2,2,1,0,4,1,1,0,0,1,2,2,2,
                         2,2,1,4,0,4,0,4,0,1,2,2,2,
                         2,2,1,0,0,0,1,0,0,1,2,2,2,
                         2,2,1,1,0,0,1,0,0,1,2,2,2,
                         2,2,2,1,1,1,1,1,1,1,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2 };

    int m3[13][13] = {   2,2,2,2,1,1,1,1,1,2,2,2,2,
                         1,1,1,1,1,0,0,0,1,2,2,2,2,
                         1,3,3,0,4,0,4,0,1,1,2,2,2,
                         1,3,3,4,0,4,0,0,0,1,2,2,2,
                         1,1,3,0,4,1,1,0,1,1,2,2,2,
                         2,1,1,1,0,0,0,0,1,2,2,2,2,
                         2,2,2,1,1,1,1,1,1,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2,
                         2,2,2,2,2,2,2,2,2,2,2,2,2 };

    /*if (eMapa == 4) {
        srand(time(nullptr));

        int random = rand();

        eMapa = (random % 3) + 1;
    }*/
   
    switch (eMapa)
    {
    case 1:
    
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                mj[i][j] = m1[i][j];
            }
        }
        break;
    case 2:
        
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                mj[i][j] = m2[i][j];
            }
        }
        break;
    case 3:

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                mj[i][j] = m3[i][j];
            }
        }
        break;

    }
}

//
void imprime_mapa(int x, int y,int mj[13][13], int eMapa) {

    carrega_mapa(mj, eMapa);

    //Imprime o jogo: mapa e personagem.
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i == x && j == y) {
                cout << char(2); //personagem
            }
            
            else {
                switch (mj[i][j]) {
                case 0: cout << " "; break; //caminho
                case 1: cout << char(219); break; //parede
                case 2: cout << " "; break; //espa�o vazio de fora
                case 3: cout << "."; break; //ponto final
                case 4: cout << "#"; break; //caixa
                    //default: cout<<"-"; //erro
                } //fim switch

            }
            
        }
        cout << "\n";
    } //fim for mapa[

    cout << "\nAperte '0' para voltar";
}

//Função para as ações dentro do jogo
void movimento(char tecla, int& x, int& y, bool& jogo, int mj[13][13]) {
    if (_kbhit()) {
        tecla = _getch();
        switch (tecla)  
        {
        case 72: case 'w': ///cima
            if (x > 0 && mj[x - 1][y] != 1) {
                if (mj[x - 1][y] == 4 && x > 1 && mj[x - 2][y] != 1 && mj[x - 2][y] != 4) { // caixa acima
                    mj[x - 2][y] = 4;
                }
                x--;
            }
            break;
        case 80: case 's': ///baixo
            if (x < 13-1 && mj[x+1][y] != 1) {
                if (mj[x + 1][y] == 4 && x < 13 - 2 && mj[x + 2][y] != 1 && mj[x + 2][y] != 4) { // caixa abaixo
                    mj[x + 2][y] = 4;
                }
                x++;
            }
            break;
        case 75:case 'a': ///esquerda
            if (y > 0 && mj[x][y-1] != 1) {
                if (mj[x][y - 1] == 4 && y > 1 && mj[x][y - 2] != 1 && mj[x][y - 2] != 4) { // caixa à esquerda
                    mj[x][y - 2] = 4;
                }
                y--;
            }
            break;
        case 77: case 'd': ///direita
            if (y < 13 - 1 && mj[x][y + 1] != 1) {
                if (mj[x][y + 1] == 4 && y < 13 - 2 && mj[x][y + 2] != 1 && mj[x][y + 2] != 4) { // caixa à direita
                    mj[x][y + 2] = 4;
                }
                y++;
            }
            break;
        case '0':
            jogo = true;
            system("cls");
            imprime_menu(); 
        }
    }
  
}

//iniciar um novo jogo
void novo_jogo(char tecla, int& x, int& y, bool& jogo, int mj[13][13], int eMapa, COORD coord, bool& verifica_jogo) {
    escolhe_mapa(eMapa, jogo);

    while (!jogo) {
        //Posiciona a escrita no in�cio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        //imprime o mapa
        imprime_mapa(x, y, mj, eMapa);
        //movimentos do jogador
        movimento(tecla, x, y, jogo, mj);
        
    }
    verifica_jogo = true;   
}

//continua um jogo existente
void continua_jogo(char tecla, int& x, int& y, bool& jogo, int mj[13][13], int eMapa, COORD coord, bool& verifica_jogo) {
    jogo = false;

    system("cls");

    while (!jogo) {
        //Posiciona a escrita no in�cio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        //imprime o mapa
        imprime_mapa(x, y, mj, eMapa);
        //movimentos do jogador
        movimento(tecla, x, y, jogo, mj);
        
    }
    verifica_jogo = true;
}

//Mostra as informções do jogo e regras.
void sobre() {
    system("cls");
    cout << "Desenvolvedor: Luiz Augusto Cugnier Neto\n";
    cout << "Data: Março/2023\n";
    cout << "Professor: Thiago Felski Pereira\n";
    cout << "Disciplina: Algoritmos e Programação II\n";
    cout << "\nINSTRUÇÕES PARA O JOGO\n";
    cout << "O Objetivo do jogo é levar as caixas para o ponto final indicado.\nO jogo termina quando todas as caixas estiverem nos devidos lugares";
    cout << "\nAperte '0' para voltar";

}

//Termina o jogo
void fim_jogo(bool& menu) {
    system("cls");
    cout << "FIM DE JOGO!!!\n";
    menu = true;
}