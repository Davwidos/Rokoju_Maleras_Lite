#include "gracz.h"
#include"gra.h"
Gracz::Gracz(Gra *gra, QString nazwa) :QObject()
{
    this->nazwa=nazwa;
    this->gra=gra;
}

Karta* Gracz::dobierz()
{
    ochrona=false;
    Karta *k=gra->dobierz();
    if(k==nullptr) return k;
    connect(k,SIGNAL(clicked(Karta*)),this,SLOT(zagraj(Karta*)));
    if(k1==nullptr)
    {
        k1=k;
        return k;
    }
    k2=k;
    return k;
}

QString Gracz::getNazwa()
{
    return nazwa;
}


void Gracz::zagraj(Karta *k)
{
    if(k->dzialanie(this) && tura)
    {
        disconnect(k,SIGNAL(clicked(Karta*)),this,SLOT(zagraj(Karta*)));
        if(k==k1) k1=k2;
        k2=nullptr;
        tura=false;
        gra->koniectury(k);
    }

}
