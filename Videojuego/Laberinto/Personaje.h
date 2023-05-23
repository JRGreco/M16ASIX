#pragma once
#include <iostream>

using namespace std;

class Personaje {
private:
	int hp;
	string name;
	int attack;
public:

	//constructor
	Personaje(int pHp, string pName, int pAttack);

	//getters
	int getHp();

	string getName();

	int getAttack();

	//setters

	void setHp(int php);

	void setName(string pname);

	void setAttack(int pattack);

	//metodos propios

	void printStatus();
	void printEnemyStatus();

};