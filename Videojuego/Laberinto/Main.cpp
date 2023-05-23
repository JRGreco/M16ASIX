#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <string>
#include "MMSystem.h"
#include <conio.h>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

//Tamaño del mapa
const int FILAS = 15;
const int COLUMNAS = 45;

//Creacion de los objetos
Personaje E1(50, "Alien", 25), E2(60, "Bowser", 30), E3(70, "Pyramid", 30), E4(80, "Dracula", 35), Hero(400, "Jeremy", 20);
EnemigoFinal Doraemon(300, "Doraemon", 35, 40, 45);


void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void logo() {
	cout << endl << endl;
	cout << string(50, ' ') << R"(
			####       ##      ######   #######  ######    ####    ##   ##  ######    #####
			##        ####     ##  ##   ##   #   ##  ##     ##     ###  ##  # ## #   ##   ##
			##       ##  ##    ##  ##   ## #     ##  ##     ##     #### ##    ##     ##   ##
			##       ##  ##    #####    ####     #####      ##     ## ####    ##     ##   ##
			##   #   ######    ##  ##   ## #     ## ##      ##     ##  ###    ##     ##   ##
			##  ##   ##  ##    ##  ##   ##   #   ##  ##     ##     ##   ##    ##     ##   ##
			#######  ##  ##    ######   #######  #### ##   ####    ##   ##   ####     #####



)" << endl;
}

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

void iniciarPGs() {

	cout << setw(63) << endl << endl << "BIENVENIDO" << endl << endl;
	Hero.printStatus();

	cout << endl << endl;
	E1.printEnemyStatus();
	E2.printEnemyStatus(); 
	E3.printEnemyStatus();
	E4.printEnemyStatus();

	Sleep(6000);
}

void dibujarMapa(char mapa[FILAS][COLUMNAS]) {
	cout << endl << endl << endl << endl << endl;
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			cout << setw(2) << mapa[i][j];
		}
		cout << endl;
	}
}

void normas() {
	cout << endl << endl << endl;
	Sleep(1200);
	cout << endl << string(55, ' ') << "NORMAS" << endl;
	Sleep(1200);
	cout << endl << string(15, ' ') << "Eres el personaje 'o', te encuentras en un laberinto en el cual se encuentran 4 enemigos " << endl << string(15, ' ') << "repartidos por todo el laberinto aleatoriamente.";
	Sleep(1200);
	cout << endl << endl << string(15, ' ') << "Te tienes que mover con las teclas (W A S D) para ir para delante, atras, izquierda o derecha.";
	Sleep(1200);
	cout << endl << endl << string(15, ' ') << "Al llegar a la ultima columna deberas de encontrar cual es la salida, pero cuidado, " << endl << string(15, ' ') << "en ella se encuentra el enemigo final que es mas poderoso que el resto de enemigos. ";
	Sleep(1200);
	cout << endl << endl << string(15, ' ') << "Una vez acabes con el FINAL BOSS ganaras la partida" << endl << endl;
	Sleep(2500);
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
	Sleep(1200);
	system("cls");
}

void enemigo1() {
	Sleep(1200);
	system("cls");

	if (E1.getHp() > 0) {
		setColor(4);
		cout << endl << string(40, ' ') << "Enemigo '" << E1.getName() << "' encontrado." << endl << endl;
		Sleep(1200);
		system("cls");
		while (Hero.getHp() > 0 && E1.getHp() > 0) {

			if (Hero.getHp() <= 0) {
				setColor(7);
				cout << endl << endl << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(4);
				cout << string(50, ' ') << "Ha ganado el enemigo " << E1.getName() << endl;
				setColor(7);
				cout << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
				break;
			}

			//Turno heroe
			Sleep(1200);
			setColor(7);
			cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
			setColor(3);
			cout << endl << string(40, ' ') << "El heroe " << Hero.getName() << " ataca al enemigo " << E1.getName() << endl;
			Sleep(1200);
			E1.setHp(E1.getHp() - Hero.getAttack());

			if (E1.getHp() <= 0) {
				E1.setHp(0);
			};

			Sleep(1200);
			cout << endl << string(25, ' ') << "Lanza su ataque de " << Hero.getAttack() << " de dano y al enemigo " << E1.getName() << " le quedan " << E1.getHp() << " puntos de vida." << endl << endl;
			Sleep(1200);
			
			setColor(7);
			cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
			Sleep(1200);
			system("cls");

			//Turno enemigo si sigue vivo
			if (E1.getHp() > 0) {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				setColor(4);
				cout << string(40, ' ') << "El enemigo " << E1.getName() << " ataca al heroe " << Hero.getName() << endl << endl;
				Sleep(1200);
				Hero.setHp(Hero.getHp() - E1.getAttack());
				Sleep(1200);
				cout << endl << string(25, ' ') << "Lanza su ataque de " << E1.getAttack() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				Sleep(1200);
				system("cls");
			}
			//En caso de ganar el heroe
			else {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(3);
				cout << endl << string(45, ' ') << "GANASTE al enemigo " << E1.getName() << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
			}
		}
	}
}

