#include <iostream>
#include <windows.h>
#include "MMSystem.h"

using namespace std;

//Validación de datos
bool ataqueValido; //Boolean "ataqueValido" se utiliza para comprobar si el ataque que introduce el héroe es uno de los que tiene el héroe establecidos
bool enemigoVivo; //Boolean "enemigoVIvo" se utiliza para comprobar si el enemigo que introduce el héroe se encuentra muerto a la hora de seleccionar el enemigo al cual atacar
bool enemigoValido; //Boolean "enemigoValido" se utiliza para comprobar si el enemigo que introduce el héroe es uno de los enemigos que existe

//Atributos del enemigo 1
int enemyHP = 150; //Establecemos la vida del enemigo 1
string enemyName = "Sauron"; //Establecemos nombre al enemigo 1
bool enemyIsAlive = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el enemigo 1

//Atributos del enemigo 2
int enemyHP2 = 125; //Establecemos la vida del enemigo 2
string enemyName2 = "Korpos"; //Establecemos nombre al enemigo 2
bool enemyIsAlive2 = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el enemigo 2

//Atrbutos del personaje
int heroHP = 250; //Establecemos la vida del héroe
string heroName; //Creamos variable heroName que la deberá inciar el propio usuario con el nombre que quiera asignarle al héroe
bool heroIsAlive = true; //Inicializamos por defecto el boolean que comprueba si se encuentra vivo el héroe

//Ataques del personaje
char optionAttack; //char optionAttack se utilizará para que el héroe escoja que opcion de los ataques quiere escoger
char optionEnemy; //char optionenemy se utilizará para que el héroe escoja que enemigo quiere atacar
int patada = 100, espada = 120, magia = 35; //Establecemos el valor de cada ataque que dispone el héroe
int ataquesDisponiblesMagia = 1; //Indica el nº de veces que tiene disponible el ataque "magia"

//Función sin retorno que inica la introducción del juego
void startGame() { 
	//Texto de introducción
	PlaySound(TEXT("inicioPelea.wav"), NULL, SND_SYNC); //Reproduce el sonido del inicio de la pelea
	cout << "Bienvenido bienaventurado a Villa Orka. \n\nEsta villa ha sido destruida por los destructores de planetas Sauron y Korpos de la galaxia N-109.\nNecesitaremos la ayuda de un gran guerrero que pueda derrotarlos y devolver la alegria y tranquilidad a la Villa.\n\nSeras capaz de derrotarlos?\n\n";
	cout << "Acaban de aparecer los enemigos " << enemyName << " y " << enemyName2; //Indica que han aparecido los enemigos
	Sleep(150); //Pausa de 150 milisegundos
	cout << "\nIntroduzca su nombre bienaventurado: "; //Texto que indica al usuario que deberá introducir un nombre al héroe
	cin >> heroName; //Pide al usuario que introduzca un nombre al héroe
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida.\n"; //Indica el nombre y de la vida del enemigo 1 que se enfrentará
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El enemigo " << enemyName2 << " tiene " << enemyHP2 << " puntos de vida.\n"; //Indica el nombre y de la vida del enemigo 2 que se enfrentará
	Sleep(750); //Pausa de 750 milisegundos
	cout << "El guerrero " << heroName << " tiene " << heroHP << " puntos de vida.\n\n"; //Indica el nombre y de la vida del héroe
	Sleep(750); //Pausa de 750 milisegundos
	cout << "Acaba con los enemigos!";
}

//Función a través de referencias que comprueba si el enemigo (1 o 2) está vivo o no y devolverá true o false
bool checkEnemiesAreAlive(int& enemyHP, string& enemyName) {
	//Si el enemigo "x" tiene 0 menos de vida se ejecutará lo siguiente
	if (enemyHP <= 0) {
		cout << "\nEl enemigo " << enemyName << " ha muerto."; //Texto indicando que el enemigo "x" se ha muerto.
		return false; //Devolverá false debido que el enemigo "x" ha muerto
	}
	//En caso de que el enemigo "x" está vivo se ejecutará lo siguiente
	else {
		return true; //Devolverá true debido que el enemigo "x" está vivo
	}
}

//Función a través de referencias que devolverá la vida del héroe después del ataque del enemigo "x"
int attackEnemy(int& enemyHP, string& enemyName) {
	int enemyDamage = rand() % (25 - 0); //Variable para el ataque del enemigo que establecerá un valor aleatorio entre 0 y 25
	//Si la vida del enemigo "x" es mayor que 0 ejecutará lo siguiente
	if (enemyHP > 0) {
		Sleep(500); //Pausa de 500 milisegundos
		cout << "\nEl enemigo " << enemyName << " tiene " << enemyHP << " puntos de vida"; //Texto indicando cuánta vida tiene el enmeigo "x".
		if (heroHP > 0) {
			Sleep(550); //Pausa de 550 milisegundos
			cout << "\nEl enemigo " << enemyName << " te ha atacado. Te ha quitado " << enemyDamage << " puntos de vida. Actualmente tienes " << heroHP << " puntos de vida";
		}
	}

	return heroHP - enemyDamage;
}

