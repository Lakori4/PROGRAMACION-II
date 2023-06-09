// Santiago Valderrama y Gina Ramírez
#include <iostream>
#include <string>

#include "Vehiculos.h"

using namespace std;

//---------------METODOS DE LA CLASE VEHICULO---------------------

Vehiculo::Vehiculo(string const &m, long p) {

    marca = m;
    potencia = p;
} 

Vehiculo::Vehiculo(Vehiculo const &V) {

    marca = V.marca;
    potencia = V.potencia;
}

/* void Vehiculo::mostrarVeh() {

    cout << "Marca del vehiculo" << marca << endl;
    cout << "Potencia del vehiculo" << potencia << endl;
} */

//---------------METODOS DE LA CLASE CAMION---------------------

Camion::Camion(string const& c, string const& t) {
    categoria = c;
    tamano = t;
}
Camion::Camion(Camion const& C) {
    categoria = C.categoria;
    tamano = C.tamano;
}

void Camion::setCategoria(string const& c) {
    categoria = c;
}
string Camion::getCategoria() const {
    return categoria;
}

void Camion::setTamano(string const& t) {
    tamano = t;
}
string Camion::getTamano() const {
    return tamano;
}

void Camion::mostrarCam() {
    mostrarVeh();
    cout << "\n\t Categoria: " << categoria << endl;
    cout << "\n\t Tamano: " << tamano << endl;
}

//---------------METODOS DE LA CLASE AUTOMOVIL---------------------

Automovil::Automovil(string const &c, int d, int e, int v) {

    combustible = c;
    l_deposito = d;
    etiquetaECO = e;
    velocidadMax = v;
}

Automovil::Automovil(Automovil const & A) {

    combustible = A.combustible;
    l_deposito = A.l_deposito;
    etiquetaECO = A.etiquetaECO;
    velocidadMax = A.velocidadMax;
}



//---------------METODOS DE LA CLASE MONOVOLUMEN---------------------

Monovolumen::Monovolumen(int l, int p) {
    largo = l;
    plazas = p;
}
Monovolumen::Monovolumen(Monovolumen const& M) {
    largo = M.largo;
    plazas = M.plazas;
}


void Monovolumen::setLargo(int l) {
    largo = l;
}
void Monovolumen::setPlazas(int p) {
    plazas = p;
}

int Monovolumen::getLargo() const {
    return largo;
}
int Monovolumen::getPlazas() const {
    return plazas;
}

void Monovolumen::mostrarMono() {
    mostrarAuto();
    cout << "\n\t Largo: " << largo << endl;
    cout << "\n\t Plazas: " << plazas << endl;
}
