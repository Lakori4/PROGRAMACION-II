#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;



template <typename T>

class CPrueba
{
private:
    int indice = -1 ;
    vector <T> v1;

public:

    CPrueba() {}
    CPrueba(int i) {

        indice = i;
        v1.resize(i);
    }

    T devolverElemento();

    void incluirElemento(T const &a) {

    v1.push_back(a);
    indice++;
    }

    ~CPrueba() {}
};

template <typename T>

T CPrueba <T>::devolverElemento() {

    return v1[indice - 1];
}




#endif 