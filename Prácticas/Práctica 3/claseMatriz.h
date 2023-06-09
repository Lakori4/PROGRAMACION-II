// SANTIAGO VALDERRAMA FLORES Y GINA RAMIREZ GUERRERO
#ifndef CLASEMATRIZ_H
#define CLASEMATRIZ_H

#include <vector>
#include <iostream>

using namespace std;

class Matriz
{
private:
    int cols, rows;
    vector<float> datos;

public:
    Matriz(int f, int c);

    int getCols() const;
    int getRows() const;

    float& pos(int i, int j);

    Matriz operator--()
    {
        for (int i = 0; i < rows * cols; i++)
        {
            --datos[i];
        }
        return *this;
    }

    Matriz operator--(int)
    {
        Matriz temp(*this);
        for (int i = 0; i < rows * cols; i++)
        {
            --datos[i];
        }
        return temp;
    }

    Matriz restarValor(int v)
    {
        Matriz result(rows, cols);
        for (int i = 0; i < rows * cols; i++)
        {
            result.datos[i] = datos[i] - v;
        }
        return result;
    }
};

Matriz::Matriz(int f, int c) {
    
    if (f <= 0 || c <= 0) {

        throw 1;
    }
    
    rows = f;
    cols = c;
    datos = vector<float>(rows * cols, 0);
}

ostream& operator<<(ostream& os, Matriz& mat)
{
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            os << mat.pos(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matriz& mat)
{
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            is >> mat.pos(i, j);
        }
    }
    return is;
}

Matriz operator-(Matriz& a, Matriz& b)
{
    if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
    {
        throw 3;
    }

    Matriz result(a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            result.pos(i, j) = a.pos(i, j) - b.pos(i, j);
        }
    }
    return result;
}

int Matriz::getCols() const {
    return cols;
}
int Matriz::getRows() const {
    return rows;
}

float& Matriz::pos(int i, int j) {
    if (i > cols || j > rows || i < 0 || j < 0) {
        throw 2;
    }

    return datos[i * cols + j];
}



#endif // CLASEMATRIZ_H
