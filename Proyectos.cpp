#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <string>
#include <windows.h>
#include <time.h>



using namespace std;
/*proyecto-2*/
char numero[50];
int  busq = 0;
bool busqueda = false;
int Final = 0;
/*proyecto-2*/
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

void menuprincipaljaime() {
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

int Inicio, Tope, opcion = 0;

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

void menujaime() {
	int dato;
	int op;
	int x;

	system("color 0b");

	do {
		menuprincipaljaime(); cin >> op;
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

/*Proyecto 2*/

struct datos
{
	int valor, dato;
	datos *direccionA;
	datos *direccion_sig;
	datos *direccionB;
};
datos *pilao,*pilaaux;
datos *primero,*cola,*ultimo=NULL;
datos *listao,*listaaux, *anterior;

void menuPrincipalErvin() {
	system("color 0f");
	gotoxy(30, 2); cout << "\n\t PILAS, COLAS Y LISTAS DINAMICAS\n\n";
	gotoxy(30, 7); cout << "1. PILA DINAMICA" << endl;
	gotoxy(30, 8); cout << "2. COLA DINAMICA" << endl;
	gotoxy(30, 9); cout << "3. LISTA DINAMICA" << endl;
	gotoxy(30, 10); cout << "4.	SALIR" << endl;

	gotoxy(30, 12); cout << "\n INGRESE OPCION : ";
}

void ingresoPila();
void mostrarPila();
void eliminarPila();
void buscarPila();

void ingresoCola();
void mostrarCola();
void eliminarCola();
void buscarCola();

void ingresoLista();
void mostrarLista();
void eliminarLista();
void buscarLista();
void MenuPila();
void MenuCola();
void MenuLista();

void MenuPila(){
int opcion;
	do{
		system("cls");
		system("color 06");
		gotoxy(20, 2); cout<<"PROGRAMA PILA DINAMICA:"<<endl;
		gotoxy(20, 7); cout<<"1 Ingreso de datos a la pila"<<endl;
	 	gotoxy(20, 8); cout<<"2 Leer datos de la pila"<<endl;
		gotoxy(20, 9); cout<<"3 Eliminar datos de la pila"<<endl;
		gotoxy(20, 10); cout<<"4 Buscar datos en la pila"<<endl;
		gotoxy(20, 11); cout<< "5 Salir:";
		gotoxy(20, 14); cout << "Elija una opcion:  ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingresoPila();
				break;
			}
			case 2:{
				mostrarPila();
				break;
			}
			case 3:{
				eliminarPila();
				break;
			}
			case 4:{
				buscarPila();
				break;
			}
			case 5:{
				break;
			}
			
		}
		_getch();
	}while (opcion != 5);	
}

void ingresoPila(){
	if(pilao==NULL){
		pilao=new(datos);
	
		cout<<"Ingrese PRIMER dato: "<<endl;
		cin>>pilao->valor;
		cout<<"Dato ingresado correctamente"<<endl;
		pilao->direccionA=NULL;
			system("cls");
		return;
		
	}
	pilaaux=new(datos);
	cout<<"Ingrese dato"<<endl;
	cin>>pilaaux->valor;
	cout<<"Dato ingresado correctamente"<<endl;
	pilaaux->direccionA=pilao;
	pilao=pilaaux;
	system("cls");
}
void mostrarPila(){
	if(pilao==NULL){
		cout<<"No hay datos en la pila"<<endl;
	}
	pilaaux=pilao;
	cout<<"Los datos son: "<<endl;
	while(pilaaux!=NULL){
		cout<<pilaaux->valor<<endl;
		pilaaux=pilaaux->direccionA;
	}
	cout<<"FIN"<<endl;
	_getch();
	system("cls");
}
void eliminarPila(){
	if(pilao==NULL){
		cout<<"No hay datos en la pila"<<endl;
		return;
	}
	pilaaux=new(datos);
	pilaaux=pilao;
	cout<<"Elemento eliminado "<<pilaaux->valor<<endl;
	pilao=pilaaux->direccionA;
	delete(pilaaux);
	mostrarPila();
}
void buscarPila(){
	if(pilao==NULL){
		cout<<"La pila esta vacia"<<endl;
		return;
	}
	int buscardatos;
	bool encontrado=false;
	pilaaux=pilao;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(pilaaux!=NULL){
		if(buscardatos==pilaaux->valor){
			cout<<"Valor Encontrado: "<<pilaaux->valor<<endl;
			encontrado=true;
			break;
		}
		pilaaux=pilaaux->direccionA;
	}
	if(encontrado==false){
		cout<<"No se encontro el valor"<<endl;
	}
}

///colas Dinamicas
void MenuCola(){
	int opcion;
	do{
		system("cls");
		system("color 03");
		gotoxy(20, 2); cout<<"PROGRAMA COLA DINAMICA:"<<endl;
		gotoxy(20, 7); cout<<"1 Ingreso de datos a la cola"<<endl;
	 	gotoxy(20, 8); cout<<"2 Leer datos de la cola"<<endl;
		gotoxy(20, 9); cout<<"3 Eliminar datos de la cola"<<endl;
		gotoxy(20, 10); cout<<"4 Buscar datos en la cola"<<endl;
		gotoxy(20, 11); cout<< "5 Salir:";
		gotoxy(20, 14); cout << "Elija una opcion:  ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingresoCola();
				break;
			}
			case 2:{
				mostrarCola();
				break;
			}
			case 3:{
				eliminarCola();
				break;
			}
			case 4:{
				buscarCola();
				break;
			}
			case 5:{
				break;
			}
			
		}
		_getch();
	}while (opcion != 5);	
}

