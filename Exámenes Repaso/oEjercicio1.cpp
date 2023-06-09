// Santiago Valderrama


#include <iostream>


using namespace std;

int multiplo3 (int n);

int main () {

    int n;

    cout << "Introduce un número natural: ";
    cin >> n;
     int m = multiplo3(n);

    cout << "El mayor número múltiplo de 3 inferior a " << n << " es " << m << endl;
    return 0;
}

int multiplo3 (int n) {

    for (int i = n-1; i > 0; i--) {
        if (i%3 == 0) return i;
    } 
}
