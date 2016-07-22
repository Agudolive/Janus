#ifndef FENETRE_H
#define FENETRE_H
#include <parametre.h>
#include <json.h>
#include <QWidget>
#include <QListView>
#include <QStringListModel>
#include <QList>
#include <QLabel>
#include <QItemSelectionModel>
#include <QPushButton>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include <QTabWidget>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>

class JSon;
class QStringList;
class QStringListModel;
class QItemSelectionModel;

class Fenetre : public QWidget
{
Q_OBJECT

public:
    Fenetre(QVector<QVector<Parametre *> > Global);
    QGridLayout *mainLayout;

public slots:
    void slot_selectionChanged (const QItemSelection &selected, const QItemSelection &deselected);
    void slot_textchanged(const QString string);
    void slot_ecriturebtn();
    void slot_tabwidget(int index);
    void slot_button_valider();
    void slot_button_read();

private:

    QLineEdit *m_linedit;
    QListView *m_listv;
    QStringList m_list, empty_list;
    QStringListModel *m_model, *empty_model;
    QTextEdit *m_label1, *m_label2, *m_label3, *m_label4;
    QPushButton *m_button;
    QPushButton *m_button2;
    QPushButton *m_button3;
    QPushButton *m_button_read;
    QItemSelectionModel *m_selectmodel;
    QVector<QVector<Parametre*>> vecpar;
    QComboBox *m_box;
    QTabWidget *m_tabw;
    QDateTime *m_datetime;
    int current_tab_index;
    int index = 0;
};

#endif // FENETRE_Hk

