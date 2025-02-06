/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Nathan Lessard et Gabriel Bruneau
 * Date : 13 janvier 2025
 * Description: Declaration de la classe Canevas. La classe Canevas gere un
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <sstream>
#include "VectorLib/vector.h"
#include "Formes/forme.h"
#include "couche.h"

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();

   bool ajouterCouche();
   bool retirerCouche(int index = -1);

   bool reinitialiser();
   bool reinitialiserCouche(int index);

   bool activerCouche(int index);
   bool desactiverCouche(int index);

   const Vector<Couche*> getCouches();

   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index = -1);

   bool coucheSuivante();
   bool couchePrecedente();

   bool formeSuivante();
   bool formePrecedente();
   bool formeActive(int index);
   void modePile(bool mode);

   bool setCouche(int index);

   double aire();
   bool translater(int deltaX, int deltaY);
   ostringstream afficher();

private:
    bool pile = false;
    Vector<Couche*> couches;
};

#endif
