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
#include <fstream>
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

void graphicus_Interface::coucheTranslater(int deltaX, int deltaY)
{
	canevas.translater(deltaX, deltaY);
	preDraw();
}

void graphicus_Interface::ajouterCarre(int x, int y, int c) 
{	
	Carre* square = new Carre(x, y, c);
	canevas.ajouterForme(square);
	preDraw();
}

void graphicus_Interface::ajouterRectangle(int x, int y, int l, int h)
{
	canevas.ajouterForme(new Rectangle(x, y, l, h));
	preDraw();
}

void graphicus_Interface::ajouterCercle(int x, int y, int r)
{
	canevas.ajouterForme(new Cercle(x, y, r));
	preDraw();
}

void graphicus_Interface::retirerForme() 
{
	canevas.retirerForme();
	preDraw();
}

void graphicus_Interface::couchePremiere() 
{
	canevas.activerCouche(0);
	preDraw();
}

void graphicus_Interface::coucheDerniere()
{
	canevas.activerCouche(-1);
	preDraw();
}

void graphicus_Interface::coucheAjouter()
{
	canevas.ajouterCouche();
	preDraw();
}

void graphicus_Interface::coucheSuivante()
{
	canevas.coucheSuivante();
	preDraw();
}

void graphicus_Interface::couchePrecedente()
{
	canevas.couchePrecedente();
	preDraw();
}


void graphicus_Interface::reinitialiserCanevas()
{
	canevas.reinitialiser();
	preDraw();
}

void graphicus_Interface::coucheRetirer()
{
	canevas.retirerCouche();
	preDraw();
}

void graphicus_Interface::formePremiere()
{
	canevas.formeActive(0);
	preDraw();
}

void graphicus_Interface::formeDerniere()
{
	canevas.formeActive(-1);
	preDraw();
}

void  graphicus_Interface::formeSuivante()
{
	canevas.formeSuivante();
	preDraw();
}

void graphicus_Interface::formePrecedente()
{
	canevas.formePrecedente();
	preDraw();
}

void graphicus_Interface::preDraw() 
{
	ostringstream os;

	os = canevas.afficher();

	dessiner(os.str().c_str());
	GraphicusGUI::afficher(cout);
	
}

bool graphicus_Interface::sauvegarderFichier(const char* fileName) {
	try
	{
		std::ofstream file(fileName);
		if (file.is_open()) {
			file << canevas.getCouches();
		}

		std::cout << "saved successfuly" << std::endl;
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool graphicus_Interface::ouvrirFichier() {
	try
	{
		

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}