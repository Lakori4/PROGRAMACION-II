// Santiago Valderrama


#include <iostream>
#include"template.h"
#include <queue>



using namespace std;


int main () {
try{

    MiVector<int> Vi;
    
    Vi.push_back(1);
    Vi.push_back(1);
    Vi.push_back(1);
    Vi.pop_back();
    cout << Vi.at(1);

    MiVector<string> Vs;

    Vs.push_back("Hola");
    Vs.push_back("Hola");
    Vs.push_back("Hola");
    //Vs.pop_back();

    cout << Vs.at(0);

    Perro p1;
    p1.nombre = "Lika";
    p1.chip = 348762;
    p1.edad = 11;

    Perro p2;
    p2.nombre = "Osa";
    p2.chip = 598632;
    p2.edad = 16;

    Perro p3;
    p3.nombre = "Pipa";
    p3.chip = 324090;
    p3.edad = 4;

    MiVector<Perro> Vp;

    Vp.push_back(p1);
    Vp.push_back(p2);
    Vp.push_back(p3);
    //Vp.pop_back();

    cout << Vp.at(0);

    cout << Vi;

}

catch (int e) {

    if (e==0) {cout << "\n\n\tSe ha intentado acceder a una posición que no existe" << endl;}
    
}

    return 0;
}
