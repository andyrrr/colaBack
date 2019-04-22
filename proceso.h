#ifndef PROCESO_H
#define PROCESO_H

#include <string>


using namespace std;

class Proceso
{
public:
    Proceso(string nombre,float tiempo);
    void setNombre(string nombre);
    void setTiempo(float numero);
    string getNombre();
    float getTiempo();
    void completando(float numero);
    float Hecho=0;
    string Nombre;
    float Tiempo;
    bool terminado=false;


};

#endif // PROCESO_H
