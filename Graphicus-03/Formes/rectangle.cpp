/***
 * Fichier: rectangle.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Implementation des methodes de la classe Rectangle.
 */

#include <sstream>
#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int h) : Forme(x, y), largeur(l), hauteur(h)
{
}

Rectangle::~Rectangle()
{
}

double Rectangle::aire() {
    return largeur * hauteur;
}
string Rectangle::afficher()
{
    ostringstream os;

    os << "R " << ancrage.x << " " << ancrage.y <<
    " " << largeur << " " << hauteur << endl;
    
    return os.str().c_str();
}