#ifndef LINEAPROCESO_H
#define LINEAPROCESO_H
#include <QWidget>
#include "dibujar.h"
#include <string>
#include "listaproceso.h"
#include "listacarro.h"

using namespace std;

class LineaProceso;
class LineaProceso : public QWidget
{
    Q_OBJECT

public:
    LineaProceso(Dibujar *dibujar, QWidget *parent, string Nombre);
    string Nombre;
    void ejecutar(ListaProceso* colaProcesos);
    void enCola(ListaCarro* colaCarros);
    void completarProceso();
    void asignarTresProcesos();

    ListaProceso *ColaProcesos;
    ListaProceso *tresProcesos;
    ListaCarro *ColaCarros;

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Dibujar *Dibu;

};

#endif // LINEAPROCESO_H
