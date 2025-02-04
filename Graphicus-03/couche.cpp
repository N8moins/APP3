/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Nathan Lessard et Gabriel Bruneau
 * Date : 13 janvier 2025
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "couche.h"
#include "string"

Couche::Couche()
{
}

Couche::~Couche()
{
    for (int i = 0; i < count; i++)
        if (formes->Get(i) != nullptr)
            delete formes->Get(i);
}

bool Couche::ajouterForme(Forme *forme)
{
    if (etat != Couche::Etat::actif)
        return false;
   
    formes->Add(forme);
    count++;
    courante = formes->Count();
    return true;
    
    return false;
}

Couche::Etat Couche::getEtat()
{
    return etat;
}

Forme *Couche::supprimerForme(int index)
{
    if (index >= formes->Count())
        return nullptr;
    if (formes->Get(index) == nullptr)
        return nullptr;
    if (etat != Couche::Etat::actif)
        return nullptr;
    if (index < 0)
        index = courante;
    if (formes->Count() == 0)
        return nullptr;

    Forme *pForme = (formes->Get(index));

    Forme* f  = formes->Get(index);

    for (int i = 0; i + index < count; i++)
    {
        formes[index + i] = formes[index + i + 1];
    }
    
    f = formes->Get(formes->Count() - 1);
    f = nullptr;

    count--;

    return pForme;
}

Forme *Couche::getForme(int index)
{
    if (index >= formes->Count()|| index < 0)
        return nullptr;

    if (formes->Get(index) == nullptr)
        return nullptr;

    return formes->Get(index);
}

double Couche::aireTotale()
{
    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += formes->Get(i)->aire();
    }

    return total;
}

bool Couche::translater(int deltaX, int deltaY)
{
    try
    {
        for (int i = 0; i < formes->Count(); i++)
        {
            Forme* forme = formes->Get(i);
            if(forme != nullptr)
                forme->translater(deltaX, deltaY);
        }

        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool Couche::reinitialiser()
{
    if (etat == Couche::Etat::Initialise)
        return false;

    etat = Couche::Etat::Initialise;

    for (int i = 0; i < count; i++)
        delete formes->Get(i);

    count = 0;

    return true;
}

bool Couche::changerEtat(Etat etat)
{
    if (etat == this->etat)
        return false;

    this->etat = etat;
    return true;
}

string Couche::afficherCouche()
{
    string s;

    if (!count)
    {
        return "";
    }
    else
    {
        int i = 0;
        while (i < count)
        {
            s += formes->Get(i)->afficher();
            i++;
        }
    }
    return s;
}