#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"compte.h"
#include<QSqlRecord>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_epargneRB_clicked();

    void on_courantRB_clicked();

    void on_ajoutPB_clicked();

    void on_rechercherPB_clicked();

    void on_supprimerPB_clicked();

private:

    Ui::MainWindow *ui;
    Compte tmpCp;
};

#endif // MAINWINDOW_H
