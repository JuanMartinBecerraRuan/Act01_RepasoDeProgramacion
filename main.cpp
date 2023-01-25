#include <iostream>
#include <paqueteria.h>

using namespace std;

int main(void){
    system("color 0a");
    Paqueteria lista;
    char opcion;
    int id;
    string origen;
    string destino;
    float peso;
    do{
        system("cls");
        cout<<"\t\tMENU PRINCIPAL"<<endl<<endl;
        cout<<"\t[1] Agregar paquete"<<endl;
        cout<<"\t[2] Eliminar paquete"<<endl;
        cout<<"\t[3] Mostrar"<<endl;
        cout<<"\t[4] Guardar (respaldo.txt)"<<endl;
        cout<<"\t[5] Recuperar (respaldo.txt)"<<endl;
        cout<<"\t[6] Salir"<<endl<<endl;
        cout<<"Elige una opcion: ";
        cin>>opcion;
        switch(opcion){
            case '1':{
                system("cls");
                cout<<"\t\tInsertar al inicio"<<endl<<endl;
                cout<<"ID: ";
                cin>>id;
                cout<<"ORIGEN: ";
                cin.ignore();
                getline(cin,origen);
                cout<<"DESTINO: ";
                getline(cin,destino);
                cout<<"PESO: ";
                cin>>peso;
                Paquete *nuevo = new Paquete(id,origen,destino,peso);
                lista.agregarAlInicio(nuevo);
                cout<<endl;
                system("pause");
                break;
            }
            case '2':{
                system("cls");
                lista.eliminarAlInicio();
                system("pause");
                break;
            }
            case '3':{
                system("cls");
                lista.mostrar();
                cout<<endl;
                system("pause");
                break;
            }
            case '4':{
                system("cls");
                lista.guardar();
                cout<<endl;
                system("pause");
                break;
            }
            case '5':{
                system("cls");
                lista.recuperar();
                cout<<endl;
                system("pause");
                break;
            }
        }
    }while(opcion!='6');
    cout<<endl;
    return 0;
}
