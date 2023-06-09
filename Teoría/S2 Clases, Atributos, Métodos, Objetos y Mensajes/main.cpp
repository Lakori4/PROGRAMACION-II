#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Persona {

    private:

        string nombre;
        string apellido;
        int edad;

    public:
        void setNombre(string const &n);
        void setEdad(int a);
        void setApellido(string const &a);

        string getNombre() const;
        string getApellido() const;
        int getEdad() const;
        void mostrar()const;
        bool esCoetaneo (Persona const &a);
};

int menu();

Persona getPersona(int i);

int main () {

    vector <Persona> personas;
    bool exit = false;
    string nom;

    do {

        switch (menu()) {

            case 1:
                
                int n;
                cout << "\nEscribe el número de personas que quieres añadir: ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    
                    personas.push_back(getPersona(i));
                }
                
                break;
            
            case 2:

                for (int i = 0; i < personas.size(); i++) {
                
                    cout << "\nPersona " << i+1 << endl;
                    personas[i].mostrar();
                }
                
                break;

            case 3: 

                
                cout << "\nEscribe el nombre o apellido de la persona que quieres buscar: ";
                cin >> nom;
                n = 0;

                for (int i = 0; i < personas.size(); i++) {

                    if (personas[i].getNombre() == nom || personas[i].getApellido() == nom) {

                        cout << "\n\nSe ha encontrado esta persona";
                        cout << "\nPersona " << i+1 << endl;
                        personas[i].mostrar();
                        n = 1;
                    }
                }

                if (n != 1) {cout << "\n\tNO SE HAN ENCONTRADO RESULTADOS";}

                break;

            case 4:

                exit = true;
                return 0;

                break;
        };

    } while (exit == false);
}


//---------------------------------------------------------
    void Persona::setEdad(int a){

        if (a < 0) {

            edad = 0;
            cout << "\n\n\tError, la edad toma el valor 0" << endl;
        }

        else {

            edad = a;
        }
        
    }

    void Persona::setNombre(string const &n) {

        nombre = n;
    }

    void Persona::setApellido(string const &a) {

        apellido = a;
    }

    string Persona::getNombre() const {

        return nombre;
    }

    string Persona::getApellido() const {

        return apellido;
    }


    int Persona::getEdad() const {

        return edad;
    }

    void Persona::mostrar() const {

        cout << "\n\n\tNombre: " << nombre;
        cout << "\n\tApellido: " << apellido;
        cout << "\n\tEdad: " << edad;
    }

    bool Persona::esCoetaneo (Persona const &a) {

        if (edad == a.edad) {

            return true;
        }

        else {

            return false;
        }
    }

    int menu () {

        int i;
        cout << "\n\nEscoja una opción.\n\n\t1. Introducir tantas personas.\n\t2. Mostrar datos de todas las personas.\n\t3. Buscar una persona y mostrar sus datos.\n\t4. Salir.\n";
        cin >> i;

        return i;
    }

    Persona getPersona (int i) {

        Persona p;
        string nom;
        string apel;
        int edad;

        cout << "\n\n\tEscribe el nombre de la persona " << i+1 << ": ";
        cin >> nom;
        p.setNombre(nom);

        cout << "\n\tEscribe el apellido de la persona " << i+1 << ": ";
        cin >> apel;
        p.setApellido(apel);

        cout << "\n\tEscribe la edad de la persona " << i+1 << ": ";
        cin >> edad;
        p.setEdad(edad);   

        return p;

    }
