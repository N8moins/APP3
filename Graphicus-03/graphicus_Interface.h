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

class graphicus_Interface : public GraphicusGUI
{
public:
	graphicus_Interface(const char *theName = nullptr);
};

#endif // MONINTERFACE_H