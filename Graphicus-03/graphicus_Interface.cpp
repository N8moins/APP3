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

using namespace std;

graphicus_Interface::graphicus_Interface(const char* theName) : GraphicusGUI(theName)
{
	effacerInformations();
}

void graphicus_Interface::ajouterCarre(int x, int y, int c) 
{	
	ostringstream os;
	canevas->ajouterCouche();
	os << "K " << x << " " << y << " " << " " << c << endl;
	dessiner(os.str().c_str());
}

void graphicus_Interface::coucheAjouter()
{
	ostringstream os;
	canevas->ajouterCouche();
	os << "L a" << endl;
	dessiner(os.str().c_str());
}