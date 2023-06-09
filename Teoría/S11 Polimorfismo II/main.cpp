// Santiago Valderrama


#include <iostream>
#include <string>


using namespace std;

class poligono {

public:
    virtual void darAlta();
    virtual string getNombre();

    virtual ~poligono() {}
};


class regular : public poligono
{
private:
    int numLados = 3;
public:
    regular() {}

    void darAlta();
    int getNumLados() {return numLados;}
    ~regular () {}
};

class cuadrado : public regular
{
private:
    int lado = 1;

public:
    cuadrado () {}
    void darAlta();
    string getNombre() {return "cuadrado";}
    int getLado() {return lado;}
    ~cuadrado () {}
};


class triangulo : public regular
{
private:
    int base = 1;
    int altura = 1;
public:
    triangulo () {}
    ~triangulo () {}
};

int menu() ;


int main () {


    do
    {
        switch (menu())
        {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;

        case 3 :
            /* code */
            break;

        case 0:
            
            break;
        
        default:
            cout << "\n\n\tERROR, opción desconocida";
            break;
        }
    } while (true);
    
    return 0;
}


int menu () {

    int opc;
    cout << "\n\n\t1. Dar de alta cuadrado\n\t2. Dar de alta triangulo\n\t3. Mostrar polígonos regulares\n\t0. Salir.\n\n";
    cin >> opc;

    return opc;
}
