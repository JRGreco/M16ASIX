#include "EnemigoFinal.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "MMSystem.h"
#include <conio.h>

void setColor2(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

using namespace std;

EnemigoFinal::EnemigoFinal(
	int pHp, string pName, int pAttack, int pAtaqueFuego, int pAtaqueRayo) : Personaje(pHp, pName, pAttack) { ataqueFuego = pAtaqueFuego; ataqueRayo = pAtaqueRayo;
}

//Getters

int EnemigoFinal::getAtaqueFuego() {
	return ataqueFuego;
}

int EnemigoFinal::getAtaqueRayo() {
	return ataqueRayo;
}

//Setters

void EnemigoFinal::setAtaqueFuego(int pAtaqueFuego) {
	ataqueFuego = pAtaqueFuego;
}

void EnemigoFinal::setAtaqueRayo(int pAtaqueRayo) {
	ataqueRayo = pAtaqueRayo;
}

//Metodos propios

void EnemigoFinal::printEnemyFinalStats() {
	setColor2(3);
	cout << endl << setw(61) << getName() << endl;
	setColor2(7);
	cout << endl << setw(59) << "- Vida: " << getHp();
	cout << endl << setw(59) << "- Ataque normal: " << getAttack();
	cout << endl << setw(59) << "- Ataque fuego: " << getAtaqueFuego();
	cout << endl << setw(59) << "- Ataque rayo: " << getAtaqueRayo();
}