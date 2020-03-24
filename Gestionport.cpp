#include"Gestionport.hpp"
using namespace std;

//defaut constructeur
Gestionport::Gestionport() {}

//Destructeur
Gestionport::~Gestionport() {}

//Getters
map<string, Client> Gestionport::get_clientele() {return clientele;}
vector<Place*> Gestionport::get_place_tab() {return place_tab;}

void Gestionport::init_places()
{
    cout << "Combien de places de moins de 10 mètres créer ?\n";
    int place10m;
    cin >> place10m;
    for (int i = 0; i<place10m; i++)
    {
        place_tab.push_back(new Place());
    }
    cout << "Combien de places de moins de 25 mètres créer ?\n";
    int place25m;
    cin >> place25m;
    for (int i = 0; i<place25m; i++)
    {
        place_tab.push_back(new Placeservices1());
    }
    cout << "Combien de places de plus de 25 mètres créer ?\n";
    int place30m;
    cin >> place30m;
    for (int i = 0; i<place30m; i++)
    {
        cout << "Taille de la place : \n";
        float taille;
        cin >> taille;
        place_tab.push_back(new Placeservices2(taille));
    }
    cout << "Combien de places sur des corps-morts créer ?\n";
    int placecm;
    cin >> placecm;
    for (int i = 0; i<placecm; i++)
    {
        cout << "Taille de la place : \n";
        float taille;
        cin >> taille;
        place_tab.push_back(new Placecorpsmort(taille));
    }
    cout << "Port créé !\n";
}

void Gestionport::affiche_port()
{
    cout << "Voici toutes les places du port : \n";
    vector<Place*>::const_iterator itr;
    for (itr = place_tab.begin(); itr != place_tab.end(); itr++)
    {
        (*itr)->affiche_place();
    }
}

void Gestionport::affiche_place_libre()
{
    cout << "Les places libres du port sont : \n";
    vector<Place*>::const_iterator itr;
    for (itr = place_tab.begin(); itr != place_tab.end(); itr++)
    {
        if ((*itr)->get_dispo() == 1)
        {
            (*itr)->affiche_place();
        }
    }
}

void Gestionport::affiche_place_taille()
{
    cout << "Taille minimale des places à afficher : \n";
    float taille;
    cin >> taille;
    cout << "Les places d'au moins " << taille << " mètres sont : \n";
    vector<Place*>::const_iterator itr;
    for (itr = place_tab.begin(); itr != place_tab.end(); itr++)
    {
        if ((*itr)->get_taille_max() >= taille)
        {
            (*itr)->affiche_place();
        }
    }
}

void Gestionport::affiche_allclients()
{
    cout << "Liste de tous les clients actuellement dans le port :\n";
    map<string, Client>::iterator itr;
    for (itr = clientele.begin(); itr != clientele.end(); itr++)
    {
        cout << itr->first << endl;
    }
}

void Gestionport::assigner_place()
{
    Client client = Client::creer_client();
    Bateau* bateau = Bateau::creer_bateau();
    client.set_bateau(bateau);
    
    cout << "Les places disponibles sont : \n";
    vector<Place*>::iterator itr;
    for (itr = place_tab.begin(); itr != place_tab.end(); itr++)
    {
        if ((*itr)->get_taille_max() >= (*bateau).get_taille() && (*itr)->get_dispo() == 1)
        {
            (*itr)->affiche_place();
        }
    }

    cout << "Quelle place attibuer (numéro) ? \n";
    int num;
    cin >> num;
    for (itr = place_tab.begin(); itr != place_tab.end(); itr++)
    {
        if ((*itr)->get_numero_place() == num)
        {
            (*itr)->set_dispo(0);
            client.set_place(*itr);  
        }
    }   

    if (client.get_abo() == true)
    {
        client.set_facture(Facture(500/12, 0));
    }

    else if (client.get_abo() == false)
    {
        client.set_facture(Facture(20, 0));
    }

    clientele.insert({client.get_nom(), client});
    cout << "Client créé !\n";
}

void Gestionport::chercher_client()
{
    cout << "Nom du client à chercher : \n";
    string nom;
    cin >> nom;
    map<string, Client>::iterator itr;
    for (itr = clientele.begin(); itr != clientele.end(); itr++)
    {
        if (itr->first == nom)
        {
            itr->second.affiche_client();
            clientele[nom].get_bateau()->affiche_bateau();
            clientele[nom].get_place()->affiche_place();
            itr->second.get_facture().affiche_dernier_paiement();
        }
    }
}

// void Gestionport::facturation(string nom)
// {
//     string eau, elec;
//     cout << "Le client a-t-il utilisé l'eau ? (y/n)\n";
//     cin >> eau;
//     cout << "Le client a-t-il utilisé l'électricité ? (y/n)\n";
//     cin >> elec;
//     cout << "Nombre de jours ou de mois (pour les abonnés) où le client a stationné : \n";
//     int num;
//     cin >> num;

