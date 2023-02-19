#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

//VARIABLES CARTAS
int picas[12];
int diamantes[12];
int corazones[12];
int treboles[12];

//VARIABLES DEL JUGADOR 1
string jugador1;
int puntosJ1 = 0;
bool rendirseJ1 = false;
bool ganadorJ1 = false;
bool perdedorJ1 = false;

//VARIABLES DEL CROUPIERE
string jugador2 = "Croupiere";
int puntosJ2 = 0;
bool rendirseJ2 = false;
bool ganadorJ2 = false;
bool perdedorJ2 = false;

//Funciones

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
		cout << setw(80) << LBar << endl;
		if (LCounter == 15 || LCounter == 23 || LCounter == 33 || LCounter == 42) LMessageCounter++;
	}
	Sleep(500);
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
	Sleep(400);
	cout << setw(70) << "THE DEVELOPMENT TEAM\n\n";
	Sleep(800);
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
	Sleep(600);
}

void comoSeJuega() {
	cout << endl << endl << endl;
	cout << setw(65) << "COMO SE JUEGA?" << endl << endl;
	Sleep(600);
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
	cout << "- Llega el turno del croupier, que tiene que al menos mejorar la puntuacion del jugador, sin pasarse de 21." << endl << endl;
	Sleep(600);
	cout << "- Si la mejora sin pasarse gana el croupier." << endl << endl;
	Sleep(600);
	cout << "- Si se pasa de 21, pierde el croupier." << endl << endl;
	Sleep(600);
	cout << "\t- Si el jugador alcanza los 21 puntos." << endl << endl;
	Sleep(600);
	cout << "- Llega el turno del croupier, que tiene que intentar llegar a 21 obligatoriamente." << endl << endl;
	Sleep(600);
	cout << "- Si llega a 21, el jugador y el croupier empatan." << endl << endl;
	Sleep(600);
	cout << "- Si se pasa de 21, el croupier pierde." << endl;
	Sleep(600);
}

void iniciarArray(int(&array)[12]) {
	for (int i = 0; i < 12; i++) {
		array[i] = 1;
	}
}

void escogerCartas(int& puntosTotales, string jugador) {
	boolean elegido = false;
	string tipoCarta;
	int paloCarta = 0, valorCarta = 0, indiceCarta = 0;

	while (!elegido) {
		srand(time(NULL));

		paloCarta = 1 + rand() % 4; //Genera un nº del 1 al 4 que definirá que tipo de carta es
		indiceCarta = rand() % 12; //Genera un nº del 0 al 12 que indicará la posición del array que ocupará
		valorCarta = indiceCarta + 1;

		//Si el palo Carta es 1 se ejecutará las Picas
		if (paloCarta == 1) {
			tipoCarta = "Picas";
			if (picas[indiceCarta] == 1) {
				picas[indiceCarta] = 0;
				elegido = true;
			}
		}
		//Si el palo Carta es 2 se ejecutará los Diamantes
		else if (paloCarta == 2) {
			tipoCarta = "Diamantes";
			if (diamantes[indiceCarta] == 1) {
				diamantes[indiceCarta] = 0;
				elegido = true;
			}
		}
		//Si el palo Carta es 3 se ejecutará los Corazones
		else if (paloCarta == 3) {
			tipoCarta = "Corazones";
			if (corazones[indiceCarta] == 1) {
				corazones[indiceCarta] = 0;
				elegido = true;
			}

		}
		//Si el palo Carta es 4 se ejecutará los Tréboles
		else if (paloCarta == 4) {
			tipoCarta = "Treboles";
			if (treboles[indiceCarta] == 1) {
				treboles[indiceCarta] = 0;
				elegido = true;
			}
		}
		else {
			elegido = false;
		}

	}
	puntosTotales += valorCarta;
	cout << endl << "El jugador " << jugador << " ha sacado un " << valorCarta << " de " << tipoCarta << ". Tiene un total de " << puntosTotales;
	//En caso de que salga J, Q o K
	/*
	if (indiceCarta == 10) {
		valorCarta = 10;
		puntosTotales += valorCarta;
		cout << endl << "El jugador " << jugador << " ha sacado una J de " << tipoCarta << ". Tiene un total de " << puntosTotales;
	}
	else if (indiceCarta == 11) {
		valorCarta = 10;
		puntosTotales += valorCarta;
		cout << endl << "El jugador " << jugador << " ha sacado una Q de " << tipoCarta << ". Tiene un total de " << puntosTotales;
	}
	else if (indiceCarta == 12) {
		valorCarta = 10;
		puntosTotales += valorCarta;
		cout << endl << "El jugador " << jugador << " ha sacado una K de " << tipoCarta << ". Tiene un total de " << puntosTotales;
	}
	else {
		puntosTotales += valorCarta;
		cout << endl << "El jugador " << jugador << " ha sacado un " << valorCarta << " de " << tipoCarta << ". Tiene un total de " << puntosTotales;
	}
	*/
}

