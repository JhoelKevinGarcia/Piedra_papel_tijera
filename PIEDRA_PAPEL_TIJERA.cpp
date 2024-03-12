//PIEDRA_PAPEL_TIJERA
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Opcion { PIEDRA = 1, PAPEL = 2, TIJERA = 3 };

class Juego {
private:
	int puntosJugador1;
	int puntosJugador2;
	
public:
	Juego() : puntosJugador1(0), puntosJugador2(0) {}
	
	void imprimirMenu() {
		cout << "Elige una opción:" << endl;
		cout << "1 - Piedra" << endl;
		cout << "2 - Papel" << endl;
		cout << "3 - Tijera" << endl;
	}
	
	Opcion obtenerOpcion(int opcion) {
		switch (opcion) {
		case 1:
			return PIEDRA;
		case 2:
			return PAPEL;
		case 3:
			return TIJERA;
		default:
			return PIEDRA; 
		}
	}
	
	void determinarGanador(Opcion jugador1, Opcion jugador2) {
		if (jugador1 == jugador2) {
			cout << "Empate!" << endl;
		} else if ((jugador1 == PIEDRA && jugador2 == TIJERA) ||
			(jugador1 == PAPEL && jugador2 == PIEDRA) ||
			(jugador1 == TIJERA && jugador2 == PAPEL)) {
			cout << "Jugador 1 gana!" << endl;
			puntosJugador1++;
		} else {
				cout << "Jugador 2 gana!" << endl;
				puntosJugador2++;
			}
	}
	
	void jugar() {
		srand(time(nullptr));
		
		while (true) {
			imprimirMenu();
			
			int opcionJugador1, opcionJugador2;
			cout << "Jugador 1: ";
			cin >> opcionJugador1;
			
			cout << "Jugador 2: ";
			cin >> opcionJugador2;
			
			Opcion jugadaJugador1 = obtenerOpcion(opcionJugador1);
			Opcion jugadaJugador2 = obtenerOpcion(opcionJugador2);
			
			cout << "Jugador 1 eligió: " << opcionJugador1 << endl;
			cout << "Jugador 2 eligió: " << opcionJugador2 << endl;
			
			determinarGanador(jugadaJugador1, jugadaJugador2);
			
			cout << "Puntuación:" << endl;
			cout << "Jugador 1: " << puntosJugador1 << " puntos" << endl;
			cout << "Jugador 2: " << puntosJugador2 << " puntos" << endl;
			
			char continuar;
			cout << "¿Quieres seguir jugando? (s/n): ";
			cin >> continuar;
			if (continuar != 's' && continuar != 'S') {
				break;
			}
		}
		
		cout << "Fin del juego." << endl;
	}
};

int main() {
	Juego juego;
	juego.jugar();
	
	return 0;
}