//     map<string, Client>::iterator itr;
//     for (itr = clientele.begin(); itr != clientele.end(); itr++)
//     {
//         if(itr->first == nom)
//         {
//             float swap = itr->second.get_facture().get_tarif();
//             if (itr->second.get_place().get_type() == 2)
//             {
//                 itr->second.get_facture().set_majoration2();
//                 itr->second.get_facture().set_mult(num);
//                 if (eau == "y" && elec == "y") {itr->second.get_facture().set_eau_elec();}
//                 else if(eau == "y" || elec =="y") {itr->second.get_facture().set_eau();}
//                 itr->second.get_facture().set_dernier_paiement();
//                 itr->second.get_facture().affiche_tarif();
//                 itr->second.get_facture().set_tarif(swap);
//             }
//             else if (itr->second.get_place().get_type() == 1)
//             {
//                 itr->second.get_facture().set_majoration1();
//                 itr->second.get_facture().set_mult(num);
//                 if (eau == "y" && elec == "y") {itr->second.get_facture().set_eau_elec();}
//                 else if(eau == "y" || elec =="y") {itr->second.get_facture().set_eau();}
//                 itr->second.get_facture().set_dernier_paiement();
//                 itr->second.get_facture().affiche_tarif();
//                 itr->second.get_facture().set_tarif(swap);
//             }
//             else if (itr->second.get_place().get_type() == 3)
//             {
//                 itr->second.get_facture().set_minorationcm();
//                 itr->second.get_facture().set_mult(num);
//                 itr->second.get_facture().set_dernier_paiement();
//                 itr->second.get_facture().affiche_tarif();
//                 itr->second.get_facture().set_tarif(swap);
//             }
//             else if (itr->second.get_place().get_type() == 0)
//             {
//                 itr->second.get_facture().set_mult(num);
//                 itr->second.get_facture().set_dernier_paiement();
//                 itr->second.get_facture().affiche_tarif();
//                 itr->second.get_facture().set_tarif(swap);
//             }
//         }
//     }
//     cout << "Client facturé !\n";
// }

// void Gestionport::suppr_client(string nom)
// {
//     Gestionport::facturation(nom);
//     map<string, Client>::iterator itr;
//     for(itr = clientele.begin(); itr != clientele.end(); itr++)
//     {
//         if (itr->first == nom)
//         {
//             int swap = itr->second.get_place().get_numero_place();
//             vector<Place>::iterator itrp;
//             for (itrp = place_tab.begin(); itrp !=place_tab.end(); itrp++)
//             {
//                 if (itrp->get_numero_place() == swap)
//                 {
//                     itrp->set_dispo(1);
//                 }
//             }
//             clientele.erase(itr);
//         }
//     }
//     cout << "Client supprimé !\n";
// }

// void Gestionport::savedata()
// {
//     ofstream Placefile;
//     Placefile.open("Places.txt");
//     if (Placefile.is_open())
//     {
//         Placefile.clear();
//         for (int i = 0; i < place_tab.size(); i++)
//         {
//             place_tab[i].save_places(Placefile); 
//         }
//         Placefile.close();
//     }

//     ofstream Clientfile;
//     Clientfile.open("Clients.txt");
//     if (Clientfile.is_open())
//     {
//         Clientfile.clear();
//          map<string, Client>::iterator itr;
//         for (itr = clientele.begin(); itr != clientele.end(); itr++)
//         {
//             itr->second.save_client(Clientfile);
//         }
//         Clientfile.close();
//     }
//     cout << "Les données ont été sauvegardées !\n";
// }

// void Gestionport::loaddata()
// {
//     string nom_client, prenom_client, nom_bateau;
//     bool abo_client, dispo_place;
//     int nb_cabine_bateau, num_place, type_place;
//     float taille_bateau, taillemax_place, tarif, dernier_paiement;

//     ifstream Placefile;
//     Placefile.open("Places.txt");
//     if (!Placefile)
//     {
//         cout << "Pas de fichier trouvé !\n";
//         return;
//     }
//     while (Placefile >> num_place >> type_place >> taillemax_place >> dispo_place)
//     {
//         Place place(num_place, type_place, taillemax_place, dispo_place);
//         place_tab.push_back(place);
//     }
//     Placefile.close();

//     ifstream Clientfile;
//     Clientfile.open("Clients.txt");
//     if (!Clientfile)
//     {
//         cout << "Pas de fichier trouvé !\n";
//         return;
//     }
//     while(Clientfile >> nom_client >> prenom_client >> abo_client >> nom_bateau
//     >> taille_bateau >> nb_cabine_bateau >> tarif >> dernier_paiement >> num_place
//     >> type_place >> taillemax_place >> dispo_place)
//     {
//         Bateau bateau(nom_bateau, taille_bateau, nb_cabine_bateau);
//         Facture facture(tarif, dernier_paiement);
//         Place place(num_place, type_place, taillemax_place, dispo_place);
//         Client client(nom_client, prenom_client, abo_client);
//         client.set_bateau(bateau);
//         client.set_facture(facture);
//         client.set_place(place);
//         clientele.insert({nom_client, client});
//     }
//     Clientfile.close();
//     cout << "Données chargées !\n";
// }