void ingresoCola(){
	cola=new(datos);
	cout<<"Ingrese dato a la cola"<<endl;
	cin>>cola->dato;
	if(ultimo!=NULL){
		ultimo->direccion_sig=cola;
		cola->direccion_sig=NULL;
		ultimo=cola;
		cout<<"Dato Ingresado "<<endl;
	system("cls");
	}
	else{
		primero=ultimo=cola;
		cout<<"primer dato ingresado"<<endl;
		cout<<primero<<" "<<ultimo<<" "<<cola<<endl;
	}
		cout<<ultimo->direccion_sig<<" "<<cola->direccion_sig<<endl;
		system("cls");
}
void mostrarCola(){
	if(ultimo==NULL){
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cola=primero;
	cout<<"Los dato de la cola son; "<<endl;
	while(cola!=NULL){
		cout<<cola->dato<<endl;
		cola=cola->direccion_sig;

	}
	_getch();
	system("cls");
}
void eliminarCola(){
	if(primero!=NULL){
		cola=primero;
		cout<<"Eliminado "<<primero->dato<<endl;
		primero=cola->direccion_sig;
		delete(cola);
		mostrarCola();
		if(primero==NULL){
			cola=NULL;
			ultimo=NULL;
			
		}
	}
	else{
		cout<<"La cola esta vacia"<<endl;
			
	}
}
void buscarCola(){
	if(primero==NULL){
		cout<<"La cola esta vacia"<<endl;
		return;
	}
	cola=primero;
	bool encontrado=false;
	int buscardatos;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(cola!=NULL){
		if(buscardatos==cola->dato){
			cout<<"Encontrado, el dato es; "<<cola->dato<<endl;
			encontrado=true;
			break;
		}
		cola=cola->direccion_sig;
	}
	if(encontrado==false){
		cout<<"No se encontro el dato"<<endl;
	}

}

///Listas Dinamicas
void MenuLista(){
		int opcion;
		do{
		system("cls");
		system("color 09");
		gotoxy(20, 2); cout<<"PROGRAMA LISTA DINAMICA:"<<endl;
		gotoxy(20, 7); cout<<"1 Ingreso de datos a la lista"<<endl;
	 	gotoxy(20, 8); cout<<"2 Leer datos de la lista"<<endl;
		gotoxy(20, 9); cout<<"3 Eliminar datos de la lista"<<endl;
		gotoxy(20, 10); cout<<"4 Buscar datos en la lista"<<endl;
		gotoxy(20, 11); cout<< "5 Salir:";
		gotoxy(20, 14); cout << "Elija una opcion:  ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingresoLista();
				break;
			}
			case 2:{
				mostrarLista();
				break;
			}
			case 3:{
				eliminarLista();
				break;
			}
			case 4:{
				buscarLista();
				break;
			}
			case 5:{
				break;
			}
			
		}
		_getch();
	}while (opcion != 5);	
}

