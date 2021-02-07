#ifndef MYFILE
#define MYFILE
#include <iostream>
using namespace std;

class Rabbit{
    public:
        void executa();
};

class Tiger{
    public:
        void executa();
};

class Hunter{
    int i,j;
    string walk;

    public:
        void LocalAtual(int m,int n); //registra int i e int j
        void insere(string wa);       //registra string walk
        int AndaX();
        int AndaY();
};

#endif // MYFILE
