#include <iostream>
using namespace std;

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct personal{
	string dni;
	string nombres;
	fecha nacimiento;
};

void seleccionDir(int, personal[]);
bool compararFechas(personal, personal);
int busquedaBinaria(personal[], int, personal);

int main() {
	int n;
	personal personas[50];
	personal buscar;
	cout << "Ingresa la cantidad de personas que va a ingresar: ";
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cout << endl << "Persona Nro " << i+1 << ": " << endl;
		cout << "Ingresa el DNI: ";
		cin >> personas[i].dni;
		cout << "Ingresa los nombres: ";
		cin.ignore();
		getline(cin, personas[i].nombres);
		cout << "Ingresa su fecha de nacimiento" << endl;
		cout << "Anio: ";
		cin >> personas[i].nacimiento.anio;
		cout << "Mes: ";
		cin >> personas[i].nacimiento.mes;
		cout << "Dia: ";
		cin >> personas[i].nacimiento.dia;
	}
	seleccionDir(n, personas);
	cout << endl << "Arreglo ordenado por fechas: " << endl;
	for ( int i = 0; i < n; i++ ) {
		cout << endl << "Persona Nro " << i+1 << ": " << endl;
		cout << "DNI: " << personas[i].dni << endl;
		cout << "Nombres: " << personas[i].nombres << endl;
		cout << "Fecha de nacimiento: " << endl;
		cout << "Dia: " << personas[i].nacimiento.dia << endl;
		cout << "Mes: " << personas[i].nacimiento.mes << endl;
		cout << "Anio: " << personas[i].nacimiento.anio << endl << endl;
	}
	cout << endl << "Ingresa una fecha para comprobar si se encuentra la persona" << endl;
	cout << "Dia: ";
	cin >> buscar.nacimiento.dia;
	cout << "Mes: ";
	cin >> buscar.nacimiento.mes;
	cout << "Anio: ";
	cin >> buscar.nacimiento.anio;
	if ( busquedaBinaria(personas, n, buscar) >= 0 ) {
		cout << "Si se encontro la persona, esta en la posicion: " << busquedaBinaria(personas, n, buscar);
	} else {
		cout << "No se encontro la persona, deberia estar en la posicion: " << busquedaBinaria(personas, n, buscar);
	}
	return 0;
}

void seleccionDir(int n, personal personas[50]) {
	int k;
	personal menor;
	for ( int i = 0; i < n; i++ ) {
		menor = personas[i];
		k = i;
		for ( int j = i + 1; j < n; j++ ) {
			if ( compararFechas(personas[j], menor) ) {
				menor = personas[j];
				k = j;
			}
		}
		personas[k] = personas[i];
		personas[i] = menor;
	}
}

bool compararFechas(personal p1, personal p2) {
    if (p1.nacimiento.anio != p2.nacimiento.anio) {
        return p1.nacimiento.anio < p2.nacimiento.anio;
    }
    if (p1.nacimiento.mes != p2.nacimiento.mes) {
        return p1.nacimiento.mes < p2.nacimiento.mes;
    }
    return p1.nacimiento.dia < p2.nacimiento.dia;
}

int busquedaBinaria(personal personas[50], int n, personal buscar) {
    int izquierda = 0;
    int derecha = n - 1;
    while (izquierda <= derecha) {
        int mitad = (izquierda + derecha) / 2;
        
        if (compararFechas(personas[mitad], buscar)) {
            izquierda = mitad + 1;
        } else if (compararFechas(buscar, personas[mitad])) {
            derecha = mitad - 1;
        } else {
            return mitad;
        }
    }
    return -izquierda;
}
