// Santiago Valderrama


#include <iostream>


using namespace std;

const double pi = 3.14159265358979;

class Punto
{
private:
    int x, y;
public:
    Punto(): x(0), y(0) {}

    void setPunto();

    void setX(int cX) { x = cX; }
    void setY(int cY) { y = cY; }

    int getX() { return x; }
    int getY() { return y; }

    void mostrar();
    
};

void Punto::setPunto() {

    int cX, cY;

    cout << "Escribe la coordenada X del punto: " ;
    cin >> cX;

    cout << "Escribe la coordenada Y del punto: " ;
    cin >> cY; 

    setX(cX); 
    setY(cY);
}

void Punto::mostrar() {

    cout << "\n\n\tCoordenada x: " << getX() << "\n\tCoordenada y: " << getY();
}

class Circulo : public Punto 
{
private:
    double radio;
public:
    Circulo(): radio (0)  {}

    void setCirculo();

    void setRadio(double r) { radio = r; }
    double getRadio() { return radio; }

    double getDiam() { return 2*radio; }
    double getLong () { return radio*2*pi; }
    double getArea() { return radio*radio*pi; }

    void mostrar(); 
    
};

void Circulo::setCirculo() {

    Punto::setPunto();
    int r;

    cout << "Escribe el radio del circulo: ";
    cin >> r;
    
    setRadio(r);        
}

void Circulo::mostrar() {

    cout << "\n\nCoordenadas del centro: "; 
    Punto::mostrar();
    cout << "\n\nRadio del circulo: " << radio << endl;
}


int menu ();

int main () {

Circulo c1;

int cX, cY;
double r;

while (true) {
    switch (menu())
    {
    case 1:


        c1.setCirculo();
        break;

    case 2:
        c1.mostrar();
        break;

    case 3:
        cout << "\n\n\tEl diámetro del circulo es: " << c1.getDiam();
        break;

    case 4:
        cout << "\n\n\tLa longitud del circulo es: " << c1.getLong();
        break;

    case 5:
        cout << "\n\n\tEl área del circulo es: " << c1.getArea();
        break;

    case 6:

        if (c1.getX() > 0 && c1.getY() > 0) {cout << "\n\n\tEl punto está en el primer cuadrante";}
        if (c1.getX() < 0 && c1.getY() > 0) {cout << "\n\n\tEl punto está en el segundo cuadrante";}
        if (c1.getX() < 0 && c1.getY() < 0) {cout << "\n\n\tEl punto está en el tercer cuadrante";}
        if (c1.getX() > 0 && c1.getY() < 0) {cout << "\n\n\tEl punto está en el cuarto cuadrante";}

        else {cout << "\n\n\tNo está en ningún cuadrante";}


        break;

    case 0:
        cout << "\n\n\tGracias por jugar.\n"; return 0;
        break;

    default:
        cout << "\n\n\tEl número introducido no se corresponde con ninguna opción.\n\tVolverás al menu principal.";
        break;
    }
}


}


int menu () {

    int opc;
    cout << "\n\nElige una opción\n\t1. Solicitar datos de un circulo";
    cout << "\n\t2. Mostrar datos del circulo\n\t3. Mostrar diámetro del circulo";
    cout << "\n\t4. Mostrar longitud del circulo\n\t5. Mostrar área del circulo";
    cout << "\n\t6. Mostrar el cuadrante donde está el circulo\n\t0. Salir del programa" << endl;

    cin >> opc;

    return opc;
}
