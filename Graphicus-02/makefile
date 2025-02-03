#
# Auteur: C.-A. Brunet
# Date: 13 juin 2024
# Modifie par : Nathan Lessard et Gabriel Bruneau
# Date : 12 janvier 2025		
# Description: compilation de graphicus-02. Ce fichier fait partie de
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o couche.o forme.o rectangle.o carre.o cercle.o

graphicus-02.o: graphicus-02.cpp canevas.h couche.h Formes/forme.h
	g++ -c graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h Formes/forme.h
	g++ -c tests.cpp

canevas.o: ./VectorLib/vector.h canevas.cpp canevas.h couche.h Formes/forme.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h Formes/forme.h
	g++ -c couche.cpp

forme.o: Formes/forme.cpp Formes/forme.h
	g++ -c Formes/forme.cpp

rectangle.o: Formes/rectangle.cpp Formes/rectangle.h forme.o
	g++ -c Formes/rectangle.cpp

carre.o: Formes/carre.cpp Formes/carre.h Formes/rectangle.h forme.o
	g++ -c Formes/carre.cpp

cercle.o: Formes/cercle.cpp Formes/cercle.h forme.o
	g++ -c Formes/cercle.cpp



clean:
	rm  -f *.o
