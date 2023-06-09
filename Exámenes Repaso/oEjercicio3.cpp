// Santiago Valderrama


#include <iostream>
#include <string>

using namespace std;

class coche
{
private:
    string marca;
    string matricula;
    

public:
    coche();

    bool operator> (const coche &c);
    bool operator< (const coche &c) {return !operator> (c);}
    bool operator== (const coche &c);
    bool operator!= (const coche &c) {return !operator== (c);}

    friend ostream &operator<< (ostream &os, const coche &c);
    ~coche();
};

coche::coche() {
    string m, l; 
    int n;

    do
    {
        system("cls");

        cout << "\n\n\tEscribe las 3 letras de la matrícula del coche: ";
        cin >> l;

        cout << "\n\tEscribe los 4 números de la matrícula: ";
        cin >> n;
        
    } while (l.size() != 3 || n < 0 || n > 9999);

    for (int i = 0; i < l.size(); i++) {
        l[i] = toupper(l[i]);
    }

    cout << "\n\tEscribe la marca del coche: ";
    cin >> m;
    
    marca = m;
    matricula = to_string(n) + l;
    
}

bool coche::operator> (const coche &c) {
    if (matricula < c.matricula) return true;
    else return false;
}

bool coche::operator== (const coche &c) {
    if (marca == c.marca && matricula == c.matricula) return true;
    else return false;
}

ostream &operator<< (ostream &os, const coche &c) {


    os << "\n\n\tLa marca del coche es " << c.marca;
    os << "\n\tLa matrícula del coche es " << c.matricula;

    return os;
}
coche::~coche()
{
}





int main () {

    coche c1;
    coche c2;

    if (c1 > c2) cout << "El primer coche es más viejo que el segundo";

    if (c1 != c2) cout << "Los dos coches no son iguales";

    cout << c1 << c2;

    return 0;
    
}
