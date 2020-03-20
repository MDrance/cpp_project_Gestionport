Prog: Facture.o Place.o Bateau.o Client.o Gestionport.o main.o 
	g++ -o prog main.o Gestionport.o Client.o Bateau.o Place.o Facture.o

Facture.o: Facture.cpp
	g++ -c Facture.cpp

Place.o: Place.cpp
	g++ -c Place.cpp

Bateau.o: Bateau.cpp
	g++ -c Bateau.cpp

Client.o: Client.cpp
	g++ -c Client.cpp

Gestionport.o: Gestionport.cpp
	g++ -c Gestionport.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o

