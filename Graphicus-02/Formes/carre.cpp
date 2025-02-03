/***
 * Fichier:  carre.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Implementation des methodes de la classe carre.
 */


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

void Carre::afficher(std::ostream &s) {
    s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y <<
            ", c=" << cote << ", aire=" << aire() << ")" << endl;
}