//SANTIAGO VALDERRAMA FLORES Y GINA RAMIREZ GUERRERO

#ifndef CLASECOMPLEJO_H
#define CLASECOMPLEJO_H

class Complejo
{
private:
    double real, imag;

public:
    // Constructor por defecto e inicializadores
    Complejo() : real(0), imag(0) {}
    Complejo(double r, double i) : real(r), imag(i) {}

    // Métodos get
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Método para restar un valor a la parte real del número complejo
    Complejo restarValor(int v) { return Complejo(real - v, imag); }

    // Sobrecarga del operador -- (predecremento)
    Complejo operator--()
    {
        --real;
        --imag;
        return *this;
    }

    // Sobrecarga del operador -- (posdecremento)
    Complejo operator--(int)
    {
        Complejo temp(*this);
        --real;
        --imag;
        return temp;
    }

    // Función amiga para la sobrecarga del operador -
    friend Complejo operator-(Complejo a, Complejo b);
};

Complejo operator- (Complejo a, Complejo b) {

    return Complejo(a.real - b.real, a.imag - b.imag);
}

ostream& operator<<(ostream& os, Complejo const& nC) {
    os << "Parte real: " << nC.getReal() << ", parte imag: " << nC.getImag();
    return os;
}


#endif // CLASECOMPLEJO_H