void ingresoLista(){
	if(listao==NULL){
		listao=new(datos);
		cout<<"Ingrese PRIMER dato a la Lista"<<endl;
		cin>>listao->valor;
		cout<<"Dato ingresado correctamente"<<endl;
		listao->direccionB=NULL;
		return;
		system("cls");
	}
	listaaux=new(datos);
	cout<<"Ingrese dato a la Lista"<<endl;
	cin>>listaaux->valor;
	cout<<"Dato ingresado correctamente"<<endl;
	listaaux->direccionB=listao;
	listao=listaaux;
	
}
void mostrarLista(){
	if(listao==NULL){
		cout<<"No hay datos en la Lista"<<endl;
	}
	listaaux=listao;
	cout<<"Los datos de la Lista son: "<<endl;
	while(listaaux!=NULL){
		cout<<listaaux->valor<<endl;
		listaaux=listaaux->direccionB;
	}
	cout<<"FIN"<<endl;
	_getch();
	system("cls");
}
void buscarLista(){
	if(listao==NULL){
		cout<<"La Lista esta vacia"<<endl;
		return;
	}
	int buscardatos;
	bool encontrado=false;
	listaaux=listao;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(listaaux!=NULL){
		if(buscardatos==listaaux->valor){
			cout<<"Encontrado, el valor es; "<<listaaux->valor<<endl;
			encontrado=true;
			break;
		}
		listaaux=listaaux->direccionB;
	}
	if(encontrado==false){
		cout<<"No se encontro el valor"<<endl;
	}
}
void eliminarLista(){
	int buscardato;
	bool encontrado=false;
	if(listao==NULL){
		cout<<"No hay datos en la lista"<<endl;
		listaaux=NULL;
		return;
	}
	listaaux=listao;
	anterior=listaaux;
	cout<<"Ingrese el dato a eliminar"<<endl;
	cin>>buscardato;
	while(listaaux!=NULL){
		if(buscardato==listaaux->valor){
			cout<<"El valor a eliminar es: "<<listaaux->valor<<endl;
			if(listaaux==listao){
				listao=listao->direccionB;
				mostrarLista();
			}
			else{
				anterior->direccionB=listaaux->direccionB;
			}
			delete(listaaux);
			encontrado=true;
			break;
		}
		anterior=listaaux;
		listaaux=listaaux->direccionB;
	}
	if(listaaux=NULL){
		listao=NULL;
	}
	if(encontrado=false){
		cout<<"no se encontro el valor"<<endl;
	}
}

//Menu 
void menuErvin() {
	int dato;
	int op;
	int x;

	system("color 0b");

	do {
		menuPrincipalErvin(); cin >> op;
		switch (op) {
		case 1:
			MenuPila();
			break;

		case 2:
			MenuCola();
			break;

		case 3:
			MenuLista();
			break;
		}
		cout << endl << endl;
		system("pause");
		system("cls");
	} while (op != 4);

}
/*proyecto 3*/
void menueliminar();
struct Nodo {
	int info;
	Nodo *derecha;
	Nodo *izquierda;
	Nodo*padre;

};
Nodo *arbol = NULL;
typedef struct Nodo *aux;

int delet[100];
int auxiliar = 0;




Nodo *crearNodo(int n, Nodo *padre) {        //Funcion para crear un nuevo nodo

	Nodo *nodonue = new Nodo();

	nodonue->info = n;
	nodonue->derecha = NULL;
	nodonue->izquierda = NULL;
	nodonue->padre = padre;
	cout << endl;
	return nodonue;
}

