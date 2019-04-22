#ifndef LISTAPROCESO_H
#define LISTAPROCESO_H
#include "proceso.h"
#include "carro.h"

#include <string>

using namespace std;
class NodoProceso{
public:
    NodoProceso(Proceso *Dato);

     void setDato(Proceso *);
     void setSig(NodoProceso *);
     Proceso *getDato() const;
     NodoProceso  *getSig() const;
     ~NodoProceso();
     NodoProceso *Sig;

private:
    Proceso *Dato;
};
class ListaProceso {
public:
    ListaProceso();
    bool estaVacia();
    void agregar(Proceso * proceso);
    void agregar(Carro * carro);
    Proceso *retornar(int);
    int tamano();
    string toString();
    void limpiar();
    ~ListaProceso();
    NodoProceso *getInicio();
    void setInicio(NodoProceso *inicio);
    NodoProceso *getFin();
    void setFin(NodoProceso *fin);
    NodoProceso *Inicio;
    NodoProceso *Fin;
    void eliminar(Proceso* proceso);
};

#endif // LISTAPROCESO_H
