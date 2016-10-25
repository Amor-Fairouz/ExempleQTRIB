#include "compteepargne.h"

compteEpargne::compteEpargne()
{
}
compteEpargne::compteEpargne(int rib, QString nom, float solde,float interet)
    :Compte(rib, nom,solde)
{
    this->interet=interet;
}
