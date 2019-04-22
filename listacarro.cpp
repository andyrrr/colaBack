#include "listacarro.h"

NodoCarro::NodoCarro(Carro *dato):Dato(dato), Sig(nullptr){

}
void NodoCarro::setDato(Carro *dato) {
    Dato=dato;
}
void NodoCarro::setSig(NodoCarro *sig) {
    Sig=sig;
}
Carro *NodoCarro::getDato() const{
    return Dato;
}
NodoCarro *NodoCarro::getSig() const{
    return Sig;
}
NodoCarro::~NodoCarro() {

}

ListaCarro::ListaCarro() {
    Inicio= nullptr;
    Fin= nullptr;
}


bool ListaCarro::estaVacia() {
    return this->getInicio()== nullptr;
}


void ListaCarro::agregar(Carro *dato) {
    NodoCarro *actual= this->getInicio();
    if (estaVacia()){
        actual = new NodoCarro(dato);
        this->setInicio(actual);
        this->setFin(actual);
    } else {
        actual = new NodoCarro(dato);
        actual->setSig(Inicio);
        this->setInicio(actual);

    }
}


NodoCarro *ListaCarro::retornar(int i) {
    int lugar=0;
    NodoCarro *actual = this->getInicio();
    while (lugar<i){
        actual = actual->getSig();
        lugar++;
    }
    return actual;
}


string ListaCarro::toString() {
    string ListaFinal="[";
    NodoCarro *actual = this->getInicio();
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



int ListaCarro::tamano() {
    if (estaVacia()){
        return  0;
    } else {
        int tam = 1;
        NodoCarro *actual = this->getInicio();
        while (actual->getSig() != nullptr) {
            actual = actual->getSig();
            tam++;
        }
        return tam;
    }
}


void ListaCarro::limpiar() {

    this->setInicio(nullptr);
    this->setFin(nullptr);
}

NodoCarro *ListaCarro::getInicio() {
    return Inicio;
}


void ListaCarro::setInicio(NodoCarro *inicio) {
    Inicio = inicio;
}


NodoCarro *ListaCarro::getFin(){
    return Fin;
}


void ListaCarro::setFin(NodoCarro *fin) {
    Fin = fin;
}

ListaCarro::~ListaCarro() {

}

