/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Nathan Lessard et Gabriel Bruneau
 * Date : 13 janvier 2025
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include <sstream>
#include "canevas.h"
#include "couche.h"

using namespace std;

Canevas::Canevas()
{
}

Canevas::~Canevas()
{
}

bool Canevas::ajouterCouche()
{
    Couche* tmp = new Couche();

    if (couches.Count() == 0)
    {
        tmp->changerEtat(Couche::Etat::actif);
    }

    if (tmp->getEtat() == Couche::Etat::actif)
    {
        active = tmp;
    }

    couches += tmp;

    return true;
}

bool Canevas::retirerCouche(int index)
{
    if (index > couches.Count())
        return false;


    if (couches.IsEmpty())
        return false;


    if (index < 0) {
        for (int i = 0; i < couches.Count(); i++) {
            if (active == couches[i]) {
                index = i;
            }
        }
    }

    if (index == -1) {
        return false;
    }

    Couche* c = couches[index];

    c->reinitialiser();

    cout << "Couche " << index << " retiree" << endl;

    couches.Remove(index);


    // TODO -- A CHANGER
    c = nullptr;

    return true;
}

bool Canevas::reinitialiser()
{
    try
    {
        for (int i = 0; i < couches.Count(); i++)
        {
            couches[i]->reinitialiser();
        }

        couches.Clear();

        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}

bool Canevas::reinitialiserCouche(int index)
{
    if (index >= couches.Count() || index < 0)
        return false;

    if (couches[index] == active)
        return false;

    couches[index]->reinitialiser();

    return true;
}

bool Canevas::activerCouche(int index)
{
    if (index == -1)
        index = couches.Count() - 1;
    if (index >= couches.Count() || index < 0)
        return false;
    if (couches[index] == active)
        return false;

    couches[index]->changerEtat(Couche::Etat::actif);

    active->changerEtat(Couche::Etat::desactive);
    active = couches[index];
    return true;
}

bool Canevas::coucheSuivante()
{
    for (int i = 0; i < couches.Count(); i++) {
        if (active == couches[i]) {
            if (i != couches.Count() - 1) {
                active->changerEtat(Couche::Etat::desactive);
                active = couches[i + 1];
                active->changerEtat(Couche::Etat::actif);
            }
            return true;
        }
    }

    if (couches.Count() > 0) {
        active = couches[0];
        active->changerEtat(Couche::Etat::actif);
        return true;
    }

    return false;
}

bool Canevas::couchePrecedente()
{
    for (int i = 0; i < couches.Count(); i++) {
        if (active == couches[i]) {
            if (i != 0) {
                active->changerEtat(Couche::Etat::desactive);
                active = couches[i-1];
                active->changerEtat(Couche::Etat::actif);
                return true;
            }
        }
    }

    if (couches.Count() > 0) {
        active = couches[0];
        active->changerEtat(Couche::Etat::actif);
        return true;
    }

    return false;
}

bool Canevas::desactiverCouche(int index)
{

    if (index >= couches.Count() || index < 0)
        return false;
    if (couches[index]->getEtat() == Couche::Etat::desactive)
        return false;

    couches[index]->changerEtat(Couche::Etat::desactive);
    return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
    if (p_forme == nullptr)
    {
        return false;
    }

    if (couches.Count() == 0)
    {
        return false;
    }

    if (active->getEtat() != Couche::Etat::actif)
        return false;

    return active->ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
    if (couches.Count() == 0)
        return false;
    if (active->getEtat() != Couche::Etat::actif)
        return false;

    active->supprimerForme(index);
    return true;
}

double Canevas::aire()
{
    double aire = 0;

    for (int i = 0; i < couches.Count(); i++)
    {
        aire += couches[i]->aireTotale();
    }
    return aire;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    if (active->getEtat() != Couche::Etat::actif)
        return false;

    return active->translater(deltaX, deltaY);
}

const Vector<Couche*> Canevas::getCouches() {
    return couches;
}

ostringstream Canevas::afficher()
{
    ostringstream os;
    if (couches.IsEmpty())
    {
        return os;
    }
    else
    {
        for (int i = 0; i < couches.Count(); i++)
        {
            os << couches[i]->afficherCouche();
        }
    }
    return os;
}