void insertarn(Nodo *&arbol, int n, Nodo *padre) { //Funcion que permite insertar elementos en el arbol

	if (arbol == NULL) { 				//Antes de ingresar un nodo verifica si el arbol esta vacio 

		Nodo *nodonue = crearNodo(n, padre);// el primer nodo que lee seria el nodo padre o nodo raiz
		arbol = nodonue;

	}
	else {//si existe un0 o varios nodos en el arbol, necesitamos saber el valor del nodo raiz

		int valoraiz = arbol->info;//Obtenemos el valor de la raiz 
		if (n < valoraiz) {//compara si el valor de la raiz es mayor o menor del dato ingresado
			insertarn(arbol->izquierda, n, arbol);//si el dato es menor lo ingresa en el lado izquierdo
		}
		else {
			insertarn(arbol->derecha, n, arbol); //si el dato es mayor lo ingresa en el lado derecho
		}
	}
}

void buscarn(Nodo *arbol, int n) {		//Funcion que nos permite buscar y eleminar un nodo

	if (arbol == NULL) { //compara si el arbol esta vacio

		return;
	}
	else if (n<arbol->info) {			//Si el dato a buscar es menor

		buscarn(arbol->izquierda, n); //busca por el lado izquierdo

	}
	else if (n>arbol->info) {		//Si el dato a buscar es mayor

		buscarn(arbol->derecha, n); //Busca por el lado derecha

	}
	else {//opcion que nos muetra que se encontro el dato en el arbol

		busqueda = true;
		/*	cout << "padre :"<<arbol->dato<<" "<< arbol->der->dato<<" "<<arbol->izq->dato << endl;*/
	}
}



void llenarArbol() {//metodo que nos permite introducir los datos de un archivo al arbol 
	fstream archivo;
	string nombre;
	char line[120];
	char * token1;
	char * token2;
	int n1, n2;


	gotoxy(45, 5); cout << "*BIENVENIDO* " << endl;
	gotoxy(25, 10); printf("INTRODUZCA EL NOMBRE DEL ARCHIVO(SIN .txt): ");
	scanf("%s", &numero);
	strcat(numero, ".txt");
	archivo.open(numero, ios::in);//nos permite abrir el archivo en modo de lectura 

	int contador = 0;
	if (archivo.fail())//verificamos si se abrio correctamente el archivo
	{
		system("cls");
		gotoxy(10, 25); cout << "NO APARECE NINGUN ARCHIVO CON ESE NOMBRE\n\n" << endl;

		_getch();
		exit(EXIT_FAILURE);
	}
	while (!archivo.eof())//pemite verificar todo el contenido del archivo mientras no sea el final
	{
		contador = contador + 1;


		_getch();

		archivo.getline(line, 120);//nos permite leer el archivo linea por linea

		if (contador == 1) {

			token1 = strtok(line, ",");//nos permite leer el primer dato de linea, dividiendo cada dato con una coma

			while (token1 != NULL)
			{

				n1 = atoi(token1);
				token1 = strtok(NULL, ",");
				busqueda = false;

				buscarn(arbol, n1);
				if (busqueda == false) {
					insertarn(arbol, n1, NULL);
				}
			}
		}
		if (contador = 2) {
			cout << "LOS DATOS PARA EL ARBOL FUERON AGREGADOS EXITOSAMENTE\n\n" << endl;
			cout << "LOS DATOS QUE SE PUEDEN ELIMINAR FUERON AGREGADOS EXITOSAMENTE\n\n " << endl;

			token2 = strtok(line, ",");//lee la segunda linea
			while (token2 != NULL)// compara si la segunda linea esta vacia
			{
				n2 = atoi(token2);
				delet[Final] = n2;
				Final++;
				token2 = strtok(NULL, ",");

			}
		}
	}
	archivo.close();//cierra el archivo
}

void muestrarb(Nodo *Arbol, int aux2) {//Funcion que nos permite mostrar el  árbol

	if (Arbol == NULL) {//Compara si el  árbol esta vacio

		return;
	}

	auxiliar += 4;//variable que nos permite verificar la posicion 

	muestrarb(Arbol->izquierda, aux2 + 2);//seprara hasta el nodo mas a la izquierda del árbol construye primero el subarbol izquierdo


	gotoxy(10 + auxiliar - aux2, 15 + aux2);//le asigna al nodo segun sus variables en X y en Y

	cout << Arbol->info << endl << endl;//Muestra el dato del nodo 


	muestrarb(Arbol->derecha, aux2 + 2);//Separa hasta el nodo mas a la derecho del árbol, construyendo el subarbol derecho


}

