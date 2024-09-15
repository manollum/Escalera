#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#include <iostream>
#include<cstdio>
#include<ctime>

using namespace std;


/// Desarrollo de funciones / Definiciones

void cargarAleatorio(int v[], int tam, int limite){
        int i;
        for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }

}


void mostrarDados(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

void pausarConMensaje(const string&) {
    cout << "Presiona ENTER para volver a tirar...";
    cin.get();
}

void pausarConMensaje2(const string&) {
    cout << "Presiona ENTER para volver al MENU PRINCIPAL.";
    cin.ignore();
    cin.get();
}


#endif // MISFUNCIONES_H_INCLUDED


