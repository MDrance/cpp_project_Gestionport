#ifndef GESTIONPORT_HPP
#define GESTIONPORT_HPP
#include"Client.hpp"
#include"Bateau.hpp"
#include"Place.hpp"
#include"Facture.hpp"
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Gestionport
{
    vector<Place> place_tab;
    map<string, Client> clientele;

    public:
        Gestionport();
        ~Gestionport();
        void init_places();
        map<string, Client> get_clientele();
        void affiche_port();
        void affiche_place_libre();
        void assigner_place();
        void chercher_client();
        void facturation();
        void set_facturation(Facture& facture);
};

#endif