void BorraNodo(Nodo *eliminar) {//Funcion que permite eliminar un nodo del arbol

	eliminar->izquierda = NULL;
	eliminar->derecha = NULL;

	delete eliminar;
}

void reemplazarNodo(Nodo *arbol, Nodo *nuevoNodo) {//Funcion que nos permite reemplazar un nodo y eliminar un nodo hijo

	if (arbol->padre) {//verifica si el nodo tiene padre, si tiene se le asigna nuevo hijo

		if (arbol->info == arbol->padre->izquierda->info) {//comparamos si el dato del arbol es igual al dato del padre  en el lado izquierdo
			arbol->padre->izquierda = nuevoNodo;//reemplazamos el nodo hijo izquierdo por un nuevo nodo
		}
		else if (arbol->info == arbol->padre->derecha->info) { ////comparamos si el dato del arbol es igual al dato del padre  en el lado derecho
			arbol->padre->derecha = nuevoNodo;//reemplazamos el nodo hijo derecho por nuevo nodo
		}
	}
	if (nuevoNodo) {

		//Se le asigna al nuevo nodo su nuevo Padre
		nuevoNodo->padre = arbol->padre;
	}

}
//Funcion que permite verificare el nodo mas izquierdo del arbol
Nodo *Minimo(Nodo *arbol) {
	if (arbol == NULL) {//verifica si el arbol esta vacio
		return NULL;
	}
	if (arbol->izquierda) {//verifica si el arbol tiene un hijo izquierdo
		return Minimo(arbol->izquierda);//si si verificamos la parte mas izquierda del arbol
	}
	else {//sino tiene hijo izquierdo
		return arbol;
	}
}

void cambiarND(Nodo *arbol, Nodo *nuevoNodo) {//Funcion que nos permite reemplazar un nodo y eliminar un nodo hijo

	if (arbol->padre) {//verifica si el nodo tiene padre, si tiene se le asigna nuevo hijo
		cout << "ENTRO 2" << endl;
		if (arbol->info == arbol->padre->izquierda->info) { //comparamos si el dato del arbol es igual al dato del padre  en el lado izquierdo
			arbol->padre->izquierda = nuevoNodo;//reemplazamos el nodo hijo izquierdo por nuevo nodo
		}
		else if (arbol->info == arbol->padre->derecha->info) {//comparamos si el dato del arbol es igual al dato del padre  en el lado izquierdo
			arbol->padre->derecha = nuevoNodo;//reemplazamos el nodo hijo derecho por nuevo nodo
		}
	}
	if (nuevoNodo) {
		cout << "ENTRO" << endl;
		//Se le asigna al nuevo nodo su nuevo Padre
		nuevoNodo->padre = arbol->padre;
	}

}



void buscarP(Nodo *arbol, Nodo *dir) {//Funcion que nos permite buscar un nodo


	if (arbol == NULL) {//Verifica si el arbol esta vacio

	}
	else {
		buscarP(arbol->derecha, dir);// busca el nodo por el lado derecho y busca el dato


		if (arbol->izquierda == dir) {//verifica si el nodo a buscar es igual al nodo izquierdo

			cout << arbol->info << endl;

			arbol->izquierda = NULL;
			delete(dir);//elimina el dato
			_getch();

		}

		if (arbol->derecha == dir) {//verifica  si el nodo a buscar es igual al nodo derecho

			cout << arbol->info << endl;
			arbol->derecha = NULL;
			delete(dir);//elimina el dato 
			_getch();

		}
		buscarP(arbol->izquierda, dir);// busca el nodo por el lado derecho y busca el dato

	}

}


