#include "repartition.h"
#include "fenetre.h"
#include "parametre.h"
#include "json.h"

Repartition::Repartition(QVector<Parametre*> Vecteur)
{
    int copie;
    QString matuidi_charo;

    for(int a = 0; a < Vecteur.size(); a++){

        if(Vecteur[a]->m_id.toInt() > 99){

            tampon.append(Vecteur[a]);
        }

        else{
            general.append(Vecteur[a]);
        }
    }

    for(int i = 0; i < tampon.size(); i++){

        Antenne_1_temp.append(*tampon[i]);
        Antenne_2_temp.append(*tampon[i]);
        Antenne_3_temp.append(*tampon[i]);
        Antenne_4_temp.append(*tampon[i]);
    }

    Antenne_1.resize(Antenne_1_temp.size());
    Antenne_2.resize(Antenne_2_temp.size());
    Antenne_3.resize(Antenne_3_temp.size());
    Antenne_4.resize(Antenne_4_temp.size());


    for(int i = 0; i < Antenne_1.size(); i++){

        Antenne_1[i] = &Antenne_1_temp[i];
        Antenne_2[i] = &Antenne_2_temp[i];
        Antenne_3[i] = &Antenne_3_temp[i];
        Antenne_4[i] = &Antenne_4_temp[i];

    }


    for(int z = 0; z < Antenne_2.size(); z++){

        copie = 0;
        copie = Antenne_2[z]->m_id.toInt();
        copie = copie + 100;
        matuidi_charo = QString::number(copie);
        Antenne_2[z]->m_id = matuidi_charo;

    }

    for(int z = 0; z < Antenne_3.size(); z++){

        copie = 0;
        copie = Antenne_3[z]->m_id.toInt();
        copie = copie + 200;
        matuidi_charo = QString::number(copie);
        Antenne_3[z]->m_id = matuidi_charo;
    }

    for(int z = 0; z < Antenne_4.size(); z++){

        copie = 0;
        copie = Antenne_4[z]->m_id.toInt();
        copie = copie + 300;
        matuidi_charo = QString::number(copie);
        Antenne_4[z]->m_id = matuidi_charo;

    }


    Global.append(general);
    Global.append(Antenne_1);
    Global.append(Antenne_2);
    Global.append(Antenne_3);
    Global.append(Antenne_4);



}
