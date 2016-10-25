#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H
#include"compte.h"
class compteCourant : public Compte
{
public:
    compteCourant();
    compteCourant(int rib, QString nom, float solde);

};

#endif // COMPTECOURANT_H
