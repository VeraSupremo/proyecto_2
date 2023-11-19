#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

 struct guardian{
	string nombre;
	int lvl;
	string maestro;
	string ciudad;
	
};
//se crearan las funciones del arbol binario para colocar el ranking por niveles (k pro)
struct nodo{
	int DatoNIvel;
	nodo* izquierda;
	nodo* derecha;
};
nodo* crearNodo(int DatoNIvel){
	guardian* Aguard= new guardian;
	DatoNIvel = Aguard->lvl;
	nodo* Nnodo= new nodo;
	Nnodo->DatoNIvel = DatoNIvel;
	
	Nnodo->derecha = NULL;
	Nnodo->izquierda = NULL;
	return Nnodo;
	
}
nodo* agregar(nodo* raiz, int ingreso){
	guardian* Aguard= new guardian;
	ingreso = Aguard->lvl; 
	if(raiz == NULL){
		raiz = crearNodo(ingreso);
		return raiz;
	}
	if(ingreso <= raiz->DatoNIvel){           //aca si el guardian tiene un nivel menor se ira a l aizquierda sino a la derecha 
		raiz->izquierda = agregar(raiz->izquierda, ingreso);
	}else{
		raiz->derecha = agregar(raiz->derecha, ingreso);
	}
	cout<<raiz<<std::endl;
	return raiz;
}
void imprimir(nodo* raiz){
	if(raiz == NULL){
		return;
	}
	cout<<raiz->DatoNIvel<<" ";
	
	imprimir(raiz->izquierda);
	imprimir(raiz->derecha);
}






//funcion para leer archivos

void LeeGuardianes(const string& nombreArchivo, nodo*& arbol) {
    ifstream archivo("");

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }
	guardian* nuevoGuardian = new guardian;
    while (!archivo.eof()) {
        guardian* nuevoGuardian = new guardian;

        if (archivo >> nuevoGuardian->nombre >> nuevoGuardian->lvl >> nuevoGuardian->maestro >> nuevoGuardian->ciudad) {
            arbol = agregar(arbol, nuevoGuardian);
        } else {
            delete nuevoGuardian;  // Liberar memoria si la lectura falla
            cerr << "Error al leer datos desde el archivo." << endl;
            break;  // Salir del bucle
        }
    }

    archivo.close();
}

int main(){
nodo* arbol = NULL;
LeeGuardianes("",arbol);

cout<<"___________________________________________________"<<endl;
cout<<"________________Bienvenido guardian________________"<<endl;
Sleep(1000);
cout<<"      deberas elegir que guardian deseas ser       "<<endl;
cout<<"  tu mision sera llegar al rango entre 90 y 99     \n     para ser de los mejores guardianes del reino"<<endl;
cout<<"___________________________________________________"<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
cout<<"."<<endl;
Sleep(1000);
system("cls");

cout<<"______________Que opcion desea elegir______________"<<endl;
cout<<"           Opcion____________________1             "<<endl;  //acas edaran las opciones de que deben elegirr suceptible a cambio
cout<<"           Opcion____________________2             "<<endl;
cout<<"           Opcion____________________3             "<<endl;
cout<<"           Opcion____________________4             "<<endl;
cout<<"           Opcion____________________5             "<<endl;
cout<<"___________________________________________________"<<std::endl;



return 0;
}

