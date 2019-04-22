#ifndef CARRO_H
#define CARRO_H
#include <string>
#include "proceso.h"
using namespace std;


class Carro
{
public:
    Carro(string nombre, int trud, int tcarr, int tvol, int tsill, int tfre, int tmot);
    void setNombre(string nombre);
    string getNombre();
    string toString();

    Proceso *ruedas = new Proceso("Ruedas",0);
    Proceso *carroceria = new Proceso("Carroceria",0);
    Proceso *volante = new Proceso("Volante",0);
    Proceso *sillones = new Proceso("Sillones",0);
    Proceso *frenos = new Proceso("Frenos",0);
    Proceso *motor = new Proceso("Motor",0);

private:
    string Nombre;

};

#endif // CARRO_H
