/***
 * Fichier:  carre.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Implementation des methodes de la classe carre.
 */


#include <sstream>
#include "carre.h"


Carre::Carre(int x, int y, int cote) : Rectangle(x, y, cote, cote)
{
    this->cote = cote;
}

Carre::~Carre()
{
}

double Carre::aire()
{
    return cote * cote;
}

string Carre::afficher() {
    ostringstream os;

    os << "K " << ancrage.x << " " << ancrage.y <<
            " " << cote << endl;

    return os.str().c_str();
}