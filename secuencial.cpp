#include <iostream>
using namespace std;

int secuencialDes(int [], int , int);

int main() {
	//SE CREA EL ARREGLO DESORDENADO
	int arregloDesordenado[10] = {9, 1, 10, 4, 7, 6, 8, 2, 3, 5};
	//SE CREA EL ARREGLO ORDENADO
	int arregloOrdenado[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int capacidad = 10; //CAPACIDAD DEL ARREGLO
	int dato, opcion;
	cout << "// PROGRAMA DE BUSQUEDA // " << endl;
	do {
		cout << "1. Metodo de busqueda secuencial en datos desordenados" << endl;
		cout << "2. Metodo de busqueda secuencial en datos ordenados" << endl;
		cout << "3. Salir del programa" << endl;
		cin >> opcion;
		switch ( opcion ) {
			case 1:
				//PRIMERO SE MUESTRA EL ARREGLO
				cout << "Arreglo desordenado: ";
				for ( int i = 0; i < 10; i++ ) {
					cout << arregloDesordenado[i] << "  ";
				}
				cout << endl;
				//SE PIDE AL USUARIO INGRESAR EL NUMERO A BUSCAR
				cout << "Que numero desea buscar: ";
				cin >> dato;
				cout << "Posicion en el que se encuentra el dato: " << secuencialDes(arregloDesordenado, capacidad, dato) << endl;
				break;
			case 2:
				//PRIMERO SE MUESTRA EL ARREGLO
				cout << "Arreglo ordenado:";
				for ( int i = 0; i < 10; i++ ) {
					cout << arregloOrdenado[i] << "  ";
				}
				cout << endl;
				//SE PIDE AL USUARIO INGRESAR EL NUMERO A BUSCAR
				cout << "Que numero desea buscar: ";
				cin >> dato;
				
				break;
			case 3:
				cout << "Saliendo del programa ..." << endl;
				break;
			default:
				cout << "Error: Ingreo un numero no valido" << endl;
				break;
		}
	} while ( opcion != 3 );
	
	return 0;
}

int secuencialDes(int arregloDesordenado[10], int capacidad, int dato) {
	int pos = -1;
	int i = 0;
	while ( i <= capacidad && arregloDesordenado[i] != dato ) {
		i = i + 1;
	}
	if ( i <= capacidad ) {
		pos = i;
	}
	return pos;
}