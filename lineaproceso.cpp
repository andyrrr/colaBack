#include "lineaproceso.h"
#include <QPainter>
#include <iostream>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "workercompletar.h"


using namespace std;

LineaProceso::LineaProceso(Dibujar *dibujar,QWidget *parent, string nombre):QWidget(parent),Nombre(nombre),Dibu(dibujar)
{
    ColaCarros = new ListaCarro();
    ColaProcesos = new ListaProceso();
    tresProcesos = new ListaProceso();

    connect(pro,SIGNAL(progreso()),this,SLOT(handleresul()));
    pro->cambio(true);
    pro->start();
    repaint();

}

void LineaProceso::actuCarros(){
    if (CarrosGeneral!=nullptr){
        CarrosGeneral->repaint();
    }

}
void LineaProceso::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    Dibu->PintarAutos(&painter,ColaCarros);
    Dibu->paint(&painter, Nombre);
    Dibu->PintarCola(&painter, tresProcesos);

    actuCarros();

}

void LineaProceso::enCola(ListaCarro *colaCarros){
    cout<<"Se une a la cola"<<endl;
    cout<<"Tamaño de la cola de carros: "<<colaCarros->tamano()<<endl;
    ColaCarros = colaCarros;
    repaint();
}
void LineaProceso::ejecutar(ListaProceso *colaProcesos){
    cout<<"Se une a la cola de la linea"<<endl;
    cout<<"Tamaño de la cola: "<<colaProcesos->tamano()<<endl;
    ColaProcesos = colaProcesos;

    asignarTresProcesos();

}

void LineaProceso::asignarTresProcesos(){
    tresProcesos->limpiar();
    srand(time(NULL));
    if (ColaProcesos->tamano()<4){
        for (int j =0; j<ColaProcesos->tamano();j++){
            tresProcesos->agregar(ColaProcesos->retornar(j));
        }
    } else{
        int arreglo[3];
            int aux = 0;
            srand(time(NULL));
            for(int i = 0; i < 3; i++){
                aux = ( rand() % (0-ColaProcesos->tamano()));

                int aux2 = 0;
                while(aux2 < i){
                    if(aux != arreglo[aux2])
                        aux2++;
                    else{
                            aux = ( rand() % (0-ColaProcesos->tamano()));
                            aux2 = 0;
                        }
                }
                arreglo[i] = aux;
                tresProcesos->agregar(ColaProcesos->retornar(arreglo[i]));
                ///cout << arreglo[i] <<endl;
            }
    }
    cout<<"Se asignan tres procesos"<<endl;
    pro->cambio(false);
    repaint();

}

void LineaProceso::handleresul(){
    completarProceso();
}


void LineaProceso::completarProceso(){
    segundos++;

    cout<<tresProcesos->toString()<<endl;
        for (int j=0;j<tresProcesos->tamano();j++){
            tresProcesos->retornar(j)->completando(1);
            if(tresProcesos->retornar(j)->terminado){
                ColaProcesos->eliminar(tresProcesos->retornar(j));
                tresProcesos->eliminar(tresProcesos->retornar(j));
                asignarTresProcesos();
            }
        }
    repaint();

    if (ColaProcesos->tamano()==0){
        pro->cambio(true);
    }
    if (segundos==5){
        segundos=0;
        asignarTresProcesos();
    }
}

