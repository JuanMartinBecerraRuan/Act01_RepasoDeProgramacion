#ifndef PAQUETE_H
#define PAQUETE_H
#include <iostream>

using namespace std;

class Paquete{
    public:
        int id;
        string origen;
        string destino;
        float peso;
        Paquete *next;
        Paquete(int, string, string, float);
};

#endif // PAQUETE_H
