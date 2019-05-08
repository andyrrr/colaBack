#include "dibujar.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <string>
#include "listaproceso.h"

Dibujar::Dibujar()
{
    contorno.setColor(Qt::black);
    contorno.setWidth(2);
    textFont.setPixelSize(2);

}
void Dibujar::paint(QPainter *painter, string nombre){
    const char *l = nombre.c_str();
    painter->setPen(contorno);
    painter->setBrush(QBrush(Qt::green));
    painter->drawText(QRect(0,0,500,25),Qt::AlignCenter,QString(l));
}

void Dibujar::PintarCola(QPainter *painter, ListaProceso *tresProcesos){
    for (int pros=0; pros<tresProcesos->tamano();pros++){
        const char *ProcesoNombre= tresProcesos->retornar(pros)->getNombre().c_str();
        painter->drawText(QRect(pros*(600/tresProcesos->tamano()-1)+2,25,75,25),Qt::AlignCenter,QString(ProcesoNombre));
        painter->setBrush(QBrush(Qt::white));
        painter->drawRect(pros*(600/tresProcesos->tamano()-1)+4,50,70,20);
        float tamaño= (float)tresProcesos->retornar(pros)->Hecho / (float)tresProcesos->retornar(pros)->Tiempo;
        //cout<<"Tamaño de la vara "<<tamaño<<" "<<70*tamaño<<endl;
        painter->setBrush(QBrush(Qt::green));
        painter->drawRect(pros*(600/tresProcesos->tamano()-1)+4,50,70*tamaño,20);
    }

}

void Dibujar::PintarAutos(QPainter *painter, ListaCarro *colaAutos){
    painter->setPen(contorno);
    for (int aut=0;aut<colaAutos->tamano();aut++) {
        const char *AutoNombre= colaAutos->retornar(aut)->getDato()->getNombre().c_str();
        ListaProceso temporal;
        temporal.agregar(colaAutos->retornar(aut)->getDato()->motor);
        temporal.agregar(colaAutos->retornar(aut)->getDato()->frenos);
        temporal.agregar(colaAutos->retornar(aut)->getDato()->ruedas);
        temporal.agregar(colaAutos->retornar(aut)->getDato()->volante);
        temporal.agregar(colaAutos->retornar(aut)->getDato()->sillones);
        temporal.agregar(colaAutos->retornar(aut)->getDato()->carroceria);
        painter->drawText(QRect(0,aut*75+25,450,25),Qt::AlignCenter,QString(AutoNombre));
        for (int pros=0; pros<6;pros++){
            const char *ProcesoNombre= temporal.retornar(pros)->getNombre().c_str();
            painter->drawText(QRect(pros*75+2,aut*75+45,75,25),Qt::AlignCenter,QString(ProcesoNombre));
            painter->setBrush(QBrush(Qt::white));
            painter->drawRect(pros*75+4,aut*75+70,70,20);
            float tamaño= (float)temporal.retornar(pros)->Hecho / (float)temporal.retornar(pros)->Tiempo;
            //cout<<"Tamaño de la vara "<<tamaño<<" "<<70*tamaño<<endl;
            painter->setBrush(QBrush(Qt::green));
            painter->drawRect(pros*75+4,aut*75+70,70*tamaño,20);
        }
    }

}
