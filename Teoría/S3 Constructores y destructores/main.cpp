#include <iostream>
#include <array>

using namespace std;

class vectorElementos {
    private:

        array <int,10> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    public:

        vectorElementos();

        void mostrarElems();
        array <int, 10> cambiaElem();
        int sumaElem();

        ~vectorElementos();
};

vectorElementos::vectorElementos(/* args */) {
}

vectorElementos::~vectorElementos() {
}


int main () {

    bool exit = true;
    vectorElementos v;

    while (exit) {
        
        cout << "\n¿Quieres ejecutar el programa? (0/1): ";
        cin >> exit;

        if (!exit) {

            return 0;
        }
        
        system("cls");
        v.cambiaElem();
    }

    return 0;
}

void vectorElementos::mostrarElems() {

    cout << "\nELEMENTOS: ";
    for (int i = 0; i < elems.size(); i++) {

        cout << "|" << elems.at(i) << "| ";
        
    }
    
    cout << endl << "POSICIONES: ";
    
    for (int i = 0; i < elems.size(); i++) {

        cout << "(" << i << ") ";
    }

    cout << "\n\nLa suma de sus elementos es: " << sumaElem() << endl;
}

array <int, 10> vectorElementos::cambiaElem () {

    mostrarElems();

    int i;
    cout << "\n\n\tSelecciona la posición del elemento a cambiar: ";
    cin >> i;

    cout << "\nEste es el elemento escogido: " << elems.at(i) << ".\n\n\tEscribe ahora el número por el que lo quieres cambiar: ";
    cin >> elems.at(i);
    system("cls");
    mostrarElems();

    return elems;
}

int vectorElementos::sumaElem() {

    int suma = 0;
    for (int i = 0; i < elems.size(); i++) {

        suma = suma + elems.at(i); 
    }

    return suma;
}
