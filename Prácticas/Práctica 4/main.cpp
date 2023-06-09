// Santiago Valderrama y Gina Ramírez

#include <iostream>
#include <string>

#include "Vehiculos.h"
#include "Vehiculos.cpp"

# define OPCIONES 8
# define FIN 0

using namespace std;

int Menu (void);

int main ()
{
   Vehiculo miVehiculo;
   Camion miCamion;
   Automovil miAuto;
   Monovolumen miMonovol;

    string cat{ " " };
    string tamaño{ " " };
    string marca{ " " };
    string combustible{ " " };
    char etiqueta;
    int vmax;
    int deposito;
    int potencia;
    int cm;
    int plz;

   int opcion;

    do {
      opcion = Menu();
      system ("cls");
      switch (opcion)  {
        case 1:  cout << "\n\n\t\tSOLICITAR LOS DATOS PARA UN VEHICULO\n\n" << endl;

                cout << "Introduce la marca del vehículo: ";
                cin >> marca;

                miVehiculo.setMarca(marca);  

                cout << "Introduce la potencia del vehículo: ";
                cin >> potencia;

                miVehiculo.setPotencia(potencia);                 
                 
                 break;

        case 2:
                 cout << "\n\n\t\tMOSTRAR LOS DATOS DE UN VEHICULO\n\n" << endl;
                 
                 miVehiculo.mostrarVeh();
                 
                 break;

        case 3:
                  cout << "\n\n\t\tSOLICITAR LOS DATOS PARA UN CAMION\n\n" << endl;
                
                  cout << "\n\t Introduzca la marca: ";
                  cin >> marca;
                  miCamion.setMarca(marca);

                  cout << "\n\t Introduzca la potencia: ";
                  cin >> potencia;
                  miCamion.setPotencia(potencia);

                  cout << "\n\t Introduzca la categoria (personas/mercancias/remolques): ";
                  cin >> cat;

                  miCamion.setCategoria(cat);

                  cout << "\n\t Introduzca el tamano (ligeros/medianos/pesados): ";
                  cin >> tamaño;
                  miCamion.setTamano(tamaño);

                 
                 break;

        case 4:
                 cout << "\n\n\t\tMOSTRAR LOS DATOS DE UN CAMION\n\n" << endl;
                 
                 miCamion.mostrarCam();

                 
                 break;

        case 5:
                 cout << "\n\n\t\tSOLICITAR LOS DATOS PARA UN AUTOMOVIL\n\n" << endl;
                
                cout << "Introduce la marca del vehículo: ";
                cin >> marca;

                miVehiculo.setMarca(marca);  

                cout << "Introduce la potencia del vehículo: ";
                cin >> potencia;

                miVehiculo.setPotencia(potencia); 

                cout << "Introduce el tipo de combustible del automóvil: ";
                cin >> combustible;

                miAuto.setCombustible(combustible);  

                cout << "Introduce la capacidad del depósito del automóvil: ";
                cin >> deposito;

                miAuto.setL_deposito(deposito);

                cout << "Introduce la etiqueta ECO del automóvil: ";
                cin >> etiqueta;

                miAuto.setEtiquetaECO(etiqueta);

                cout << "Introduce la velocidad máxima del automóvil: ";
                cin >> vmax;

                miAuto.setVelocidadMax(vmax);
                 
                 break;

        case 6:
                 cout << "\n\n\t\tMOSTRAR LOS DATOS DE UN AUTOMOVIL\n\n" << endl;
                 
                 miAuto.mostrarAuto();
                 
                 break;

        case 7:
                  cout << "\n\n\t\tSOLICITAR LOS DATOS PARA UN MONOVOLUMEN\n\n" << endl;


                  cout << "\n\t Introduzca la marca: ";
                  cin >> marca;
                  miMonovol.setMarca(marca);

                  cout << "\n\t Introduzca la potencia: ";
                  cin >> potencia;
                  miMonovol.setPotencia(potencia);

                  cout << "\n\t Introduzca el combustible: ";
                  cin >> combustible;
                  miMonovol.setCombustible(combustible);

                  cout << "\n\t Introduzca la capacidad del deposito: ";
                  cin >> deposito;
                  miMonovol.setL_deposito(deposito);

                  cout << "\n\t Introduzca etiqueta ECO: ";
                  cin >> etiqueta;
                  miMonovol.setEtiquetaECO(etiqueta);

                  cout << "\n\t Introduzca velocidad maxima: ";
                  cin >> vmax;
                  miMonovol.setVelocidadMax(vmax);

                  cout << "\n\t Introduzca el largo: ";
                  cin >> cm;
                  miMonovol.setLargo(cm);

                  cout << "\n\t Introduzca el numero de plazas: ";
                  cin >> plz;
                  miMonovol.setPlazas(plz);

                 
                 break;

        case 8:
                cout << "\n\n\t\tMOSTRAR LOS DATOS DE UN MONOVOLUMEN\n\n" << endl;
                 
                miMonovol.mostrarMono();
                 
                 break;

        case 0:  cout << "\n\n\t\tFIN PROGRAMA\n\n" << endl;
    }

    system("pause");
 } while (opcion!=FIN);

   return 0;
}

int Menu (void)
{ int opcion;

  do { system ("cls");

      cout << "\n\tMENU PRINCIPAL" << endl;
      cout << "\n\t1.- Solicitar datos para un vehiculo." << endl;
      cout << "\n\t2.- Mostrar datos de un vehiculo." << endl;
      cout << "\n\t3.- Solicitar datos para un camion." << endl;
      cout << "\n\t4.- Mostrar datos de un camion." << endl;
      cout << "\n\t5.- Solicitar datos para un automovil." << endl;
      cout << "\n\t6.- Mostrar datos de un automovil." << endl;
      cout << "\n\t7.- Solicitar datos para un monovolumen." << endl;
      cout << "\n\t8.- Mostrar datos de un monovolumen." << endl;

      cout << "\n\t0.- FIN PROGRAMA  " << endl;
      cout << "\n\n Teclee opcion ";
      cin >> opcion;
      cin.ignore();

  } while ((opcion < FIN) || (opcion > OPCIONES));

  return opcion;
}

