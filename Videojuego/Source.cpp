#include <iostream>
#include <windows.h>
#include "MMSystem.h"

using namespace std;

//Booleans
bool ataqueValido, enemigoVivo, enemigoValido;

//Atributos del enemigo 1
int enemyHP = 15;
string enemyName = "Sauron";
bool enemyIsAlive = true;

//Atributos del enemigo 2
int enemyHP2 = 25;
string enemyName2 = "Korpos";
bool enemyIsAlive2 = true;

//Atrbutos del personaje
int heroHP = 2;
string heroName;
bool heroIsAlive = true;

bool victoria = true;

//Ataques del personaje
char optionAttack, optionEnemy;
int patada = 10, espada = 20, magia = 35;
int ataquesDisponiblesMagia = 1;

void startGame() {
	//Texto de introducción
	PlaySound(TEXT("inicioPelea.wav"), NULL, SND_SYNC); //Reproduce el sonido del inicio de la pelea
	cout << "Han aparecido los enemigos " << enemyName << " y " << enemyName2;
	Sleep(150);
	cout << "\nIntroduce el nombre del guerrero: ";
	cin >> heroName;
	Sleep(750);
	cout << "El enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida.\n";
	Sleep(750);
	cout << "El enemigo " << enemyName2 << " tiene " << enemyHP2 << " puntos de vida.\n";
	Sleep(750);
	cout << "El guerrero " << heroName << " tiene " << heroHP << " puntos de vida.\n\n";
}

bool checkEnemyIsAlive() {
	//Comprobar si el enemigo 1 está muerto
	if (enemyHP <= 0) {
		enemyHP = 0;
		cout << "\nEl enemigo " << enemyName << " ha muerto.";
		return false;
	}
	else {
		return true;
	}
}

bool checkEnemyIsAlive2() {
	//Comprobar si el enemigo 2 está muerto
	if (enemyHP2 <= 0) {
		enemyHP2 = 0;
		cout << "\nEl enemigo " << enemyName2 << " ha muerto.";
		return false;
	}
	else {
		return true;
	}
}

int attackEnemy1() {
	//Ataque del enemigo 1 si está vivo
	int enemyDamage = rand() % (25 - 0);
	if (enemyHP > 1) {
		Sleep(550);
		cout << "\nEl enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida.";
		if (heroHP > 1) {
			Sleep(550);
			cout << "\nEl enemigo " << enemyName << " te ha atacado. Te ha quitado " << enemyDamage << " puntos de vida. Actualmente tienes " << heroHP << " puntos de vida.";
		}
	}
	return heroHP - enemyDamage;
}

int attackEnemy2() {
	//Ataque del enemigo 2 si está vivo
	int enemyDamage = rand() % (25 - 0);
	if (enemyHP2 > 1) {
		Sleep(550);
		cout << "\nEl enemigo " << enemyName2 << " tiene " << enemyHP2 << " puntos de vida.";
		if (heroHP > 1) {
			Sleep(550);
			cout << "\nEl enemigo " << enemyName2 << " te ha atacado. Te ha quitado " << enemyDamage << " puntos de vida. Actualmente tienes " << heroHP << " puntos de vida.";
		}
	}
	return heroHP - enemyDamage;
}

void optionAttackEnemy1() {
	enemigoVivo = true;
	enemigoValido = true;
	do {

		//Menú de opciones de ataques disponibles del jugador
		Sleep(750);
		cout << "\n\nIntroduce el tipo de ataque que quieres realizar al enemigo: ";
		cin >> optionAttack;

		switch (optionAttack) {
		case '1':
			Sleep(600);
			PlaySound(TEXT("patada.wav"), NULL, SND_SYNC); //Reproduce el sonido de una patada
			enemyHP = enemyHP - patada;
			ataqueValido = true;
			break;
		case '2':
			Sleep(600);
			PlaySound(TEXT("espada.wav"), NULL, SND_SYNC); //Reproduce el sonido de una espada
			enemyHP = enemyHP - espada;
			ataqueValido = true;
			break;
		case '3':
			ataqueValido = true;
			if (ataquesDisponiblesMagia == 1) {
				PlaySound(TEXT("magia.wav"), NULL, SND_SYNC); //Reproduce el sonido de magia
				ataquesDisponiblesMagia = ataquesDisponiblesMagia - 1;
				enemyHP = enemyHP - magia;
			}
			else {
				Sleep(750);
				cout << "\nNo te quedan ataques de magia";
			}
			break;
		default:
			//En caso de que el jugador introduzca otro ataque no registrado se le indicará que introduzca uno válido
			ataqueValido = false;
			Sleep(750);
			cout << "\nEl ataque introducido es incorrecto. Introduce un ataque válido.";
		}
	} while (!ataqueValido);
}

