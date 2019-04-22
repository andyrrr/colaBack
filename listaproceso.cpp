#include "listaproceso.h"
#include <iostream>
using namespace std;
NodoProceso::NodoProceso(Proceso *dato):Sig(nullptr),Dato(dato){

}
void NodoProceso::setDato(Proceso *dato) {
    Dato=dato;
}
void NodoProceso::setSig(NodoProceso *sig) {
    Sig=sig;
}
Proceso *NodoProceso::getDato() const{
    return Dato;
}
NodoProceso *NodoProceso::getSig() const{
    return Sig;
}
NodoProceso::~NodoProceso() {

}

ListaProceso::ListaProceso() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaProceso::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaProceso::agregar(Proceso *dato) {
    NodoProceso *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoProceso(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoProceso(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}

void ListaProceso::agregar(Carro *carro){
    this->agregar(carro->motor);
    this->agregar(carro->frenos);
    this->agregar(carro->ruedas);
    this->agregar(carro->volante);
    this->agregar(carro->sillones);
    this->agregar(carro->carroceria);
}


Proceso *ListaProceso::retornar(int i) {
    int lugar=0;
    NodoProceso *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual->getDato();
}
void ListaProceso::eliminar(Proceso *proceso){
    cout<<this->toString()<<endl;
    NodoProceso *actual = this->getInicio();
    if (this->getInicio()->getDato()==proceso){
        cout<<"Elimina el nodo: "<<Inicio->getDato()->getNombre()<<endl;
        this->setInicio(Inicio->getSig());
    }else {
        while(actual->getSig()!=nullptr){
            cout<<proceso->getNombre()<<endl;
            cout<<"Actual: "<<actual->getDato()->getNombre()<<endl;
            cout<<"Siguiente: "<<actual->getSig()->getDato()->getNombre()<<endl;
            if(actual->getSig()->getDato() == proceso){
                cout<<"Elimina el nodo: "<<actual->getSig()->getDato()->getNombre()<<endl;
                if(actual->getSig()->getSig()==nullptr){
                    cout<<"Se quiebra"<<endl;
                    actual->setSig(nullptr);
                    break;
                }else{
                    actual->setSig(actual->getSig()->getSig());
                }

                cout<<this->toString()<<endl;
            }
            actual = actual->getSig();
        }
    }
    cout<<"Pasa"<<endl;
}


string ListaProceso::toString() {
    string ListaFinal="[";
    NodoProceso *actual = this->getInicio();
    if (estaVacia()){
        return "";
    } else {
        while(actual != nullptr){
            if (actual==Inicio){
                ListaFinal= ListaFinal+actual->getDato()->getNombre();
            }else{
                ListaFinal= ListaFinal+", "+actual->getDato()->getNombre();
            }
            actual=actual->getSig();
        }
    }
    ListaFinal=ListaFinal+"]";
    return ListaFinal;
}



int ListaProceso::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoProceso *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaProceso::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoProceso *ListaProceso::getInicio() {
    return Inicio;
}


void ListaProceso::setInicio(NodoProceso *inicio) {
    Inicio = inicio;
}


NodoProceso *ListaProceso::getFin(){
    return Fin;
}


void ListaProceso::setFin(NodoProceso *fin) {
    Fin = fin;
}

ListaProceso::~ListaProceso() {

}
