#pragma once
#include <iostream>

using namespace std;

class lancha {
private:
	string playerName;
	int velocidad;
	int distanciaRecorrida;
	int nitro;

public:

	//constructor
	lancha(string pPlayerName, int pVelocidad, int pDistanciaRecorrida, int pNitro);

	//getters
	string getPlayerName();
	int getVelocidad();
	int getDistanciaRecorrida();
	int getNitro();

	//setters
	void setPlayerName(string pPlayerName);
	void setVelocidad(int pVelocidad);
	void setDistanciaRecorrida(int pDistanciaRecorrida);
	void setNitro(int pNitro);

	//metodos propios
	void printLanchaStats();
	void calcularDistancia();
};