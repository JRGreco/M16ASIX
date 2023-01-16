#include <iostream>
#include <windows.h>
#include "MMSystem.h"

using namespace std;

//Validaci�n de datos
bool ataqueValido; //Boolean "ataqueValido" se utiliza para comprobar si el ataque que introduce el h�roe es uno de los que tiene el h�roe establecidos
bool enemigoVivo; //Boolean "enemigoVIvo" se utiliza para comprobar si el enemigo que introduce el h�roe se encuentra muerto a la hora de seleccionar el enemigo al cual atacar
bool enemigoValido; //Boolean "enemigoValido" se utiliza para comprobar si el enemigo que introduce el h�roe es uno de los enemigos que existe

//Atributos del enemigo 1
int enemyHP = 150; //Establecemos la vida del enemigo 1
string enemyName = "Sauron"; //Establecemos nombre al enemigo 1
bool enemyIsAlive = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el enemigo 1

//Atributos del enemigo 2
int enemyHP2 = 125; //Establecemos la vida del enemigo 2
string enemyName2 = "Korpos"; //Establecemos nombre al enemigo 2
bool enemyIsAlive2 = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el enemigo 2

//Atrbutos del personaje
int heroHP = 250; //Establecemos la vida del h�roe
string heroName; //Creamos variable heroName que la deber� inciar el propio usuario con el nombre que quiera asignarle al h�roe
bool heroIsAlive = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el h�roe

//Ataques del personaje
char optionAttack; //char optionAttack se utilizar� para que el h�roe escoja que opcion de los ataques quiere escoger
char optionEnemy; //char optionenemy se utilizar� para que el h�roe escoja que enemigo quiere atacar
int patada = 100, espada = 120, magia = 35; //Establecemos el valor de cada ataque que dispone el h�roe
int ataquesDisponiblesMagia = 1; //Indica el n� de veces que tiene disponible el ataque "magia"

//Funci�n sin retorno que inica la introducci�n del juego
void startGame() { 
	//Texto de introducci�n
	PlaySound(TEXT("inicioPelea.wav"), NULL, SND_SYNC); //Reproduce el sonido del inicio de la pelea
	cout << "Bienvenido bienaventurado a Villa Orka. \n\nEsta villa ha sido destruida por los destructores de planetas Sauron y Korpos de la galaxia N-109.\nNecesitaremos la ayuda de un gran guerrero que pueda derrotarlos y devolver la alegria y tranquilidad a la Villa.\n\nSeras capaz de derrotarlos?\n\n";
	cout << "Acaban de aparecer los enemigos " << enemyName << " y " << enemyName2; //Indica que han aparecido los enemigos
	Sleep(150); //Pausa de 150 milisegundos
	cout << "\nIntroduzca su nombre bienaventurado: "; //Texto que indica al usuario que deber� introducir un nombre al h�roe
	cin >> heroName; //Pide al usuario que introduzca un nombre al h�roe
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida.\n"; //Indica el nombre y de la vida del enemigo 1 que se enfrentar�
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El enemigo " << enemyName2 << " tiene " << enemyHP2 << " puntos de vida.\n"; //Indica el nombre y de la vida del enemigo 2 que se enfrentar�
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El guerrero " << heroName << " tiene " << heroHP << " puntos de vida.\n\n"; //Indica el nombre y de la vida del h�roe
	Sleep(750); //Pausa de 750 milisegundos
	cout << "Acaba con los enemigos!";
}

//Funci�n a trav�s de referencias que comprueba si el enemigo (1 o 2) est� vivo o no y devolver� true o false
bool checkEnemiesAreAlive(int& enemyHP, string& enemyName) {
	//Si el enemigo "x" tiene 0 menos de vida se ejecutar� lo siguiente
	if (enemyHP <= 0) {
		cout << "\nEl enemigo " << enemyName << " ha muerto."; //Texto indicando que el enemigo "x" se ha muerto.
		return false; //Devolver� false debido que el enemigo "x" ha muerto
	}
	//En caso de que el enemigo "x" est� vivo se ejecutar� lo siguiente
	else {
		return true; //Devolver� true debido que el enemigo "x" est� vivo
	}
}

//Funci�n a trav�s de referencias que devolver� la vida del h�roe despu�s del ataque del enemigo "x"
int attackEnemy(int& enemyHP, string& enemyName) {
	int enemyDamage = rand() % (25 - 0); //Variable para el ataque del enemigo que establecer� un valor aleatorio entre 0 y 25
	//Si la vida del enemigo "x" es mayor que 0 ejecutar� lo siguiente
	if (enemyHP > 0) {
		Sleep(500); //Pausa de 500 milisegundos
		cout << "\nEl enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida"; //Texto indicando cu�nta vida tiene el enmeigo "x".
		if (heroHP > 0) {
			Sleep(550); //Pausa de 550 milisegundos
			cout << "\nEl enemigo " << enemyName << " te ha atacado. Te ha quitado " << enemyDamage << " puntos de vida. Actualmente tienes " << heroHP << " puntos de vida";
		}
	}

	return heroHP - enemyDamage;
}

