#ifndef WORKERCOMPLETAR_H
#define WORKERCOMPLETAR_H


#include <QThread>
#include <QObject>
#include "listaproceso.h"


class workerCompletar: public QThread
{
    Q_OBJECT
public:
    explicit workerCompletar(QObject *parent = 0);
    void cambio(bool cambio);
    bool vacia;

signals:
    void progreso();
protected:
    void run() override;

};
#endif // WORKERCOMPLETAR_H
