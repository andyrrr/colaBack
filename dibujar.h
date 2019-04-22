#ifndef DIBUJAR_H
#define DIBUJAR_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <string>
#include "listacarro.h"
#include "listaproceso.h"

using namespace std;


class Dibujar
{
public:
    Dibujar();
    void paint(QPainter *painter, string nombre);
    void PintarCola(QPainter *painter, ListaProceso *colaProcesos);
    void PintarAutos(QPainter *painter, ListaCarro *colaAutos);

private:
    QPen contorno;
    QPen textPen;
    QFont textFont;

};

#endif // DIBUJAR_H
