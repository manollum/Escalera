#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MisFunciones.h"
#include "Juego.h"
#include "simulado.h"
#include "Windows.h"


using namespace std;

int main() {
    system ("color 2");
    int opcion, limite = 6, contadorRondas, puntaje, puntajeAnterior = 0, maximoPuntaje = 0, sumaPuntoTres = 0;
    int puntajeJugador1, puntajeJugador2;
    string nombreDelGanador;
    bool hayEscalera = false, jugadorGano, reseteoSeis = true, dadosIguales = true;
    const int tam = 6;
    int dados[6]; // Declaracion de dados vectores
    string nombre, nombreJugador1, nombreJugador2;
    srand(time(NULL)); // La semilla de los numeros aleatorios. Siempre se setea 1 sola vez y en el MAIN

    // Inicializo los dados en 0.
    ponerCero(dados, tam);

    // Voy a armar acá el MENÚ PRINCIPAL del juego.
    do {
        contadorRondas = 1;
        jugadorGano = false; // Bandera para verificar si el jugador gano. Se pone en false en cada inicio de ciclo.

        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese su nombre: ";
                cin.ignore();
                getline(cin, nombre);

                puntajeJugador1 = 0;

                while (puntajeJugador1 < 100) {
                        puntajeAnterior=0;
                    for (int i = 1; i <= 3; i++) {
                        cargarAleatorio(dados, tam, limite);
                        puntaje = sumarVector(dados, tam);
                        reseteoSeis = hayReseteo(dados, tam);
                        if (reseteoSeis) {
                            puntaje = 0;
                            puntajeAnterior = 0;
                            puntajeJugador1 = 0;
                        }
                        cout << endl;
                        cout << "Jugador: " << nombre << endl;
                        cout << "Puntaje hasta el momento: " << puntajeJugador1 << endl;
                        cout << "Ronda numero #" << contadorRondas << endl;
                        cout << "Tirada " << i << "/3" << endl;
                        cout << endl;
                        mostrarDados(dados, tam);
                        hayEscalera = escalera(dados, tam);
                        if (hayEscalera) {
                            cout << endl;
                            cout << "************************************************" << endl;
                            cout << "   GANASTE!!!!!! Escalera servida!!! =D     " << endl;
                            cout << "      El jugador " << nombre << " ha ganado!   " << endl;
                            cout << "************************************************" << endl;
                            cout << "Regresando al menú principal..." << endl;
                            system("pause");
                            jugadorGano = true;
                            break;
                        }

                        dadosIguales = mismosDados(dados, tam);
                        if (dadosIguales) {
                            puntaje = dados[1] * 10;
                        }
                        cout << "El puntaje de esta tirada fue de: " << puntaje << endl;
                        if (puntaje > puntajeAnterior) {
                            puntajeAnterior = puntaje;
                            maximoPuntaje = puntaje;
                        } else {
                            maximoPuntaje = puntajeAnterior;
                        }

                        cout << endl;
                        pausarConMensaje("");
                    }
                    system("cls");
                    if (jugadorGano) {
                        break;
                    }
                    cout << endl;
                    cout << "El mejor puntaje de las 3 tiradas fue: " << maximoPuntaje << endl;
                    cout << "_____________________________________________________________________________________" << endl;
                    contadorRondas++;
                    puntajeJugador1 += maximoPuntaje;
                }
                cout << endl;
                if (!jugadorGano) {
                    cout << nombre << ", has ganado la partida en " << contadorRondas - 1 << " rondas!!! FELICITACIONES!!! =)" << endl;
                    cout << endl;
                    if(puntajeJugador1>sumaPuntoTres)
                    {
                        sumaPuntoTres = puntajeJugador1;
                        nombreDelGanador = nombre;
                    }

                    cout << "El total de puntos acumulados es: " << puntajeJugador1 << endl;
                    cout << "La puntuacion mas alta fue: " << sumaPuntoTres << " realizada por " << nombreDelGanador << endl;
                    system("pause");
                }
                break;

            case 2:
                cout << "Ingrese nombre del jugador 1: ";
                cin.ignore();
                getline(cin, nombreJugador1);
                cout << "Ingrese nombre del jugador 2: ";
                getline(cin, nombreJugador2);

                // Juego para 2.
                puntajeJugador1 = 0;
                puntajeJugador2 = 0;

                while (puntajeJugador1 < 100 && puntajeJugador2 < 100) {
                        puntajeAnterior=0;


                    cout << endl;
                    cout << "Turno de " << nombreJugador1 << ":" << endl;
                    for (int i = 1; i <= 3; ++i) {
                        cargarAleatorio(dados, tam, limite);
                        int puntaje = sumarVector(dados, tam);
                        reseteoSeis = hayReseteo(dados, tam);
                        if (reseteoSeis) {
                            puntaje = 0;
                            puntajeAnterior = 0;
                            puntajeJugador1 = 0;
                        }
                        cout << endl;
                        cout << "Jugador: " << nombreJugador1 << endl;
                        cout << "Puntaje hasta el momento: " << puntajeJugador1 << endl;
                        cout << "Ronda numero #" << contadorRondas << endl;
                        cout << "Tirada " << i << "/3" << endl;
                        cout << endl;
                        mostrarDados(dados, tam);
                        hayEscalera = escalera(dados, tam);
                        if (hayEscalera) {
                            cout << endl;
                            cout << "************************************************" << endl;
                            cout << "   GANASTE!!!!!! Escalera servida!!! =D     " << endl;
                            cout << "      El jugador " << nombreJugador1 << " ha ganado!   " << endl;
                            cout << "************************************************" << endl;
                            cout << "Regresando al menú principal..." << endl;
                            system("pause");
                            jugadorGano = true;
                            break;
                        }

                        cout << "El puntaje de esta tirada fue de: " << puntaje << endl;
                        if (puntaje > puntajeAnterior) {
                            puntajeAnterior = puntaje;
                            maximoPuntaje = puntaje;
                        } else {
                            maximoPuntaje = puntajeAnterior;
                        }

                        cout << endl;
                        pausarConMensaje("");
                    }
                    system("cls");

                    if (jugadorGano) {
                        break;
                    }
                    cout << endl;
                    cout << "El mejor puntaje de las 3 tiradas fue: " << maximoPuntaje << endl;
                    cout << "_____________________________________________________________________________________" << endl;
                    cout << endl;

                    puntajeJugador1 += maximoPuntaje;

                    puntajeAnterior = 0;

                    cout << "Turno de " << nombreJugador2 << ":" << endl;
                    for (int i = 1; i <= 3; ++i) {
                        cargarAleatorio(dados, tam, limite);
                        int puntaje = sumarVector(dados, tam);
                        reseteoSeis = hayReseteo(dados, tam);
                        if (reseteoSeis) {
                            puntaje = 0;
                            puntajeAnterior = 0;
                            puntajeJugador2 = 0;
                        }
                        cout << endl;
                        cout << "Jugador: " << nombreJugador2 << endl;
                        cout << "Puntaje hasta el momento: " << puntajeJugador2 << endl;
                        cout << "Ronda numero #" << contadorRondas << endl;
                        cout << "Tirada " << i << "/3" << endl;
                        cout << endl;
                        mostrarDados(dados, tam);
                        hayEscalera = escalera(dados, tam);
                        if (hayEscalera) {
                            cout << endl;
                            cout << "************************************************" << endl;
                            cout << "   GANASTE!!!!!! Escalera servida!!! =D     " << endl;
                            cout << "      El jugador " << nombreJugador2 << " ha ganado!   " << endl;
                            cout << "************************************************" << endl;
                            cout << "Regresando al menú principal..." << endl;
                            system("pause");
                            jugadorGano = true;
                            break;
                        }

                        cout << "El puntaje de esta tirada fue de: " << puntaje << endl;
                        if (puntaje > puntajeAnterior) {
                            puntajeAnterior = puntaje;
                            maximoPuntaje = puntaje;
                        } else {
                            maximoPuntaje = puntajeAnterior;
                        }

                        cout << endl;
                        pausarConMensaje("");
                    }
                    system("cls");
                    if (jugadorGano)  // Volver al Menu Principal
                        break;

                    cout << endl;
                    cout << "El mejor puntaje de las 3 tiradas fue: " << maximoPuntaje << endl;
                    cout << "_____________________________________________________________________________________" << endl;
                    puntajeJugador2 += maximoPuntaje;
                    contadorRondas++; // Aumenta el numero de ronda cuando termina el turno del jugador 2
                }

                cout << endl;

                if(!jugadorGano)
                {
                    if (puntajeJugador1 > puntajeJugador2)
                    {
                    cout << "El jugador " << nombreJugador1 << " ha ganado la partida en " << contadorRondas - 1 << " rondas!!! FELICITACIONES!!! =)" << endl;
                    cout << "El total de puntos acumulados fue: " << puntajeJugador1;
                    if(puntajeJugador1>sumaPuntoTres)
                    {
                        sumaPuntoTres = puntajeJugador1;
                        nombreDelGanador = nombreJugador1;
                    }
                    }

                    else if(puntajeJugador2 > puntajeJugador1)
                    {
                    cout << "El jugador " << nombreJugador2 << " ha ganado la partida en " << contadorRondas - 1 << " rondas!!! FELICITACIONES!!! =)" << endl;
                    cout << "El total de puntos acumulados fue: " << puntajeJugador2;
                    if(puntajeJugador2>sumaPuntoTres)
                    {
                        sumaPuntoTres = puntajeJugador2;
                        nombreDelGanador = nombreJugador2;
                    }
                    }
                    else
                    cout<< "La partida ha finalizado en EMPATE!!!" << endl;

                }
                cout << endl;
                system("pause");
                break;

            case 3:
                cout << "La puntuacion mas alta fue: " << sumaPuntoTres << " realizada por " << nombreDelGanador << endl;
                cout << endl;
                pausarConMensaje2("");
                break;

            case 4:
                modoSimulado();
                break;

            case 0:
                cout << endl;
                cout << "Gracias por jugar!!! HASTA LA PROXIMA =)" << endl;
                return 0;

            default:
                cout << "Opcion incorrecta" << endl;
                pausarConMensaje2("");
                break;
        }
    } while (opcion != 0);

    return 0;
}
