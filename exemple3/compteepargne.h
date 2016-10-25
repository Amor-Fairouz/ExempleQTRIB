#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include"compte.h"
class compteEpargne : public Compte
{
    float interet;
public:
    compteEpargne();
    compteEpargne(int rib, QString nom, float solde,float interet);

};

#endif // COMPTEEPARGNE_H
