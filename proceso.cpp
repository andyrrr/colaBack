#include "proceso.h"

Proceso::Proceso(string nombre, float tiempo):Nombre(nombre),Tiempo(tiempo)
{

}

string Proceso::getNombre(){
    return Nombre;
}

float Proceso::getTiempo(){
    return Tiempo;
}

void Proceso::setNombre(string nombre){
    Nombre=nombre;
}
void Proceso::setTiempo(float numero){
    Tiempo=numero;
}

void Proceso::completando(float numero){
    Hecho=Hecho+numero;
    if (Hecho==Tiempo){
        terminado=true;
    }
}
