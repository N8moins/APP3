/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Nathan Lessard et Gabriel Bruneau
 * Date : 13 janvier 2025
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec
 *    les specifications de Graphicus. Ce fichier fait partie de
 *    la distribution de Graphicus.
 ********/

#ifndef COUCHE_H
#define COUCHE_H

#include "Formes/forme.h"
#include "coordonnee.h"

const int MAX_FORMES = 5;

// A completer

class Couche
{
public:
    enum Etat
    {
        Initialise,
        desactive,
        actif
    };

  Couche();
  ~Couche();
  bool ajouterForme(Forme *forme);
  Forme *supprimerForme(int index);
  Forme *getForme(int index);
  double aireTotale();
  bool translater(int deltaX, int deltaY);
  bool reinitialiser();
  bool changerEtat(Etat etat);
  void afficherCouche(ostream &s);
  Etat getEtat();

private:
  Forme *formes[MAX_FORMES];
    Coordonnee ancrage;
    Etat etat;
    int count = 0;
};

#endif
