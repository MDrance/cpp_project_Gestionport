#include"Client.hpp"
#include<iostream>
#include<string>
//Constructeur
Client::Client() {}

//Surcharge constructeur
Client::Client(std::string nom, std::string prenom, bool abo)
{
    m_nom = nom;
    m_prenom = prenom;
    m_abo = abo;
}

//Destructeur
Client::~Client() {}

//Getters
std::string Client::get_nom() const {return m_nom;}
bool Client::get_abo() const {return m_abo;}
Bateau Client::get_bateau() const {return m_bateau;}
Facture Client::get_facture() const {return m_facture;}
Place Client::get_place() const {return m_place;}

//Setters
void Client::set_bateau(Bateau bateau) {m_bateau = bateau;}
void Client::set_place(Place place) {m_place = place;}
void Client::set_facture(Facture facture) {m_facture = facture;}

//Affichage client
void Client::affiche_client() const
{
    std::cout << "Nom : " << m_nom << std::endl;
    std::cout << "Prenom : " << m_prenom << std::endl;
    std::cout << "Abo : " << m_abo << std::endl;
}

//Création d'un client
Client Client::creer_client()
{
    std::string nom;
    std::string prenom;
    std::string sabo;
    bool abo;
    std::cout << "Nom du client : \n";
    std::cin >>nom;
    std::cout << "Prénom du client : \n";
    std::cin >> prenom;
    std::cout << "Le client veut-il s'abonner ? (y/n)\n";
    std::cin >> sabo;
    if (sabo == "y")
    {
        Client client(nom, prenom, true);
        return client;
    }
    if (sabo == "n")
    {
        Client client (nom, prenom, false);
        return client;
    }
}
