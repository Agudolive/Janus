#include <QDebug>
#include "json.h"
#include "parametre.h"
#include "fenetre.h"
#include <QApplication>
#include "repartition.h"


int main(int argc, char **argv){

    QApplication a(argc, argv);

    JSon json;

    Repartition split(json.Param_Vect);

    Fenetre window(split.Global);

    window.setMinimumSize(512,512);

    window.setLayout(window.layout());

    window.activateWindow();

    window.show();

    return a.exec();

}
