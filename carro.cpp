#include "carro.h"
#include "proceso.h"
#include "iostream"

Carro::Carro(string nombre, int trud, int tcarr, int tvol, int tsill, int tfre, int tmot):Nombre(nombre)
{
    ruedas->setTiempo(trud);
    carroceria->setTiempo(tcarr);
    volante->setTiempo(tvol);
    sillones->setTiempo(tsill);
    frenos->setTiempo(tfre);
    motor->setTiempo(tmot);


}

string Carro::getNombre(){
    return Nombre;
}

void Carro::setNombre(string nombre){
    Nombre=nombre;
}

string Carro::toString(){
    cout<<"El carro "<<Nombre<<" tiene los siguientes procesos: "<<endl;
    cout<<ruedas->getNombre()<<" con tiempo: "<<ruedas->getTiempo()<<endl;
    cout<<sillones->getNombre()<<" con tiempo: "<<sillones->getTiempo()<<endl;
    cout<<frenos->getNombre()<<" con tiempo: "<<frenos->getTiempo()<<endl;
    cout<<carroceria->getNombre()<<" con tiempo: "<<carroceria->getTiempo()<<endl;
    cout<<motor->getNombre()<<" con tiempo: "<<motor->getTiempo()<<endl;
    cout<<volante->getNombre()<<" con tiempo: "<<volante->getTiempo()<<endl;
    cout<<""<<endl;
    return "";
}