void eliminarN(Nodo *nodoEliminar) { //Funcion para eliminar el dato encontrado

	Nodo * dir = NULL;


	if (nodoEliminar->izquierda && nodoEliminar->derecha) {//verifica si tiene hijo izquierdo y si tiene hijo derecho

		Nodo *menor = Minimo(nodoEliminar->derecha); //creamos un nuevo nodo y le asignamos la funcion eliminar pero por la parte derecha
		nodoEliminar->info = menor->info;//verificamos el nodo dato a eliminar y lo reemplazamos por el nuevo dato
		eliminarN(menor);//eliminamos el nodo
	}
	//borrar un nodo con un subarbol hijo
	else if (nodoEliminar->izquierda) {//Si el nodo a eliminar tiene un subarbol izquierdo

		reemplazarNodo(nodoEliminar, nodoEliminar->izquierda);//reemplazamos el nodo a eliminar izquierdo por el nuevo nodo 
		BorraNodo(nodoEliminar);//eliminamos el nodo izquierdo
	}
	else if (nodoEliminar->derecha) {	//Si el nodo a eliminar tiene un subarbol izquierdo

		reemplazarNodo(nodoEliminar, nodoEliminar->derecha);//reemplazamos el nodo a eliminar derecho por el nuevo nodo 
		BorraNodo(nodoEliminar);//eliminamos el nodo derecho
	}
	else {//Eliminar un Nodo que no tenga hijos-->HOJA
		cout << "EL DATO SE ENCONTRO" << endl;
		_getch();
		buscarP(arbol, nodoEliminar);

	}
}



Nodo *minimoDerecha(Nodo*arbol) {
	if (arbol == NULL) {//verificamos si el arbol esta vacio
		return NULL;
	}
	if (arbol->derecha) {//verifica si el arbol tiene un hijo derecho
		return Minimo(arbol->derecha);
	}
	else {//sino tiene hijo izquierdo
		return arbol;
	}
}

void eliminacion(Nodo *arbol, int n) {		//Funcion para  buscar y eleminar dato

	if (arbol == NULL) {

		return;
	}
	else if (n<arbol->info) {			//Si el dato es menor

		eliminacion(arbol->izquierda, n); //Buscar por el lado  izquierdo

	}
	else if (n>arbol->info) {		//Si el dato es mayor

		eliminacion(arbol->derecha, n); //Busca por el lado derecho

	}
	else {//Se encontro el dato

		eliminarN(arbol);

	}
}

void eliminarNodoPorderecha(Nodo *nodoEliminar) { //Funcion para eliminar el dato encontrado

	Nodo * dir = NULL;

	if (nodoEliminar->izquierda && nodoEliminar->derecha) {//si el nodo tienehijo izquierdo e hijo derecho

		Nodo *menor = minimoDerecha(nodoEliminar->izquierda);//creamos un nuevo nodo y le asignamos la funcion eliminar pero por la parte izquierda
		nodoEliminar->info = menor->info;//verificamos el nodo dato a eliminar y lo reemplazamos por el nuevo dato
		eliminarNodoPorderecha(menor);//eliminamos el nodo
	}
	else if (nodoEliminar->izquierda) {//Si el nodo a eliminar tiene un subarbol izquierdo

		reemplazarNodo(nodoEliminar, nodoEliminar->derecha);//reemplazamos el nodo a eliminar derecho por el nuevo nodo
		BorraNodo(nodoEliminar);//eliminamos el nodo
	}
	else if (nodoEliminar->derecha) {//Si el nodo a eliminar tiene un subarbol derecho

		reemplazarNodo(nodoEliminar, nodoEliminar->izquierda);//reemplazamos el nodo a eliminar izquierdo por el nuevo nodo
		BorraNodo(nodoEliminar);//eliminamos nodo
	}
	else {//Eliminar un Nodo que no tenga hijos-->HOJA
		cout << " EL DATO SE ENCONTRO" << endl;
		_getch();
		buscarP(arbol, nodoEliminar);
	}
}

