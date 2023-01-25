#include "paquete.h"

Paquete::Paquete(int id, string origen, string destino, float peso){
    this->id=id;
    this->origen=origen;
    this->destino=destino;
    this->peso=peso;
    next=NULL;
}
