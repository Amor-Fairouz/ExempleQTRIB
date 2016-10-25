#include "compte.h"
#include"QDebug"
Compte::Compte(int rib, QString nom, float solde)
{
    this->rib= rib;
    this->nomProprietaire=nom;
    this->solde=solde;


}
bool Compte::ajoutCompte(Compte *cp)
{
    createConnection();
    QSqlQuery query;
    QString res= QString::number(cp->getSolde());
    QString str= "insert into compte values("+ QString::number(cp->getRib())+",'"+cp->getNom()+"',"+res+")";
    qDebug()<<str;
    bool res1 = query.exec(str);
    return res1;

}
QSqlQueryModel * Compte::afficherCompte()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    createConnection();
    model->setQuery("select * from compte");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de Proprietaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Solde"));
    return model;
}
QSqlQueryModel * Compte::rechercherCompte(int rib)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    createConnection();
    QString str="select * from compte where rib ="+QString::number(rib);
    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de Proprietaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Solde"));

    return model;

}
bool Compte::supprimerCompte(int rib)
{
    QSqlQuery query;
    QString str="delete from compte where rib ="+QString::number(rib);
    qDebug()<<str;
    bool res = query.exec(str);
    return res;

}
