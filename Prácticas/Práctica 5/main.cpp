//SANTIAGO VALDERRAMA FLORES Y GINA ANDREA RAMÍREZ GUERRERO
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Animales.h"
#include "Animales.cpp"

#define OPCIONES 6

using namespace std;

int Menu (void);

// pedirDatosPato 
void pedirDatosPato(Pato & p);

// pedirDatosPollito 
void pedirDatosPollito(Pollito & p);

void pedirDatosPerro(Perro &p);

// pedirDatosGato 
void pedirDatosGato(Gato& g);

// mostraAnimales 


int main ()
{
    int opcion;
    // Declarar el vector <> granja; para guardar el acceso a todos los animales domésticos creados por el usuario
    vector <shared_ptr <ADomestico>> granja;

    do {
      opcion = Menu();

      try{

      if (opcion==1)
      {
        cout << "\n\n\t\tCREAR Y MOSTRAR UN PATO\n\n" << endl;

         Pato p1;
         pedirDatosPato(p1);

         granja.push_back(make_shared <Pato> (p1));
	    
      }


      else if (opcion==2)
      {
         cout << "\n\n\t\tCREAR Y MOSTRAR UN POLLITO\n\n" << endl;

        // Crear un nuevo elemento en el vector para un Pollito
        Pollito p1;
	    // pedirDatosPollito

       pedirDatosPollito(p1);

       granja.push_back(make_shared <Pollito> (p1));
	    
      }


      else if (opcion==3)
      {
            cout << "\n\n\t\tCREAR Y MOSTRAR UN PERRO\n\n" << endl;

            // Crear un nuevo elemento en el vector para un Perro
            Perro p1;
            
            // pedirDatosPerro
            pedirDatosPerro(p1);

            granja.push_back(make_shared<Perro>(p1));
         
      }
      else if (opcion==4)
      {
         cout << "\n\n\t\tCREAR Y MOSTRAR UN GATO\n\n" << endl;
         
         // Crear un nuevo elemento en el vector para un Gato
         Gato g1;
         // pedirDatosGato
         pedirDatosGato(g1);
         granja.push_back(make_shared<Gato>(g1));
      }
      else if (opcion==5)
      {
         cout << "\n\n\t\tMOSTRAR ANIMALES DOMESTICOS DEL VECTOR\n\n" << endl;
         
         //   mostraAnimales
         
      }
      else  cout << "\n\n\t\tFIN PROGRAMA\n\n" << endl;

      }

      catch (int e) {

         cout << "El mes no es válido";

      }

 } while (opcion!=OPCIONES);
    

   return 0;
}

int Menu (void)
{ int opcion;

  do { system ("cls");

      cout << "\n\tMENU PRINCIPAL" << endl;
      cout << "\n\t1.- Datos del Pato." << endl;
      cout << "\n\t2.- Datos del Pollito." << endl;
      cout << "\n\t3.- Datos del Perro." << endl;
      cout << "\n\t4.- Datos del Gato." << endl;
      cout << "\n\t5.- Mostrar los Animales Domesticos." << endl;

      cout << "\n\t6.- FIN PROGRAMA  " << endl;
      cout << "\n\n Teclee opcion ";
      cin >> opcion;

  } while ((opcion < 1) || (opcion > OPCIONES));

  return opcion;
}
void pedirDatosPollito(Pollito & p) {
   p.pedirIdentificacion();
   p.conocerOnomatopeya();
   p.verTipo(); 
}

void pedirDatosPato(Pato & p) {
   p.pedirIdentificacion();
   p.conocerOnomatopeya();
   p.verTipo();
} 

void pedirDatosGato(Gato & g) {
 
    g.pedirIdentificacion();
    g.conocerOnomatopeya();
    g.verTipo();
}

void pedirDatosPerro(Perro & p) {
    p.pedirIdentificacion();
    p.conocerOnomatopeya();
    p.verTipo();
}