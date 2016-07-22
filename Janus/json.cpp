#include <parametre.h>
#include <json.h>

JSon::JSon()
{
    QString settings;
    QFile file;
    file.setFileName("court.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    settings = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(settings.toUtf8());
    QJsonArray array = doc.array();
    Param_Vect.resize(array.size());
    int c;
    for(c = 0; c < array.size(); c++){

        Param_Vect[c] = new Parametre(array[c].toObject());
    }
}
