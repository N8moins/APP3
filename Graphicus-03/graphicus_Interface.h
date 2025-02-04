/********
* Fichier: graphicus_Interface.h
* Auteurs: Nathan Lessard
* Date: 3 fevrier 2025
*
* Copyright 2025 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "../Graphicus-03/QTLib/graphicusGUI.h"
#include "../Graphicus-03/canevas.h"

class graphicus_Interface : public GraphicusGUI
{
public:
	graphicus_Interface(const char *theName = nullptr);
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCarre(int x, int y, int cote);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int long_x, int long_y);
	
	void reinitialiserCanevas();
	
	void coucheAjouter();
	void coucheRetirer();
	void retirerForme();
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	
	//void formePremiere();
	//void formePrecedente();
	//void formeSuivante();
	//void formeDerniere();
	void preDraw();

private:
	Canevas* canevas = new Canevas();
};

#endif // MONINTERFACE_H