// Santiago Valderrama y Gina Ramírez
#ifndef VEHICULOS_H
#define VEHICULOS_H

#include <iostream>
#include <string>
using namespace std;

// INCLUIR LA HERENCIA NECESARIA ENTRE CLASES

//---------------CLASE VEHICULO---------------------
class Vehiculo {

    private:
        string  marca;
        long potencia;

    public:
        Vehiculo(): marca("McLaren"), potencia(720) {}
        Vehiculo(string const &m, long p);
        Vehiculo(Vehiculo const &V);

        string getMarca() const { return marca;}
        long getPotencia() const { return potencia;}

        void setMarca(string const &m) { marca = m;}
        void setPotencia(long p) { potencia = p;}


        void mostrarVeh() {

            cout << "\n\n\tMarca del vehiculo: " << marca << endl;
            cout << "\n\n\tPotencia del vehiculo: " << potencia << endl;
        }
    
    // MODIFICAR SEGUN ENUNCIADO
};

//---------------CLASE CAMION---------------------
class Camion: public Vehiculo {
private:
    string categoria;
    string tamano;
public:
    Camion() : categoria{ " " }, tamano{ " " } {}; //Por defecto con inicializadores 
    Camion(string const& c, string  const& t); //Con parametros
    Camion(Camion const& C); //Copia 

    void setCategoria(string const& c);
    string getCategoria() const;

    void setTamano(string const& t);
    string getTamano() const;

    void mostrarCam();
        
    // MODIFICAR SEGUN ENUNCIADO
};

//---------------CLASE AUTOMOVIL---------------------
class Automovil: public Vehiculo  {
    private:
        string combustible;
        int l_deposito;
        char etiquetaECO;
        int velocidadMax;
    
    public:
        Automovil(): combustible("SP98"), l_deposito(70), etiquetaECO('B'), velocidadMax(250) {}
        Automovil(string const &c, int d, int e, int v);
        Automovil(Automovil const &A);

        string getCombustible() const { return combustible;}
        int getL_deposito() const { return l_deposito;}
        char getEtiquetaECO() const { return etiquetaECO;}
        int getVelocidadMax() const { return velocidadMax;}

        void setCombustible(string const &c) { combustible = c;}
        void setL_deposito(int d) { l_deposito = d;}
        void setEtiquetaECO(char e) { etiquetaECO = e;}
        void setVelocidadMax(int v) { velocidadMax = v;}

        void mostrarAuto() {

            mostrarVeh();

            cout << "\n\n\tCombustible: " << combustible;
            cout << "\n\t Capacidad del depósito (L): " << l_deposito;
            cout << "\n\t Etiqueta ECO: " << etiquetaECO;
            cout << "\n\t Velocidad máxima: " << velocidadMax;
        }

    // MODIFICAR SEGUN ENUNCIADO
};

//---------------CLASE MONOVOLUMEN---------------------
class Monovolumen: protected Automovil  {
private:
    int largo;
    int plazas;
public:
    Monovolumen() : largo{ 0 }, plazas{ 0 } {}; //Por defecto con inicializadores
    Monovolumen(int l, int p); //Con parametros
    Monovolumen(Monovolumen const& M);

    void setLargo(int l);
    void setPlazas(int p);

    int getLargo() const;
    int getPlazas() const;

    void mostrarMono();
        
    // MODIFICAR SEGUN ENUNCIADO
};

#endif // VEHICULOS_H