void eliminarPorder(Nodo *arbol, int n) {		//Funcion para  buscar y eleminar dato

	if (arbol == NULL) {

		return;

	}
	else if (n<arbol->info) {			//Si el dato es menor

		eliminarPorder(arbol->izquierda, n); //Buscar por la izquierda

	}
	else if (n>arbol->info) {		//Si el dato es mayor

		eliminarPorder(arbol->derecha, n); //Busca por la derecha

	}
	else {//Se encontro el dato

		eliminarNodoPorderecha(arbol);

	}
}

bool Buscar(int a) {//funcion que nos devuelve verdadero y falso 
	for (int i = 1; i < Final; i++) {
		if (delet[i] == a) {
			return true;
		}
	}
	return false;
}

int NumeroNodo(Nodo *arbol)//Funcion que permite contar lo nodos de nodos
{
	if (arbol == NULL)
		return 0;

	else
		return 1 + NumeroNodo(arbol->izquierda) + NumeroNodo(arbol->derecha);

}

int sumaNodos(Nodo *arbol)//funcion que nos permite sumar los nodos
{
	if (arbol == NULL)
		return 0;

	return arbol->info + sumaNodos(arbol->derecha) + sumaNodos(arbol->izquierda);

}

//Funcion que nos permite contar las hojas
int contarHoj(Nodo *arbol) {
	if (arbol == NULL)
	{
		return 0;
	}
	if ((arbol->derecha == NULL) && (arbol->izquierda == NULL))
	{
		return 1;
	}
	else
	{
		return contarHoj(arbol->izquierda) + contarHoj(arbol->derecha);
	}
}

//Funcion que nos permite ver la altura del arbol
int alturaAB(Nodo *arbol)
{
	int AltIzq, AltDer;

	if (arbol == NULL)
		return -1;
	else
	{
		AltIzq = alturaAB(arbol->izquierda);
		AltDer = alturaAB(arbol->derecha);

		if (AltIzq>AltDer)
			return AltIzq + 1;
		else
			return AltDer + 1;
	}
}

//funcion que nos permite el recorrido Preorden

void preOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout << arbol->info << " - ";
		preOrden(arbol->izquierda);
		preOrden(arbol->derecha);
	}
}
// funcion que nos permite el recorrido InOrden

void inOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		inOrden(arbol->izquierda);
		cout << arbol->info << " - ";
		inOrden(arbol->derecha);
	}
}

//funcion que nos permite el recorrido PostOrden
void postOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		postOrden(arbol->izquierda);
		postOrden(arbol->derecha);
		cout << arbol->info << " - ";

	}
}
//Menu de los recorridos del arbol
void menurecorrido() {
	system("cls");
	gotoxy(30, 9); cout << " ||1. RECORRIDO PRE-ORDEN    ||" << endl;
	gotoxy(30, 10); cout << " ||2. RECORRIDO IN-ORDEN     ||" << endl;
	gotoxy(30, 11); cout << " ||3. RECORRIDO POST-ORDEN   ||" << endl;
	cout << "Ingrese una opcion: ";

}
//Menu Principal
void menuprincipalkevin() {
	llenarArbol();
	int opc = 0;
	int opc2 = 0;
	auxiliar = 0;
	do {

		system("cls");

		gotoxy(25, 7);  cout << "||           MENU PRINCIPAL PROYECTO 2   ||" << endl;
		gotoxy(25, 8);  cout << "||1.       MOSTRAR ARBOL                 ||" << endl,
			gotoxy(25, 9);	cout << "||2.       ELIMINAR NODO                 ||" << endl;
		gotoxy(25, 10); cout << "||3.       DATOS DEL ARBOL               ||" << endl;
		gotoxy(25, 11); cout << "||4.       RECORRIDOS DEL ARBOL          ||" << endl;
		gotoxy(25, 12); cout << "||5.       BUSCAR DATO                   ||" << endl;
		gotoxy(25, 13); cout << "||6.       SALIR                         ||" << endl;
		gotoxy(25, 16); cout << "    INGRESE UNA OPCION : [  ] ";
		gotoxy(51, 16); cin >> opc;
		switch (opc)
		{
		case 1:
			system("cls");
			cout << "\tMOSTRANDO ARBOL" << endl;
			auxiliar = 0;
			muestrarb(arbol, 0);
			cout << endl << endl << endl;
			_getch();
			break;
		case 2:

			menueliminar();
			_getch();
			break;
		case 3:;
			system("cls");
			int h;
			h = contarHoj(arbol);
			gotoxy(30, 10); cout << "Contar Hojas: " << h << endl;

			int m;
			m = alturaAB(arbol);
			gotoxy(30, 11); cout << "Altura del Arbol: " << m << endl;

			int n;
			n = NumeroNodo(arbol);
			gotoxy(30, 12); cout << "El total de los nodos es: " << n << endl;

			int j;
			j = sumaNodos(arbol);
			gotoxy(30, 13); cout << "La suma de los nodos es: " << j << endl;
			_getch();
			break;
		case 4:
			system("cls");
			menurecorrido();
			cin >> opc2;
			if (arbol != NULL)
			{
				switch (opc2)
				{
				case 1:preOrden(arbol);
					_getch();
					break;
				case 2:inOrden(arbol);
					_getch();
					break;
				case 3:postOrden(arbol);
					_getch();
					break;
				}

			}
			else
				cout << "\n\t Arbol vacio..!";
			break;
		case 5:
			busqueda = false;
			cout << "INGRESE UN DATO A BUSCAR" << endl;
			cin >> busq;
			buscarn(arbol, busq);
			if (busqueda == true) {
				cout << "EL DATO FUE ENCONTRADO" << endl;
			}
			else {
				cout << "EL DATO NO PUDO SER ENCONTRADO" << endl;
			}
			_getch();
			break;
		case 6:
			system("cls");
			exit(0);
			break;
		}
	} while (opc != 7);

}

