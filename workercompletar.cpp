#include "workercompletar.h"
#include <iostream>

using namespace std;

workerCompletar::workerCompletar(QObject *parent): QThread(parent)
{
    vacia=false;
}

void workerCompletar::cambio(bool cambio){
    vacia=cambio;
}

void workerCompletar::run(){
    int segundos=0;
    while (true){
        sleep(1);
        segundos++;
        if(!vacia){
            emit progreso();
        }
    }
}
