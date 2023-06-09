//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMÍREZ GUERRERO
#include <iostream>
#include <string>

#include "Animales.h"

using namespace std;

//--------------CLASE ADOMÉSTICO----------------

string ADomestico::pedirIdentificacion() {

    int mes, ano;
    
    cout << "Escribe el mes de nacimiento: ";
    cin >> mes;

    if (mes < 1 || mes > 12) {throw 1;}

    cout << "Escribe el año de nacimiento: ";
    cin >> ano;
    

    string fecha = to_string(mes)  + "/" + to_string(ano);

    return fecha;

}

//---------------CLASE PERRO---------------------

string Perro::getFecha()const {
	return fecha; 
}

string Perro::getNombre() const {
	return nombre;
}

void Perro::pedirIdentificacion() {
	
	fecha = ADomestico::pedirIdentificacion();


	string name;
	cout << "\n\t Introdzuca el nombre del perro: ";
	cin >> name;
	nombre = name;
}

void Perro::conocerOnomatopeya() const {
	cout << "\n\t El perro " << nombre << " dice: " << " GUAU GUAU" << endl;
}

string Perro::verTipo() const {
	string const tipo = "Perro";
	return tipo;
}

//---------------CLASE GATO---------------------

string Gato::getFecha()const {
	return fecha;
}

string Gato::getNombre() const {
	return nombre;
}

void Gato::pedirIdentificacion() {
	
	fecha = ADomestico::pedirIdentificacion();

	string name;
	cout << "\n\t Introdzuca el nombre del gato: ";
	cin >> name;
	nombre = name;
}

void Gato::conocerOnomatopeya() const {
	cout << "\n\t El gato " << nombre << " dice: " << " MIAU MIAU" << endl;
}

string Gato::verTipo() const {
	string const tipo = "Gato";
	return tipo;
}
//---------------CLASE AVE---------------------



//---------------CLASE PATO---------------------



//---------------CLASE POLLITO---------------------



