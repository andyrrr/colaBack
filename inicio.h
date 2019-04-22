#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include "dibujar.h"
#include "listaproceso.h"
#include "listacarro.h"
#include "lineaproceso.h"


namespace Ui {
class Inicio;
}

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    int ContBMW=0;
    int ContKia=0;
    int ContToyota=0;
    int ContNissan=0;
    int ContAudi=0;
    int ContFord=0;
    int ContGlob;

    LineaProceso *LineaBMW;
    LineaProceso *LineaKia;
    LineaProceso *LineaToyota;
    LineaProceso *LineaNissan;
    LineaProceso *LineaAudi;
    LineaProceso *LineaFord;
    LineaProceso *Carros1;


    ListaProceso *ColaBMW = new ListaProceso;
    ListaProceso *ColaKia = new ListaProceso;
    ListaProceso *ColaToyota = new ListaProceso;
    ListaProceso *ColaNissan = new ListaProceso;
    ListaProceso *ColaAudi = new ListaProceso;
    ListaProceso *ColaFord = new ListaProceso;
    ListaCarro *Cola = new ListaCarro;

    void Graficar(ListaProceso *colaCarro, Carro *carro, LineaProceso *linea);



    ~Inicio();

private slots:
    void on_BttmBMW_clicked();

    void on_BttmKia_clicked();

    void on_BttmToyota_clicked();

    void on_BttmNissan_clicked();

    void on_BttmFord_clicked();

    void on_BttmAudi_clicked();

private:
    Ui::Inicio *ui;
    Dibujar dibL1;
};

#endif // INICIO_H