//Menu de Eliminar
void menueliminar() {
	int a;
	system("cls");
	cout << "DATOS QUE SE PUEDEN ELIMINAR:" << endl;
	for (int i = 1; i < Final; i++) {
		cout << delet[i] << endl;
	}
	cout << "DATOS A ELIMINAR:" << endl;
	cin >> a;
	if (Buscar(a) == true) {
		int opcion2 = 0;
		do
		{
			system("cls");
			gotoxy(45, 7); cout << "*ELIMINACION*" << endl;
			gotoxy(30, 9); cout << "||1. ELIMINACION POR LA IZQUIERDA   ||" << endl;
			gotoxy(30, 10); cout << "||2. ELIMINACION POR LA DERECHA     ||" << endl;
			gotoxy(30, 11); cout << "||3. REGRESAR AL MENU               ||" << endl;
			gotoxy(30, 13); cout << "    INGRESE UNA OPCION : [  ]";
			gotoxy(56, 13); cin >> opcion2;
			switch (opcion2)
			{
			case 1:
				eliminacion(arbol, a);
				menuprincipalkevin();
				break;
			case 2:
				eliminarPorder(arbol, a);
				menuprincipalkevin();
				break;
			}
		} while (opcion2 = 3); {
			menuprincipalkevin();
		}
	}
	else {
		cout << "EL DATO NO ES VALIDO PARA ELIMINAR" << endl;
	}

}
int main() {
	system("color F1");
	int opcion = 0;
	do {

		system("cls");

		gotoxy(25, 6);  cout << "           MENU PRINCIPAL DE PROYECTOS                    " << endl;
		gotoxy(25, 9);  cout << "       1. IMPLEMENTACION DE PILAS Y COLAS ESTATICAS       " << endl;
		gotoxy(25, 10); cout << "       2. IMPLEMENTACION DE PILAS,COLAS Y LISTAS DINAMICAS" << endl;
		gotoxy(25, 11); cout << "       3. ARBOLES ABB                        " << endl;
		gotoxy(25, 12); cout << "       4. SALIR                            " << endl;
		gotoxy(25, 13); cout << "INGRESE UNA OPCION : [   ] ";
		gotoxy(48, 14); cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			menujaime();
			break;
		case 2:
			system("cls");
			menuErvin();
			break;
		case 3:
			system("cls");
			menuprincipalkevin();
			break;
			
		case 4:
			system("cls");
			exit(0);
			break;
		}
	} while (opcion != 5);

	system("pause");
}
