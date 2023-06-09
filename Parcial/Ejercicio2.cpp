// Santiago Valderrama


#include <iostream>
#include <string>
#include <vector>
#include "template.h"


using namespace std;



int main () {

    CPrueba <int> p1 (4);
    CPrueba <string> p2 (3);

    p2.incluirElemento("Hola");
    cout << p2.devolverElemento();
    return 0;
}
