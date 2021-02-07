#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string>
#include "myfile.h"

using namespace std;

int VerNum (string str){ //recebe e guarda retorno com jogador

    int n;

    cout << str;
    cin >> n;

    return n;
}

int NumAlea(int menor, int maior) { //gera numero aleatorio
    return rand()%(maior-menor+1) + menor;
}

void GeraMapa(){
    int i,j,matriz[10][10];

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(matriz[i][j]==0){
                cout<<"-"<<" ";
            }
            if(matriz[i][j]==1){
                cout<<"R"<<" ";
            }
            if(matriz[i][j]==2){
                cout<<"T"<<" ";
            }
            if(matriz[i][j]==3){
                cout<<"*"<<" ";
            }
            if(matriz[i][j]==4){
                cout<<"O"<<" ";
            }
            if(matriz[i][j]==5){
                cout<<"H"<<" ";
            }
        }
        cout<<"\n";
    }
}


int main (){

    int numra,numti,grasses,pits,pot,human=1,HP=5; //gera variavel para numero de coelhos, tigres, mato, poços, poções, 1 humano e 5 pontos de vida
    int matriz[10][10]; //gera matriz de 10x10 -> mapa
    int alea1,alea2; //guarda posicao do humano gerada aleatoriamente
    int xMatriz,yMatriz; //guarda posicao do humano
    int AddxMatriz,AddyMatriz; //muda a posicao do humano
    int i,j,v,h,t,localx,localy,r;
    int posrax[10]={10,10,10,10,10,10,10,10,10,10}; //guarda posicao dos coelhos
    int posray[10]={10,10,10,10,10,10,10,10,10,10}; //guarda posicao dos coelhos
    int rodra[10]={1,1,1,1,1,1,1,1,1,1}; //guarda posicao dos coelhos
    int postix[10]={10,10,10,10,10,10,10,10,10,10}; //guarda posicao dos tigres
    int postiy[10]={10,10,10,10,10,10,10,10,10,10}; //guarda posicao dos tigres
    int rodti[10]={1,1,1,1,1,1,1,1,1,1}; //guarda posicao dos tigres
    int f=0; //Steps
    int comeu=0; //variavel para saber se tigre comeu humano
    int score=0, capra=0, capti=0; //Score - coelho capiturado - tigre capiturado
    char a, dif; //variavel para saber se usa poção ou não
    string b; //variavel para receber para onde o humano caminhará

    Hunter Hu;

    // Entrada de dados
    numra = VerNum("Enter initial number of rabbits - max(10) : ");
    if (numra>10){
        numra=10;
    }

    numti = VerNum("Enter initial number of tigers - max(10) : ");
    if (numti>10){
        numti=10;
    }

    /*
    grasses = VerNum("Enter initial number of grasses - max(10) : ");
    if (grasses>10){
        grasses=10;
    }

    pits = VerNum("Enter initial number of pits - max(10) : ");
    if (pits>10){
        pits=10;
    }
    */

    pot = VerNum("Enter initial number of potions - max(3) : ");
    if (pot>3){
        pot=3;
    }

    cout << "Nivel de dificuldade (Noob: 'n' ou Deus: 'd'): ";
    cin >> dif;

    if(dif=='n' || dif=='d'){

    } else {
        while(dif!='n' || dif!='d'){
            cout << "Nivel de dificuldade (Noob: 'n' ou Deus: 'd'): ";
            cin >> dif;

            if(dif=='n' || dif=='d'){
                break;
            }

        }
    }

    system("cls"); //Limpa a tela da entrada de dados

    int tempo = clock(); //começa a contar o tempo
    while(clock() - tempo < 1000){ //espera de 1 segundo necessária para trocar valor de r

    }

    if(dif=='d'){
        cout << "MODO DEUS... RUN !!!";
        int tempo = clock(); //começa a contar o tempo
        while(clock() - tempo < 2500){ //espera de 2.5 segundo necessária para trocar valor de r

        }
    }

    system("cls"); //Limpa a tela da entrada de dados

    //Formacao do mapa alocando criaturas aleatoriamente
    //atribui valor 0 para todo o mapa
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matriz[i][j]=0;
        }
    }

    //modifica o valor do mapa
    for(v=0;v<numra;v++){
        i=0;
        do{
            srand(time(NULL));
            alea1 = NumAlea(0, 9);
            alea2 = NumAlea(0, 9);

            if(matriz[alea1][alea2]==0){
                matriz[alea1][alea2] = 1;
                posrax[v]=alea1;
                posray[v]=alea2;
                break;
            }
        } while (i<100);
    }
    for(v=0;v<numti;v++){
        i=0;
        do{
            srand(time(NULL));
            alea1 = NumAlea(0, 9);
            alea2 = NumAlea(0, 9);

            if(matriz[alea1][alea2]==0){
                matriz[alea1][alea2] = 2;
                postix[v]=alea1;
                postiy[v]=alea2;
                break;
            }
        } while (i<100);
    }

    /*
    for(v=0;v<grasses;v++){
        i=0;
        do{
            srand(time(NULL));
            alea1 = NumAlea(0, 9);
            alea2 = NumAlea(0, 9);

            if(matriz[alea1][alea2]==0){
                matriz[alea1][alea2] = 3;
                break;
            }
        } while (i<100);
    }
    for(v=0;v<pits;v++){
        i=0;
        do{
            srand(time(NULL));
            alea1 = NumAlea(0, 9);
            alea2 = NumAlea(0, 9);

            if(matriz[alea1][alea2]==0){
                matriz[alea1][alea2] = 4;
                break;
            }
        } while (i<100);
    }
    */

    for(v=0;v<human;v++){
        i=0;
        do{
            srand(time(NULL));
            alea1 = NumAlea(0, 9);
            alea2 = NumAlea(0, 9);

            if(matriz[alea1][alea2]==0){
                xMatriz = alea1;
                yMatriz = alea2;
                matriz[xMatriz][yMatriz] = 5;
                break;
            }
        } while (i<100);
    }

    cout << "Time step: 0" << endl;
    cout << "<Score: " << score << ", HP: " << HP << ", Potions:" << pot << ">\n" << endl;

    //Faz o mapa
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(matriz[i][j]==0){
                cout<<"-"<<" ";
            }
            if(matriz[i][j]==1){
                cout<<"R"<<" ";
            }
            if(matriz[i][j]==2){
                cout<<"T"<<" ";
            }
            if(matriz[i][j]==3){
                cout<<"*"<<" ";
            }
            if(matriz[i][j]==4){
                cout<<"O"<<" ";
            }
            if(matriz[i][j]==5){
                cout<<"H"<<" ";
            }
        }
        cout<<"\n";
    }

    //expoe dados na tela
    cout << "\n";
    cout << "number of rabbits: " << numra << "       <captured:" << capra << ">" << endl;
    cout << "number of tigers:  " << numti << "       <captured:" << capti << ">" << endl;
    //cout << "number of grasses: " << grasses << endl;
    //cout << "number of pits: " << pits << endl;
    cout << "\n";
    cout << "Input the moving direction (Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
    cin >> b;

    if(b=="w" || b=="d" || b=="s" || b=="a"){

    } else {
        do{
            cout << "Input the moving direction (Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
            cin >> b;

            if(b=="w" || b=="d" || b=="s" || b=="a"){
                break;
            }

        }while(i<100);
    }

    cout << "Are you going to use potion (Yes: 'y', No: 'n'): ";
    cin >> a;

    if(a=='y' || a=='n'){

    } else {
        do{
            cout << "Are you going to use potion (Yes: 'y', No: 'n'): ";
            cin >> a;

            if(a=='y' || a=='n'){
                break;
            }

        }while(i<100);
    }

    Hu.insere(b); //Envia comando de andar
    HP--;


    while(HP>=0){

        if(numra!=0 || numti!=0){
            f++;

            system("cls"); //Limpa a tela da entrada de dados

            AddxMatriz = Hu.AndaX();
            AddyMatriz = Hu.AndaY();

            if((xMatriz==0 && AddxMatriz==-1) || (xMatriz==9 && AddxMatriz==1)){
                AddxMatriz=0;
            }

            if((yMatriz==0 && AddyMatriz==-1) || (yMatriz==9 && AddyMatriz==1)){
                AddyMatriz=0;
            }

            matriz[xMatriz][yMatriz] = 0; //zera local do humano

            xMatriz = xMatriz + AddxMatriz;
            yMatriz = yMatriz + AddyMatriz;


            if(matriz[xMatriz][yMatriz]==1){
                for(v=0;v<10;v++){
                    if(posrax[v]==xMatriz && posray[v]==yMatriz){

                        //tira coelho do mapa
                        posrax[v]=10;
                        posray[v]=10;
                        rodra[v]=0; //zera turno do coelho
                        numra--; //diminui coelho
                        capra++; //aumenta os capiturados
                        score++; //aumenta ponto
                        HP = HP + 2; //aument HP em 2 pra proxima rodada
                        break;
                    }
                }
            }

            if(matriz[xMatriz][yMatriz]==2){
                for(v=0;v<10;v++){
                    if(postix[v]==xMatriz && postiy[v]==yMatriz){

                        //tira tigre do mapa
                        postix[v]=10;
                        postiy[v]=10;
                        rodti[v]=0; //zera turno do tigre
                        numti--; //diminui tigre
                        capti++; //aumenta os capiturados
                        score=score+3; //aumenta ponto
                        HP=HP-2; //sofre 2 de dano por lutar com tigre
                        break;
                    }
                }
            }

            matriz[xMatriz][yMatriz] = 5; //add humano no lugar

            //Muda coelhos e tigres de posição
            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    if(matriz[i][j]==1){
                        for(v=0;v<10;v++){
                            if(posrax[v]==i && posray[v]==j && rodra[v]==f){

                                int tempo = clock(); //começa a contar o tempo

                                srand(time(NULL));

                                //movimenta somente em x ou em y com a restrição do mapa
                                r = NumAlea(0, 1);

                                if(r==0){
                                    if(i==0){
                                        alea1 = NumAlea(0, 1);
                                    }
                                    else if(i==9){
                                        alea1 = NumAlea(-1, 0);
                                    }
                                    else{
                                        alea1 = NumAlea(-1, 1);
                                    }
                                    alea2 = 0;
                                }
                                else{
                                    if(j==0){
                                        alea2 = NumAlea(0, 1);
                                    }
                                    else if(j==9){
                                        alea2 = NumAlea(-1, 0);
                                    }
                                    else{
                                        alea2 = NumAlea(-1, 1);
                                    }
                                    alea1 = 0;
                                }

                                localx = i + alea1;
                                localy = j + alea2;

                                h = matriz[localx][localy];

                                if(h==0){ //mudou de lugar
                                    matriz[localx][localy]=1;
                                    matriz[i][j]=0;

                                    //atualiza posicao do coelho atual
                                    posrax[v]=localx;
                                    posray[v]=localy;
                                }
                                else{ //permace no lugar
                                    matriz[i][j]=1;

                                    posrax[v]=i;
                                    posray[v]=j;
                                }

                                rodra[v]=f+1; //add turno do coelho
                                r = 3;
                                alea1 = 3;
                                alea2 = 3;

                                while(clock() - tempo < 700){ //espera de 0.7 segundo necessária para trocar valor de r
                                }
                                break;
                            }
                        }
                    }

                    if(matriz[i][j]==2){
                        for(v=0;v<10;v++){
                            if(postix[v]==i && postiy[v]==j && rodti[v]==f){
                                if(dif=='n'){

                                    int tempo = clock(); //começa a contar o tempo

                                    srand(time(NULL));

                                    //movimenta somente em x ou em y com a restrição do mapa
                                    r = NumAlea(0, 1);

                                    if(r==0){
                                        if(i==0){
                                            alea1 = NumAlea(0, 1);
                                        }
                                        else if(i==9){
                                            alea1 = NumAlea(-1, 0);
                                        }
                                        else{
                                            alea1 = NumAlea(-1, 1);
                                        }
                                        alea2 = 0;
                                    }
                                    else{
                                        if(j==0){
                                            alea2 = NumAlea(0, 1);
                                        }
                                        else if(j==9){
                                            alea2 = NumAlea(-1, 0);
                                        }
                                        else{
                                            alea2 = NumAlea(-1, 1);
                                        }
                                        alea1 = 0;
                                    }

                                    localx = i + alea1;
                                    localy = j + alea2;

                                    h = matriz[localx][localy];

                                    if(h==0){ //mudou de lugar
                                        matriz[localx][localy]=2;
                                        matriz[i][j]=0;

                                        //atualiza posicao do tigre atual
                                        postix[v]=localx;
                                        postiy[v]=localy;
                                    }
                                    else if(h==5){ //mata humano
                                        matriz[localx][localy]=2;
                                        matriz[i][j]=0;

                                        //atualiza posicao do tigre atual
                                        postix[v]=localx;
                                        postiy[v]=localy;

                                        //mata humano
                                        comeu++;
                                    }
                                    else{ //permace no lugar
                                        matriz[i][j]=2;

                                        postix[v]=i;
                                        postiy[v]=j;
                                    }

                                    rodti[v]=f+1; //add turno do tigre
                                    r = 3;
                                    alea1 = 3;
                                    alea2 = 3;

                                    // cout << "postix[v]: " << postix[v] << endl;
                                    // cout << "postiy[v]: " << postiy[v] << endl;
                                    // cout << "rodti[v]: " << rodti[v] << "\n\n";

                                    while(clock() - tempo < 700){ //espera de 0.7 segundo necessária para trocar valor de r
                                    }
                                }
                                else{

                                    if(i!=xMatriz){
                                        if(i<xMatriz){
                                            alea1 = 1;
                                        }
                                        else{
                                            alea1 = -1;
                                        }
                                        alea2 = 0;
                                    }
                                    else{
                                        if(j<yMatriz){
                                            alea2 = 1;
                                        }
                                        else{
                                            alea2 = -1;
                                        }
                                        alea1 = 0;
                                    }

                                    localx = i + alea1;
                                    localy = j + alea2;

                                    h = matriz[localx][localy];

                                    if(h==0){ //mudou de lugar
                                        matriz[localx][localy]=2;
                                        matriz[i][j]=0;

                                        //atualiza posicao do tigre atual
                                        postix[v]=localx;
                                        postiy[v]=localy;
                                    }
                                    else if(h==5){ //mata humano
                                        matriz[localx][localy]=2;
                                        matriz[i][j]=0;

                                        //atualiza posicao do tigre atual
                                        postix[v]=localx;
                                        postiy[v]=localy;

                                        //mata humano
                                        comeu++;
                                    }
                                    else{ //permace no lugar
                                        matriz[i][j]=2;

                                        postix[v]=i;
                                        postiy[v]=j;
                                    }

                                    rodti[v]=f+1; //add turno do tigre
                                    r = 3;
                                    alea1 = 3;
                                    alea2 = 3;

                                }
                                break;
                            }
                        }
                    }

                }
            }

            if(comeu==0){

                cout << "Time step: " << f << endl;
                cout << "<Score: " << score << ", HP: " << HP << ", Potions:" << pot << ">\n" << endl;

                //Faz o mapa
                for(i=0;i<10;i++){
                    for(j=0;j<10;j++){
                        if(matriz[i][j]==0){
                            cout<<"-"<<" ";
                        }
                        if(matriz[i][j]==1){
                            cout<<"R"<<" ";
                        }
                        if(matriz[i][j]==2){
                            cout<<"T"<<" ";
                        }
                        if(matriz[i][j]==3){
                            cout<<"*"<<" ";
                        }
                        if(matriz[i][j]==4){
                            cout<<"O"<<" ";
                        }
                        if(matriz[i][j]==5){
                            cout<<"H"<<" ";
                        }
                    }
                    cout<<"\n";
                }

                cout << "\n";
                cout << "number of rabbits: " << numra << "       <captured:" << capra << ">" << endl;
                cout << "number of tigers:  " << numti << "       <captured:" << capti << ">" << endl;
                //cout << "number of grasses: " << grasses << endl;
                //cout << "number of pits: " << pits << endl;
                cout << "\n";
                cout << "Input the moving direction (Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
                cin >> b;

                if(b=="w" || b=="d" || b=="s" || b=="a"){

                } else {
                    do{
                        cout << "Input the moving direction (Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
                        cin >> b;

                        if(b=="w" || b=="d" || b=="s" || b=="a"){
                            break;
                        }

                    }while(i<100);
                }

                cout << "Are you going to use potion (Yes: 'y', No: 'n'): ";
                cin >> a;

                if(a=='y' || a=='n'){

                } else {
                    do{
                        cout << "Are you going to use potion (Yes: 'y', No: 'n'): ";
                        cin >> a;

                        if(a=='y' || a=='n'){
                            break;
                        }

                    }while(i<100);
                }

                if(a=='y'){
                    HP=6;
                    pot--;
                }

                Hu.insere(b); //Envia comando de andar (string)

            } else {
                cout << "UM TIGRE COMEU VOCE!!!" << "\n";
                cout << "PONTUACAO: " << score << "\n\n";
                cout << "GAME OVER" << "\n";
                break;
            }
        } else {
            cout << "NAO EXISTEM MAIS COELHOS E TIGRES NO MAPA" << "\n";
            cout << "PONTUACAO: " << score << "\n\n";
            break;
        }

        HP--;

    }

    if(HP<0){
        system("cls"); //Limpa a tela da entrada de dados
        cout << "HP < 0" << "\n";
        cout << "PONTUACAO: " << score << "\n\n";
        cout << "GAME OVER" << "\n";
    }

    system("pause");
    return 0;

}
