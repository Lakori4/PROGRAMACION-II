//SANTIAGO VALDERRAMA FLORES Y GINA RAMIREZ GUERRERO

#include <iostream>
#include "claseMatriz.h"
#include "claseComplejo.h"
#include "Funciones.h"

using namespace std;

int main()
{
    // IMPORTANTE: INCLUIR EL TRATAMIENTO DE EXCEPCIONES

    try {
        
        int fil, col;

        //---------------PETICIÓN DE DATOS PARA LAS MATRICES-----------------

        // Peticion de datos para la primera matriz
        cout << "\n\n\tIntroduce el numero de filas de la matriz 1: ";
        cin >> fil;
        cout << "\n\n\tIntroduce el numero de columnas de la matriz 1: ";
        cin >> col;
        Matriz mat1{ fil, col };

        cout << "\n\n\tIntroduce los numeros de la matriz por filas:\n";
        cin >> mat1;

        // Peticion de datos para la segunda matriz
        cout << "\n\n\tIntroduce el numero de filas de la matriz 2: ";
        cin >> fil;
        cout << "\n\n\tIntroduce el numero de columnas de la matriz 2: ";
        cin >> col;
        Matriz mat2{ fil, col };

        cout << "\n\n\tIntroduce los numeros de la matriz por filas:\n";
        cin >> mat2;

        //---------------------OPERACIONES CON MATRICES------------------------

        --mat1;
        cout << "\n\tLa matriz 1 decrementada es:\n" << mat1 << "\n\n";

        Matriz mat3{ fil, col };
        mat3 = mat2--;
        cout << "\n\tLa matriz 3 es: \n" << mat3 << "\n\n";
        cout << "\n\tLa matriz 2 decrementada es:\n" << mat2 << "\n\n";

        Matriz matR = restar(mat1, mat2);
        cout << "\n\tLa matriz 1 es: \n" << mat1 << "\n\n";
        cout << "\n\tLa matriz 2 es: \n" << mat2 << "\n\n";
        cout << "\n\tLa resta obtenida es: \n" << matR << "\n\n";

        Matriz mat4{ fil, col };
        mat4 = decrementar(mat3, 10);
        cout << "\n\tLa matriz 3 decrementada en 10 es: \n" << mat3 << "\n\n";
        cout << "\n\tLa matriz 4 es: \n" << mat4 << "\n\n";

        // Prueba del error 2: 
        //mat4.pos(-1, 3);
    }

    //-----------------------ERRORES ATRAPADOS------------------------------
    
    catch (int error) {

        if (error == 1) {
            cout << "\n\n\tERROR, las dimensiones son incorrectas\n\n";
        }
        else if (error == 2) {
            cout << "\n\n\tERROR, la posicion del elemento es incorrecto\n\n";
        }
        else if (error == 3) {
            cout << "\n\n\tERROR, las dimensiones de las matrices no son correctas\n\n";
        }
    } 

    //-------------------------OPERACIONES CON COMPLEJOS---------------------------

    Complejo nC1(20.7, 13.3);
    Complejo nC2(10.5, 8.5);

    // Forma prefija del operador --
    cout << "\n LA OPERACION ES --x " << endl;
    --nC1;
    cout << "\n El complejo 1 en binomial es: " << nC1 << endl;

    // Forma postfija del operador --
    cout << "\n\n\n LA OPERACION REALIZADA ES nC1 = nC2-- " << endl;
    nC1 = nC2--;
    cout << "\n El complejo 1 en binomial es: " << nC1 << endl;
    cout << "\n El complejo 2 en binomial es: " << nC2 << endl;

    Complejo nCR;

    nCR = restar(nC1, nC2);

    cout << "\n El complejo nCR en binomial es: " << nCR << endl;

    Complejo nC3, nC4(15.5, 18.5);
    cout << "\n\n\n LA OPERACION ES nC3 = nC4-10 " << endl;
    nC3 = decrementar(nC4, 10);

    cout << "\n El complejo nC3 en binomial es: " << nC3 << endl;
    cout << "\n El complejo nC4 en binomial es: " << nC4 << endl;

    



    return 0;
}

