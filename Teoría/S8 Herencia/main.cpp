// Santiago Valderrama


#include <iostream>


using namespace std;


class figura
{
private:
    int nLados;
    float longitud;

public:
    figura(): nLados(0), longitud(0) {}
    figura(int l, float h): nLados(l), longitud(h) {}

    int getNLado() {return nLados;}
    float getLongitud() {return longitud;}

    void setnLados(int n) {nLados = n;}
    void setLongitud(float l) {longitud = l;}
};


class cuadrado : private  figura
{
private:
    float diagonal;
public:
    cuadrado(): diagonal(0){}

    void setDiagonal (float d) {diagonal = d;}

    float getDiagonal () {return diagonal;}

    void calcularDiag() {}
    
};





int main () {

    cuadrado c1;
    return 0;
}
