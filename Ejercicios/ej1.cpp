// Santiago Valderrama


#include <iostream>


using namespace std;

const double pi = 3.14159265359;

class circulo
{
private:
    float radio = 10, area = radio*radio*pi;
public:
    circulo() {}; //Constructor por defecto
    //circulo(): radio(10), area(radio*radio*pi) {} // Constructor con incializadores
    circulo(float r, float a): radio(r), area(a){} //Constructor con parámetros
    circulo(const circulo &c) {radio = c.radio;} //Constructor copia

    void setRadio(int r) {radio = r;}

    float getRadio() {return radio;}
    float getArea() {return area;}

    void calcularArea() {area = radio*radio*pi;}

    ostream& operator<< (ostream& out);
};

ostream& circulo::operator<< (ostream& os) {

    calcularArea();
    
    os << "\n\n\tRadio: " << radio << "\n\tÁrea: " << area;
    
    return os;
}



int main () {

    circulo c1;
    circulo c2 (5, pi);
    return 0;
}
