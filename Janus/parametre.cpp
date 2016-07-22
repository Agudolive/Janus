#include "parametre.h"

Parametre::Parametre(const QJsonObject object){

    m_id = object["parametre"].toString();
    m_nom_D = object["nom_D"].toString();
    m_nom_E = object["nom_E"].toString();
    m_nom_F = object["nom_F"].toString();
    m_desc_D = object["desc_D"].toString();
    m_desc_E = object["desc_E"].toString();
    m_desc_F = object["desc_F"].toString();
    m_choix_D = object["choix_D"].toArray();
    m_choix_E = object["choix_E"].toArray();
    m_choix_F = object["choix_F"].toArray();
    m_code_choix = object["code_choix"].toArray();

}

Parametre::Parametre(){

}