//Función a través de referencias que devolverá la vida del enemigo "x" correspondiente después del ataque que le realice el héroe
void optionAttackEnemy(int&enemyHP) {
	enemigoVivo = true;
	enemigoValido = true;
	do {

		//Menú de opciones de ataques disponibles del jugador
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
			//En caso de que el jugador introduzca otro ataque no registrado se le indicará que introduzca uno válido
			ataqueValido = false;
			Sleep(750); //Pausa de 750 milisegundos
			cout << "\nEl ataque introducido es incorrecto. Introduce un ataque válido.";
		}
	} while (!ataqueValido);
}

//Función de menú para que el héroe elija a quian atacar
void optionEnemys() {
	//En caso de que el guerrero esté vivo se ejecutará
	heroIsAlive = true; //Asignamos boolean como true
	enemigoValido = true; //Inicilziamos boolean como true
	do {
		Sleep(750); //Pausa de 750 milisegundos
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
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de daño. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de daño. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de daño, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
				optionAttackEnemy(enemyHP);
			}
			break;
			//En caso de que el jugador elija atacar a Korpos se ejecutará lo siguiente
		case '2':
			//Si el enemigo Korpos está muerto le aparecerá un mensaje al jugador indicando que debe escoger otro enemigo 
			if (enemyIsAlive2 == false) {
				enemigoVivo = false;
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nEl enemigo " << enemyName2 << " esta muerto. Debes elegir otro enemigo.\n";
			}
			else {
				//En caso de que el enemigo Korpos se encuentre vivo se ejecutará
				Sleep(750); //Pausa de 750 milisegundos
				cout << "\nDispones de los siguientes ataques:";
				cout << "\nEl ataque patada hace 10 de daño. Selecciona '1' para realizar ataque.";
				cout << "\nEl ataque espada hace 20 de daño. Selecciona '2' para realizar ataque.";
				cout << "\nEl ataque magia hace 35 de daño, pero solamente dispones de 1 ataque de este tipo. Selecciona '3' para realizar ataque.";
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
	startGame(); //Llamada a la función "startGame" que nos mostrará la introducción del juego

	while ((heroIsAlive) && (enemyIsAlive || enemyIsAlive2)) { //Bucle para que se repita el juego mientras el héroe esté vivo y/o los enemigos también

		enemyIsAlive = checkEnemiesAreAlive(enemyHP, enemyName); //LLamada a la función por referencias "checkEnemiesAreAlive" dándole los valores del enemy1 para comprobar si está vivo o no
		enemyIsAlive2 = checkEnemiesAreAlive(enemyHP2, enemyName2); //LLamada a la función por referencias "checkEnemiesAreAlive" dándole los valores del enemy2 para comprobar si está vivo o no

		//Si los enemigos están muertos el juego se acaba y gana el Héroe
		if ((enemyIsAlive == false) && (enemyIsAlive2 == false)) { //Comprueba las booleans que comprueban si los enemigos están vivos, en caso de que no estén vivos se ejecutará lo siguioente
			cout << "\nEl juego se ha acabado. Ha ganado el guerrero " << heroName << "\n\n"; //Texto final del juego indicando que ha ganado el guerrero
			PlaySound(TEXT("victoria.wav"), NULL, SND_SYNC); //Reproduce el sonido de victoria
			break; //Finaliza el juego
		}

		//Si el héroe está muerto el juego se acaba y ganan los Enemigos
		if (heroHP <= 0) { //Comprueba si heroHP es igual o menor que 0
			heroIsAlive = false; //Declara boolean como false indicando que el Héroe está muerto para que finalice el bucle del inicio del juego
			cout << "\n\nTe han atacatado y te has quedado sin vida. El guerrero " << heroName << " ha muerto.\nEl juego se ha acabado. Han ganado los enemigos " << enemyName << " y " << enemyName2 << "\n\n"; //Texto final de juego indicando que han ganado los enemigos
			PlaySound(TEXT("derrota.wav"), NULL, SND_SYNC); //Reproduce el sonido de derrota
			break; //FInaliza el juego
		}
		else { //En caso de que el héroe se encuentre vivo se ejecutará esta parte del código
			optionEnemys(); //Llamada a la función "optionEnemys()" que nos hará escoger a qué enemigo queremos atacar
		}
		heroHP = attackEnemy(enemyHP, enemyName); //LLamada a la función por referencias "attackEnemy" dándole los valores del enemy1 para el ataque de dicho enemigo al héroe
		heroHP = attackEnemy(enemyHP2, enemyName2); //LLamada a la función por referencias "attackEnemy" dándole los valores del enemy2 para el ataque de dicho enemigo al héroe
	}
}