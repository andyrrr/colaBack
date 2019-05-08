#include "inicio.h"
#include "ui_inicio.h"
#include "lineaproceso.h"
#include "carro.h"

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
    linea->CarrosGeneral = Carros1;

}

void Inicio::on_BttmBMW_clicked()
{
    ContBMW++;
    string nombre = "BMW " + to_string(ContBMW);
    Carro *BMW = new Carro(nombre,20 ,20 ,40 ,10 ,30 ,10 );
    BMW->toString();
    Graficar(ColaBMW,BMW,LineaBMW);

}

void Inicio::on_BttmKia_clicked()
{
    ContKia++;
    string nombre = "Kia " + to_string(ContKia);
    Carro *Kia = new Carro(nombre,10 ,10 ,20 ,30 ,20 ,10 );
    Kia->toString();
    Graficar(ColaKia,Kia,LineaKia);

}

void Inicio::on_BttmToyota_clicked()
{
    ContToyota++;
    string nombre = "Toyota " + to_string(ContToyota);
    Carro *Toyota = new Carro(nombre,30 ,10 ,20 ,10 ,40 ,10 );
    Toyota->toString();
    Graficar(ColaToyota,Toyota,LineaToyota);
}

void Inicio::on_BttmNissan_clicked()
{
    ContNissan++;
    string nombre = "Nissan " + to_string(ContNissan);
    Carro *Nissan = new Carro(nombre,30 ,20 ,10 ,40 ,10 ,20 );
    Nissan->toString();
    Graficar(ColaNissan,Nissan,LineaNissan);

}


void Inicio::on_BttmFord_clicked()
{
    ContFord++;
    string nombre = "Ford " + to_string(ContFord);
    Carro *Ford = new Carro(nombre,10 ,20 ,40 ,30 ,40 ,10 );
    Ford->toString();
    Graficar(ColaFord,Ford,LineaFord);
}

void Inicio::on_BttmAudi_clicked()
{
    ContAudi++;
    string nombre = "Audi " + to_string(ContAudi);
    Carro *Audi = new Carro(nombre,40 ,40 ,20 ,50 ,30 ,50);
    Audi->toString();
    Graficar(ColaAudi,Audi,LineaAudi);
}


