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

Couche::Couche()
{
    // etat = INITIALISE;
    for (int i = 0; i < MAX_FORMES; i++)
        formes[i] = nullptr;
}

Couche::~Couche()
{
    for (int i = 0; i < count; i++)
        if (formes[i] != nullptr)
            delete formes[i];
}

bool Couche::ajouterForme(Forme *forme)
{
    if (etat != Couche::Etat::actif)
        return false;

    if (count < MAX_FORMES)
    {
        formes[count] = forme;
        count++;
        return true;
    }
    return false;
}

Couche::Etat Couche::getEtat()
{
    return etat;
}

Forme *Couche::supprimerForme(int index)
{
    if (index >= MAX_FORMES || index < 0)
        return nullptr;
    if (formes[index] == nullptr)
        return nullptr;
    if (etat != Couche::Etat::actif)
        return nullptr;

    Forme *pForme = (formes[index]);

    formes[index] = nullptr;

    for (int i = 0; i + index < count; i++)
    {
        formes[index + i] = formes[index + i + 1];
    }
    
    formes[MAX_FORMES - 1] = nullptr;
    count--;

    return pForme;
}

Forme *Couche::getForme(int index)
{
    if (index >= MAX_FORMES || index < 0)
        return nullptr;

    if (formes[index] == nullptr)
        return nullptr;

    return formes[index];
}

double Couche::aireTotale()
{
    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += formes[i]->aire();
    }

    return total;
}

bool Couche::translater(int deltaX, int deltaY)
{
    try
    {
        for (int i = 0; i < MAX_FORMES; i++)
        {
            Forme* forme = formes[i];
            if(forme != nullptr)
                forme->translater(deltaX, deltaY);
        }

        // ancrage.x += deltaX;
        // ancrage.y += deltaY;

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
        delete formes[i];

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

void Couche::afficherCouche(ostream &s)
{
    s << "État: " << ((etat == Couche::Etat::Initialise) ? "initialisée" : (etat == Couche::Etat::actif) ? "active"
                                                                                                         : "inactive")
      << endl;
    if (!count)
    {
        s << "Couche: vide" << endl;
    }
    else
    {
        int i = 0;
        while (i < count)
        {
            formes[i]->afficher(s);
            i++;
        }
    }
}