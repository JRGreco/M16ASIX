#include "lanchas.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "MMSystem.h"

using namespace std;

int turnos = 5;
int dado = 0;

lancha lancha1("Jeremy", 0, 0, 1), lancha2("IA", 0, 0, 1); //Creacion de los objetos

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
		Sleep(110);
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

	cout << setw(61) << " _                      _" << endl;
	cout << setw(71) << "| |  __ _   _ _    __  | |_    __ _" << endl;
	cout << setw(72) << "| | / _` | | ' \\  / _| | ' \\  / _` |" << endl;
	cout << setw(72) << "|_| \\__,_| |_||_| \\__| |_||_| \\__,_|" << endl;
}

void introduccion() {
	cout << setw(63) << endl << "BIENVENIDOS" << endl << endl << endl;
	lancha1.printLanchaStats();
	cout << endl << endl;
	lancha2.printLanchaStats();
	Sleep(800);
}

void finDeJuego() {
	cout << endl << endl << endl;

	cout << setw(67) << "THE DEVELOPMENT TEAM" << endl << endl;
	Sleep(1000);
	cout << setw(63) << "Programador" << endl << endl;
	Sleep(800);
	cout << setw(74) << "Jeremy Joel Rodriguez Chapilliquen" << endl << endl << endl;
	Sleep(800);
	cout << setw(66) << "Diseno del juego" << endl << endl;
	cout << setw(74) << "Jeremy Joel Rodriguez Chapilliquen" << endl << endl << endl;
	Sleep(800);
	cout << setw(69) << "GRACIAS POR SU TIEMPO" << endl << endl << endl;
}

void comoSeJuega() {
	cout << endl << endl << endl;
	cout << setw(60) << "COMO SE JUEGA" << endl << endl;
	Sleep(1000);
	cout << setw(25) << "- Hay 5 turnos para" << setw(1) << " cada jugador. Al comenzar la carrera, la velocidad y la distancia seran 0 y " << endl << setw(22) << "se dispondra 1" << setw(1) << " nitro disponible." << endl << endl;
	Sleep(800);
	cout << setw(22) << "- Cada turno, el" << setw(1) << " jugador lanzara un dado, pudiendo obtener de 1 a 6 puntos por tirada." << endl << endl;
	Sleep(800);
	cout << setw(18) << "- Cada lanza" << setw(1) << "miento del dado se añadira a la velocidad de la lancha.Es decir, si en el turno 3 la " << endl << setw(17) << "velocidad" << setw(1) << " es de 15 y el jugador obtiene un 5, su velocidad pasara a 20." << endl <<endl;
	Sleep(800);
	cout << setw(17) << "- La nitro," << setw(1) << " se podra usar, si se quiere, en cualquiera de los turnos despues del calculo de la " << endl << setw(18) << "velocidad." << setw(1) << " Solo podra usarse una vez, y al hacerlo, se ejecutara un numero aleatorio entre 0 y 1." << endl << setw(18) << "Si sale 0," << setw(1) << " la velocidad TOTAL tendra que dividirse por la mitad.Si sale 1, la velocidad TOTAL" << endl << setw(10) << " se" << setw(1)<< " multiplicara por dos." << endl << endl;
	Sleep(800);
	cout << setw(19) << "- Al terminar" << setw(1) << " el 5to turno, se comprobara que jugador ha ganado." << endl << endl;
	Sleep(7000);
}

void comprobarGanador() {
	system("cls");
	Sleep(500);
	if (lancha1.getDistanciaRecorrida() > lancha2.getDistanciaRecorrida()) {
		cout << setw(65) << endl << endl << endl << "Ha ganado el jugador " << lancha1.getPlayerName();
	}
	else if (lancha1.getDistanciaRecorrida() == lancha2.getDistanciaRecorrida()) {
		cout << setw(62) << endl << endl << endl << "Hay empate.";
	}
	else {
		cout << setw(65) << endl << endl << endl << "Ha ganado el jugador " << lancha2.getPlayerName();
	}
}

void mostrarStatsFinal() {
	Sleep(600);
	cout << setw(50) << endl << endl <<  endl << "Los resultados" << setw(1) << " finales son los siguientes:" << endl << endl;
	lancha1.printLanchaStats();
	Sleep(600);
	cout << endl;
	lancha2.printLanchaStats();
	Sleep(600);
}

