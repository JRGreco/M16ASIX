
//JUEGO BLACKJACK REALIZADO POR JEREMY RODRIGUEZ Y PAU DALMAU

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "MMSystem.h"

using namespace std;

//VARIABLES CARTAS
int picas[12];
int diamantes[12];
int corazones[12];
int treboles[12];

//VARIABLES DEL JUGADOR
string jugador1;
int puntosJ1 = 0;
boolean rendirseJ1 = false;
boolean ganador1 = false;
boolean perdedorJ1 = false;

//VARIABLES DE LA BANCA
string jugador2 = "Croupiere";
int puntosJ2 = 0;
boolean rendirseJ2 = false;
boolean ganadorJ2 = false;
boolean perdedorJ2 = false;

void cargando() {

	char LCharacter = char(2);

	char LBar[51] = { ' ',' ',' ',' ', ' ',' ', ' ',' ', ' ',' ',
					 ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ',
					 ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ',
					 ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ',
					 ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ',0 };

	int LCounter;

	string LMessage[5] = { "Players...","Interface...","Sounds...","Etc...","Done..." };
	int LMessageCounter = 0;
	for (LCounter = 0; LCounter < 50; LCounter++) {
		LBar[LCounter] = LCharacter;
		Sleep(150);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		cout << setw(58) << "Loading " << LMessage[LMessageCounter] << endl;
		printf("\n");
		cout << setw(82) << LBar << endl;
		if (LCounter == 15 || LCounter == 23 || LCounter == 33 || LCounter == 42) LMessageCounter++;
	}
	Sleep(1000);
}

void textoLogo() {
	system("cls");
	printf("\n\n\n");
	cout << setw(80) << " _     _            _    _            _    \n";
	cout << setw(80) << "| |   | |          | |  (_)          | |   \n";
	cout << setw(80) << "| |__ | | __ _  ___| | ___  __ _  ___| | __\n";
	cout << setw(80) << "| '_ \\| |/ _` |/ __| |/ / |/ _` |/ __| |/ /\n";
	cout << setw(80) << "| |_) | | (_| | (__|   <| | (_| | (__|   < \n";
	cout << setw(80) << "|_.__/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\\n";
	cout << setw(80) << "                       _/ |                \n";
	cout << setw(73) << "                      |__/           ";
}

void finDeJuego() {
	printf("\n\n\n");
	cout << setw(69) << "THE DEVELOPMENT TEAM\n\n";
	Sleep(1000);
	cout << setw(66) << "Programadores\n\n";
	Sleep(800);
	cout << setw(75) << "Jeremy Joel Rodriguez Chapilliquen\n";
	Sleep(800);
	cout << setw(70) << "Pau Dalmau Aregall\n\n";
	Sleep(800);
	cout << setw(68) << "Diseno del juego\n\n";
	Sleep(800);
	cout << setw(75) << "Jeremy Joel Rodriguez Chapilliquen\n";
	Sleep(800);
	cout << setw(73) << "Pau Dalmau Aregall\n\n\n\n\n";
	Sleep(800);
	cout << setw(71) << "GRACIAS POR SU TIEMPO\n\n\n";
}

void normas() {
	cout << endl << endl << endl;
	cout << setw(60) << "NORMAS" << endl << endl;
	Sleep(1000);
	cout << "- Todas las cartas del 2 al 10 tienen el mismo valor que su numero: P.e. Un 4 de corazones son 4 puntos y un 7 de picas son 7 puntos." << endl << endl;
	Sleep(600);
	cout << "- El AS puede valer un 1 o puede valer un 11. Depende del jugador o de la banca el valor que quiera darle:" << endl << endl;
	Sleep(600);
	cout << "\t- Para el jugador: Pedira por comando al usuario que indique si quiere que se sume un punto o que se sume 11." << endl;
	Sleep(600);
	cout << "\t- Para el croupier: Tendra que elegir la maquina automaticamente. Si con un 11 no sobrepasa los 21 puntos," << endl << "\t  elegira un 11. Si lo sobrepasa, elegira un 1." << endl << endl;
	Sleep(600);
	cout << "- Las figuras J, Q y K tienen todas un valor de 10." << endl << endl;
	Sleep(600);
	cout << "- El jugador gana cuando:" << endl << endl;
	Sleep(600);
	cout << "\t- Alcanza un 21 y el croupier no empata a 21 o se pasa de 21." << endl;
	Sleep(600);
	cout << "\t- Alcanza menos de 21 pero la banca se pasa de 21." << endl << endl;
	Sleep(600);
	cout << "- El jugador empata cuando:" << endl << endl;
	Sleep(600);
	cout << "\t- Alcanza un 21 y el croupier alcanza tambien 21." << endl << endl;
	Sleep(600);
	cout << "- El jugador pierde cuando:" << endl << endl;
	Sleep(600);
	cout << "\t- Se pasa de 21." << endl;
	Sleep(600);
	cout << "\t- Tiene una puntuacion menor a 21, pero la banca tiene una puntuacion mayor, sin pasarse de 21." << endl;
	Sleep(5000);
}

void comoSeJuega() {
	cout << endl << endl << endl;
	cout << setw(65) << "COMO SE JUEGA" << endl << endl;
	Sleep(1000);
	cout << "- El croupier reparte dos cartas al jugador y reparte una para el." << endl << endl;
	Sleep(600);
	cout << "\t- Es posible que el jugador alcance 21 en esa misma ronda con una combinacion de AS (con valor de 11) y un 10" << endl << "\t  o una figura.Por lo que pasaria automaticamente al turno de la banca para tratar de al menos empatar." << endl << endl;
	Sleep(600);
	cout << "- El jugador, si tiene menos de 21 puntos, puede pedir nuevas cartas al croupier, hasta que decida plantarse, " << endl << " llegue a 21 o se pase de 21." << endl << endl;
	Sleep(600);
	cout << "\t- Si el jugador se pasa de 21, el croupier gana automaticamente." << endl;
	Sleep(600);
	cout << "\t- Si el jugador se queda a menos de 21 y se rinde." << endl << endl;
	Sleep(600);
	cout << "\t\t- Llega el turno del croupier, que tiene que al menos mejorar la puntuacion del jugador, " << endl << "\t\t  sin pasarse de 21." << endl << endl;
	Sleep(600);
	cout << "\t\t\t- Si la mejora sin pasarse gana el croupier." << endl << endl;
	Sleep(600);
	cout << "\t\t\t- Si se pasa de 21, pierde el croupier." << endl << endl;
	Sleep(600);
	cout << "\t- Si el jugador alcanza los 21 puntos." << endl << endl;
	Sleep(600);
	cout << "\t\t- Llega el turno del croupier, que tiene que intentar llegar a 21 obligatoriamente." << endl << endl;
	Sleep(600);
	cout << "\t\t\t- Si llega a 21, el jugador y el croupier empatan." << endl << endl;
	Sleep(600);
	cout << "\t\t\t- Si se pasa de 21, el croupier pierde." << endl;
	Sleep(5000);
}

void iniciarCartas(int(&cartas)[12]) {
	for (int i = 0; i < 12; i++) {
		cartas[i] = 1;
	}
}

void escogerCartas(int& puntosTotales, string jugador) {
	boolean escogido = false;
	int indiceCarta = 0, paloCarta = 0;
	string tipoPalo;
	while (!escogido) {
		PlaySound(TEXT("barajarCartas.wav"), NULL, SND_SYNC);
		Sleep(100);
		paloCarta = 1 + rand() % 4; //Escogerá un número del 1 al 4 que dirá que tipo de carta es
		indiceCarta = rand() % 12; //Escogerá un número del 0 al 12 que determinará la posición de la carta

		//Si el palo Carta es 1 se ejecutará las Picas
		if (paloCarta == 1) {
			tipoPalo = "Picas";
			if (picas[indiceCarta] == 1) {
				picas[indiceCarta] = 0;
				escogido = true;
			}
		}
		//Si el palo Carta es 2 se ejecutará los Diamantes
		else if (paloCarta == 2) {
			tipoPalo = "Diamantes";
			if (diamantes[indiceCarta] == 1) {
				diamantes[indiceCarta] = 0;
				escogido = true;
			}
		}
		//Si el palo Carta es 3 se ejecutará los Corazones
		else if (paloCarta == 3) {
			tipoPalo = "Corazones";
			if (corazones[indiceCarta] == 1) {
				corazones[indiceCarta] = 0;
				escogido = true;
			}

		}
		//Si el palo Carta es 4 se ejecutará los Tréboles
		else if (paloCarta == 4) {
			tipoPalo = "Treboles";
			if (treboles[indiceCarta] == 1) {
				treboles[indiceCarta] = 0;
				escogido = true;
			}
		}
		else {
			escogido = false;
		}
	}

	//Comprobar si sale AS, J, Q, K o el resto de cartas

	//Si sale un AS se ejecutará
	if (indiceCarta == 0) {
		boolean opcionAsValido;
		int opcionAs;

		//Si sale un AS para la banca se escogerá automáticamente que valor obtiene AS si un 1 o un 11, escogerá un 11 si escogiendo el 11 no pasa de 21, en caso contrario, escogerá el 1
		if (jugador == jugador2) {
			if (puntosTotales <= 10) {
				indiceCarta = 10;
				puntosTotales += indiceCarta + 1;
				cout << endl << setw(35) << "El jugador " << jugador << " ha sacado un AS de (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
			}
			else if (puntosTotales > 10) {
				indiceCarta = 0;
				puntosTotales += indiceCarta + 1;
				cout << endl << setw(35) << "El jugador " << jugador << " ha sacado un AS de (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
			}
		}
		//Si sale un AS para el jugador se le pedirá por consola que valor otorgarle un 1 o un 11
		else if (jugador == jugador1) {
			do {
				cout << "\n\n";
				cout << setw(80) << "Ha salido un AS, que valor quieres asignarle?" << endl << endl;
				cout << setw(65) << "[1] Valor carta 1" << endl;
				cout << setw(67) << "[11] Valor carta 11" << endl;
				cout << endl << setw(65) << "Introduce una opcion: ";
				cin >> opcionAs;
				system("cls");
				switch (opcionAs) {
				case 1:
					indiceCarta = 0;
					puntosTotales += indiceCarta + 1;
					cout << endl << setw(35) << "El jugador " << jugador << " ha sacado un AS de (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
					opcionAsValido = true;
					break;
				case 11:
					indiceCarta = 10;
					puntosTotales += indiceCarta + 1;
					cout << endl << setw(35) << "El jugador " << jugador << " ha sacado un AS de (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
					opcionAsValido = true;
					break;
				default:
					cout << endl << setw(65) << "Introduce una opcion correcta." << endl;
					Sleep(10000);
					opcionAsValido = false;
					break;
				}
			} while (!opcionAsValido);
		}
	}
	//Si sale una J se ecutará
	else if (indiceCarta == 10) {
		indiceCarta = 9;
		puntosTotales += indiceCarta + 1;
		cout << endl << setw(35) << "El jugador " << jugador << " ha sacado una J (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
	}
	//Si sale una Q se ecutará
	else if (indiceCarta == 11) {
		indiceCarta = 9;
		puntosTotales += indiceCarta + 1;
		cout << endl << setw(35) << "El jugador " << jugador << " ha sacado una Q (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
	}
	//Si sale una K se ecutará
	else if (indiceCarta == 12) {
		indiceCarta = 9;
		puntosTotales += indiceCarta + 1;
		cout << endl << setw(35) << "El jugador " << jugador << " ha sacado una K (" << indiceCarta + 1 << ") de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
	}
	//Si sale cualquier carta que no sea un AS, J, Q, K se ejecutará lo siguiente
	else {
		puntosTotales += indiceCarta + 1;
		cout << endl << setw(35) << "El jugador " << jugador << " ha sacado un " << indiceCarta + 1 << " de " << tipoPalo << " y tiene un total de " << puntosTotales << "." << endl;
	}
}

bool comprobarPuntos(int& puntos, boolean& ganador, boolean& perdedor) {
	if (puntos == 21) {
		ganador = true;
		return true;
	}
	else if (puntos > 21) {
		perdedor = true;
		return true;
	}
	return false;
}

bool comprobarGanador(int puntosJ1, int puntosJ2, boolean& ganadorJ2) {
	if (puntosJ2 > puntosJ1) {
		ganadorJ2 = true;
		return true;
	}
	return false;
}

void primerReparto() {
	escogerCartas(puntosJ1, jugador1);
	Sleep(500);
	escogerCartas(puntosJ1, jugador1);
	Sleep(500);

	rendirseJ1 = comprobarPuntos(puntosJ1, ganador1, perdedorJ1); // Puede pasar que ganemos o perdamos nada más comenzar

	Sleep(500);
	escogerCartas(puntosJ2, jugador2); // Primer reparto de cartas para la banca
	Sleep(500);
}

void seguirJugando() {
	while (!rendirseJ1) {
		int escogerCarta = 0;
		boolean escogerCartaValido;

		while (escogerCarta != 1 && escogerCarta != 2) {
			cout << endl << endl << setw(42) << "Tienes " << puntosJ1 << " puntos. Quieres pedir mas cartas?" << endl << endl;
			cout << setw(59) << "[1] Si" << endl;
			cout << setw(59) << "[2] No" << endl;
			cout << endl << setw(67) << "Introduce una opcion: ";
			cin >> escogerCarta;
			system("cls");
			switch (escogerCarta) {
			case 1:
				Sleep(500);
				escogerCartas(puntosJ1, jugador1);
				rendirseJ1 = comprobarPuntos(puntosJ1, ganador1, perdedorJ1);
				escogerCartaValido = true;
				break;
			case 2:
				Sleep(500);
				rendirseJ1 = true;
				escogerCartaValido = true;
				break;
			default:
				cout << endl << endl << setw(67) << "Elige una opcion correcta." << endl;
				Sleep(1000);
				system("cls");
				escogerCartaValido = false;
				break;
			}
		}
	}
	//Termina el turno del jugador 1. Hay que comprobar si ha ganado o ha perdido, en caso contrario, la banca tirará
	if (ganador1) {
		Sleep(500);
		system("cls");
		cout << endl << endl << setw(50) << "El jugador " << jugador1 << " gana y la banca pierde." << endl << endl << endl;
		cout << setw(70) << "Resultado de la partida" << endl;
		cout << endl << setw(50) << "El jugador '" << jugador1 << "' ha obtenido finalmente " << puntosJ1 << " puntos.";
		cout << endl << setw(48) << "La banca '" << jugador2 << "' ha obtenido finalmente " << puntosJ2 << " puntos.";
		PlaySound(TEXT("victoria.wav"), NULL, SND_SYNC);
		Sleep(10000);
	}
	else if (perdedorJ1) {
		Sleep(500);
		system("cls");
		cout << endl << endl << setw(50) << "El jugador " << jugador1 << " pierde y la banca gana." << endl << endl << endl;
		cout << setw(70) << "Resultado de la partida" << endl;
		cout << endl << setw(50) << "El jugador '" << jugador1 << "' ha obtenido finalmente " << puntosJ1 << " puntos.";
		cout << endl << setw(48) << "La banca '" << jugador2 << "' ha obtenido finalmente " << puntosJ2 << " puntos.";
		PlaySound(TEXT("derrota.wav"), NULL, SND_SYNC);
		Sleep(10000);
	}
	else {
		//turno de la banca
		while (!rendirseJ2) {
			escogerCartas(puntosJ2, jugador2);
			Sleep(500);
			rendirseJ2 = comprobarPuntos(puntosJ2, ganadorJ2, perdedorJ2);
			if (!rendirseJ2) {
				Sleep(500);
				rendirseJ2 = comprobarGanador(puntosJ1, puntosJ2, ganadorJ2);
			}
		}
		if (ganadorJ2) {
			Sleep(500);
			system("cls");
			cout << endl << endl << setw(67) << "La banca gana y el jugador " << jugador1 << " pierde." << endl << endl << endl;
			cout << setw(72) << "Resultado de la partida" << endl;
			cout << endl << setw(48) << "El jugador '" << jugador1 << "' ha obtenido finalmente " << puntosJ1 << " puntos.";
			cout << endl << setw(46) << "La banca '" << jugador2 << "' ha obtenido finalmente " << puntosJ2 << " puntos.";
			PlaySound(TEXT("derrota.wav"), NULL, SND_SYNC);
			Sleep(10000);
		}
		else if (perdedorJ2) {
			Sleep(500);
			system("cls");
			cout << endl << endl << setw(67) << "La banca pierde y el jugador " << jugador1 << " gana." << endl << endl << endl;
			cout << setw(72) << "Resultado de la partida" << endl;
			cout << endl << setw(48) << "El jugador '" << jugador1 << "' ha obtenido finalmente " << puntosJ1 << " puntos.";
			cout << endl << setw(46) << "La banca '" << jugador2 << "' ha obtenido finalmente " << puntosJ2 << " puntos.";
			PlaySound(TEXT("victoria.wav"), NULL, SND_SYNC);
			Sleep(10000);
		}
	}
}

void reiniciarPuntos() {
	puntosJ1 = 0, puntosJ2 = 0;
}

void jugar() {

	srand(time(NULL));
	reiniciarPuntos(); // En caso de que se vuelva a jugar se reinician los puntos

	// Inicializamos las cartas
	iniciarCartas(picas); iniciarCartas(diamantes); iniciarCartas(corazones); iniciarCartas(treboles);

	// Introducción
	cout << endl << endl << setw(67) << "Introduce tu nombre jugador: ";
	cin >> jugador1;
	Sleep(300);
	system("cls");
	//Juego
	primerReparto();
	Sleep(500);
	seguirJugando();
}

void menuJuego() {
	boolean exitProgram;

	do {
		textoLogo();
		cout << endl << endl << endl;
		cout << setw(65) << "[0] Salir del programa" << endl;
		cout << setw(53) << "[1] Normas" << endl;
		cout << setw(61) << "[2] Como se juega?" << endl;
		cout << setw(52) << "[3] Jugar" << endl << endl;
		cout << setw(64) << "Introduce una opcion: ";
		int option;
		cin >> option;
		system("cls");

		switch (option) {
		case 0:
			exitProgram = true;
			finDeJuego();
			Sleep(10000);
			break;
		case 1:
			exitProgram = false;
			normas();
			break;
		case 2:
			exitProgram = false;
			comoSeJuega();
			break;
		case 3:
			exitProgram = false;
			jugar();
			break;
		default:
			exitProgram = false;
			cout << endl << endl << setw(71) << "Introduzca una opcion correcta.";
			Sleep(1200);
			break;
		}
	} while (!exitProgram);
}

int main() {
	cargando();
	menuJuego();
}
