/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : Nathan Lessard et Gabriel Bruneau
 * Date : 13 janvier 2025
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"
#include "./Formes/rectangle.h"
#include "./Formes/carre.h"
#include "./Formes/cercle.h"
#include "couche.h"

Canevas *canevas = new Canevas();

void Tests::tests_unitaires_formes()
{
     Forme *pCarre = new Carre(0, 0, 3);
     pCarre->afficher(std::cout);
     pCarre->translater(2, -1);
     pCarre->afficher(std::cout);
     pCarre->setAncrage({5, 5});
     pCarre->afficher(std::cout);
     delete pCarre;
     Forme *pCercle = new Cercle(2, 3, 5);
     pCercle->afficher(std::cout);
     delete pCercle;
     Forme *pRectangle = new Rectangle(0, 0, 3, 4);
     pRectangle->afficher(std::cout);
     delete pRectangle;
}

void Tests::tests_unitaires_couche()
{
     Couche *couche = new Couche();
     couche->changerEtat(Couche::Etat::actif);
     Forme *pCarre = new Carre(0, 0, 3);
     couche->ajouterForme(pCarre);
     Forme *pCercle = new Cercle(2, 3, 5);
     couche->ajouterForme(pCercle);
     Forme *pRectangle = new Rectangle(0, 0, 3, 4);
     couche->ajouterForme(pRectangle);
     couche->afficherCouche(std::cout);
     couche->translater(2, -1);
     couche->afficherCouche(std::cout);
     couche->afficherCouche(std::cout);
     Forme *pCarre2 = new Carre(0, 0, 3);
     couche->ajouterForme(pCarre2);
     Forme *pCercle2 = new Cercle(2, 3, 5);
     couche->ajouterForme(pCercle2);
     Forme *pRectangle2 = new Rectangle(0, 0, 3, 4);
     couche->ajouterForme(pRectangle2);
     couche->afficherCouche(std::cout);
     couche->changerEtat(Couche::Etat::desactive);
     couche->afficherCouche(std::cout);
}

void Tests::tests_unitaires_vecteur()
{
     // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_canevas()
{
     canevas->afficher(std::cout);
     std::cout << "Test ajouter : " << canevas->ajouterCouche() << endl;
     canevas->afficher(std::cout);
     Forme *pCarre = new Carre(0, 0, 3);
     canevas->ajouterForme(pCarre);
     canevas->afficher(std::cout);
     Forme *pCercle = new Cercle(2, 3, 5);
     canevas->ajouterForme(pCercle);
     Forme *pRectangle = new Rectangle(0, 0, 3, 4);
     canevas->ajouterForme(pRectangle);
     canevas->afficher(std::cout);
     canevas->activerCouche(0);
     canevas->afficher(std::cout);
     canevas->ajouterCouche();
     canevas->afficher(std::cout);
     canevas->activerCouche(1);
     canevas->afficher(std::cout);
}

void Tests::tests_unitaires()
{
     // Fait tous les tests unitaires
     tests_unitaires_formes();
     tests_unitaires_couche();
     tests_unitaires_vecteur();
     tests_unitaires_canevas();
}

void Tests::tests_application()
{
     // Fait tous les tests applicatifs
     tests_application_cas_01();
     tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
     cout << "TESTS APPLICATION (CAS 01)" << endl;

     cout << endl
          << "----- Etape 1 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 2 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;

     cout << endl
          << "----- Etape 3 -----" << endl;
     canevas->ajouterCouche();
     canevas->ajouterCouche();
     canevas->ajouterCouche();
     canevas->ajouterCouche();
     canevas->ajouterCouche();
     cout << "Ajout de 5 couches" << endl;

     cout << endl
          << "----- Etape 4 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 5 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;

     cout << endl
          << "----- Etape 6 -----" << endl;
     canevas->activerCouche(2);
     canevas->ajouterForme(new Cercle(0, 1, 5));
     canevas->ajouterForme(new Carre(1, 2, 6));
     canevas->ajouterForme(new Rectangle(2, 3, 4, 9));
     cout << "Ajout du cercle (0, 1, 5), du carre (1, 2, 6) et du rectangle (2, 3, 4, 9) a la couche 2" << endl;

     cout << endl
          << "----- Etape 7 -----" << endl;
     canevas->activerCouche(1);
     canevas->ajouterForme(new Rectangle(0, 0, 12, 3));
     cout << "Ajout Rectangle (0, 0, 12, 3) a la couche 1" << endl;

     cout << endl
          << "----- Etape 8 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 9 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;

     cout << endl
          << "----- Etape 10 -----" << endl;
     canevas->activerCouche(0);
     canevas->ajouterForme(new Rectangle(0, 0, 1, 1));
     canevas->ajouterForme(new Cercle(0, 0, 1));
     canevas->ajouterForme(new Carre(0, 0, 1));

     cout << "Ajout Rectangle (0, 0, 1, 1), Carre (0, 0, 1) et Cercle (0, 0, 1) a la couche 0" << endl;

     cout << endl
          << "----- Etape 11 -----" << endl;
     canevas->activerCouche(2);
     canevas->translater(2, 1);
     cout << "Translation de la couche 2 de (2, 1)" << endl;

     cout << endl
          << "----- Etape 12 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 13 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;

     cout << endl
          << "----- Etape 14 -----" << endl;
     canevas->activerCouche(0);
     canevas->retirerForme(2);
     cout << "Retrait de la forme 2 de la couche 0" << endl;

     cout << endl
          << "----- Etape 15 -----" << endl;
     canevas->reinitialiserCouche(1);
     cout << "Reinitialisation de la couche 1" << endl;

     cout << endl
          << "----- Etape 16 -----" << endl;
     canevas->activerCouche(2);
     cout << "Activation de la couche 2" << endl;

     cout << endl
          << "----- Etape 17 -----" << endl;
     canevas->retirerCouche(2);
     cout << "Retrait de la couche 2" << endl;

     cout << endl
          << "----- Etape 18 -----" << endl;
     canevas->activerCouche(4);

     cout << endl
          << "----- Etape 19 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 20 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;

     cout << endl
          << "----- Etape 21 -----" << endl;
     canevas->reinitialiser();

     cout << endl
          << "----- Etape 22 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 23 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;
     ;

     cout << endl
          << "----- Etape 24 -----" << endl;
     canevas->activerCouche(3);
     canevas->ajouterForme(new Carre(10, 10, 10));
     canevas->ajouterForme(nullptr);
     cout << "Ajout Carre (10, 10, 10) et nullptr a la couche 3" << endl;

     cout << endl
          << "----- Etape 25 -----" << endl;
     canevas->activerCouche(6);
     cout << "Activation de la couche 6" << endl;

     cout << endl
          << "----- Etape 26 -----" << endl;
     canevas->afficher(std::cout);

     cout << endl
          << "----- Etape 27 -----" << endl;
     cout << "Aire :" << canevas->aire() << endl;
}

void Tests::tests_application_cas_02()
{
     // cout << "TESTS APPLICATION (CAS 02)" << endl;
     // Il faut ajouter les operations realisant ce scenario de test.
}
