/***
 * Fichier:  carre.h
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Definition de la classe carre selon 
 * les specifications de Graphicus. 
 */

#ifndef CARRE_H
#define CARRE_H

#include <iostream>
#include <string>
#include "rectangle.h"

using namespace std;

class Carre : public Rectangle
{
    public:
        Carre(int x = 0, int y = 0, int cote = 1);
        ~Carre();
        string afficher();
        double aire();
    protected:
        int cote;
};

#endif