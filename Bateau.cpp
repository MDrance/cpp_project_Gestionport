#include "Bateau.hpp"
#include <iostream>

//constructeur
Bateau::Bateau() {}

//Surcharge constructeur
Bateau::Bateau(std::string nom_bateau, float taille, int cabine)
{
    m_nom_bateau = nom_bateau;    
    m_taille = taille;
    m_cabine = cabine;
}

//Destructeur
Bateau::~Bateau() {}

//Getters
std::string Bateau::get_nom_bateau() const {return m_nom_bateau;}
float Bateau::get_taille() const {return m_taille;}
int Bateau::get_cabine() const {return m_cabine;}

//Affichage bateau
void Bateau::affiche_bateau() const
{
    std::cout << "Nom du bateau : " << m_nom_bateau << std::endl;
    std::cout << "Taille bateau : " << m_taille << std::endl;
    std::cout << "Cabine(s) bateau : " << m_cabine << std::endl;
}

Bateau Bateau::creer_bateau()
{
    std::string nom_bateau;
    float taille;
    int cabine;
    std::cout << "Quel est le nom du bateau ? \n";
    std::cin >> nom_bateau;
    std::cout << "Quelle est la taille du bateau ? \n";
    std::cin >> taille;
    std::cout << "Quel est le nombre de cabine ? \n";
    std::cin >> cabine;
    Bateau bateau(nom_bateau, taille, cabine);
    return bateau;
}





