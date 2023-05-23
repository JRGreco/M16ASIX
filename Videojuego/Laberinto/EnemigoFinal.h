#pragma once
#include "Personaje.h"

using namespace std;

class EnemigoFinal :

	public Personaje {

private:
	int ataqueFuego;
	int ataqueRayo;
public:

	//Constructor con los elementos heredades de Personaje con el nuevo

	EnemigoFinal(int pHp, string pName,int pAttack, int pAtaqueFuego, int pAtaqueRayo);

	//Getters

	int getAtaqueFuego();
	int getAtaqueRayo();

	//Setters

	void setAtaqueFuego(int pAtaqueFuego);
	void setAtaqueRayo(int pAtaqueRayo);

	//Metodos propios

	void printEnemyFinalStats();
};