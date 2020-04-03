#ifndef GESTIONPORT_HPP
#define GESTIONPORT_HPP
#include"Client.hpp"
#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

class Gestionport
{
    vector<Place*> place_tab;
    map<string, Client> clientele;
    map<string, Client> ancien_client;

    public:
        Gestionport();
        ~Gestionport();
        void init_places();
        map<string, Client> get_clientele();
        vector<Place*> get_place_tab();
        void affiche_port();
        void affiche_place_libre();
        void affiche_place_taille();
        void affiche_allclients();
        void assigner_place();
        void chercher_client();
        void facturation(string nom);
        void suppr_client(string nom);
        void afficher_ancienclient();
        void savedata();
        void loaddata();
};


#endif