// Santiago Valderrama y Clara Mateo


#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "template.h"


using namespace std;

class Jugador
{
private:
    string n;
    int g = 1;
public:
    Jugador(string nom): n(nom) {}

    string getN() {return n;}
    int getG() {return g;}

    void setN(string nom) {n = nom;}
    int operator++(int) {return g++;}

};



class Celda { friend class Tablero;
private:
    int num {0};
    bool esMina {0}, esBandera {0}, esDescubierta {0};
public:
    Celda() {}
    friend ostream &operator << (ostream& os, const Celda& a);
};

ostream &operator << (ostream& os, const Celda& a) {

    if (a.esBandera) { os << "B";}

    else if (!a.esDescubierta) {os << "-"; }

    else if (a.num == 0) {os << " "; }

    else if (!a.esMina && !a.esBandera) { os << a.num; }    

    else if (a.esMina && !a.esBandera) { os << "X";}


    return os;
}



class Tablero {
private:
    int dificultad {1};
    int minas {0};
    bool gana {1}, pierde {0};
    vector <vector<Celda>> malla;

public:
    Tablero() {}

    void setDificultad (int d) {dificultad = d;}

    bool getGana() { return gana;}
    bool getPierde() { return pierde;}

    friend ostream &operator << (ostream& os, const Tablero& a);
    void setMalla();

    int getCy() {return malla[1].size();}
    int getCx() {return malla.size();}

    void descubrirCelda(int i, int j);
    void setBandera(int i, int j);
    void setGana();
    void descubrirMinas();

};

ostream &operator << (ostream& os, const Tablero& a) {

    system ("cls");

    os << "\n\n\t";
    for (int i = 0; i < a.malla[1].size(); i++) {

        os << " " << i+1;
    }

    for (int i = 0; i < a.malla.size(); i++) {

        os << "\n" << i+1 << "\t|";
        for (int j = 0; j < a.malla[i].size(); j++) {

            mostrar(a.malla[i][j]);
            os << "|";
        }
    } 

    return os;
}


void Tablero::setMalla () {

    if (dificultad == 1) {

        minas = 5;

        malla.resize(6);
        for (int i = 0; i < malla.size(); i++) {

            malla[i].resize(6);
        }

        for (int i = 0; i < minas; i++) {
            int rX{rand() % 6}, rY{rand() % 6};

            if (malla[rX][rY].esMina) {

                rX = rand() % 6; 
                rY = rand() % 6;

                i--;
            }

            else {
                malla[rX][rY].esMina = true;
            }
        }
    }

    if (dificultad == 2) {

        minas = 10;

        malla.resize(9);
        for (int i = 0; i < malla.size(); i++) {

            malla[i].resize(9);
        }

        for (int i = 0; i < minas; i++) {
            int rX{rand() % 9}, rY{rand() % 9};

            if (malla[rX][rY].esMina) {

                rX = rand() % 6; 
                rY = rand() % 6;

                i--;
            }

            else {
                malla[rX][rY].esMina = true;
            }
        }
    }

    if (dificultad == 3) {
        int x, y;

        cout << "\n\n\tIntroduce la anchura del tablero: ";
        cin >> x;
        cout << "\n\tIntroduce la altura del tablero: ";
        cin >> y;
        cout << "\n\tIntroduce la cantidad de minas: ";
        cin >> minas;

        malla.resize(y);
        for (int i = 0; i < malla.size(); i++) {

            malla[i].resize(x);
        }

        for (int i = 0; i < minas; i++) {
            int rX{rand() % x}, rY{rand() % y};

            if (malla[rY][rX].esMina) {

                rX = rand() % 6; 
                rY = rand() % 6;

                i--;
            }

            else { malla[rY][rX].esMina = true; }
        }
    }

    for (int i = 0; i < malla.size(); i++) {
        for (int j = 0; j < malla[i].size(); j++) {

            if (malla[i][j].esMina) {

                for (int i2 = -1; i2 < 2; i2++) {
                    for (int j2 = -1; j2 < 2; j2++) {

                        if (!(i+i2 < 0 || i+i2 >= malla.size() || j+j2 < 0 || j+j2 >= malla[i].size())) {
                    
                            malla[i+i2][j+j2].num++;
                            
                        }
                    }
                }
            }
        }   
    }
} 