void jugar() {

	introduccion();

	Sleep(700);
	system("cls");
	for (int i = 0; i < turnos; i++)
	{
		Sleep(600);

		//Turno jugador 1
		cout << setw(50) << endl << endl << endl << "Turno jugador: " << lancha1.getPlayerName() << ". Se lanzara un dado." << endl;
		Sleep(800);
		dado = 1 + rand() % 6; //Lanzará un dado del 1 al 6		
		cout << setw(60) << endl << "Ha sacado un " << dado << endl;

		int escogerNitro = 0;
		if (lancha1.getNitro() == 1) {
			cout << setw(81) << endl << "Tienes el nitro disponible. Deseas utilizarlo?" << endl << endl;
			cout << setw(55) << "[1] Si" << endl;
			cout << setw(55) << "[2] No" << endl;
			cout << setw(60) << "Introduce una opcion: ";
			cin >> escogerNitro;
			int nitroAleatorio1 = 0, resultadoVel1Nitro = 0;

			switch (escogerNitro) {
			case 1:
				Sleep(500);
				nitroAleatorio1 = rand() % 2; //escogera un valor aleatorio entre 0 y 1
				lancha1.setNitro(0);
				//Si sale 0 la velocidad se multiplica * 2
				if (nitroAleatorio1 == 0) { 
					resultadoVel1Nitro = dado * 2;
					dado = dado * 2;
					cout << setw(40) << endl << "Se ha utilizado" << setw(1) << " el nitro. Ha salido ganando. Su velocidad se multiplicara por 2." << endl;
					cout << setw(38) << "Se multiplica" << setw(1) << " por 2 y obtiene una velocidad total de " << resultadoVel1Nitro << endl;
					Sleep(800);
				}
				//Si sale 1 la velocidad se divide entre 2
				else {
					resultadoVel1Nitro = dado / 2;
					dado = dado / 2;
					cout << setw(40) << endl << "Se ha utilizado" << setw(1) << " el nitro. Ha salido perdiendo. Su velocidad se dividira entre 2. " << endl;
					cout << setw(38) << "Se divide" << setw(1) << " entre 2 y obtiene una velocidad total de " << resultadoVel1Nitro << endl;
					Sleep(800);
				}
				break;
			case 2:
				Sleep(500);
				break;
			default:
				Sleep(500);
				break;
			}
		}

		lancha1.setVelocidad(dado);
		Sleep(500);
		lancha1.calcularDistancia();
		Sleep(800);
		cout << setw(42) << endl << "La distancia" << setw(1) << " actual de su jugador " << lancha1.getPlayerName() << " es " << lancha1.getDistanciaRecorrida() << " metros." << endl;
		Sleep(1600);
		system("cls");

		//Turno jugador 2
		cout <<setw(50) << endl << endl << endl << "Turno jugador: " << lancha2.getPlayerName() << ". Se lanzara un dado." << endl;
		Sleep(800);
		dado = 1 + rand() % 6; //Lanzará un dado del 1 al 6		
		cout << setw(60) << endl << "Ha sacado un " << dado << endl;

		if (lancha2.getNitro() == 1) {

			int nitroAleatorio2 = 0, resultadoVel2Nitro = 0;

			nitroAleatorio2 = rand() % 2; //Si sale 0 IA usara el nitro, si sale 1 no lo usará

			if (nitroAleatorio2 == 0) {
				lancha2.setNitro(0);
				resultadoVel2Nitro = dado * 2;
				dado = dado * 2;
				cout << setw(40) << endl << "Se ha utilizado" << setw(1) << " el nitro. Ha salido ganando. Su velocidad se multiplicara por 2." << endl;
				cout << setw(38) << "Se multiplica" << setw(1) << " por 2 y obtiene una velocidad total de " << resultadoVel2Nitro << endl;
				Sleep(800);
			}
			else if (nitroAleatorio2 == 1) {
				resultadoVel2Nitro = dado / 2;
				dado = dado / 2;
				cout << setw(40) << endl << "Se ha utilizado " << setw(1) << " el nitro. Ha salido perdiendo. Su velocidad se dividira entre 2. " << endl;
				cout << setw(38) << "Se divide " << setw(1) << " entre 2 y obtiene una velocidad total de " << resultadoVel2Nitro << endl;
				Sleep(800);
			}
		} 

		lancha2.setVelocidad(dado);
		Sleep(500);
		lancha2.calcularDistancia();
		Sleep(800);
		cout << setw(42) << endl << "La distancia" << setw(1) << " actual del jugador " << lancha2.getPlayerName() << " es " << lancha2.getDistanciaRecorrida() << " metros." << endl;
		Sleep(1600);
		system("cls");
	}

	comprobarGanador();
	mostrarStatsFinal();

	Sleep(2000);
}

void gameMenu() {
	boolean exitProgram;

	do {
		textoLogo();
		cout << endl << endl << endl;
		cout << setw(65) << "[0] Salir del programa" << endl;
		cout << setw(61) << "[1] Como se juega?" << endl;
		cout << setw(52) << "[2] Jugar" << endl << endl;
		cout << setw(64) << "Introduce una opcion: ";
		int option;
		cin >> option;
		system("cls");

		switch (option) {
		case 0:
			exitProgram = true;
			finDeJuego();
			break;
		case 1:
			exitProgram = false;
			comoSeJuega();
			break;
		case 2:
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

	srand(time(NULL));

	cargando();

	gameMenu();

	return 0;
}

