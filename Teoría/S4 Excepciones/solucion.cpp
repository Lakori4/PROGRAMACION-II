#include <iostream>
#include <string>

using namespace std;

class CalcularNumPositivo {
    private:
        int numero;
        double resultado;

    public:
        CalcularNumPositivo();
        CalcularNumPositivo(const CalcularNumPositivo &obj);

        void setNumero(float num);
        float getNumero() const;
        void setResultado(float res);
        float getResultado() const;

        float sumaNum(float num);
        float restaNum(float num);
        float multiplicaPor(float num);
        float dividePor(float num);

        class DivisionPorCeroException : public exception {
            public:
                const char* what() const throw();
        };

        class DivisionPorNegativoException : public exception {
            public:
                const char* what() const throw();
        };
};


int main() {
    CalcularNumPositivo calc;
    float num;
    cout << "Introduce un número: ";
    cin >> num;
    calc.setNumero(num);
    cout << "Introduce otro número para sumar: ";
    cin >> num;
    float suma = calc.sumaNum(num);
    float resta= calc.restaNum(num);
    float product = calc.multiplicaPor(num);
    float division = calc.dividePor(num);
    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "El producto es: " << product << endl;
    cout << "La division es: " << division << endl;
    return 0;
}


CalcularNumPositivo::CalcularNumPositivo() {
}

CalcularNumPositivo::CalcularNumPositivo(const CalcularNumPositivo &obj) {
}

void CalcularNumPositivo::setNumero(float num) {
    numero = num;
}

float CalcularNumPositivo::getNumero() const {
    return numero;
}

void CalcularNumPositivo::setResultado(float res) {
    resultado = res;
}

float CalcularNumPositivo::getResultado() const {
    return resultado;
}

float CalcularNumPositivo::sumaNum(float num) {
    resultado = numero + num;
    return resultado;
}

float CalcularNumPositivo::restaNum(float num) {
    resultado = numero - num;
    return resultado;
}

float CalcularNumPositivo::multiplicaPor(float num) {
    resultado = numero * num;
    return resultado;
}

float CalcularNumPositivo::dividePor(float num) {
    if (num == 0) {
        throw DivisionPorCeroException();
    }
    else if (num < 0) {
        throw DivisionPorNegativoException();
    }
    else {
        resultado = numero / num;
        return resultado;
    }
}

const char* CalcularNumPositivo::DivisionPorCeroException::what() const throw() {
    return "Error: división por cero";
}

const char* CalcularNumPositivo::DivisionPorNegativoException::what() const throw() {
    return "Error: división por número negativo";
}