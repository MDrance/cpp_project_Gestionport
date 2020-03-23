#include"Place.hpp"
#include<iostream>

//Place
//Compteur nombre places
int Place::nbr_place = 1;

//Destructeur
Place::~Place() {}

//Constructeur
Place::Place()
{
    m_numero_place = nbr_place;
    m_type = 0;
    m_taille_max = 10;
    m_dispo = true;
    nbr_place++;
}

//Getters
int Place::get_numero_place() const {return m_numero_place;}
int Place::get_type() const {return m_type;}
float Place::get_taille_max() const {return m_taille_max;}
bool Place::get_dispo() const {return m_dispo;}

//Setters
void Place::set_dispo(bool dispo) {m_dispo = dispo;}

//Affichage place
void Place::affiche_place() const
{
    std::cout << "Numéro place : " << m_numero_place << std::endl;
    std::cout << "Type : " << m_type << std::endl;
    std::cout << "Taille max : " << m_taille_max << std::endl;
    if (m_dispo == 1) {std::cout << "Place libre\n";}
    else {std::cout << "Place indisponible\n";}
}

void Place::save_places(std::ofstream& file) const
{
    file << m_numero_place << std::endl;
    file << m_type << std::endl;
    file << m_taille_max << std::endl;
    file << m_dispo << std::endl;
}

//Placeservices1
//Surcharge constructeur
Placeservices1::Placeservices1():Place()
{
    m_type = 1;
    m_taille_max = 25;
}

//Destructeur
Placeservices1::~Placeservices1() {}


//Placecervices2
//Surcharge constructeur
Placeservices2::Placeservices2(float taille_max):Placeservices1()
{
    m_type = 2;
    m_taille_max = taille_max;
}

//Destructeur
Placeservices2::~Placeservices2() {}

//Placecorpsmort
//Surcharge constructeur
Placecorpsmort::Placecorpsmort(float taille_max):Place()
{
    m_type = 3;
    m_taille_max = taille_max; 
}

//Destructeur
Placecorpsmort::~Placecorpsmort() {}
