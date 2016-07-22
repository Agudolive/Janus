#include "fenetre.h"
#include "parametre.h"
#include "json.h"
#include <iostream>

Fenetre::Fenetre(QVector<QVector<Parametre*>> Global) : QWidget()
{

    current_tab_index = 0;

    vecpar = Global;
    m_listv = new QListView;
    m_model = new QStringListModel;
    m_tabw = new QTabWidget(this);

    for(int c = 0; c < vecpar[current_tab_index].size(); c++){

        m_list.insert(c, vecpar[current_tab_index][c]->m_id);
        qWarning() << m_list[c];
    }

    m_model->setStringList(m_list);

    m_datetime = new QDateTime;

    m_tabw->addTab(new QWidget, "General");
    m_tabw->addTab(new QWidget, "Antenne 1");
    m_tabw->addTab(new QWidget, "Antenne 2");
    m_tabw->addTab(new QWidget, "Antenne 3");
    m_tabw->addTab(new QWidget, "Antenne 4");

    m_listv = new QListView(this);
    m_listv->setModel(m_model);
    m_listv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_listv->show();
    m_label1 = new QTextEdit(this);
    m_label2 = new QTextEdit(this);
    m_label3 = new QTextEdit(this);
    m_label4 = new QTextEdit(this);

    m_label1->setStyleSheet("border: 2px solid");
    m_label2->setStyleSheet("border: 2px solid");
    m_label3->setStyleSheet("border: 2px solid");
    m_label4->setStyleSheet("border: 2px solid");

    m_label1->setFixedSize(300,50);
    m_label2->setFixedSize(300,50);
    m_label3->setFixedSize(300,50);
    m_label4->setFixedSize(300,50);

    m_label1->setReadOnly(true);
    m_label2->setReadOnly(true);
    m_label3->setReadOnly(true);
    m_label4->setReadOnly(true);

    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(m_tabw,0,0,6,2);
    mainLayout->addWidget(m_listv,1,0,6,1);
    mainLayout->addWidget(m_label1,1,3,1,2);
    mainLayout->addWidget(m_label2,2,3,1,2);
    mainLayout->addWidget(m_label3,3,3,1,2);
    mainLayout->addWidget(m_label4,4,3,1,2);

    m_button_read = new QPushButton(this);
    m_button_read->setText("Read .PAR File");
    m_button_read->setGeometry(390,750,80,80);

    m_button = new QPushButton(this);
    m_button->setText(".PAR File");
    m_button->setGeometry(300,750,80,80);

    m_button3 = new QPushButton(this);
    m_button3->setText("Valider");
    m_button3->setGeometry(830,670,150,25);

    m_box = new QComboBox(this);
    m_box->setGeometry(850,520,150,25);

    m_selectmodel = new QItemSelectionModel(m_model);
    m_listv->setSelectionModel(m_selectmodel);

    connect(m_selectmodel, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slot_selectionChanged(QItemSelection, QItemSelection)));

    connect(m_box, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_textchanged(QString)));

    connect(m_button, SIGNAL(clicked()), this, SLOT(slot_ecriturebtn()));

    connect(m_button3, SIGNAL(clicked()), this, SLOT(slot_button_valider()));

    connect(m_tabw, SIGNAL(currentChanged(int)), this, SLOT(slot_tabwidget(int)));

    connect(m_button_read, SIGNAL(clicked()), this, SLOT(slot_button_read()));
}

void Fenetre::slot_selectionChanged(const QItemSelection &selected, const QItemSelection &deselected){
    for(int i = 0; i < selected.indexes().size(); ++i)
    {
//        if(vecpar[current_tab_index][index]->m_code_choix.isEmpty() == 0){

            index = selected.at(i).topLeft().row();
            m_box->clear();
            m_label1->setText(vecpar[current_tab_index][index]->m_desc_D);
            m_label2->setText(vecpar[current_tab_index][index]->m_nom_D);
            m_label3->setText(vecpar[current_tab_index][index]->m_desc_E);
            m_label4->setText(vecpar[current_tab_index][index]->m_desc_F);

            for(int z = 0; z < vecpar[current_tab_index][index]->m_code_choix.size(); ++z){

                m_box->addItem(vecpar[current_tab_index][index]->m_code_choix[z].toString());

            }


//        else{
            index = selected.at(i).topLeft().row();

            m_linedit = new QLineEdit(this);
            m_linedit->setGeometry(800,620,150,25);
            m_linedit->setStyleSheet("border: 2px solid");
            m_linedit->setPlaceholderText("test");
            m_linedit->show();

}

}