void enemigo2() {
	Sleep(1200);
	system("cls");

	if (E2.getHp() > 0) {
		setColor(4);
		cout << endl << endl << string(40, ' ') << "Enemigo '" << E2.getName() << "' encontrado." << endl << endl;
		Sleep(1200);
		system("cls");
		while (Hero.getHp() > 0 && E2.getHp() > 0) {

			if (Hero.getHp() <= 0) {
				setColor(7);
				cout << endl << endl << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(4);
				cout << string(50, ' ') << "Ha ganado el enemigo " << E2.getName() << endl;
				setColor(7);
				cout << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
				break;
			}

			Sleep(1200);
			setColor(7);
			cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
			setColor(3);
			cout << endl << string(40, ' ') << "El heroe " << Hero.getName() << " ataca al enemigo " << E2.getName() << endl;
			Sleep(1200);
			E2.setHp(E2.getHp() - Hero.getAttack());

			if (E2.getHp() <= 0) {
				E2.setHp(0);
			};

			Sleep(1200);
			cout << endl << string(25, ' ') << "Lanza su ataque de " << Hero.getAttack() << " de dano y al enemigo " << E2.getName() << " le quedan " << E2.getHp() << " puntos de vida." << endl << endl;
			Sleep(1200);

			setColor(7);
			cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
			Sleep(1200);
			system("cls");
			if (E2.getHp() > 0) {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				setColor(4);
				cout << string(40, ' ') << "El enemigo " << E2.getName() << " ataca al heroe " << Hero.getName() << endl << endl;
				Sleep(1200);
				Hero.setHp(Hero.getHp() - E2.getAttack());
				Sleep(1200);
				cout << endl << string(25, ' ') << "Lanza su ataque de " << E2.getAttack() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				Sleep(1200);
				system("cls");
			}
			else {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(3);
				cout << endl << string(45, ' ') << "GANASTE al enemigo " << E2.getName() << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
			}
		}
	}
}

void enemigo3() {
	Sleep(1200);
	system("cls");

	if (E3.getHp() > 0) {
		setColor(4);
		cout << endl << endl << string(40, ' ') << "Enemigo '" << E3.getName() << "' encontrado." << endl << endl;
		Sleep(1200);
		system("cls");
		while (Hero.getHp() > 0 && E3.getHp() > 0) {

			if (Hero.getHp() <= 0) {
				setColor(7);
				cout << endl << endl << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(4);
				cout << string(50, ' ') << "Ha ganado el enemigo " << E3.getName() << endl;
				setColor(7);
				cout << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
				break;
			}

			Sleep(1200);
			setColor(7);
			cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
			setColor(3);
			cout << endl << string(40, ' ') << "El heroe " << Hero.getName() << " ataca al enemigo " << E3.getName() << endl;
			Sleep(1200);
			E3.setHp(E3.getHp() - Hero.getAttack());

			if (E3.getHp() <= 0) {
				E3.setHp(0);
			};

			Sleep(1200);
			cout << endl << string(25, ' ') << "Lanza su ataque de " << Hero.getAttack() << " de dano y al enemigo " << E3.getName() << " le quedan " << E3.getHp() << " puntos de vida." << endl << endl;
			Sleep(1200);

			setColor(7);
			cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
			Sleep(1200);
			system("cls");
			if (E3.getHp() > 0) {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				setColor(4);
				cout << string(40, ' ') << "El enemigo " << E3.getName() << " ataca al heroe " << Hero.getName() << endl << endl;
				Sleep(1200);
				Hero.setHp(Hero.getHp() - E3.getAttack());
				Sleep(1200);
				cout << endl << string(25, ' ') << "Lanza su ataque de " << E3.getAttack() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				Sleep(1200);
				system("cls");
			}
			else {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(3);
				cout << endl << string(45, ' ') << "GANASTE al enemigo " << E3.getName() << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
			}
		}
	}
}

