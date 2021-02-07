#include <iostream>
#include "myfile.h"

using namespace std;

void Hunter::insere(string wa){
    walk = wa;
}
/*
void Hunter::LocalAtual(int m,int n){
    i = m;
    j = n;
}
*/

int Hunter::AndaX(){
    int i2;

    if(walk=="w"){i2 = -1;}
    if(walk=="s"){i2 = 1;}
    if(walk=="d" || walk=="a"){i2 = 0;}

    return i2;
}

int Hunter::AndaY(){
    int j2;

    if(walk=="a"){j2 = -1;}
    if(walk=="d"){j2 = 1;}
    if(walk=="w" || walk=="s"){j2 = 0;}

    return j2;
}