/***
 * Fichier: rectangle.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Implementation des methodes de la classe Rectangle.
 */

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
void Rectangle::afficher(ostream &s)
{
    s << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y <<
    ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << endl;
}