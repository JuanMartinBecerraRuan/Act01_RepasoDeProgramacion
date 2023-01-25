#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include <paquete.h>
#include <fstream>

class Paqueteria{
    private:
        Paquete *head;
        Paquete *aux;
    public:
        Paqueteria();
        void agregarAlInicio(Paquete *);
        void eliminarAlInicio();
        void mostrar();
        void guardar();
        void recuperar();
        void invertirLista(Paquete** head);
};

#endif // PAQUETERIA_H
