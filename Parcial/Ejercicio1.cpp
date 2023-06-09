// Santiago Valderrama


#include <iostream>
#include <string>


using namespace std;

class CFecha
{
private:
    
    int mes;
    int ano;
    string texto_libre;
public:
    CFecha(string t, int m, int a);
    CFecha(const CFecha &f) {mes = f.mes; ano = f.ano; texto_libre = f.texto_libre;}

    void setMes(int m);
    void setAno (int a);
    void setTexto (string t) {texto_libre = t;}

    int getMes () {return mes;} 
    int getAno () {return ano;} 
    string getTexto () {return texto_libre;} 
    
    bool operator == (const CFecha &f);

    friend ostream & operator<< (ostream &out, const CFecha &f);
    ~CFecha();
};

CFecha::CFecha(string t, int m, int a)
{

    if (m <= 0 || m >= 13) {

        throw 1;
    }

    if (a > 2023) {

        throw 2;
    }

    else {

        texto_libre = t;
        mes = m;
        ano = a;
    }
}

void CFecha::setMes (int m) {

    if (m <= 0 || m >= 13) {

        throw 1;
    }

    else {

        mes = m;
    }
}

void CFecha::setAno (int a) {

    if (a > 2023) {

        throw 2;
    }

    else {

        ano = a;
    }
}

bool CFecha::operator==(const CFecha &f) {

    if (mes == f.mes && ano == f.ano && texto_libre == f.texto_libre)
        return true;

    else return false;
}


CFecha::~CFecha()
{
}





int main () {

    try {

        int mes;
        int ano;
        string texto;
        

        cout << "Escribe un mes: ";
        cin >> mes;

        cout << "Escribe un año: ";
        cin >> ano;

        cout << "Escribe una descripción de esta fecha: ";
        cin >> texto;

        CFecha F1 (texto, mes, ano);

        CFecha F2 ("F", 8, 2004);

        if (F1 == F2) {
            cout << "Las fechas son iguales";
            cout << "Fecha 1: " << F1;
            cout << "Fecha 2: " << F2;
        }

        else {
            cout << "Las fechas no son iguales";
        }
        
        
    }

    catch (int error) {

        if (error == 1) {

            cout << "\n\n\tEL FORMATO DEL MES NO ES CORRECTO";
        }

        if (error == 2) {

            cout << "\n\n\tEL AÑO ES SUPERIOR A 2023";
        }
    }
    return 0;
}

ostream & operator<< (ostream &out, const CFecha &f) {
    cout << "\n\n\tMes: " << f.mes;
    cout << "\n\n\tAño: " << f.ano;
    cout << "\n\n\tTexto libre: " << f.texto_libre;

    return out;

}
