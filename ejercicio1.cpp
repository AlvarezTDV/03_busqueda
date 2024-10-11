#include <iostream>
using namespace std;

struct monomio {
	int coef;
	int exp;
};

void ordenaPol(int, monomio []);
int secuencialOrd(monomio[], int, monomio);

int main() {
	int n;
	monomio buscar;
	monomio ter[50];
	cout << "Ingresa la cantidad de terminos del polinomio: ";
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cout << "Ingresa el coeficiente " << i + 1 << ": ";
		cin >> ter[i].coef;
		cout << "Ingresa el exponente " << i + 1 << ": ";
		cin >> ter[i].exp;
	}
	ordenaPol(n, ter);
	cout << "Polinomio ordenado: " << endl;
	for ( int i = 0; i < n; i++ ) {
		if ( i >= 1 ) {
			cout << " + ";
		}
		cout << ter[i].coef << "x^";
		cout << ter[i].exp;
	}
	cout << endl << "Ingresa un monomio para comprobar si se encuentra" << endl;
	cout << "Ingresa el coeficiente: ";
	cin >> buscar.coef;
	cout << "Ingresa el exponente: ";
	cin >> buscar.exp;
	if ( secuencialOrd(ter, n, buscar) >= 0 ) {
		cout << "Si se encontro el monomio, esta en la posicion: " << secuencialOrd(ter, n, buscar);
	} else {
		cout << "No se encontro el monomio, deberia estar en la posicion: " << secuencialOrd(ter, n, buscar);
	}
	return 0;
}

void ordenaPol( int n, monomio ter[50] ) {
	monomio aux;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = n-1; j > i; j-- ) {
			if ( ter[j].exp < ter[j-1].exp ) {
				aux = ter[j];
				ter[j] = ter[j-1];
				ter[j-1] = aux;
			}
		}
	}
}

int secuencialOrd(monomio ter[50], int n, monomio buscar) {
    int i = 0;
    while (i < n && (ter[i].exp < buscar.exp || (ter[i].exp == buscar.exp && ter[i].coef < buscar.coef))) {
        i++;
    }
    if (i >= n || ter[i].exp != buscar.exp || ter[i].coef != buscar.coef) {
        return -i;
    } else {
        return i;
    }
}
