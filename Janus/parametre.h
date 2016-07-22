#ifndef PARAMETRE_H
#define PARAMETRE_H
#include <json.h>
#include <parametre.h>
#include <QVector>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QList>
#include <QComboBox>

class Parametre
{
public:
    Parametre(const QJsonObject object);
    Parametre();

    QString m_id;           //Composants d'un parametre
    QString m_nom_D;
    QString m_nom_E;
    QString m_nom_F;
    QString m_desc_D;
    QString m_desc_E;
    QString m_desc_F;
    QJsonArray m_choix_D;
    QJsonArray m_choix_E;
    QJsonArray m_choix_F;
    QJsonArray m_code_choix; // Composants d'un parametre

    QString m_save;
    QComboBox *m_Qbox;

private:

};

#endif // PARAMETRE_H
