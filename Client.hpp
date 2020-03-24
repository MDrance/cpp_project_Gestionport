#ifndef CLIENT_HPP
#define CLIENT_HPP
#include<string>
#include<fstream>
#include"Bateau.hpp"
#include"Facture.hpp"
#include"Place.hpp"

class Client 
{
    std::string m_nom;
    std::string m_prenom;
    bool m_abo;
    Bateau* m_bateau;
    Facture* m_facture;
    Place* m_place;


    public:
        Client();
        Client(std::string nom, std::string prenom, bool abo);
        ~Client();
        std::string get_nom() const;
        bool get_abo() const;
        Bateau* get_bateau() const;
        Facture* get_facture() const;
        Place* get_place() const;
        void set_bateau(Bateau* bateau);
        void set_place(Place* place);
        void set_facture(Facture* facture);
        void affiche_client() const;       
        static Client creer_client();
        // void save_client(std::ofstream& file) const;
};

#endif