#ifndef LINEAPROCESO_H
#define LINEAPROCESO_H
#include <QWidget>
#include "dibujar.h"
#include <string>
#include "listaproceso.h"
#include "listacarro.h"
#include "workercompletar.h"

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
    void actuCarros();

    LineaProceso *CarrosGeneral = nullptr;
    ListaProceso *ColaProcesos;
    ListaProceso *tresProcesos;
    ListaCarro *ColaCarros;
    int segundos=0;

    workerCompletar *pro = new workerCompletar;

public slots:
    void handleresul();

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Dibujar *Dibu;
};

#endif // LINEAPROCESO_H
