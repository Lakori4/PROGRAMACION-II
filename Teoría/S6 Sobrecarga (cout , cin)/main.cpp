// Santiago Valderrama


#include <iostream>


using namespace std;

class Complejo
{
private:
    int real;
    int imag;
public:
    Complejo(/* args */): real(0), imag(0){}
    Complejo (int r, int i): real (r), imag (i){}

    void setReal (int n);
    void setImag (int n);

    int getReal();
    int getImag();

    Complejo operator +(Complejo &c) const;
    Complejo operator -(Complejo &c) const;
    Complejo operator *(Complejo &c) const;
    Complejo operator /(Complejo &c) const;

    friend Complejo operator ++(Complejo &c, int);
    friend Complejo operator --(Complejo c, int);
    friend ostream &operator << (ostream &os, Complejo const &c);
    friend ostream &operator >> (ostream &os, Complejo const &c);
    
};


void Complejo::setReal (int n) {
    real = n;
}

void Complejo::setImag (int n) {
    imag = n;
}

int Complejo::getReal () {
    return real;
}

int Complejo::getImag () {
    return imag;
}

Complejo Complejo::operator+ (Complejo &c) const {

    return Complejo (real + c.getReal(), imag + c.getImag());
}

Complejo Complejo::operator- (Complejo &c) const {

    return Complejo (real - c.getReal(), imag - c.getImag());
}

Complejo Complejo::operator* (Complejo &c) const {

    return Complejo ((real * c.getReal()) - (imag * c.getImag()), (real * c.getImag()) + (imag * c.getReal()));
}

Complejo Complejo::operator/ (Complejo &c) const {

    return Complejo ((real * c.getReal()) + (imag * c.getImag()) / ((c.getReal() * c.getReal()) + (imag * imag)), (imag * c.getReal()) - (real * c.getImag()) / ((c.getReal() * c.getReal()) + (imag * imag)));
}



Complejo operator+ (Complejo &c1, Complejo &c2){
    return Complejo (c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}

Complejo operator- (Complejo &c1, Complejo &c2){
    return Complejo (c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
}

Complejo operator* (Complejo &c1, Complejo &c2){
    return Complejo ((c1.getReal() * c2.getReal()) - (c1.getImag() * c2.getImag()), (c1.getReal() * c2.getImag()) + (c1.getImag() * c2.getReal()));
}

Complejo operator/ (Complejo &c1, Complejo &c2){
    return Complejo ((c1.getReal() * c2.getReal()) + (c1.getImag() * c2.getImag()) / ((c2.getReal() * c2.getReal()) + (c1.getImag() * c1.getImag())), (c1.getImag() * c2.getReal()) - (c1.getReal() * c2.getImag()) / ((c2.getReal() * c2.getReal()) + (c1.getImag() * c1.getImag())));

}

Complejo operator ++(Complejo &c, int) {

    c.real++;
    c.imag++;

    return c;
}

Complejo operator --(Complejo c, int) {


    c.real--;
    c.imag--;

    return c;
}

ostream &operator << (ostream &os, Complejo const &c) {

    os << "Parte Real: " << c.real << "\nParte Imaginaria: " << c.imag;
    return os;
}

int main () {

    Complejo c (0, 3);

    c++;
    
    cout << c << endl;

    return 0;
}
