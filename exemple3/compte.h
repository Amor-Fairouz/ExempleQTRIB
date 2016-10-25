#ifndef COMPTE_H
#define COMPTE_H
#include"QString"
#include "connection.h"
#include "QSqlQueryModel"
class Compte
{

protected:
    int rib;
    QString nomProprietaire;
    float solde;


public:
    Compte(){};
    Compte(int rib, QString nom, float solde);
    int getRib(){return rib;};
    QString getNom(){return nomProprietaire;} ;
    float getSolde() {return solde;};
    bool ajoutCompte(Compte *cp);
    virtual QSqlQueryModel * afficherCompte();
    QSqlQueryModel * rechercherCompte(int rib);
    bool supprimerCompte(int rib);





};

#endif // COMPTE_H
