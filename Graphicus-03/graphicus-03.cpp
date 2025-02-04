/********
 * Fichier: graphicus-03.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 03 fevrier
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#include <QApplication>
#include <sstream>
#include "graphicus_Interface.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	graphicus_Interface gui("GraphicusGUI 3.0");
	return app.exec();
}
