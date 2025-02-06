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
        couches.SetActive(couches.Count());
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
            if (couches.GetActive() == couches[i]) {
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

    if (couches[index] == couches.GetActive())
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
    if (couches[index] == couches.GetActive())
        return false;

    couches[index]->changerEtat(Couche::Etat::actif);

    couches.GetActive()->changerEtat(Couche::Etat::desactive);
    couches.SetActive(index);
    return true;
}

bool Canevas::coucheSuivante()
{
    if (couches.Count() == 0)
        return false;

    Couche *c = couches.GetActive();
    ++couches;
    if (c != couches.GetActive())
        c->changerEtat(Couche::Etat::desactive);
        couches.GetActive()->changerEtat(Couche::Etat::actif);

    return false;
}

bool Canevas::couchePrecedente()
{
    if (couches.Count() == 0)
        return false;

    Couche* c = couches.GetActive();
    --couches;
    if (c != couches.GetActive())
        c->changerEtat(Couche::Etat::desactive);
    couches.GetActive()->changerEtat(Couche::Etat::actif);

    return false;
}

bool Canevas::formeSuivante() {
    if (couches.Count() == 0)
        return false;

    if (couches.GetActive() == nullptr) {
        return false;
    }

    return couches.GetActive()->formeSuivante();
}

bool Canevas::formePrecedente() {
    if (couches.Count() == 0)
        return false;

    if (couches.GetActive() == nullptr) {
        return false;
    }

    return couches.GetActive()->formePrecedente();

}

bool Canevas::formeActive(int index) {
    if (couches.Count() == 0)
        return false;

    if (couches.GetActive() == nullptr) {
        return false;
    }

    return couches.GetActive()->setActive(index);
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

    if (couches.GetActive()->getEtat() != Couche::Etat::actif)
        return false;

    return couches.GetActive()->ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
    if (couches.Count() == 0)
        return false;
    if (couches.GetActive()->getEtat() != Couche::Etat::actif)
        return false;

    couches.GetActive()->supprimerForme(index);
    return true;
}

void Canevas::modePile(bool mode)
{
    pile = mode;
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
    if (couches.GetActive()->getEtat() != Couche::Etat::actif)
        return false;

    return couches.GetActive()->translater(deltaX, deltaY);
}

Vector<Couche*>& Canevas::getCouches() {
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
        if (!pile)
        {
            for (int i = (couches.Count()-1); i >= 0; i--)
            {
                os << couches[i]->afficherCouche();
            }
        }
        else
        {    
            for (int i = 0; i < couches.Count(); i++)
            {
                os << couches[i]->afficherCouche();
            }
        }
    }
    return os;
}
