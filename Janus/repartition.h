#ifndef REPARTITION_H
#define REPARTITION_H
#include <QVector>
#include <string>

class JSon;

class Parametre;

class Repartition
{
public:

    Repartition(QVector<Parametre *> Vecteur);

    QVector<Parametre*> tampon;
    QVector<Parametre*> general;
    QVector<Parametre> Antenne_1_temp;
    QVector<Parametre*> Antenne_1;
    QVector<Parametre> Antenne_2_temp;
    QVector<Parametre*> Antenne_2;
    QVector<Parametre> Antenne_3_temp;
    QVector<Parametre*> Antenne_3;
    QVector<Parametre> Antenne_4_temp;
    QVector<Parametre*> Antenne_4;
    QVector<QVector<Parametre*>> Global;

};

#endif // REPARTITION_H
