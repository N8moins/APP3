/***
 * Fichier:  cercle.h
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Definition de la classe Rectangle selon 
 * les specifications de Graphicus. 
 */

#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include <string>
#include "forme.h"

using namespace std;

class Cercle : public Forme
{
    public:
        Cercle(int x = 0, int y = 0, int rayon = 1);
        ~Cercle();
        string afficher();
        double aire();
    protected:
        int rayon;
};

#endif