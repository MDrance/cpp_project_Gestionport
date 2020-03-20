#include "Facture.hpp"
#include<iostream>

//Facture
//Constructeur
Facture::Facture() {m_tarif = 20; m_dernier_paiement = 0; std::cout<<"facture\n";}

//Destructeur
Facture::~Facture() {}

//Getters
float Facture::get_tarif() const {return m_tarif;}
float Facture::get_dernier_paiement() const {return m_dernier_paiement;}

//Setters
void Facture::set_dernier_paiement() {m_dernier_paiement = m_tarif;}

//Affichage
void Facture::affiche_tarif() const
{
    std::cout << "Votre facture (euros) est de : " << m_tarif << std::endl;
    std::cout << "Prix journalier de base : 20 euros/jours" << std::endl;
    std::cout << "Majoration 30\% pour les places de plus de 10 mètres" << std::endl;
    std::cout << "Majoration 60\% pour les places de plus de 25 mètres" << std::endl;
    std::cout << "Si charge électrique ou eau : 5 euros/services" << std::endl;;
    std::cout << "Dernier paiement : " << m_dernier_paiement << std::endl;
}

//Majoration fonction de la place
void Facture::set_majoration1() {m_tarif = m_tarif + (m_tarif*30) / 100;}
void Facture::set_majoration2() {m_tarif = m_tarif + (m_tarif*60) / 100;}
void Facture::set_minorationcm() {m_tarif = (m_tarif / 2);}
void Facture::set_eau_elec() {m_tarif = m_tarif+10;}
void Facture::set_eau() {m_tarif = m_tarif+5;}
void Facture::set_mult(int num) {m_tarif = m_tarif*num;}

//Factureabo
//Constructeur
Factureabo::Factureabo() {m_tarif = 500/12; m_dernier_paiement = 0; std::cout<<"factureabo\n";}

//Destructeur
Factureabo::~Factureabo() {}

//Affichage
void Factureabo::affiche_tarif() const
{
    std::cout << "Votre facture mensuelle (euros) est de : " << m_tarif << std::endl;
    std::cout << "Prix abonnement de base : 500 euros/mois" << std::endl;
    std::cout << "Majoration 30\% pour les places de plus de 10 mètres" << std::endl;
    std::cout << "Majoration 60\% pour les places de plus de 25 mètres" << std::endl;
    std::cout << "Si charge électrique ou eau : 5 euros/services" << std::endl;
    std::cout << "Dernier paiement : " << m_dernier_paiement << std::endl;
}

