#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

using namespace std;


void mostrarMenu(){

    string nombre, nombreJugador1, nombreJugador2;

    system("cls");
    cout << endl;
    cout << "************ MENU PRINCIPAL ************" << endl;
    cout << "************   ESCALERA     ************" << endl;
    cout << endl;
    cout << "1)Iniciar partida para un jugador." << endl;
    cout << "2)Iniciar partida para dos jugadores. " << endl;
    cout << "3)Mostrar puntuacion mas alta." << endl;
    cout << "4)Modo simulado" << endl;
    cout << "0)Salir del juego." << endl;
    cout << endl;

}


bool escalera(int v[], int tam){

    int dado1=0, dado2=0, dado3=0, dado4=0, dado5=0, dado6=0;

    int i;
    for(i=0; i<tam;++i) {
        switch(v[i]) {
            case 1:
                dado1++;
            break;
            case 2:
                dado2++;
            break;
            case 3:
                dado3++;
            break;
            case 4:
                dado4++;
            break;
            case 5:
                dado5++;
            break;
            case 6:
                dado6++;
            break;
        }
    }
    if(dado1==1 && dado2==1 && dado3==1 && dado4==1 && dado5==1 && dado6==1){
        return true;
        }
        return false;

}


bool hayReseteo(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]!=6)
        return false;
        }
}

bool mismosDados(int v[], int tam){
    int i;
    for(i=0;i<tam-1;i++){///esto es para no desbordar el vector
        if(v[i]!=v[i+1] || v[i]==6)
        return false;
        }
}
#endif // JUEGO_H_INCLUDED