void Fenetre::slot_textchanged(const QString string){

    vecpar[current_tab_index][index]->m_save = string;

    qWarning() << vecpar[current_tab_index][index]->m_id << "=" << vecpar[current_tab_index][index]->m_save;

}

void Fenetre::slot_ecriturebtn(){

    QString file = QFileDialog::getSaveFileName(this, tr("Ouvrir image ..."),"TRX12",tr("Parameter (*.PAR)"));

    QFileInfo fileInfo(file);

    QString dirPath = fileInfo.filePath(); // Path vers le fichier

    QFile fichier(dirPath);
    QTextStream out(&fichier);


    out << "********************************************";
    out << "\r\n" << "TRX12.PAR     " << m_datetime->currentDateTime().toString();
    out << "\r\n" << "********************************************";

    fichier.open(QIODevice::ReadWrite);

    for(int f = 0; f < vecpar.size(); f++){


        for(int v = 0; v < vecpar[f].size(); v++){

            if(vecpar[f][v]->m_save.isEmpty()){


            }

            else{

                int nbr = vecpar[f][v]->m_id.size();

                switch (nbr) {

                case 1:

                    out << "\r\n" << "\r\n" << "#" << "000" << vecpar[f][v]->m_id << "=" << vecpar[f][v]->m_save;

                    break;

                case 2:

                    out << "\r\n" << "\r\n" << "#" << "00" << vecpar[f][v]->m_id << "=" << vecpar[f][v]->m_save;

                    break;

                case 3:

                    out << "\r\n" << "\r\n" << "#" << "0" << vecpar[f][v]->m_id << "=" << vecpar[f][v]->m_save;

                    break;

                }

            }

        }

    }

    out << "\r\n" << "\r\n" << "---------------------------------------------";

    fichier.close();
}

void Fenetre::slot_tabwidget(int index)
{
    current_tab_index = m_tabw->currentIndex();

    m_list.clear();

    for(int c = 0; c < vecpar[current_tab_index].size(); c++){

        m_list.insert(c, vecpar[current_tab_index][c]->m_id);
        qWarning() << m_list[c];
    }
    m_model->setStringList(m_list);

    m_selectmodel = new QItemSelectionModel(m_model);
    m_listv->setSelectionModel(m_selectmodel);

    connect(m_selectmodel, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slot_selectionChanged(QItemSelection, QItemSelection)));

    qDebug("currentChanged(%d), currentIndex() = %d", index, current_tab_index);

}


void Fenetre::slot_button_valider(){

    vecpar[current_tab_index][index]->m_save = m_linedit->text();

    m_linedit->clear();

}

void Fenetre::slot_button_read(){

    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Parameter File (*.PAR)");

    QFileInfo fileInfo(fichier);

    QString filePath = fileInfo.filePath();

    QString fileName = fileInfo.fileName();

    QFile fichier_a_ouvrir(fichier);

    fichier_a_ouvrir.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream flux(&fichier_a_ouvrir);

    QString temp = flux.readAll();

    int compte = temp.count("=");

    qWarning() << compte;

    int position = 0;

    int prov;

    QVector<int> index, valeur;

    for(int a = 0 ; a < compte ; a++){

        temp.indexOf("=",position);

        qWarning() << position;

        temp.rightRef(5);

        prov = (temp.indexOf("=",position));

        position = prov+1;



    }




     //temp.count("=", Qt::CaseInsensitive);

//    if (temp.contains("=", Qt::CaseInsensitive)){
//        qWarning() << "zebzeb";
//    }

//    else{
//        qWarning() << "Que dalle frolo zebzeb";
//    }

    //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);



}