void optionAttackenemy2() {
	enemigoVivo = true;
	enemigoValido = true;
	do {
		//Menú de opciones de ataques disponibles del jugador
		Sleep(750);
		cout << "\n\nIntroduce el tipo de ataque que quieres realizar al enemigo: ";
		cin >> optionAttack;

		switch (optionAttack) {
		case '1':
			Sleep(600);
			PlaySound(TEXT("patada.wav"), NULL, SND_SYNC); //Reproduce el sonido de una patada
			enemyHP2 = enemyHP2 - patada;
			ataqueValido = true;
			break;
		case '2':
			Sleep(600);
			PlaySound(TEXT("espada.wav"), NULL, SND_SYNC); //Reproduce el sonido de una espada
			enemyHP2 = enemyHP2 - espada;
			ataqueValido = true;
			break;
		case '3':
			ataqueValido = true;
			if (ataquesDisponiblesMagia == 1) {
				Sleep(600);
				PlaySound(TEXT("magia.wav"), NULL, SND_SYNC); //Reproduce el sonido de magia
				ataquesDisponiblesMagia = ataquesDisponiblesMagia - 1;
				enemyHP2 = enemyHP2 - magia;
			}
			else {
				Sleep(750);
				cout << "\nNo te quedan ataques de magia";
			}
			break;
		default:
			//En caso de que el jugador introduzca otro ataque no registrado se le indicará que introduzca uno válido
			ataqueValido = false;
			Sleep(750);
			cout << "\nEl ataque introducido es incorrecto. Introduce un ataque válido.\n";
		}
	} while (!ataqueValido);
}

void optionEnemys() {
	//En caso de que el guerrero esté vivo se ejecutará
	heroIsAlive = true;
	enemigoValido = true;
	do {
		Sleep(750);
		cout << "\nElige al enemigo que quieres atacar: (1) " << enemyName << " o (2) " << enemyName2 << ": ";
		cin >> optionEnemy;
		enemigoVivo = true;

		switch (optionEnemy) {
			//En caso de que el jugador elija atacar a Sauron se ejecutará lo siguiente
		case '1':
			if (enemyIsAlive == false) {
				enemigoVivo = false;
				cout << "\nEl enemigo " << enemyName << " está muerto. Debes eleguir otro enemigo.\n";
			}
			else {
				//En caso de que el enemigo Sauron se encuentre vivo ejecutará
				Sleep(750);
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de daño. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de daño. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de daño, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
				optionAttackEnemy1();
			}
			break;
			//En caso de que el jugador elija atacar a Korpos se ejecutará lo siguiente
		case '2':
			//Si el enemigo Korpos está muerto le aparecerá un mensaje al jugador indicando que debe escoger otro enemigo 
			if (enemyIsAlive2 == false) {
				enemigoVivo = false;
				Sleep(750);
				cout << "\nEl enemigo " << enemyName2 << " esta muerto. Debes elegir otro enemigo.\n";
			}
			else {
				//En caso de que el enemigo Korpos se encuentre vivo se ejecutará
				Sleep(750);
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de daño. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de daño. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de daño, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
				optionAttackenemy2();
				break;
			}
		default:
			enemigoValido = false;
			Sleep(750);
			cout << "\nEl enemigo que has introducido es incorrecto. Vuelve a introducir un enemigo correcto.\n";
		}
	} while ((!enemigoVivo) || (!enemigoValido));
}

int main() {
	startGame();

	while ((heroIsAlive) && (enemyIsAlive || enemyIsAlive2)) {

		enemyIsAlive = checkEnemyIsAlive();
		enemyIsAlive2 = checkEnemyIsAlive2();

		//Si los enemigos están muertos el juego se acaba
		if ((enemyIsAlive == false) && (enemyIsAlive2 == false)) {
			cout << "\nEl juego se ha acabado. Ha ganado el guerrero " << heroName << "\n\n";
			PlaySound(TEXT("victoria.wav"), NULL, SND_SYNC); //Reproduce el sonido de victoria
			break;
		}

		//Comprobar si el guerrero está muerto
		if ((heroHP <= 0) && (victoria)) {
			heroHP = 0;
			heroIsAlive = false;
			cout << "\n\nTe han atacatado y te has quedado sin vida. El guerrero " << heroName << " ha muerto.";
			cout << "\nEl juego se ha acabado. Han ganado los enemigos " << enemyName << " y " << enemyName2 << "\n\n";
			PlaySound(TEXT("derrota.wav"), NULL, SND_SYNC); //Reproduce el sonido de derrota
			break;
		}
		else {
			optionEnemys();
		}
		heroHP = attackEnemy1();
		heroHP = attackEnemy2();
	}
	return 0;
}