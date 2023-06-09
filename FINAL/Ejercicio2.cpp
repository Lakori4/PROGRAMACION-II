// Santiago Valderrama


#include <iostream>
#include <cmath>



using namespace std;

class Vector
{
private:
    int x, y, z;
public:
    Vector(int Cx, int Cy, int Cz);
    Vector(): x(0), y(0), z(0){}

    void setX(int Cx) {CheckForm(Cx, 0, 0); x = Cx;}
    void sety(int Cy) {CheckForm(0, Cy, 0); y = Cy;}
    void setz(int Cz) {CheckForm(0, 0, Cz); z = Cz;}

    int getX() {return x;}
    int getY() {return y;}
    int getZ() {return z;}

    float calcularMagnitud();

    void CheckForm (int Cx, int Cy, int Cz);

    friend ostream &operator<< (ostream&os, const Vector &v);
    ~Vector() {}
};

Vector::Vector(int Cx, int Cy, int Cz)
{
    CheckForm(Cx, Cy, Cz);
    x = Cx;
    y = Cy;
    z = Cz;
}

float Vector::calcularMagnitud() {

    int powX = pow(x, 2);
    int powY = pow(y, 2);
    int powZ = pow(z, 2);

    float Magn = sqrt(powX + powY + powZ);

    return Magn;
}

void Vector::CheckForm (int Cx, int Cy, int Cz)
{
    if (Cx > 999) {throw 0;}
    if (Cy > 999) {throw 1;}
    if (Cz > 999) {throw 2;}
}

ostream &operator<< (ostream&os, const Vector &v) {
    os << "\n\n\tVector X: " << v.x;
    os << "\n\tVector Y: " << v.y;
    os << "\n\tVector Z: " << v.z;

    return os;
}

int main () {
    try {
        Vector V1 (20, 3, 90), V2 (3, 5, 1), V3, V4 (4, 0, 0);

        cout << V1 << "\n\tSu magnitud es: " << V1.calcularMagnitud() << endl;
        cout << V2 << "\n\tSu magnitud es: " << V2.calcularMagnitud() << endl;
        cout << V3 << "\n\tSu magnitud es: " << V3.calcularMagnitud() << endl;
        cout << V4 << "\n\tSu magnitud es: " << V4.calcularMagnitud() << endl;


        Vector V5 (123, 456, 1900);
        cout << V5 << "\n\tSu magnitud es: " << V5.calcularMagnitud() << endl;

    }

    catch (int e) {

        if (e == 0) {cout << "\n\n\tLa coordenada X es mayor que 999." << endl;}
        if (e == 1) {cout << "\n\n\tLa coordenada Y es mayor que 999." << endl;}
        if (e == 2) {cout << "\n\n\tLa coordenada Z es mayor que 999." << endl;}
    }

    return 0;
}
