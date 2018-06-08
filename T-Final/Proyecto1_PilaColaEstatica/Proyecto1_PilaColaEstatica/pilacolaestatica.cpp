#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_ERROR_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
char letras[19];

void menu() {
	gotoxy(30, 2); cout << "\n\t IMPLEMENTACION DE PILAS Y COLAS\n\n";
	gotoxy(30, 7); cout << "1. FORMA ALEATORIA	" << endl;
	gotoxy(30, 8); cout << "2. FORMA DE COLA" << endl;
	gotoxy(30, 9); cout << "3. FORMA DE PILA" << endl;
	gotoxy(30, 10); cout << "4.	SALIR" << endl;

	gotoxy(30, 12); cout << "\n INGRESE OPCION : ";
}
int generador() {
	int n;
	n = 'a' + rand() % ('z' - 'a');
	return n;

}

int Inicio, Final, Tope, opcion = 0;

bool repetidas(int n)
{
	bool recorrer = false;
	for (int i = 0; i < 20; i++)
	{
		if (n == letras[i])
		{
			recorrer = true;
		}
	}
	return recorrer;
}

void letrasaleatorio() {
	system("cls");
	system("color 0c");
	int repe;

	srand(time(NULL));
	cout << endl;
	for (int n = 0; n < 20; n++)
	{
		letras[n] = generador();
		do {
			repe = generador();
		} while (repetidas(repe) == true);
		letras[n] = char(repe);
		Final++;
		cout << letras[n] << endl;
	}
	gotoxy(20, 23); cout << "\nLetras ingresadas correctamente\n";
	_getch();
}


void MostrarPila() {
	system("cls");
	if (Final == 0)
	{
		gotoxy(20, 10);  cout << "LA PILA ESTA VACIA" << endl;
	}
	else
	{
		cout << letras[Final];

	}
	for (int r = Inicio; r < Final; r++) {
		cout << letras[r] << " \tposicion: " << r + 1 << endl;
	}
}

void EliminarPila() {
	system("cls");
	int r;
	if (Final == 0)
	{
		gotoxy(20, 10); cout << "LA PILA ESTA VACIA" << endl;
	}
	else
	{


		cout << letras[Final] << "  Se elimino el dato en la posicion: " << Final << endl;

		cout << endl;
		Final--;
	}
	for (r = Inicio; r < Final; r++) {
		cout << letras[r] << " \tposicion: " << r + 1 << endl;

	}


}


void menupila() {

	do {
		system("cls");
		system("color 02");
		gotoxy(20, 2); cout << "Programa para Control de Pila\n";

		gotoxy(20, 7); cout << "1. Mostrar datos de la pila (Recorrida)";
		gotoxy(20, 8); cout << "2. Eliminar valores de la pila (pop)";
		gotoxy(20, 9); cout << "3. Salir";
		gotoxy(20, 12); cout << "Elija una opcion:  ";
		cin >> opcion;
		switch (opcion) {
		case 1: MostrarPila(); break;
		case 2: EliminarPila(); break;
		case 3:  break;

		default:"\n no es un opcion valida";
		}
		_getch();


	} while (opcion != 3);

}

void MostrarCola() {
	system("cls");
	if (Final == 0)
	{
		cout << "LA COLA ESTA VACIA" << endl;
	}
	else
	{
		cout << letras[Final];

	}
	for (int r = Inicio; r < Final; r++) {
		cout << letras[r] << " \tposicion: " << r << endl;
	}
}

void EliminarCola() {

	system("cls");
	if (Final == 0)
	{
		cout << "LA COLA ESTA VACIA" << endl;
	}
	else
	{
		cout << letras[Inicio];
		cout << "\tSe elimino el dato en la posicion: " << Inicio << endl;
		Inicio++;
		cout << endl;
	}
	for (int i = 1; i < Final; i++) {

		cout << letras[i] << endl;

	}

	letras[Final] = ' ';

	Final--;

}

void menucola() {

	do {
		system("cls");
		system("color 01");
		gotoxy(20, 2); cout << "Programa para Control de Cola";

		gotoxy(20, 7); cout << "1. Mostrar datos de la cola (Recorrida)";
		gotoxy(20, 8); cout << "2. Eliminar valores de la cola (Deque)";
		gotoxy(20, 9); cout << "3. Salir";
		gotoxy(20, 12); cout << "Elija una opcion:  ";
		cin >> opcion;
		switch (opcion) {
		case 1: MostrarCola(); break;
		case 2: EliminarCola(); break;
		case 3:  break;

		default:"\n no es un opcion valida";
		}
		_getch();


	} while (opcion != 3);

}

void main() {
	int dato;
	int op;
	int x;

	system("color 0b");

	do {
		menu(); cin >> op;
		switch (op) {
		case 1:
			letrasaleatorio();
			break;

		case 2:
			menucola();
			break;

		case 3:
			menupila();
			break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	} while (op != 4);

}