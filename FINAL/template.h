//Santiago Valderrama


#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <queue>

using namespace std;

struct Perro
{
    string nombre;
    int chip;
    int edad;
};


template <typename T>

class MiVector
{
private:
    queue<T> cola ;

public:

    MiVector(int nElems, T elem);
    MiVector() {}
    
    T at(int n);

    void checkCola(const queue<T> &c) {if (c.empty()) {throw 0;}}

    void push_back(T elem) {cola.push(elem);}

    void pop_back () {
        checkCola(cola); 
        
        cola.back() = NULL;
        queue <T> cola2 = cola;
        }

    friend ostream &operator<< (ostream &os, const MiVector<T> &V);

    ~MiVector() {}
};

template <typename T>

MiVector <T>::MiVector(int nElems, T elem)
{
    for (int i = 0; i < n; i++) {

        cola.push(elem);
    }
}


template <typename T>

T MiVector<T>::at(int n) {

    queue <T> cola2 = cola;

    for (int i = 0; i < n; i++)
    {
        checkCola(cola2);

        cola2.pop();        
    }
    return cola2.front();
}



template <typename T>

ostream &operator<< (ostream &os, const MiVector<T> &V) {

    queue <T> cola2 = V.cola;
    
    for (int i = 0; !cola2.empty(); i++) {
        os << "\n\n\tElemento " << i << cola2.front();

        cola2.pop();
    }

    return os;
}

ostream &operator << (ostream &os, const Perro &p) {

    os << "\n\n\tEl perro se llama " << p.nombre;
    os << "\n\tChip: " << p.chip;
    os << "\n\tEdad: " << p.edad;

    return os;
}





#endif