void enemigo4() {
	Sleep(1200);
	system("cls");

	if (E4.getHp() > 0) {
		setColor(4);
		cout << endl << endl << string(40, ' ') << "Enemigo '" << E4.getName() << "' encontrado." << endl << endl;
		Sleep(1200);
		system("cls");
		while (Hero.getHp() > 0 && E4.getHp() > 0) {

			if (Hero.getHp() <= 0) {
				setColor(7);
				cout << endl << endl << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(4);
				cout << string(50, ' ') << "Ha ganado el enemigo " << E4.getName() << endl;
				setColor(7);
				cout << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
				break;
			}

			Sleep(1200);
			setColor(7);
			cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
			setColor(3);
			cout << endl << string(40, ' ') << "El heroe " << Hero.getName() << " ataca al enemigo " << E4.getName() << endl;
			Sleep(1200);
			E4.setHp(E4.getHp() - Hero.getAttack());

			if (E4.getHp() <= 0) {
				E4.setHp(0);
			};

			Sleep(1200);
			cout << endl << string(25, ' ') << "Lanza su ataque de " << Hero.getAttack() << " de dano y al enemigo " << E4.getName() << " le quedan " << E4.getHp() << " puntos de vida." << endl << endl;
			Sleep(1200);

			setColor(7);
			cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
			Sleep(1200);
			system("cls");
			if (E4.getHp() > 0) {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				setColor(4);
				cout << string(40, ' ') << "El enemigo " << E4.getName() << " ataca al heroe " << Hero.getName() << endl << endl;
				Sleep(1200);
				Hero.setHp(Hero.getHp() - E4.getAttack());
				Sleep(1200);
				cout << endl << string(25, ' ') << "Lanza su ataque de " << E4.getAttack() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				Sleep(1200);
				system("cls");
			}
			else {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(3);
				cout << endl << string(45, ' ') << "GANASTE al enemigo " << E4.getName() << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(1500);
			}
		}
	}
}

void finalBoss(){
	Sleep(1200);
	system("cls");
	cout << endl << endl;
	Doraemon.printEnemyFinalStats();
	Sleep(2000);
	if (Doraemon.getHp() > 0) {
		setColor(4);
		cout << endl << endl << string(40, ' ') << "FINAL BOOS '" << Doraemon.getName() << "' encontrado." << endl << endl;
		Sleep(1200);
		system("cls");
		while (Hero.getHp() > 0 && Doraemon.getHp() > 0) {

			//Comprobar si el heroe está vivo o no
			if (Hero.getHp() <= 0) {
				setColor(7);
				cout << endl << endl << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(4);
				cout << string(50, ' ') << "Ha ganado el enemigo " << Doraemon.getName() << endl;
				setColor(7);
				cout << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(4500);
				break;
			}

			//Turno heroe
			Sleep(1200);
			setColor(7);
			cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
			setColor(3);
			cout << endl << string(40, ' ') << "El heroe " << Hero.getName() << " ataca al enemigo " << Doraemon.getName() << endl;
			Sleep(1200);
			Doraemon.setHp(Doraemon.getHp() - Hero.getAttack());

			//Antes de atacar comprobará que el enemigo no tenga valores negativos de la vida, si tiene valores negativos lo pondrá en 0 para que finalice el bucle
			if (Doraemon.getHp() <= 0) {
				Doraemon.setHp(0);
			};

			Sleep(1200);
			cout << endl << string(25, ' ') << "Lanza su ataque de " << Hero.getAttack() << " de dano y al enemigo " << Doraemon.getName() << " le quedan " << Doraemon.getHp() << " puntos de vida." << endl << endl;
			Sleep(1200);

			setColor(7);
			cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
			Sleep(1200);
			system("cls");

			//Turno enemigo, atacará si está vivo
			if (E4.getHp() > 0) {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
				setColor(4);
				cout << string(40, ' ') << "El enemigo " << Doraemon.getName() << " ataca al heroe " << Hero.getName() << endl << endl;
				Sleep(1200);

				//Escogerá automaticamente que ataque realizará al enemigo
				int tipoAtaque = 1 + rand() % 3;

				if (tipoAtaque == 1) {
					Hero.setHp(Hero.getHp() - Doraemon.getAttack());
					Sleep(1200);
					if (Hero.getHp() <= 0) {
						Hero.setHp(0);
					};
					cout << endl << string(25, ' ') << "Lanza su ataque de " << Doraemon.getAttack() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
					setColor(7);
					cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
					Sleep(1200);
					system("cls");
				}
				else if (tipoAtaque == 2) {
					Hero.setHp(Hero.getHp() - Doraemon.getAtaqueFuego());
					Sleep(1200);
					if (Hero.getHp() <= 0) {
						Hero.setHp(0);
					};
					cout << endl << string(25, ' ') << "Lanza su ataque de " << Doraemon.getAtaqueFuego() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
					setColor(7);
					cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
					Sleep(1200);
					system("cls");
				}
				else {
					Hero.setHp(Hero.getHp() - Doraemon.getAtaqueRayo());
					Sleep(1200);
					if (Hero.getHp() <= 0) {
						Hero.setHp(0);
					};
					cout << endl << string(25, ' ') << "Lanza su ataque de " << Doraemon.getAtaqueRayo() << " de dano y al heroe " << Hero.getName() << " le quedan " << Hero.getHp() << " puntos de vida." << endl << endl;
					setColor(7);
					cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl << endl;
					Sleep(1200);
					system("cls");
				}
			}
			// Si el enemigo no está vivo se acabará el bucle
			else {
				cout << endl << endl << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				setColor(3);
				cout << endl << string(45, ' ') << "GANASTE al FINAL BOSS " << Doraemon.getName() << endl << endl;
				setColor(7);
				cout << string(35, ' ') << "oooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
				Sleep(4500);
				break;
			}
		}
	}
}

