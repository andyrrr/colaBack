#include "inicio.h"
#include <QApplication>
#include <iostream>

#include <thread>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Inicio w;
    w.setStyleSheet("background-color:white;");
    w.show();


    return a.exec();
}

void completarProceso(){
    unsigned t0,t1;
    t0= clock();
    int i=0;
    while (i<20000000){
        i++;
    }
    t1= clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

}
