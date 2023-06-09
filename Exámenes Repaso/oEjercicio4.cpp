// Santiago Valderrama


#include <iostream>
#include <vector>

using namespace std;



class Persona
{
private:
    string nombre;
    int anioNacimiento;
public:
    Persona(string n, int a);

    void setNombre(string n) { nombre = n; }
    void setAnio(int a);

    string getNombre() { return nombre; }
    int getAnio() { return anioNacimiento; }

    virtual ~Persona() { cout << "\n\n\t" << nombre << "ha muerto"; }
};

Persona::Persona(string n, int a)
{
    if (a <= 1900) throw 1;

    nombre = n;
    anioNacimiento = a;
}

void Persona::setAnio(int a) {
    if (a <= 1900) throw 1;
    anioNacimiento = a;
}


class Bombero: public Persona
{
private:
    int fuegosApagados, lBiceps;
public:
    Bombero(string n, int a, int fA, int lB);
    Bombero(string n, int a, const Bombero &b);

    void setfApagado (int fA) {if (fA <= 0) throw 2; fuegosApagados = fA;}
    void setlBiceps (int lB) {if (lB <= 0) throw 2; lBiceps = lB;}

    int getlBiceps () { return lBiceps; }
    int getfApagado () { return fuegosApagados; }
    ~Bombero() {}
};

Bombero::Bombero(string n, int a, int fA, int lB): Persona (n, a)
{
    if (fA <= 0 || lB <= 0) throw 2;   
    
    fuegosApagados = fA; 
    lBiceps = lB;
}

Bombero::Bombero(string n, int a, const Bombero &b): Persona (n, a) {

    fuegosApagados = b.fuegosApagados;
    lBiceps = b.lBiceps;
}

class Futbolista: public Persona
{
private:
    int goles, millones;
public:
    Futbolista(string n, int a, int g, int m);
    Futbolista(string n, int a, const Futbolista&f);

    int getMillones() { return millones; }
    ~Futbolista();
};

Futbolista::Futbolista(string n, int a, int g, int m): Persona(n, a)
{
    if (g < 0 || m < 0) throw 3;    

    goles = g;
    millones = m;
}

Futbolista::Futbolista(string n, int a, const Futbolista&f): Persona(n, a) {

    goles = f.goles;
    millones = f.millones;
}

Futbolista::~Futbolista()
{
}



int main () {

    try{

    vector <shared_ptr<Persona>> vectorPersonas;
    vectorPersonas.push_back(make_shared<Bombero>("Juan", 2003, 22, 18));
    vectorPersonas.push_back(make_shared<Futbolista>("Juan", 2003, 22, 18));

    for (int i = 0; i < vectorPersonas.size(); i++)
    {
        cout << "\n\n\tEl nombre de esta persona es: " << vectorPersonas[i]->getNombre();
        cout << "\n\tEl año de nacimiento de esta persona es el: " << vectorPersonas[i]->getAnio();

        Bombero* B_ptr = dynamic_cast <Bombero*> (vectorPersonas[i].get());
        Futbolista* F_ptr = dynamic_cast <Futbolista*> (vectorPersonas[i].get());
        if (B_ptr != nullptr) {cout << "\n\tLa longitud de su bíceps es de: " << B_ptr->getlBiceps();}
        if (F_ptr != nullptr) {cout << "\n\tLos millones que tiene en su banco son: " << F_ptr->getMillones();}
    }
    
    }

    catch (int e) {

        if (e == 1) {cout << "\n\n\tEl año de nacimiento es anterior a 1900";}
        if (e == 2) {cout << "\n\n\tLos fuegos apagados o la longitud del biceps son menores o iguales a 0";}
        if (e == 3) {cout << "\n\n\tLos goles marcados o los millones ganados son menores que 0";}
    }
    
    
    
    
    
    return 0;
    
}
