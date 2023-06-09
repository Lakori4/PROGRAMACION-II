// Santiago Valderrama y Gina Ramírez

#include <iostream>
#include <exception>
#include <memory>
using namespace std;
class CVector {
private:
	//TAMAÑO DEL VECTOR
	int size;
	float* vector;
public:
	// CONSTRUCTORES
	CVector() : size(0), vector(nullptr) {}
	CVector(int s) : size(s), vector(new float[s]) {}
	CVector(const CVector& v) : size(v.size), vector(new float[v.size]) {
		for (int i = 0; i < size; ++i) {
			vector[i] = v.vector[i];
		}
	}
	// DESTRUCTOR
	~CVector() {
		delete[] vector;
		vector = nullptr;
	}
	// METODOS
	int getSize() const { return size; }

    float getNum(int pos) const {
            if (pos < 0 || pos >= size) {
                throw 1;
            }
            return vector[pos];
    }

	void setNum(int pos, float num) {
		if (pos < 0 || pos >= size) {
			throw 2;
		}
		vector[pos] = num;
	}
	void setSize(int s) {
		if (s == size) {
			return;
		}
		float* newVector = new float[s];
		int minSize = (size < s) ? size : s;
		for (int i = 0; i < minSize; ++i) {
			newVector[i] = vector[i];
		}
		delete[] vector;
		vector = newVector;
		size = s;
	}
	// SOBRE CARGA DE OPERADORES
	//SUMA
	CVector operator+(const CVector& v) const {
		if (size != v.size) {
			throw "Los vectores no tienen el mismo tamano";
		}
		CVector result(size);
		for (int i = 0; i < size; ++i) {
			result.vector[i] = vector[i] + v.vector[i];
		}
		return result;
	}
	//INCREMENTO
	CVector& operator++() {
		for (int i = 0; i < size; ++i) {
			++vector[i];
		}
		return *this;
	}
	//COMPARACION
	bool operator==(const CVector& v) const {
		if (size != v.size) {
			throw "Los vectores no tienen el mismo tamano";
		}
		for (int i = 0; i < size; ++i) {
			if (vector[i] != v.vector[i]) {
				return false;
			}
		}
		return true;
	}
	//FUNCI�N MOSTRAR
	void mostrar(shared_ptr<CVector> vec) {
		cout << "\n\tTamano del vector: " << vec->getSize() << endl;
		cout << "\n\tElementos del vector: ";
		for (int i = 0; i < vec->getSize(); ++i) {
			cout << vec->getNum(i) << " ";
		}
		cout << endl;
	}
};

int menu ();


int main() {
	int op = -1;
	CVector v1, v2, result;
	int size;
	float num;

		try {
			switch (menu ()) {
				//CASO 1
			case 1:

				cout << "\n\tIntroduzca el tamano del primer vector: ";
				cin >> size;
				v1.setSize(size);

				cout << "\n\tIntroduzca los valores del primer vector:\n";
				for (int i = 0; i < size; ++i) {
					cout << "\n\tPosicion " << i << ": ";
					cin >> num;
					v1.setNum(i, num);
				}
				cout << "\n\tIntroduzca el tamano del segundo vector: ";
				cin >> size;
				v2.setSize(size);
				cout << "\n\tIntroduzca los valores del segundo vector:\n";
				for (int i = 0; i < size; ++i) {
					cout << "\n\tPosicion " << i << ": ";
					cin >> num;
					v2.setNum(i, num);
				}
				result = v1 + v2;
				cout << "\n\tEl resultado de la suma es:\n";
				for (int i = 0; i < result.getSize(); ++i) {
					cout << "\n\t" << result.getNum(i) << " ";
				}
				//v1->mostrar(result);
				//v2->mostrar(result);
				
				cout << endl;
				break;
				//CASO 2
			case 2:
				cout << "\n\tIntroduzca el tamano del vector: ";
				cin >> size;
				v1.setSize(size);
				cout << "\n\tIntroduzca los valores del vector:\n";
				for (int i = 0; i < size; ++i) {
					cout << "\n\tPosicion " << i << ": ";
					cin >> num;
					v1.setNum(i, num);
				}
				++v1;
				cout << "\n\tEl resultado de incrementar el vector es:\n";
				for (int i = 0; i < v1.getSize(); ++i) {
					cout << "\t" << v1.getNum(i) << " ";
				}
				//v1->mostrar(result);
				//v2->mostrar(result);
				
				cout << endl;
				break;
				//CASO 3
			case 3:
				cout << "\n\tIntroduzca el tamano del primer vector: ";
				cin >> size;
				v1.setSize(size);
				cout << "\n\tIntroduzca los valores del primer vector:\n";
				for (int i = 0; i < size; ++i) {
					cout << "\n\tPosicion " << i << ": ";
					cin >> num;
					v1.setNum(i, num);
				}
				cout << "\n\tIntroduzca el tamano del segundo vector: ";
				cin >> size;
				v2.setSize(size);
				cout << "\n\tIntroduzca los valores del segundo vector:\n";
				for (int i = 0; i < size; ++i) {
					cout << "\n\tPosicion " << i << ": ";
					cin >> num;
					v2.setNum(i, num);
				}
				if (v1 == v2) {
					cout << "\n\tLos vectores son iguales\n";
				}
				else {
					cout << "\n\tLos vectores son diferentes\n";
				}
				//v1->mostrar(result);
				//v2->mostrar(result);
				
				break;
			case 0:
				cout << "\n\tFin del programa\n";
				break;
			default:
				throw exception();
			}
		}
		catch (int e) {
			if (e == 1) {
				cout << "\n\tError: posicion fuera de rango\n";
			}
			else if (e == 2) {
				cout << "\n\tError: posicion fuera de rango para establecer un valor\n";
			}
		}
		catch (const char* e) {
			cout << "\n\tError: " << e << endl;
		}
		catch (...) {
			cout << "\n\tError: opcion invalida\n";
		}
		cout << endl;

	return 0;
	}

int menu () {
        int op;
		cout << "\n\t1. Sumar dos vectores componente a componente";
		cout << "\n\t2. Incrementar cada componente del vector.";
		cout << "\n\t3. Comparar dos vectores por igualdad";
		cout << "\n\t0. FIN";
		cout << "\n\tSeleccione una opcion: ";
		cin >> op;
}