/*
bool comprobarPuntos(int& puntos, bool& ganador, bool& perdedor) {
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

bool comprobarGanador(int puntosJ1, int puntosJ2, bool& ganadorJ2) {
	if (puntosJ2 > puntosJ1) {
		ganadorJ2 = true;
		return true;
	}
	else {
		return false;
	}
}
*/

bool comprobarPuntosJ1() {
	if (puntosJ1 == 21) {
		ganadorJ1 = true;
		return true;
	}
	else if (puntosJ1 > 21) {
		perdedorJ1 = true;
		return true;
	}
	return false;
}

bool comprobarPuntosJ2() {
	if (puntosJ2 == 21) {
		ganadorJ2 = true;
		return true;
	}
	else if (puntosJ2 > 21) {
		perdedorJ2 = true;
		return true;
	}
	return false;
}

bool comprobarGanador(int puntosJ1, int puntosJ2, bool& ganadorJ2) {
	//Si los puntos de la banca es igual o inferior a 21 pero es superior a los puntos del jugador1
	if ((puntosJ2 <= 21) && (puntosJ2 > puntosJ1)) {
		ganadorJ2 = true;
		return true;
	}
	else {
		return false;
	}
}

void reiniciarPuntos() {
	if ((ganadorJ1 = true) || (ganadorJ2 = true)) {
		puntosJ1 = 0, puntosJ2 = 0;
	}
}

void jugar() {

	//Reiniciamos los puntos a 0 si se vuelve a jugar
	reiniciarPuntos();

	//Iniciar los arrays de las cartas a 1
	iniciarArray(picas);
	iniciarArray(diamantes);
	iniciarArray(corazones);
	iniciarArray(treboles);

	//Introducción

	cout << endl << "Introduce tu nombre jugador: ";
	cin >> jugador1;

	//Reparto de las primeras cartas (El jugador 1 se le reparten dos cartas)
	Sleep(100);
	escogerCartas(puntosJ1, jugador1);
	Sleep(100);
	escogerCartas(puntosJ1, jugador1);
	Sleep(100);

	//Comprobar si nada más empezar el jugador gana o pierde
	rendirseJ1 = comprobarPuntosJ1();
	Sleep(100);

	//Reparto carta para el Croupiuere
	escogerCartas(puntosJ2, jugador2);
	Sleep(100);

	//Turno jugador 1

	while (!rendirseJ1) {
		Sleep(1000);
		//Menú para elegir más cartas
		int eleccion = 0;
		boolean elegirCartaValido;
		do {
			cout << endl << endl << "Tienes " << puntosJ1 << " puntos. Quieres pedir mas cartas?" << endl << endl;
			cout << "[1] Si" << endl;
			cout << "[2] No" << endl;
			cin >> eleccion;
			switch (eleccion) {
			case 1:
				elegirCartaValido = true;
				escogerCartas(puntosJ1, jugador1);
				Sleep(1000);
				break;
			case 2:
				elegirCartaValido = true;
				rendirseJ1 = true;
				Sleep(1000);
				break;
			default:
				elegirCartaValido = false;
				cout << endl << "Elige una opcion correcta." << endl;
				Sleep(1000);
				break;
			}
		} while (!elegirCartaValido);
	}

	if (ganadorJ1) {
		cout << endl << "El jugador " << jugador1 << " gana y la banca pierde" << endl;
		Sleep(1000);
	}
	else if (perdedorJ1) {
		cout << endl << "El jugador " << jugador1 << " pierde y la banca " << endl;
		Sleep(1000);
	}
	else {
		Sleep(1000);
		//Turno de la banca (groupiere)
		while (!rendirseJ2) {
			Sleep(1000);
			escogerCartas(puntosJ2, jugador2);
			Sleep(1000);
			rendirseJ2 = comprobarPuntosJ2();
			if (!rendirseJ2) {
				rendirseJ2 = comprobarGanador(puntosJ1, puntosJ2, ganadorJ2);
			}
		}
		if (ganadorJ2) {
			cout << endl << "La banca gana (" << jugador2 << ") y el jugador " << jugador1 << " pierde." << endl;
			Sleep(1000);
		}
		else if (perdedorJ2) {
			cout << endl << "La banca pierde (" << jugador2 << ") y el jugador " << jugador1 << " gana." << endl;
			Sleep(1000);
		}
	}
}

int main() {
	//	cargando();
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
		//Limpiar consola anterior
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
