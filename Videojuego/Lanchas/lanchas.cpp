#include "lanchas.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "MMSystem.h"

using namespace std;

//constructor

lancha::lancha(string pPlayerName, int pVelocidad, int pDistanciaRecorrida, int pNitro) {
	playerName = pPlayerName;
	velocidad = pVelocidad;
	distanciaRecorrida = pDistanciaRecorrida;
	nitro = pNitro;
}

//getters

string lancha::getPlayerName() {
	return playerName;
}

int lancha::getVelocidad() {
	return velocidad;
}

int lancha::getDistanciaRecorrida() {
	return distanciaRecorrida;
}

int lancha::getNitro() {
	return nitro;
}

//setters

void lancha::setPlayerName(string pPlayerName) {
	playerName = pPlayerName;
}

void lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}

void lancha::setDistanciaRecorrida(int pDistanciaRecorrida) {
	distanciaRecorrida = pDistanciaRecorrida;
}

void lancha::setNitro(int pNitro) {
	nitro = pNitro;
}

//metodos

void lancha::printLanchaStats() {
	cout << setw(60) << "Jugador: " << playerName << "." << endl;
	Sleep(300);
	cout << setw(60) << "Velocidad: " << velocidad << "." << endl;
	Sleep(300);
	cout << setw(60) << "Distancia recorrida: " << distanciaRecorrida << " metros." << endl;
	Sleep(300);
	cout << setw(60) << "Nitro: " << nitro << "." << endl;
	Sleep(300);
}

void lancha::calcularDistancia() {
	distanciaRecorrida = distanciaRecorrida + velocidad * 100;
}