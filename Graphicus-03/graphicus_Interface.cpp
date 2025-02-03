/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2024 D�partement de g�nie �lectrique et g�nie informatique
*                Universit� de Sherbrooke
********/

#include "./graphicus_Interface.h"

graphicus_Interface::graphicus_Interface(const char* theName) : GraphicusGUI(theName)
{
	effacerInformations();
}