void Tablero::descubrirCelda(int i, int j) {

    i--;
    j--;

    malla[i][j].esDescubierta = true;

    if (malla[i][j].esMina && !malla[i][j].esBandera) { pierde = true;}

    if (malla[i][j].num == 0) {

        for (int i2 = -1; i2 < 2; i2++) {
            for (int j2 = -1; j2 < 2; j2++) {

                if (!(i+i2 < 0 || i+i2 >= malla.size() || j+j2 < 0 || j+j2 >= malla[i].size() || malla[i+i2][j+j2].esDescubierta) && !(i2 == 0 && j2 == 0)) {

                    descubrirCelda(i+i2+1, j+j2+1);
                    
                }
            }
        }
    }
}

void Tablero::setBandera(int i, int j) {
    
    if (malla[i-1][j-1].esBandera)   malla[i-1][j-1].esBandera = false;
    else if (!malla[i-1][j-1].esBandera)   malla[i-1][j-1].esBandera = true;
}

void Tablero::setGana() {

    gana = true;
    for (int i = 0; i < malla.size(); i++) {
        for (int j = 0; j < malla[i].size(); j++) {
            if (!malla[i][j].esMina && !malla[i][j].esDescubierta) {
                gana = false;
            }
        }
    }
}

void Tablero::descubrirMinas() {
    for (int i = 0; i < malla.size(); i++) {
        for (int j = 0; j < malla[i].size(); j++) {
            if (malla[i][j].esMina) malla[i][j].esDescubierta = true;
        }
    } 
}


int menu ();

void mostrarLeaderboard(vector <Jugador> l);

int main () {
    
    
    srand (time(NULL));

    int opc;
    int x, y, c;
    vector <Jugador> leaderBoard;
    string n;
    bool existe;

        do {
            opc = menu ();

            Tablero T1;
            if (opc == 0) {break;}
             
            T1.setDificultad(opc);
            T1.setMalla();

            cout << endl;
            do
            {
                do {

                cout << T1;

                cout << "\n\n\t¿Cavas o plantas?";
                cout << "\n\t1. Cavas una casilla";
                cout << "\n\t2. Plantas (o quitas) una bandera de una casilla" << endl;

                cin >> c;

                } while (c != 1 && c != 2);
                
                do {

                cout << "\n\n\tIntroduce la columna de la casiila: ";
                cin >> y;
                cout << "\n\tIntroduce la fila de la casilla: ";
                cin >> x;

                } while (y > T1.getCy() || x > T1.getCx());


                if (c == 1) T1.descubrirCelda(x, y);

                if (c == 2) T1.setBandera(x, y);
                
                T1.setGana();
                 

            } while (!T1.getGana() && !T1.getPierde());



            if (T1.getGana()) {
                
                
                
                
                cout << T1 << "\n\n\t";

                cout << "\n\n\tHAS GANADO\n\n\t";
                
                cout << "Escribe tu nombre: ";
                cin >> n;

                existe = false;

                for (int i = 0; i < leaderBoard.size(); i++) {
                    if (n == leaderBoard[i].getN()) {
                        leaderBoard[i]++;
                        existe = true;

                    }
                }

                if (existe == false) {
                    leaderBoard.push_back(Jugador(n));
                }

                mostrarLeaderboard(leaderBoard);
            }


            if (T1.getPierde()) {

                T1.descubrirMinas();
                cout << T1 << "\n\n";

                cout << "\n\n\tHAS PERDIDO\n\n\t";
            }

            


            system("pause");
            system("cls");
            
            
        } while (opc != 0);
        
        return 0;
}

int menu () {

    int opc;

    do
    {
        system("cls");
        cout << "\n\n\tBienvenido al Buscaminas";
        cout << "\n\nSelecciona un nivel de dificultad";
        cout << "\n\t1. Fácil: 6x6 con 5 minas";
        cout << "\n\t2. Experto: 9x9 con 10 minas";
        cout << "\n\t3. Personalizado";
        cout << "\n\t0. Salir\n";

        cin >> opc;
    
    } while (opc < 0 || opc > 3);
    
    return opc;
}

void mostrarLeaderboard(vector <Jugador> l) {

system("cls");
    cout << "\n\n\tTABLA DE PUNTUACIONES";

    cout << "\n\n  Jugador\tPartidas ganadas\n";

    for (int i = 0; i < l.size(); i++) {

        cout << "\n  " << l[i].getN();
        cout << "\t\t\t" << l[i].getG();    
    }

    cout << "\n\n\n";

}