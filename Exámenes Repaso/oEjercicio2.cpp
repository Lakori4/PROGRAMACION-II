// Santiago Valderrama


#include <iostream>
#include <string>


using namespace std;

string textoRep(string s, int n);

int main () {
    string s;
    int n;

    cout << "Escribe una palabra: ";
    cin >> s;

    cout << "Escribe un número: ";
    cin >> n;

    cout << "El texto \"" << s << "\" repetido " << n << " veces es " << textoRep(s, n) << endl;
    return 0;
}

string textoRep(string s, int n) {

    string rs;

    for (int i = 0; i < n; i++) {

        rs.append(s);
    }
    return rs;
}
