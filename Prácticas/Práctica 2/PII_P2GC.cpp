//Santiago Valderrama y Gina Ramírez
//Grupo C
#include <iostream>
#include <vector>

using namespace std;


//FUNCIONES
int menu();


//CLASE
class CVector
{
private:

	int size;
	vector <float> nums;

public:


	CVector() : size(0) {}
	CVector(const CVector& V);

	void setSize(int s);
	void setNum(int i, float n);

	int getSize() const;
	float getNum(int i) const;

	CVector operator - (const CVector& v);
	CVector operator -- (int);

	~CVector();
};

CVector::CVector(const CVector& V) {

	size = V.size;
	nums = V.nums;
}
void CVector::setSize(int s) {

	size = s;
	nums.resize(s);
}

void CVector::setNum(int i, float n) {

	if (i < 0 || i >= size)
		throw 2;

	else
		nums[i] = n;
}

int CVector::getSize() const {

	return size;
}

float CVector::getNum(int i) const {

	if (i < 0 || i >= size)
		throw 1;

	else
		return nums[i];
}

//OPERADOR RESTA
CVector CVector::operator- (const CVector& v) {

	CVector vaux;

	if (size != v.getSize())
		throw 3;

	else {

		vaux.setSize(size);

		for (int i = 0; i < size; i++) {
			vaux.nums[i] = (i, nums[i] - v.nums[i]);
		}
	}

	return vaux;

}

//OPERADOR DECREMENTO
CVector CVector::operator-- (int) {

	CVector vaux;


	vaux.setSize(size);

	for (int i = 0; i < size; i++) {
		vaux.setNum(i, nums[i]--);
	}

	return vaux;


}


//OPERADOR COMPARACION
bool operator != (const CVector& v1, const CVector& v2) {

	bool res = true;

	if (v1.getSize() != v2.getSize()) {
		throw 4;
	}
	else {

		for (int i = 0; i < v1.getSize(); i++) {

			if (v1.getNum(i) == v2.getNum(i)) {

				res = false;
				return res;
			}

			if (!res)
				return res;
		}
	}
}


//OPERADOR OSTREAM
ostream& operator <<(ostream& out, const CVector& v) {
	for (int i = 0; i < v.getSize(); i++)
	{
		out << v.getNum(i) << ",";
	}

	return out;
}

CVector::~CVector()
{
}

int main() {


	int opc = -1;
	CVector v1, v2, v3;
	int size1, size2;
	float num{ 0 };

	do
	{
		int opc = menu();
		try
		{

		
			
		switch (opc)
		{
		case 0:
			cout << endl;

			cout << "Fin del programa." << endl;

			return 0;
			break;
		case 1:
			cout << "Introduzca la dimension del primer vector: ";
			cin >> size1;
			v1.setSize(size1);

			cout << endl;

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size1; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v1.setNum(i, num);
			}


			cout << endl;

			cout << "Introduzca la dimension del segundo vector: ";
			cin >> size2;
			v2.setSize(size2);

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v2.setNum(i, num);
			}
			
			v3 = v1 - v2;

			cout << "La resta de los vectores " << v1 <<" y " << v2 << " es igual a : " << v3 << endl;
			

			
			break;
		case 2:
			cout << "Introduzca la dimension del primer vector: ";
			cin >> size1;
			v1.setSize(size1);

			cout << endl;

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size1; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v1.setNum(i, num);
			}


			cout << endl;

			cout << "Introduzca la dimension del segundo vector: ";
			cin >> size2;
			v2.setSize(size2);

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v2.setNum(i, num);
			}

			

			cout << "Los vectores implicados fueron " << v1 << " y " << v2 << endl;

			v1 = v2--;

			cout << "El vector V2 despues del decremento: " << v2 << endl;

			break;
		case 3:

			cout << "Introduzca la dimension del primer vector: ";
			cin >> size1;
			v1.setSize(size1);

			cout << endl;

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size1; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v1.setNum(i, num);
			}


			cout << endl;

			cout << "Introduzca la dimension del segundo vector: ";
			cin >> size2;
			v2.setSize(size2);

			cout << "Introduzca los valores del vector: " << endl;
			for (int i = 0; i < size2; i++)
			{
				cout << "Posicion [" << i << "]: ";
				cin >> num;
				v2.setNum(i, num);
			}

			
			
			cout << "Los vectores " << v1 << " y " << v2;
			if (v1 != v2)
			{
				cout << " no son iguales" << endl;
			}
			else
			{
				cout << " son iguales" << endl;
			}

			break;
		default:
			cout << "Opcion invalida. Intente de nuevo" << endl;
			break;
		}


		}
		catch (int e)
		{
			switch (e)
			{
			case 1:
				cout << endl;
				cout << "Se ha intentado acceder a una posicion que no existe" << endl;
				break;
			case 2:
				cout << endl;
				cout << "Se ha intentado introducir un numero en una posicion que no existe" << endl;
				break;
			case 3:
				cout << endl;
				cout << "Se ha intentado restar 2 vectores que no tienen la misma dimension" << endl;
				break;
			case 4:
				
				cout << endl;
				cout << "Se ha intentado comparar 2 vectores que no tienen la misma dimension" << endl;
				break;
			default:
				break;
			}
		}

	} while (opc <= -1 || opc > 3);
	

	return 0;
}

int menu(){
	int opc;
	

	cout << endl;
	cout << "\n\t1. Restar dos vectores componente a componente";
	cout << "\n\t2. Decrementar cada componente del vector.";
	cout << "\n\t3. Comparar dos vectores por desigualdad";
	cout << "\n\t0. FIN";

	cout << "\n\tSeleccione una opcion: ";
	cin >> opc;

	return opc;
}