//Funci�n a trav�s de referencias que devolver� la vida del enemigo "x" correspondiente despu�s del ataque que le realice el h�roe
void optionAttackEnemy(int&enemyHP) {
	enemigoVivo = true;
	enemigoValido = true;
	do {

		//Men� de opciones de ataques disponibles del jugador
		Sleep(750); //Pausa de 750 milisegundos
		cout << "\n\nIntroduce el tipo de ataque que quieres realizar al enemigo: ";
		cin >> optionAttack;

		switch (optionAttack) {
		case '1':
			Sleep(600); //Pausa de 600 milisegundos
			PlaySound(TEXT("patada.wav"), NULL, SND_SYNC); //Reproduce el sonido de una patada
			enemyHP = enemyHP - patada;
			ataqueValido = true;
			break;
		case '2':
			Sleep(600); //Pausa de 600 milisegundos
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
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nNo te quedan ataques de magia";
			}
			break;
		default:
			//En caso de que el jugador introduzca otro ataque no registrado se le indicar� que introduzca uno v�lido
			ataqueValido = false;
			Sleep(750); //Pausa de 750 milisegundos
			cout << "\nEl ataque introducido es incorrecto. Introduce un ataque v�lido.";
		}
	} while (!ataqueValido);
}

//Funci�n de men� para que el h�roe elija a quian atacar
void optionEnemys() {
	//En caso de que el guerrero est� vivo se ejecutar�
	heroIsAlive = true; //Asignamos boolean como true
	enemigoValido = true; //Inicilziamos boolean como true
	do {
		Sleep(750); //Pausa de 750 milisegundos
		cout << "\nElige al enemigo que quieres atacar: (1) " << enemyName << " o (2) " << enemyName2 << ": ";
		cin >> optionEnemy;
		enemigoVivo = true;

		switch (optionEnemy) {
			//En caso de que el jugador elija atacar a Sauron se ejecutar� lo siguiente
		case '1':
			if (enemyIsAlive == false) {
				enemigoVivo = false;
				cout << "\nEl enemigo " << enemyName << " est� muerto. Debes eleguir otro enemigo.\n";
			}
			else {
				//En caso de que el enemigo Sauron se encuentre vivo ejecutar�
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de da�o. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de da�o. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de da�o, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
				optionAttackEnemy(enemyHP);
			}
			break;
			//En caso de que el jugador elija atacar a Korpos se ejecutar� lo siguiente
		case '2':
			//Si el enemigo Korpos est� muerto le aparecer� un mensaje al jugador indicando que debe escoger otro enemigo 
			if (enemyIsAlive2 == false) {
				enemigoVivo = false;
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nEl enemigo " << enemyName2 << " esta muerto. Debes elegir otro enemigo.\n";
			}
			else {
				//En caso de que el enemigo Korpos se encuentre vivo se ejecutar�
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de da�o. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de da�o. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de da�o, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
				optionAttackEnemy(enemyHP2);
				break;
			}
		default:
			enemigoValido = false;
			Sleep(750); //Pausa de 750 milisegundos
			cout << "\nEl enemigo que has introducido es incorrecto. Vuelve a introducir un enemigo correcto.\n";
		}
	} while ((!enemigoVivo) || (!enemigoValido));
}

int main() {
	startGame(); //Llamada a la funci�n "startGame" que nos mostrar� la introducci�n del juego

	while ((heroIsAlive) && (enemyIsAlive || enemyIsAlive2)) { //Bucle para que se repita el juego mientras el h�roe est� vivo y/o los enemigos tambi�n

		enemyIsAlive = checkEnemiesAreAlive(enemyHP, enemyName); //LLamada a la funci�n por referencias "checkEnemiesAreAlive" d�ndole los valores del enemy1 para comprobar si est� vivo o no
		enemyIsAlive2 = checkEnemiesAreAlive(enemyHP2, enemyName2); //LLamada a la funci�n por referencias "checkEnemiesAreAlive" d�ndole los valores del enemy2 para comprobar si est� vivo o no

		//Si los enemigos est�n muertos el juego se acaba y gana el H�roe
		if ((enemyIsAlive == false) && (enemyIsAlive2 == false)) { //Comprueba las booleans que comprueban si los enemigos est�n vivos, en caso de que no est�n vivos se ejecutar� lo siguioente
			cout << "\nEl juego se ha acabado. Ha ganado el guerrero " << heroName << "\n\n"; //Texto final del juego indicando que ha ganado el guerrero
			PlaySound(TEXT("victoria.wav"), NULL, SND_SYNC); //Reproduce el sonido de victoria
			break; //Finaliza el juego
		}

		//Si el h�roe est� muerto el juego se acaba y ganan los Enemigos
		if (heroHP <= 0) { //Comprueba si heroHP es igual o menor que 0
			heroIsAlive = false; //Declara boolean como false indicando que el H�roe est� muerto para que finalice el bucle del inicio del juego
			cout << "\n\nTe han atacatado y te has quedado sin vida. El guerrero " << heroName << " ha muerto.\nEl juego se ha acabado. Han ganado los enemigos " << enemyName << " y " << enemyName2 << "\n\n"; //Texto final de juego indicando que han ganado los enemigos
			PlaySound(TEXT("derrota.wav"), NULL, SND_SYNC); //Reproduce el sonido de derrota
			break; //FInaliza el juego
		}
		else { //En caso de que el h�roe se encuentre vivo se ejecutar� esta parte del c�digo
			optionEnemys(); //Llamada a la funci�n "optionEnemys()" que nos har� escoger a qu� enemigo queremos atacar
		}
		heroHP = attackEnemy(enemyHP, enemyName); //LLamada a la funci�n por referencias "attackEnemy" d�ndole los valores del enemy1 para el ataque de dicho enemigo al h�roe
		heroHP = attackEnemy(enemyHP2, enemyName2); //LLamada a la funci�n por referencias "attackEnemy" d�ndole los valores del enemy2 para el ataque de dicho enemigo al h�roe
	}
}