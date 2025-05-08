#include "View.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void View::agregarJugador() {
    try {
        casino.agregarJugador();
    } catch (std::invalid_argument &ex) {
        cout << "ERROR con parámetros: " << ex.what() << endl;
    } catch (std::exception &ex) {
        cout << "ERROR, contáctate con el administrador: " << ex.what() << endl;
    }
}

void View::jugarView() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar: ";
        cin >> idJugador;

        float cantGonzos;
        cout << "¿Cuántos gonzos desea apostar? ";
        cin >> cantGonzos;

        int idJuego;
        float gonzosResultado;
        string textoResultado;

        cout << "Elija el juego: " << endl;
        cout << "1. Mayor a 13." << endl;
        cout << "2. Dos colores." << endl;
        cout << "3. Slots." << endl;
        cout << "Opción: ";
        cin >> idJuego;

        gonzosResultado = casino.jugar(idJuego, idJugador, cantGonzos);
        if (gonzosResultado > 0) {
            textoResultado = "¡Has ganado!: ";
        } else {
            textoResultado = "Has perdido :( : ";
        }

        cout << textoResultado << gonzosResultado << " Gonzos" << endl;

    } catch (std::domain_error &ex) {
        cout << ex.what() << endl;
    }
}

int View::mostrarMenu() {
    int opcion;
    cout << "\n====== MENU ======\n";
    cout << "1. Agregar jugador" << endl;
    cout << "2. Jugar" << endl;
    cout << "3. Consultar jugador" << endl;
    cout << "4. Recargar gonzos" << endl;
    cout << "5. Retirar jugador del casino" << endl;
    cout << "0. Salir" << endl;
    cout << "Digita el número: ";
    cin >> opcion;

    // Validación básica de entrada
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1; // Valor inválido
    }

    return opcion;
}

void View::verPrincipal() {
    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                agregarJugador();
                break;
            case 2:
                jugarView();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                recargarGonzos();
                break;
            case 5:
                retirarJugador();
                break;
            case 0:
                cout << "¡Hasta pronto!" << endl;
                break;
            default:
                cout << "No hay ninguna opción para ese número." << endl;
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
    } catch (std::domain_error &ex) {
        cout << ex.what() << endl;
    }
}

void View::retirarJugador() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
        casino.retirarJugador(idJugador);
        cout << "Jugador retirado con éxito." << endl;
    } catch (std::domain_error &ex) {
        cout << ex.what() << endl;
    }
}

void View::recargarGonzos() {
    long idJugador;
    try {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.recargarGonzos(idJugador);
        cout << "Recarga realizada con éxito." << endl;
    } catch (std::domain_error &ex) {
        cout << ex.what() << endl;
    }
}
