#include <iostream>
#include <array>
#include <string>
#include <vector>

using namespace std;


class Fecha {
    public:
        Fecha(); //POR DEFECTO CON INICIALIZADORES
        Fecha(int d, int m, int a); //CON PARAMETROS

        void setDia(int n);
        void setMes(int m);
        void setAño(int a);

        int getDia();
        int getMes();
        int getAño();

        void mostrar();

    private:
        int dia;
        int mes;
        int año;
};

Fecha::Fecha()
{
	dia = 0;
	mes = 0;
	año = 0;
}

Fecha::Fecha(int d, int m, int a) {
	setDia(d);
	setMes(m);
	setAño(a);
}

void Fecha::setDia(int d) {

	bool fecha_correcta = false;


	switch (mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		
		if (d >= 1 && d <= 31 )
		{
			fecha_correcta = true;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		
		if (d>= 1 && d <= 30)
		{
			fecha_correcta = true;
		}
		break;
	case 2:
		
		if (d >= 1 && d <= 28)
		{
			fecha_correcta = true;
		
		}
		break;

	default:
		break;
	}

	if (fecha_correcta == true)
	{
		dia = d;
	}
	else
	{
		cout << "El dia no corresponde al mes, intente de nuevo" << endl;
	}

}

void Fecha::setMes(int m)
{
	if (m < 1 || m > 12)
	{
		cout << "Mes incorrecto intente de nuevo" << endl;
	}
	else
	{
		mes = m;
	}

}
void Fecha::setAño(int a) {

	año = a;


}

//gets
int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAño() {
	return año;
}


void Fecha::mostrar() {
	cout << dia << "/" << mes << "/" << año;
}


class Premio {
    public:
        Premio(); //POR DEFECTO
        Premio(string& des, string& nom); //CON PARAMETROS

        void setDescripcion(string &des);
        void setNombre(string& nom);


        string getDescripcion();
        string getNombre();


        void mostrar();
        void modificar(string& des, string& nom);


    private:
        string descripcion;
        string nombre;
};

Premio::Premio()
{
	descripcion.clear();
	nombre.clear();
	


}

Premio::Premio(string& des, string& nom) {
	setDescripcion(des);
	setNombre(nom);
	
}


//set
void Premio::setDescripcion(string& des) {
	descripcion = des;
}

void Premio::setNombre(string& nom) {
	nombre = nom;
}



//get

string Premio::getDescripcion() {
	return descripcion;
}


string Premio::getNombre() {
	return nombre;
}

void Premio:: mostrar() {
	cout << "El premio '" << descripcion << "'" << " fue otorgado a: " << nombre << endl;
}

void Premio::modificar(string& des, string& nom) {
	descripcion = des;
	nombre = nom;
}


class Pelicula {
        
    private:
        string titulo, nomDir, apelDir;
        Fecha fechaEst;

        array <Premio, 6> pre;
        
    public:
        Pelicula();
        Pelicula(string const & t, string const & n, string const & a, Fecha const & f, array <Premio, 6> const & array);
        Pelicula(Pelicula const & pel);

        void setTit (string const & t);
        void setNomDir (string const & n);
        void setApelDir (string const & a);
        void setFecha (Fecha const & f);
        void setPremio (Premio const & p);

        string getTit();
        string getNomDir();
        string getApelDir();
        Fecha getFecha ();
        array <Premio, 6> getPremios();

        void mostrar ();
        
       ~Pelicula();
};

Pelicula::Pelicula() {}

Pelicula::Pelicula(string const & t, string const & n, string const & a, Fecha const & f, array <Premio, 6> const & array) {
    titulo = t;
    nomDir = n;
    apelDir = a;
    fechaEst = f;
    pre = array;
} 

Pelicula::Pelicula(Pelicula const& pel) {
    titulo = pel.titulo;
    nomDir = pel.nomDir;
    apelDir = pel.apelDir;
    fechaEst = pel.fechaEst;
    pre = pel.pre;
} 

void Pelicula::setTit(string const & t) {
    titulo = t;
}

void Pelicula::setNomDir(string const & n) {
    nomDir = n;
}

void Pelicula::setApelDir(string const & a) {
    apelDir = a;
}

void Pelicula::setFecha(Fecha const & f) {
    fechaEst = f;
} 

void Pelicula::setPremio(Premio const & p) {
    
    for (int i = 0; i < pre.size(); i++) {

        if (pre.at(i).getNombre() == "") {

            pre[i] = p;
        }
    }
} 


string Pelicula::getTit() {
    return titulo;
}

string Pelicula::getNomDir() {
    return nomDir;
}

string Pelicula::getApelDir() {
    return apelDir;
}

Fecha Pelicula::getFecha() {
    return fechaEst;
}

array <Premio,6> Pelicula::getPremios() {
    return pre;
} 


void Pelicula::mostrar() {

    if (titulo != "") cout << "\n\tPELICULA: " << titulo;
    if (nomDir != "") cout << "\n\tDIRECTOR: " << nomDir << " " << apelDir;
    if (fechaEst.getDia() != 40) "\n\tFECHA DE ESTRENO: "; fechaEst.mostrar();

    if (pre[1].getNombre() != "") {

        for (int i = 0; i < pre.size(); i++) {

            if (pre[i].getNombre() != "") {

                pre[i].mostrar();
                cout << "\n\t         ";
            }
        }
    }    
}

Pelicula::~Pelicula()
{
}



int menu();
void introducirPelicula(vector<Pelicula> &pelis);

int main () {

    bool exit = false;
    vector <Pelicula> pelis;
    string t;
    bool m = false;
    string e;

    do {

        switch (menu()) {

        case 1:
                            
            introducirPelicula(pelis);
            
            break;

        case 2:
            
            cin.ignore();
            cout << "Escribe el título de la película que quieres buscar: ";
            getline(cin, t);
            

            for (int i = 0; i < pelis.size(); i++) {

                if (pelis[i].getTit() == t) {

                    pelis[i].mostrar();
                    m = true;
                }

                
            }

            if (!m) {cout << "\n\n\tNO SE HA ENCONTRADO LA PELICULA";}
            break;

        case 3:
            
            for (int i = 0; i < pelis.size(); i++) {
                
                pelis[i].mostrar();
                system("pause");
            }
            break;

        case 4:

            cout << "Gracias y hasta pronto.";
            return 0;
            break;

        default:

            system("cls");
            cout << "La opcion seleccionada no es valida.\n";
            break;
        }


    } while (!exit);

    return 0;
}


int menu () {

    int o;

    cout << "Bienvenido al Festival de Cine Nebrija\n\nEscribe el numero correspondiente con tu seleccion.";
    cout << "\n\n\t1. Anadir una pelicula\n\t2. Buscar una pelicula\n\t3. Mostrar todas las peliculas\n\t4. Salir\n";
    cin >> o;
    return o;
}


void introducirPelicula(vector<Pelicula> &pelis) {

    string titulo;
    string nom_director, ap_director;
    Fecha fecha;
    Pelicula p;
    int dia, mes, año;
    Premio premio;
    string prem, nom;
    char resp;

    cin.ignore();

    do {
        
        cout << "\n\n\tIntroduzca el titulo: ";
        cin.ignore();
        getline(cin, titulo);
        p.setTit(titulo);
        
        if (pelis.size()  == 0) {
            
            cout << "\n\n\tIntroduzca el nombre del director: ";
            getline(cin, nom_director);
            p.setNomDir(nom_director);

            cout << "\n\n\tIntroduzca el apellido del director: ";
            getline(cin, ap_director);
            p.setApelDir(ap_director);

            cout << "\n\n\tIntroduzca la fecha de estreno" << endl;
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            fecha.setMes(mes);
            fecha.setDia(dia);

            cout << "Año: ";
            cin >> año;
            p.setFecha(fecha);

            cout << "\n\n\tIntroduzca el premio" << endl;
            cin.ignore();
            cout << "Premio: ";
            getline(cin, prem);
            cout << "Nombre de quien lo ha ganado: ";
            getline(cin, nom);

            premio.setDescripcion(prem);
            premio.setNombre(nom);

            p.setPremio(premio);

            pelis.push_back(p);
        }
        else{
            for (int i = 0; i < pelis.size(); i++) {

                if (titulo != p.getTit())
                {
                    cout << "\n\n\tIntroduzca el nombre del director: ";
                    getline(cin, nom_director);
                    pelis[i].setNomDir(nom_director);

                    cout << "\n\n\tIntroduzca el apellido del director: ";
                    getline(cin, ap_director);
                    pelis[i].setApelDir(ap_director);

                    cout << "\n\n\tIntroduzca la fecha de estreno" << endl;
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    fecha.setMes(mes);
                    fecha.setDia(dia);

                    cout << "Año: ";
                    cin >> año;
                    p.setFecha(fecha);

                    fecha.setAño(año);

                    cout << "\n\n\tIntroduzca el premio" << endl;
                    cin.ignore();
                    cout << "Premio: ";
                    getline(cin, prem);
                    cout << "Nombre de quien lo ha ganado: ";
                    getline(cin, nom);

                    premio.setDescripcion(prem);
                    premio.setNombre(nom);
                    p.setPremio(premio);

                }
                else
                {
                    cout << "La pelicula ya se encuentra actualmente registrada" << endl;
                }
            }

        }
       

        cout << "\n\n\tDesea incluir mas peliculas (S/N): ";
       
        cin >> resp;
        resp = toupper(resp);
          
    } while (resp == 'S');

}