int mapa1() {
	char mapa[FILAS][COLUMNAS] = {
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
	{'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ',' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', '*', ' ', '*', ' ',' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', '*',' ', '*', '*', '*', '*', ' ', '*'},
	{'*', 'a', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ',' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*','*', '*', ' ', ' ', '*', ' ', '*'},
	{'*', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', ' ',' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ','*', '*', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*','*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ','*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ','*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*',' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ','*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ',' ', ' ', '*', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ','*', ' ', '*', ' ', ' ', ' ', '*'},
	{'*', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*',' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ','*', ' ', '*', ' ', '*', ' ', '*'},
	{'*', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', '*', '*', '*', '*', ' ', '*', '*', ' ', '*', ' ',' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', '*', '*', '*', ' ', ' ', '*', ' ', ' ', '*', ' ',' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ',' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', '*','*', '*', ' ', '*', '*', ' ', '*'},
	{'*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ',' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', ' ', '*', '*','*', '*', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', '*',' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*', '*', ' ',' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ',' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*',' ', '*', '*', '*', ' ', ' ', '*'},
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*',' ', ' ', ' ', ' ', ' ', ' ', '*'},
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
	};

	int posX = 1; // Posición inicial en x del personaje
	int posY = 3; // Posición inicial en y del personaje

	char tecla; mapa[posY][posX] = 'o'; // Dibujar el personaje en la posición inicial

	while (true) {
		system("cls");

		dibujarMapa(mapa);
		tecla = _getch(); 

		mapa[posY][posX] = ' '; 
		switch (tecla) {
		case 'w': // Movimiento hacia arriba 
			if (mapa[posY - 1][posX] != '*') {
				posY--;
			}
			break;
		case 's': // Movimiento hacia abajo 
			if (mapa[posY + 1][posX] != '*') {
				posY++;
			}
			break;
		case 'a': // Movimiento hacia la izquierda 
			if (mapa[posY][posX - 1] != '*') {
				posX--;
			}
			break;
		case 'd': // Movimiento hacia la derecha 
			if (mapa[posY][posX + 1] != '*') {
				posX++;
			}
			break;
		case 'q': // Salir del programa si se presiona 'q' 
			system("cls");
			return 0;
		}

		mapa[posY][posX] = 'o'; // Dibujar el personaje en la nueva posición 

		//Salida (FINAL BOSS)
		int auxPosY = 1 + rand() % 13; //Dará un numero aleatorio para que la salida sea aleatoria

		if (posX == 43 && posY == auxPosY) {
			system("cls"); 
			dibujarMapa(mapa);
			finalBoss();
			Sleep(2000);
			system("cls");
			break;
		}

		//Posicion enemigo 1
		int enemy1PosX = 2 + rand() % 12, enemy1PosY = 1 + rand() % 13;
		if (posX == enemy1PosX && posY == enemy1PosY) {
			enemigo1();
		}

		//Posicion enemigo 2
		int enemy2PosX = 13 + rand() % 22, enemy2PosY = 1 + rand() % 13;
		if (posX == enemy2PosX && posY == enemy2PosY) {
			enemigo2();
		}

		//Posicion enemigo 3
		int enemy3PosX = 23 + rand() % 32, enemy3PosY = 1 + rand() % 13;
		if (posX == enemy3PosX && posY == enemy3PosY) {
			enemigo3();
		}

		//Posicion enemigo 4
		int enemy4PosX = 33 + rand() % 42, enemy4PosY = 1 + rand() % 13;
		if (posX == enemy4PosX && posY == enemy4PosY) {
			enemigo4();
		}
	}
}

void jugar() {
	srand(time(NULL));
	iniciarPGs();
	mapa1();
}

void menuJuego() {
	boolean exitProgram;

	do {
		system("cls");
		logo();
		cout << endl << endl;
		cout << setw(68) << "[0] Salir del programa" << endl;
		cout << setw(56) << "[1] Normas" << endl;
		cout << setw(55) << "[2] Jugar" << endl << endl;
		cout << setw(67) << "Introduce una opcion: ";
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
