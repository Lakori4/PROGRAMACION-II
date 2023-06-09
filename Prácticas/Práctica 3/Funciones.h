//SANTIAGO VALDERRAMA FLORES Y GINA RAMIREZ GUERRERO

#ifndef FUNCIONES_H
#define FUNCIONES_H

//  Incluir las funciones templatizadas: restar y decrementar

template <typename T>
T restar(T &a, T &b) {
    //T aux = a - b;
    return a - b;
}

template <typename T>
T decrementar(T &a, int veces) {

    for (int i = 0; i < veces; i++) {
        a--;
    }

    return a;
}



#endif // FUNCIONES_H