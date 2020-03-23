#ifndef GESTIONPORT_HPP
#define GESTIONPORT_HPP
#include"Client.hpp"
#include"Bateau.hpp"
#include"Place.hpp"
#include"Facture.hpp"
#include<iostream>
#include<vector>
#include<map>
#include<fstream>
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
        vector<Place> get_place_tab();
        void affiche_port();
        void affiche_place_libre();
        void affiche_place_taille();
        void assigner_place();
        void chercher_client();
        void facturation(string nom);
        void suppr_client(string nom);
        void savedata();
        void loaddata();
};


#endif