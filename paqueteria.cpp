#include "paqueteria.h"

Paqueteria::Paqueteria(){
    this->head=NULL;
}

void Paqueteria::agregarAlInicio(Paquete *nuevo){
    if (this->head == NULL){
        head = nuevo;
        return;
    }
    nuevo->next = head;
    head = nuevo;
}

void Paqueteria::eliminarAlInicio(){
    if(head != NULL){
        head = head->next;
        cout<<"\n\tEliminado correctamente..."<<endl<<endl;
    }else{
        cout<<"\n\tLa lista esta vacia..."<<endl<<endl;
    }
}

void Paqueteria::mostrar(){
    if(head != NULL){
        cout<<"\tPAQUETES"<<endl<<endl;
        Paquete *aux = head;
        while(aux != NULL){
            cout<<"ID: "<<aux->id<<endl;
            cout<<"ORIGEN: "<<aux->origen<<endl;
            cout<<"DESTINO: "<<aux->destino<<endl;
            cout<<"PESO: "<<aux->peso<<endl<<endl;
            aux = aux->next;
        }
    }else{
        cout<<"\n\tLa lista esta vacia..."<<endl<<endl;
    }
}

void Paqueteria::guardar(){
    if(head != NULL){
        ofstream archivo("respaldo.txt",ios::out);
        string delimitador="|";
        Paquete *aux = head;
        while(aux != NULL){
            archivo<<aux->id<<delimitador;
            archivo<<aux->origen<<delimitador;
            archivo<<aux->destino<<delimitador;
            archivo<<aux->peso<<delimitador;
            aux = aux->next;
        }
        cout<<"\n\tGuardado correctamente..."<<endl<<endl;
        archivo.close();
    }else{
        cout<<"\n\tLa lista esta vacia..."<<endl<<endl;
    }
}

void Paqueteria::recuperar(){
    int id;
    float peso;
    string registro,origen,destino;
    ifstream archivo("respaldo.txt",ios::in);
    if(!archivo.fail()){
        while(!archivo.eof()){
            getline(archivo,registro,'|');
            id=atoi(registro.c_str());
            if(id != NULL){
                getline(archivo,origen,'|');
                getline(archivo,destino,'|');
                getline(archivo,registro,'|');
                peso=strtof(registro.c_str(), nullptr);
                Paquete *nuevo = new Paquete(id,origen,destino,peso);
                agregarAlInicio(nuevo);
            }
        }
        invertirLista(&head);
        cout<<"\n\tPaquetes recuperados..."<<endl<<endl;
    }else{
        cout<<"\n\tArchivo no encontrado..."<<endl<<endl;
    }
}

void Paqueteria::invertirLista(Paquete** head){
        Paquete *previous = NULL;
        Paquete *current = *head;
        while (current != NULL){
            Paquete *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        *head = previous;
}
