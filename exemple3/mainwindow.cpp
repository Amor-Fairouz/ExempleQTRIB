#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bankView->setModel(tmpCp.afficherCompte());
    on_courantRB_clicked();
    ui->RechercheView->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_epargneRB_clicked()
{
    ui->interetLB->setVisible(true);
    ui->interetLE->setVisible(true);
}

void MainWindow::on_courantRB_clicked()
{
    ui->interetLB->setVisible(false);
    ui->interetLE->setVisible(false);

}

void MainWindow::on_ajoutPB_clicked()
{

        int rib = ui->ribLE->text().toInt();
        QString nom= ui->nomLE->text();
        float solde = ui->montantLE->text().toFloat();
        Compte*cp = new Compte(rib,nom,solde);
        if (cp->ajoutCompte(cp))
            QMessageBox::information(0, qApp->tr("Ajout"),
                qApp->tr("Un nouveau compte a été ajouté"), QMessageBox::Ok);
        else
            QMessageBox::critical(0, qApp->tr("Ajout"),
                qApp->tr("Probléme d'ajout"), QMessageBox::Cancel);
       ui->bankView->setModel(tmpCp.afficherCompte());

}

void MainWindow::on_rechercherPB_clicked()
{
    int rib =ui->ribRechLE->text().toInt();
    QSqlQueryModel *model =tmpCp.rechercherCompte(rib);
    int ribRech = model->data(model->index(0, 0)).toInt();
    if(rib == ribRech)
    {
        ui->RechercheView->show();
        ui->RechercheView->setModel(model);
    }
     else
    {
        QMessageBox::critical(0, qApp->tr("Recherche"),
            qApp->tr("Compte non trouvé"), QMessageBox::Ok);
         ui->RechercheView->hide();
    }


}

void MainWindow::on_supprimerPB_clicked()
{
    int rib =ui->ribSupLE->text().toInt();
    QSqlQueryModel *model =tmpCp.rechercherCompte(rib);
    int ribRech = model->data(model->index(0, 0)).toInt();
    if(rib == ribRech)
    {
        QString str = " Vous voulez vraiment supprimer \n le compte ayant le RIB :"+ ui->ribSupLE->text();
        int ret = QMessageBox::question(this, tr("ATB"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
          case QMessageBox::Ok:
              if (tmpCp.supprimerCompte(rib))
                  QMessageBox ::information(0, qApp->tr("Suppression"),
                      qApp->tr("Le compte a été supprimé"), QMessageBox::Ok);

              ui->bankView->setModel(tmpCp.afficherCompte());
              break;
          case QMessageBox::Cancel:

              break;
          default:
              // should never be reached
              break;
        }



    }
     else
    {

        QMessageBox::critical(0, qApp->tr("Suppression"),
            qApp->tr("Compte non trouvé"), QMessageBox::Cancel);

    }


}
