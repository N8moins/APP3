/***
 * Fichier:  cercle.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Implementation des methodes de la classe cercle.
 */


#include "cercle.h"
#include <sstream>

Cercle::Cercle(int x, int y, int rayon) : Forme(x, y), rayon(rayon)
{
}

Cercle::~Cercle()
{
}

double Cercle::aire()
{
    return 3.14159 * rayon * rayon;
}

string Cercle::afficher() {
    ostringstream os;

    os << "C " << ancrage.x << " " << ancrage.y <<
         " " << rayon << endl;
    return os.str().c_str();
}