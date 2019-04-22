#include "inicio.h"
#include "ui_inicio.h"
#include "lineaproceso.h"
#include "carro.h"
#include "iostream"

using namespace std;

Inicio::Inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    LineaAudi = new LineaProceso(&dibL1,this,"Linea de Procesos Audi");
    ui->linea1->addWidget(LineaAudi,0,Qt::Alignment());
    LineaBMW = new LineaProceso(&dibL1,this,"Linea de Procesos BMW");
    ui->linea2->addWidget(LineaBMW,0,Qt::Alignment());
    LineaKia = new LineaProceso(&dibL1,this,"Linea de Procesos Kia");
    ui->linea3->addWidget(LineaKia,0,Qt::Alignment());
    LineaToyota = new LineaProceso(&dibL1,this,"Linea de Procesos Toyota");
    ui->linea4->addWidget(LineaToyota,0,Qt::Alignment());
    LineaFord = new LineaProceso(&dibL1,this,"Linea de Procesos Ford");
    ui->linea5->addWidget(LineaFord,0,Qt::Alignment());
    LineaNissan = new LineaProceso(&dibL1,this,"Linea de Procesos Nissan");
    ui->linea6->addWidget(LineaNissan,0,Qt::Alignment());

    Carros1 = new LineaProceso(&dibL1,this,"Linea de Carros en Proceso                ");
    ui->Carros->addWidget(Carros1,0,Qt::Alignment());
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::Graficar(ListaProceso *colaCarro, Carro *carro, LineaProceso *linea){
    colaCarro->agregar(carro);
    Cola->agregar(carro);
    Carros1->enCola(Cola);
    linea->ejecutar(colaCarro);
    cout<<colaCarro->toString()<<endl;
    cout<<""<<endl;

}

void Inicio::on_BttmBMW_clicked()
{
    ContBMW++;
    string nombre = "BMW " + to_string(ContBMW);
    Carro *BMW = new Carro(nombre,2 ,2 ,4 ,1 ,3 ,1 );
    BMW->toString();
    Graficar(ColaBMW,BMW,LineaBMW);

}

void Inicio::on_BttmKia_clicked()
{
    ContKia++;
    string nombre = "Kia " + to_string(ContKia);
    Carro *Kia = new Carro(nombre,1 ,1 ,2 ,3 ,2 ,1 );
    Kia->toString();
    Graficar(ColaKia,Kia,LineaKia);

}

void Inicio::on_BttmToyota_clicked()
{
    ContToyota++;
    string nombre = "Toyota " + to_string(ContToyota);
    Carro *Toyota = new Carro(nombre,3 ,1 ,2 ,1 ,4 ,1 );
    Toyota->toString();
    Graficar(ColaToyota,Toyota,LineaToyota);
}

void Inicio::on_BttmNissan_clicked()
{
    ContNissan++;
    string nombre = "Nissan " + to_string(ContNissan);
    Carro *Nissan = new Carro(nombre,3 ,2 ,1 ,4 ,1 ,2 );
    Nissan->toString();
    Graficar(ColaNissan,Nissan,LineaNissan);

}


void Inicio::on_BttmFord_clicked()
{
    ContFord++;
    string nombre = "Ford " + to_string(ContFord);
    Carro *Ford = new Carro(nombre,1 ,2 ,4 ,3 ,4 ,1 );
    Ford->toString();
    Graficar(ColaFord,Ford,LineaFord);
}

void Inicio::on_BttmAudi_clicked()
{
    ContAudi++;
    string nombre = "Audi " + to_string(ContAudi);
    Carro *Audi = new Carro(nombre,4 ,4 ,2 ,5,3 ,5);
    Audi->toString();
    Graficar(ColaAudi,Audi,LineaAudi);
}


