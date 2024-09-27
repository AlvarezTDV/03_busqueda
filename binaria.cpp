#include <iostream>
using namespace std;

int binaria(int [], int, int);

int main() {
	//SE CREA EL ARREGLO ORDENADO
	int arregloOrdenado[15] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
	int capacidad = 15; //CAPACIDAD DEL ARREGLO
	int dato, opcion;
	cout << "// PROGRAMA DE BUSQUEDA BINARIA // " << endl;
	do {
		cout << "1. Buscar un dato" << endl;
		cout << "2. Salir del programa" << endl;
		cin >> opcion;
		switch ( opcion ) {
			case 1:
				//PRIMERO SE MUESTRA EL ARREGLO
				cout << "Arreglo ordenado: ";
				for ( int i = 0; i < capacidad; i++ ) {
					cout << arregloOrdenado[i] << "  ";
				}
				cout << endl;
				//SE PIDE AL USUARIO INGRESAR EL NUMERO A BUSCAR
				cout << "Que numero desea buscar: ";
				cin >> dato;
				cout << "Posicion en el que se encuentra el dato: " << binaria(arregloOrdenado, capacidad, dato) << endl << endl;
				break;
			case 2:
				cout << "Saliendo del programa ..." << endl;
				break;
			default:
				cout << "Error: Ingreo un numero no valido" << endl;
				break;
		}
	} while ( opcion != 2 );
	
	return 0;
}

int binaria(int arregloOrdenado[15], int capacidad, int dato) {
	int izq = 0;
	int der = capacidad-1;
	int cen = 0;
	int pos, m;
	while ( izq <= der && cen == 0 ) {
		m = int((izq + der) / 2);
		if ( arregloOrdenado[m] == dato ) {
			cen = 1;
		} else {
			if ( arregloOrdenado[m] < dato ) {
				izq = m + 1;
			} else {
				der = m - 1;
			}
		}
	}
	if ( cen == 1 ) {
		pos = m;
	} else {
		pos = -izq;
	}
	return pos;
}