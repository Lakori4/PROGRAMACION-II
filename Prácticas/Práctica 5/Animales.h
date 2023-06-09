//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMÍREZ GUERRERO
#ifndef ANIMALES_H
#define ANIMALES_H

#include <iostream>
#include <string>
using namespace std;

//---------------CLASE ANIMAL DOMESTICO---------------------
class ADomestico {

    public:
        string pedirIdentificacion();

        ~ADomestico() {}

    
};

//---------------CLASE PERRO---------------------
class Perro: public ADomestico {
protected:
    string nombre;
    string fecha;
public:
    Perro() :nombre{ " " }, fecha{ " " } {};
    Perro(string& n, string& f) :nombre(n), fecha(f) {};

    void pedirIdentificacion();
    void conocerOnomatopeya() const;
    string getNombre() const;
    string getFecha() const;
    string verTipo()const;


};

//---------------CLASE GATO---------------------
class Gato: public ADomestico {
protected:
    string nombre;
    string fecha;
public:
    Gato() :nombre{ " " }, fecha{ " " } {};
    Gato(string& n, string& f) :nombre(n), fecha(f) {};

    void pedirIdentificacion();
    void conocerOnomatopeya() const;
    string getNombre() const;
    string getFecha() const;
    string verTipo()const;

};

//---------------CLASE AVE---------------------
class Ave: public ADomestico  {
    protected:
        string fecha;
    public:

        Ave(): fecha(""){}
        Ave(string &f): fecha(f) {}
        string getFecha() {return fecha;}
        void setFecha(const string &f) {fecha = f;}
    
};

//---------------CLASE POLLITO---------------------
class Pollito: public Ave  {

    public:
        Pollito(){}
        Pollito(const string &f) {Ave::setFecha(f);}
        string verTipo() {return "Ave";}
        void conocerOnomatopeya() {cout << "\n\t El pollito dice: " <<  "PIO PIO" << endl;}
        void pedirIdentificacion() {setFecha(ADomestico::pedirIdentificacion());}
    
    
};

//---------------CLASE PATO---------------------
class Pato: public Ave {

    public:
        Pato() {}
        Pato(const string &f) {Ave::setFecha(f);}
        string verTipo() {return "Ave";}
        void conocerOnomatopeya() {cout << "\n\t El pato dice: " <<  "CUAC CUAC" << endl;}
        void pedirIdentificacion() {setFecha(ADomestico::pedirIdentificacion());}
   
};

#endif // ANIMALES_H
