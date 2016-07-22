#ifndef JSON_H
#define JSON_H
#include <parametre.h>
#include <json.h>
#include <QVector>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QList>
#include <QDebug>

class Parametre; //j'inclus la classe Parametre afin d'utiliser ses attributs

class JSon
{
public:
    JSon();
    QVector<Parametre*> Param_Vect; //Vecteur de stockage des parametres

private:
    };

#endif // JSON_H
