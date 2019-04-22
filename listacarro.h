#ifndef LISTACARRO_H
#define LISTACARRO_H
#include "carro.h"

#include <string>

using namespace std;
class NodoCarro{
public:
    NodoCarro(Carro *Dato);

     void setDato(Carro *);
     void setSig(NodoCarro *);
     Carro *getDato() const;
     NodoCarro  *getSig() const;
     ~NodoCarro();
private:
    Carro *Dato;
    NodoCarro *Sig;
};
class ListaCarro {
public:
    ListaCarro();
    bool estaVacia();
    void agregar(Carro * carro);
    NodoCarro *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaCarro();
    NodoCarro *getInicio();
    void setInicio(NodoCarro *inicio);
    NodoCarro *getFin();
    void setFin(NodoCarro *fin);
    NodoCarro *Inicio;
    NodoCarro *Fin;
};

#endif // LISTACARRO_H
