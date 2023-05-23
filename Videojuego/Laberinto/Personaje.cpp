#pragma once
#include "Personaje.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "MMSystem.h"
#include <conio.h>



void setColor1(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

using namespace std;

//constructor
Personaje::Personaje(int pHp, string pName, int pAttack) {
	hp = pHp;
	name = pName;
	attack = pAttack;
}

//getters
int Personaje::getHp() {
	return hp;
}

string Personaje::getName() {
	return name;
}

int Personaje::getAttack() {
	return attack;
}



//setters

void Personaje::setHp(int php) {
	hp = php;
}

void Personaje::setName(string pname) {
	name = pname;
}

void Personaje::setAttack(int pattack) {
	attack = pattack;
}


//Metodos propios

void Personaje::printStatus() {


	setColor1(3);
	cout << endl << setw(61) << getName() << endl;
	setColor1(7);
	cout << endl << setw(59) << " - Vida: " << getHp();
	cout << endl << setw(61) << " - Ataque: " << getAttack();
}

void Personaje::printEnemyStatus() {
	
	setColor1(4);
	cout << endl << setw(61) << getName() << endl;
	setColor1(7);
	cout << endl << setw(59) << " - Vida: " << getHp();
	cout << endl << setw(61) << " - Ataque: " << getAttack() << endl;
}
