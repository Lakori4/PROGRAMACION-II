#include <iostream>

using namespace std;

int menu ();
int pedirNum ();

class CalcularNumPositivo {
    private:
        float num = 0, res = 0;

    public:
        CalcularNumPositivo();

        void setNum (float a);
        void setRes(float a);

        void sumaNum (float a);
        void restaNum (float a);
        void multiplicaPor (float a);
        void dividepor (float a);

        float getNum();
        float getRes();

        ~CalcularNumPositivo();
};

CalcularNumPositivo::CalcularNumPositivo() {
    num = 0;
    res = 0;
}


void CalcularNumPositivo::setNum(float a) {
    num = a;
}

void CalcularNumPositivo::setRes(float a) {
    res = a;
}



void CalcularNumPositivo::sumaNum(float a) {

    res = num + a;
    cout << "\n\n\tEl resultado de sumar " << num << " más " << a << " es igual a: " << res << endl;
    num = res;
}

void CalcularNumPositivo::restaNum(float a) {

    res = num - a;
    cout << "\n\n\tEl resultado de restar " << num << " menos " << a << " es igual a: " << res << endl;
    num = res;
}

void CalcularNumPositivo::multiplicaPor (float a) {

    res = num * a;
    cout << "\n\n\tEl resultado de multiplicar " << num << " por " << a << " es igual a: " << res << endl;            
    num = res;
}

void CalcularNumPositivo::dividepor(float a) {

    if (a == 0) {
        throw 1;
    }

    else {
        res = num / a;
        cout << "\n\n\tEl resultado de dividir " << num << " entre " << a << " es igual a: " << res << endl;
        num = res;
    }

}



float CalcularNumPositivo::getNum() {
    return num;
}

float CalcularNumPositivo::getRes() {
    return res;
}

CalcularNumPositivo::~CalcularNumPositivo() {}


int main () {

CalcularNumPositivo num;

    while (true)
    {

        float a;
        

        switch (menu()) {

        case 1:
            
            a = pedirNum();
            num.sumaNum(a);

            
            
            break;

        case 2:
            
            a = pedirNum();
            num.restaNum(a);

            break;

        case 3:
            
            a = pedirNum();
            num.multiplicaPor(a);

            break;

        case 4:
            
            a = pedirNum();

            try {

                num.dividepor(a);
            }

            catch (int error) {

                cout << "\n\n\tEL DIVISOR NO PUEDE SER CERO";
            }

            catch (string error) {
                cout << "Bruh";
            }


           
            break;

        case 5:
            
            cout << "¡Hasta pronto!";
            return 0;
            break;
        
        default:

            cout << "\nLA OPCIÓN ESCOGIDA NO ES VÁLIDA\n";
            break;
         
        }  
    }
}


int menu () {

    int a;

    do
    {
        cout << "\n\nIntroduzca el número correspondiente con su selección.\n";
        cout << "1. Sumar\n2. Restar\n3, Multiplicar\n4. Dividir\n5. Salir\n";

        cin >> a;
        if (cin.fail()) {system("cls");}

    } while (cin.fail());
    
    return a;   
}

int pedirNum () {

    int a;

    do
    {


        cout << "Introduzca un número: ";

        cin >> a;
        
        if (cin.fail()) {system("cls");}

    } while (cin.fail());
    
    return a;   
}