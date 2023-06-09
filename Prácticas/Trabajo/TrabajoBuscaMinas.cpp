#include <iostream>
#include <vector>



using namespace std;

class Celda
{
private:
    int x, y;
    bool mina = false;
    bool descubierta = false;
    bool señalada = false;

public:
    Celda(int w, int h) : x(w), y(h) {}

    void imprimir()
    {
        cout << "Celda " << x << ", " << y << " con mina? " << mina << "\n";
    }

    void setMina () {
        mina = true;
    }

    bool getMina()
    {
        return mina;
    }

    bool getDescubierta()
    {
        return descubierta;
    }

    void setDescubierta ()
    {
       descubierta = true;
    }

    bool getSeñalada()
    {
        return señalada;
    }

    void setSeñalada ()
    {
       señalada = true;
    }
};

class Tablero
{
private:

    int altura, anchura;

    vector<vector<Celda>> malla;

public:

    Tablero(int w, int h)
    {
        altura = h;
        anchura = w;
        int x, y;

        for (y = 0; y < altura; y++)
        {
            vector<Celda> fila;
            for (x = 0; x < anchura; x++)
            {
                fila.push_back((Celda(x, y)));
            }
            malla.push_back(fila);
        }
    }

    void colocarMina(int x, int y)
    {
        return malla.[x][y].setMina();
    }

    int obtenerAltura()
    {
        return altura;
    }
    int obtenerAnchura()
    {
        return anchura;
    }
    
            
    bool descubrir(int x, int y) //Regresa false si había una mina. true en caso contrario
    {
        malla[x][y].setDescubierta();

        if (malla[x][y].getMina())
        {
            return false;
        }
        return true;
    }

    int contarCeldasSinMinasYSinDescubrir()
    {
        int x, y, conteo = 0;
        for (y = 0; y < this->altura; y++)
        {
            for (x = 0; x < this->anchura; x++)
            {
                Celda c = this->malla.at(y).at(x);
                if (!c.estaDescubierta() && !c.tieneMina())
                {
                    conteo++;
                }
            }
        }
        return conteo;
    }
};

class Juego
{
private:
    Tablero tablero;
    int cantidadMinas;

    int aleatorio_en_rango(int minimo, int maximo)
    {
        return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
    }

    int filaAleatoria()
    {
        return this->aleatorio_en_rango(0, this->tablero.obtenerAltura() - 1);
    }

    int columnaAleatoria()
    {
        return this->aleatorio_en_rango(0, this->tablero.obtenerAnchura() - 1);
    }

public:
    Juego(Tablero tablero, int cantidadMinas)
    {
        this->tablero = tablero;
        this->cantidadMinas = cantidadMinas;
        this->colocarMinasAleatoriamente();
    }

    void colocarMinasAleatoriamente()
    {
        int x, y, minasColocadas = 0;

        while (minasColocadas < this->cantidadMinas)
        {
            x = this->columnaAleatoria();
            y = this->filaAleatoria();
            if (this->tablero.colocarMina(x, y))
            {
                minasColocadas++;
            }
        }
    }

    /*
        solicitarFila y solicitarColumna piden la fila y columna del 1 al N, pero
        recordemos que los índices se manejan del 0 al N-1, por eso es que se resta 1
    */

    int solicitarFila()
    {
        int fila = 0;
        cout << "Ingresa la fila: ";
        cin >> fila;
        return fila - 1;
    }

    int solicitarColumna()
    {
        int columna = 0;
        cout << "Ingresa la columna: ";
        cin >> columna;
        return columna - 1;
    }

    bool jugadorGana()
    {
        int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
        if (conteo == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void iniciar()
    {
        int fila, columna;
        while (true)
        {
            this->tablero.imprimir();
            fila = this->solicitarFila();
            columna = this->solicitarColumna();
            bool ok = this->tablero.descubrir(columna, fila);
            if (!ok)
            {
                cout << "Perdiste\n";
                // El modo programador te permite ver todo. Entonces lo activamos y volvemos a imprimir. No hay problema porque el jugador ya perdió
                this->tablero.setModoProgramador(true);
                this->tablero.imprimir();
                break;
            }

            if (this->jugadorGana())
            {
                cout << "Ganaste\n";
                this->tablero.setModoProgramador(true);
                this->tablero.imprimir();
                break;
            }
        }
    }
};

int main()
{

        int opcion;
        cout << "Selecciona un nivel: " << endl;
        cout << "1. Facil: tablero de 6 filas y 6 columnas con 5 minas." << endl;
        cout << "2. Experto: tablero de 9 filas y 9 columnas con 10 minas." << endl;
        cout << "3. Personalizado." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        int filas, columnas, minas;

        switch (opcion) {
            case 1:
                filas = 6;
                columnas = 6;
                minas = 5;
                break;
            case 2:
                filas = 9;
                columnas = 9;
                minas = 10;
                break;
            case 3:
                cout << "Introduce el numero de filas: ";
                cin >> filas;
                cout << "Introduce el numero de columnas: ";
                cin >> columnas;
                cout << "Introduce el numero de minas: ";
                cin >> minas;
                break;
            default:
                cout << "Opción no válida." << endl;
                return 0;
        }

        Juego juego(Tablero(filas, columnas ), minas);
        juego.iniciar();
        return 0;
    }


