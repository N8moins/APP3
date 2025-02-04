/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke
********/

#include <sstream>
#include "./graphicus_Interface.h"
#include "../Graphicus-03/Formes/carre.h"
#include "../Graphicus-03/Formes/rectangle.h"
#include "../Graphicus-03/Formes/cercle.h"

using namespace std;

graphicus_Interface::graphicus_Interface(const char* theName) : GraphicusGUI(theName)
{
	reinitialiserCanevas();
	effacerInformations();
}

void graphicus_Interface::ajouterCarre(int x, int y, int c) 
{	
	ostringstream os;
	canevas->ajouterForme(new Carre(x, y, c));
	preDraw();
}

void graphicus_Interface::ajouterRectangle(int x, int y, int l, int h)
{
	ostringstream os;
	canevas->ajouterForme(new Rectangle(x, y, l, h));
	preDraw();
}

void graphicus_Interface::ajouterCercle(int x, int y, int r)
{
	ostringstream os;
	canevas->ajouterForme(new Cercle(x, y, r));
	preDraw();
}

void graphicus_Interface::coucheAjouter()
{
	ostringstream os;
	canevas->ajouterCouche();
	preDraw();
}

void graphicus_Interface::reinitialiserCanevas()
{
	canevas->reinitialiser();
	preDraw();
}

void graphicus_Interface::preDraw() 
{
	ostringstream os;

	dessiner(os.str().c_str());
	
}

