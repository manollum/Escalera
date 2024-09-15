#ifndef SIMULADO_H_INCLUDED
#define SIMULADO_H_INCLUDED

void modoSimulado() {
    string nombreJugador1, nombreJugador2, nombreDelGanador;
    int limite=6, contadorRondas=1, puntaje, puntajeAnterior=0, maximoPuntaje=0, acuPuntaje=0;
    int puntajeJugador1=0, puntajeJugador2=0;
    const int tam=6;
    int dados[tam];
    bool hayEscalera = false, reseteoSeis=true, dadosIguales=true;

    cout << "Ingrese nombre del jugador 1: ";
    cin.ignore();
    getline(cin, nombreJugador1);
    cout << "Ingrese nombre del jugador 2: ";
    getline(cin, nombreJugador2);

    while (puntajeJugador1 < 100 && puntajeJugador2 < 100) {
        cout << endl;
        cout << "Turno de " << nombreJugador1 << ":" << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "Ingrese los valores de los dados para la tirada " << i << " (separados por espacio): ";
            for (int j = 0; j < tam; ++j) {
                cin >> dados[j];
            }

            puntaje=sumarVector(dados, tam);

            reseteoSeis=hayReseteo(dados, tam);
                    if (reseteoSeis){
                        puntaje=0;
                        puntajeAnterior=0;
                        puntajeJugador1=0;
                    }

            cout << endl;
            cout << "Jugador: " << nombreJugador1 << endl;
            cout << "Puntaje hasta el momento: " << puntajeJugador1 << endl;
            cout << "Ronda numero #" << contadorRondas << endl;
            cout << "Tirada " << i << "/3" << endl;
            cout << endl;
            mostrarDados(dados, tam);

            hayEscalera=escalera(dados, tam);
            if (hayEscalera) {
                cout << endl;
                cout << "************************************************" << endl;
                cout << "   GANASTE!!!!!! Escalera servida!!! =D     " << endl;
                cout << "      El jugador " << nombreJugador1 << " ha ganado!   " << endl;
                cout << "************************************************" << endl;
                cout << "Fin del juego..." << endl;
                system("pause");
                return;
            }

            dadosIguales=mismosDados(dados, tam);
            if (dadosIguales){
                    puntaje=dados[1]*10;
                    }

            cout << "El puntaje de esta tirada fue de: " << puntaje << endl;
            if (puntaje > puntajeAnterior) {
                puntajeAnterior = puntaje;
                maximoPuntaje = puntaje;
            } else
                maximoPuntaje = puntajeAnterior;
            }
            system("cls");
        cout << endl;
        cout << "El mejor puntaje de las 3 tiradas fue: " << maximoPuntaje << endl;
        cout << "_____________________________________________________________________________________" << endl;

        puntajeJugador1+=maximoPuntaje;
        puntajeAnterior=0;

        cout << endl;
        cout << "Turno de " << nombreJugador2 << ":" << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "Ingrese los valores de los dados para la tirada " << i << " (separados por espacio): ";
            for (int j = 0; j < tam; ++j) {
                cin >> dados[j];
            }

            puntaje=sumarVector(dados, tam);

            reseteoSeis=hayReseteo(dados, tam);
                    if (reseteoSeis){
                        puntaje=0;
                        puntajeAnterior=0;
                        puntajeJugador2=0;
                    }

            cout << endl;
            cout << "Jugador: " << nombreJugador2 << endl;
            cout << "Puntaje hasta el momento: " << puntajeJugador2 << endl;
            cout << "Ronda numero #" << contadorRondas << endl;
            cout << "Tirada " << i << "/3" << endl;
            cout << endl;
            mostrarDados(dados, tam);

            hayEscalera=escalera(dados, tam);
            if (hayEscalera) {
                cout << endl;
                cout << "************************************************" << endl;
                cout << "   GANASTE!!!!!! Escalera servida!!! =D     " << endl;
                cout << "      El jugador " << nombreJugador2 << " ha ganado!   " << endl;
                cout << "************************************************" << endl;
                cout << "Fin del juego..." << endl;
                system("pause");
                return;
            }

            dadosIguales=mismosDados(dados, tam);
            if (dadosIguales){
                    puntaje=dados[1]*10;
                    }

            cout << "El puntaje de esta tirada fue de: " << puntaje << endl;
            if (puntaje > puntajeAnterior) {
                puntajeAnterior=puntaje;
                maximoPuntaje=puntaje;
            } else {
                maximoPuntaje=puntajeAnterior;
            }

            cout << endl;

        }
        system("cls");
        cout << endl;
        cout << "El mejor puntaje de las 3 tiradas fue: " << maximoPuntaje << endl;
        cout << "_____________________________________________________________________________________" << endl;


        contadorRondas++;
        puntajeJugador2+=maximoPuntaje;
        puntajeAnterior=0;

    }

    if (puntajeJugador1 > puntajeJugador2) {
        cout << "El jugador " << nombreJugador1 << " ha ganado la partida en " << contadorRondas - 1 << " rondas!!! FELICITACIONES!!! =)" << endl;
        cout << "El total de puntos acumulados fue: " << puntajeJugador1 << endl;

    } else if (puntajeJugador2 > puntajeJugador1){
        cout << "El jugador " << nombreJugador2 << " ha ganado la partida en " << contadorRondas - 1 << " rondas!!! FELICITACIONES!!! =)" << endl;
        cout << "El total de puntos acumulados fue: " << puntajeJugador2 << endl;

    } else{
        cout<< "La partida ha finalizado en EMPATE!!!" << endl;
    }

    system("pause");
}



#endif // SIMULADO_H_INCLUDED
