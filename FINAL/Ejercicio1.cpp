// Santiago Valderrama


#include <iostream>


using namespace std;

class Chora
{
private:
    int hora, minuto;
public:
    Chora(): hora(0), minuto(0) {}
    Chora(int h, int m);
    Chora(const Chora &c) {hora = c.hora; minuto = c.minuto;}

    void setHora(int h) {checkForm(h, 0); hora = h; }
    void setMinuto(int m) { checkForm(0, m); minuto = m;}

    int getHora() { return hora;}
    int getminuto() { return minuto; }

    void checkForm(int h, int m);

    friend istream &operator >>(istream &is, Chora &c);
    friend ostream &operator<< (ostream&os, const Chora &c);
    ~Chora() {}
};

Chora::Chora(int h, int m) {
    checkForm(h, m);

    hora = h;
    minuto = m;

}

void Chora::checkForm(int h, int m) {

    bool ok = true;
    if (h < 0 || h > 23) {throw 0;}
    if (m < 0 || m > 59) {throw 1;}
}

istream &operator >> (istream &is, Chora &c)
{   
    int h, m;
    cout << "Introduce la hora: ";
    is >> h;

    cout << "Introduce los minutos: ";
    is >> m;

    c.checkForm(h, m);

    c.setHora(h);
    c.setMinuto(m);

    return is;
    
}

ostream &operator<< (ostream&os, const Chora &c) {
    os << "La hora actual\n\n\t" << c.hora << ":" << c.minuto << endl;

    return os;
}



int main () {
try {
    Chora c1;
    cin >> c1;
    cout << c1;
    
}

catch (int e) {
    if (e == 0) {cout << "La hora es menor que 0 o mayor que 23";}
    if (e == 1) {cout << "Los minutos son menores que 0 o mayores que 59";}
}

return 0;
}
