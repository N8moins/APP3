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
#include <string>
#include <sstream>
#include "../Formes/rectangle.h"
#include "../Formes/cercle.h"
#include "../Formes/carre.h"

Couche::Couche()
{
    
    etat = Couche::Etat::Initialise;
}

Couche::~Couche()
{
    formes.Clear();
}

bool Couche::ajouterForme(Forme *forme)
{
    if (etat != Couche::Etat::actif)
        return false;
   
    formes += forme;
    ++formes;
    return true;
    
    return false;
}

Couche::Etat Couche::getEtat()
{
    return etat;
}

Forme *Couche::supprimerForme(int index)
{
    if (index >= formes.Count())
        return nullptr;
    if (formes[index] == nullptr)
        return nullptr;
    if (etat != Couche::Etat::actif)
        return nullptr;
    if (formes.Count() == 0)
        return nullptr;

    Forme *pForme = (formes[index]);

    if (index < 0)
        pForme = formes.GetActive();
    Forme* f  = formes[index];
    
    f = formes[formes.Count() - 1];
    
    f = nullptr;

    return pForme;
}

Forme *Couche::getForme(int index)
{
    if (index >= formes.Count()|| index < 0)
        return nullptr;

    if (formes[index] == nullptr)
        return nullptr;

    return formes[index];
}

double Couche::aireTotale()
{
    float total = 0;

    for (int i = 0; i < formes.Count(); i++)
    {
        total += formes[i]->aire();
    }

    return total;
}

bool Couche::translater(int deltaX, int deltaY)
{
    try
    {
        for (int i = 0; i < formes.Count(); i++)
        {
            Forme* forme = formes[i];
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

bool Couche::formeSuivante() 
{
    ++formes;
    return true;
}

bool Couche::formePrecedente()
{
    --formes;
    return true;
}

bool Couche::setActive(int index)
{

    if (index == -1)
        index = formes.Count() - 1;
    if (index >= formes.Count() || index < 0)
        return false;
    if (formes[index] == formes.GetActive())
        return false;

    formes.SetActive(index);
    return true;
}

bool Couche::reinitialiser()
{
    if (etat == Couche::Etat::Initialise)
        return false;

    etat = Couche::Etat::Initialise;

    formes.Clear();

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
    ostringstream os;
    os << "L " << (etat == Couche::Etat::actif ? "a" :
        etat == Couche::Etat::desactive ? "x" : "i") << endl;
    if (!formes.Count())
    {
        return os.str().c_str();
    }
    else
    {
        int i = 0;
        while (i < formes.Count())
        {
            os << formes[i]->afficher();
            i++;
        }
    }
    return os.str().c_str();
}

Vector<int> Split(std::string input, char divider) {
    Vector<int> values;
    size_t pos;
    while ((pos = input.find(divider)) != std::string::npos) {
        values += std::stoi(input.substr(0, pos));
        input = input.substr(pos + 1);
    }
    values += std::stoi(input);
    return values;
}

std::istream& operator>>(std::istream& is, Couche& layer) {
    std::string line;
    while (std::getline(is, line)) {

        Couche* layer = new Couche();
        if (line.find('a') != std::string::npos)
            layer->changerEtat(Couche::Etat::actif);
        else if (line.find('i') != std::string::npos)
            layer->changerEtat(Couche::Etat::Initialise);
        else if (line.find('x') != std::string::npos)
            layer->changerEtat(Couche::Etat::desactive);
        else if (line.find('K') != std::string::npos) {
            Vector<int> values = Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int c = values[2];

            Carre* square = new Carre(x, y, c);
            layer->ajouterForme(square);
        }
        else if (line.find('R') != std::string::npos) {
            Vector<int> values = Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int l = values[2];
            int h = values[3];

            Rectangle* rect = new Rectangle(x, y, l, h);
            layer->ajouterForme(rect);
        }
        else if (line.find('C') != std::string::npos) {
            Vector<int> values = Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int r = values[2];

            Cercle* circle = new Cercle(x, y, r);
            layer->ajouterForme(circle);
        }
    }
    return is;
}