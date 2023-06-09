/*----------------------------------------------------------------
   Ejercicio que aparece en la teorÍ­a de SOBRECARGA DE OPERADORES
| ----------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Rectangulo
{	private :
        int ladox;
        int ladoy;
        
    public :
        Rectangulo (void);
        Rectangulo (int x, int y);

        void mostrarLados (void);
        int getladoX()const;
        int getladoY()const;
        int calcularArea (void) const;
        int calcularPerimetro (void) const;

        // Operador BINARIO CON UN PARÁMETRO
        Rectangulo operator +(const Rectangulo &r);
        Rectangulo operator -(const Rectangulo &r);
        bool operator >(const Rectangulo &r);
        bool operator <(const Rectangulo &r);
        bool operator ==(const Rectangulo &r);

        //Rectangulo suma (const Rectangulo &r);
};

// Operador BINARIO

Rectangulo operator +(const Rectangulo &r1, const Rectangulo &r2);
Rectangulo operator -(const Rectangulo &r1, const Rectangulo &r2);
bool operator >(const Rectangulo &r1, const Rectangulo &r2);
bool operator <(const Rectangulo &r1, const Rectangulo &r2);
bool operator ==(const Rectangulo &r1, const Rectangulo &r2);


// Programa Principal
int main(void)
{
    Rectangulo R1(5, 7), R2(20, 2), Rsuma1, Rsuma2;

    cout << "\n\n\tDatos del rectangulo R1 " << endl;
    cout << "\t======================= " << endl;
    R1.mostrarLados ();

    cout << "\n\n\tDatos del rectangulo R2 " << endl;
    cout << "\t======================= " << endl;
    R2.mostrarLados ();

    // El objeto Rsuma tendrÃ¡ ladox = 25 y ladoy = 9
    Rsuma1 = R1 + R2;

    cout << "\n\n\tDatos del rectangulo Rsuma " << endl;
    cout << "\t========================== " << endl;
    Rsuma1.mostrarLados ();

    // Forma con un mÃ©todo que suma rectÃ¡ngulos
    //Rsuma2 = R1.suma(R2);

    cout << "\n\n\tDatos del rectangulo Rsuma " << endl;
    cout << "\t========================== " << endl;
    Rsuma2.mostrarLados ();

    cout << "\n\tEl area del objeto Rsuma es: " << Rsuma1.calcularArea();
    cout << "\n\tSu perimetro es " << Rsuma1.calcularPerimetro() << endl << endl;

    cout << "\n\n\t";
    return 0;
}

Rectangulo::Rectangulo (void)  {
        ladox=0;
        ladoy=0;
}

Rectangulo::Rectangulo (int x, int y)  {
        ladox = x;
        ladoy = y;
}

int Rectangulo::getladoX()const {
    return ladox;
}
int Rectangulo::getladoY()const {
    return ladoy;
}

int Rectangulo::calcularArea (void) const  {
    return ladox * ladoy;
}

int Rectangulo::calcularPerimetro (void) const {
    return 2*(ladox + ladoy);
}

// OPERADOR BINARIO CON UN PARÃMETRO
Rectangulo Rectangulo::operator +(const Rectangulo &r)  {
    return Rectangulo (ladox + r.getladoX(), ladoy + r.getladoY());
}

Rectangulo Rectangulo::operator -(const Rectangulo &r)  {
    return Rectangulo (ladox + r.getladoX(), ladoy + r.getladoY());
}

bool Rectangulo::operator >(const Rectangulo &r)  {
    
    if (calcularArea() > r.calcularArea()) {
        return true;
    }
    else return false;

}

bool Rectangulo::operator <(const Rectangulo &r)  {
    
    if (calcularArea() < r.calcularArea()) {
        return true;
    }
    else return false;

}

bool Rectangulo::operator ==(const Rectangulo &r)  {
    
    if (calcularArea() == r.calcularArea()) {
        return true;
    }
    else return false;

}

// OPERADOR BINARIO
Rectangulo operator +(const Rectangulo &r1, const Rectangulo &r2)  {
    return Rectangulo(r1.getladoX() + r2.getladoX(), r1.getladoY() + r2.getladoY());
}

Rectangulo operator -(const Rectangulo &r1, const Rectangulo &r2)  {
    return Rectangulo(r1.getladoX() - r2.getladoX(), r1.getladoY() - r2.getladoY());
}

bool operator >(const Rectangulo &r1, const Rectangulo &r2)  {
    
    if (r1.calcularArea() > r2.calcularArea()) return true;
    else return false; 
}

bool operator <(const Rectangulo &r1, const Rectangulo &r2)  {
    
    if (r1.calcularArea() < r2.calcularArea()) return true;
    else return false; 
}

bool operator ==(const Rectangulo &r1, const Rectangulo &r2)  {
    
    if (r1.calcularArea() == r2.calcularArea()) return true;
    else return false; 
}
void Rectangulo::mostrarLados (void)  {
        cout << "\n\tEl lado horizontal vale: " << ladox;
        cout << "\n\tEl lado vertical vale: " << ladoy << endl;
}