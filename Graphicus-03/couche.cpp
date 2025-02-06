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
    for (int i = 0; i < count; i++)
        if (formes[i] != nullptr)
            delete formes[i];
}

bool Couche::ajouterForme(Forme *forme)
{
    if (etat != Couche::Etat::actif)
        return false;
   
    formes += forme;
    count++;
    courante = formes.Count();
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
    if (index < 0)
        index = courante;
    if (formes.Count() == 0)
        return nullptr;

    Forme *pForme = (formes[index]);

    Forme* f  = formes[index];

    for (int i = 0; i + index < count; i++)
    {
        formes[index + i] = formes[index + i + 1];
    }
    
    f = formes[formes.Count() - 1];
    f = nullptr;

    count--;

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

string Couche::afficherCouche()
{
    ostringstream os;
    os << "L " << (etat == Couche::Etat::actif ? "a" :
        etat == Couche::Etat::desactive ? "x" : "i") << endl;
    if (!count)
    {
        return "";
    }
    else
    {
        int i = 0;
        while (i < count)
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