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
        client.set_facture(new Factureabo(500/12, 0));
    }

    else if (client.get_abo() == false)
    {
        client.set_facture(new Facture(20, 0));
    }

    clientele.insert({client.get_nom(), client});
    cout << "Client créé !\n";
}

void Gestionport::chercher_client()
{
    if(clientele.empty())
    {
        std::cout << "Auncun client dans le fichier !\n";
    }
    else
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
                clientele[nom].get_facture()->affiche_dernier_paiement();
            }
        }
    }
}

void Gestionport::facturation(string nom)
{
    string eau, elec;
    cout << "Le client a-t-il utilisé l'eau ? (y/n)\n";
    cin >> eau;
    cout << "Le client a-t-il utilisé l'électricité ? (y/n)\n";
    cin >> elec;
    cout << "Nombre de jours ou de mois (pour les abonnés) où le client a stationné : \n";
    int num;
    cin >> num;

    map<string, Client>::iterator itr;
    for (itr = clientele.begin(); itr != clientele.end(); itr++)
    {
        if(itr->first == nom)
        {
            float swap = clientele[nom].get_facture()->get_tarif();
            if (clientele[nom].get_place()->get_type() == 2)
            {
                clientele[nom].get_facture()->set_majoration2();
                clientele[nom].get_facture()->set_mult(num);
                if (eau == "y" && elec == "y") {clientele[nom].get_facture()->set_eau_elec();}
                else if(eau == "y" || elec =="y") {clientele[nom].get_facture()->set_eau();}
                clientele[nom].get_facture()->set_dernier_paiement();
                clientele[nom].get_facture()->affiche_tarif();
                clientele[nom].get_facture()->set_tarif(swap);
            }
            else if (clientele[nom].get_place()->get_type() == 1)
            {
                clientele[nom].get_facture()->set_majoration1();
                clientele[nom].get_facture()->set_mult(num);
                if (eau == "y" && elec == "y") {clientele[nom].get_facture()->set_eau_elec();}
                else if(eau == "y" || elec =="y") {clientele[nom].get_facture()->set_eau();}
                clientele[nom].get_facture()->set_dernier_paiement();
                clientele[nom].get_facture()->affiche_tarif();
                clientele[nom].get_facture()->set_tarif(swap);
            }
            else if (clientele[nom].get_place()->get_type() == 3)
            {
                clientele[nom].get_facture()->set_minorationcm();
                clientele[nom].get_facture()->set_mult(num);
                clientele[nom].get_facture()->set_dernier_paiement();
                clientele[nom].get_facture()->affiche_tarif();
                clientele[nom].get_facture()->set_tarif(swap);
            }
            else if (clientele[nom].get_place()->get_type() == 0)
            {
                clientele[nom].get_facture()->set_mult(num);
                clientele[nom].get_facture()->set_dernier_paiement();
                clientele[nom].get_facture()->affiche_tarif();
                clientele[nom].get_facture()->set_tarif(swap);
            }
        }
    }
    cout << "Client facturé !\n";
}

void Gestionport::suppr_client(string nom)
{
    Gestionport::facturation(nom);
    map<string, Client>::iterator itr;
    for(itr = clientele.begin(); itr != clientele.end(); itr++)
    {
        if (itr->first == nom)
        {
            int swap = clientele[nom].get_place()->get_numero_place();
            vector<Place*>::iterator itrp;
            for (itrp = place_tab.begin(); itrp !=place_tab.end(); itrp++)
            {
                if ((*itrp)->get_numero_place() == swap)
                {
                    (*itrp)->set_dispo(1);
                }
            }
            delete clientele[nom].get_bateau();
            clientele[nom].set_bateau(0);
            clientele[nom].set_place(0);
            ancien_client.insert({nom, clientele[nom]});
            clientele.erase(itr);
        }
    }
    cout << "Client supprimé !\n";
}

void Gestionport::afficher_ancienclient()
{
    if(ancien_client.empty())
    {
        std::cout << "Aucun client dans ce fichier !\n";
    }
    else
        {
        std::cout << "Les clients ayant été facturés mais ne séjournant plus dans le port sont : \n";
        map<string, Client>::iterator itr;
        for (itr = ancien_client.begin(); itr != ancien_client.end(); itr++)
        {
            cout << itr->first << endl;
        }
        std::cout << "Entrez le nom d'un client pour afficher son dernier paiement : \n";
        string nom;
        std::cin >> nom;
        for (itr = ancien_client.begin(); itr != ancien_client.end(); itr++)
        {
            if(itr->first == nom)
            {
                itr->second.affiche_client();
                ancien_client[nom].get_facture()->affiche_dernier_paiement();
            }
        }
    }
}

void Gestionport::savedata()
{
    ofstream Placefile;
    Placefile.open("Places.txt");
    if (Placefile.is_open())
    {
        Placefile.clear();
        for (int i = 0; i < place_tab.size(); i++)
        {
            place_tab[i]->save_places(Placefile); 
        }
        Placefile.close();
    }

    ofstream Clientfile;
    Clientfile.open("Clients.txt");
    if (Clientfile.is_open())
    {
        Clientfile.clear();
        map<string, Client>::iterator itr;
        for (itr = clientele.begin(); itr != clientele.end(); itr++)
        {
            itr->second.save_client(Clientfile);
        }
        Clientfile.close();
    }

    ofstream Ancienfile;
    Ancienfile.open("Anciens.txt");
    if (Ancienfile.is_open())
    {
        Ancienfile.clear();
        map<string, Client>::iterator itr;
        for (itr = ancien_client.begin(); itr != ancien_client.end(); itr++)
        {
            itr->second.save_ancienclient(Ancienfile);
        }
        Ancienfile.close();
    }
    cout << "Les données ont été sauvegardées !\n";
}

void Gestionport::loaddata()
{
    string nom_client, prenom_client, nom_bateau;
    bool abo_client, dispo_place;
    int nb_cabine_bateau, num_place, type_place;
    float taille_bateau, taillemax_place, tarif, dernier_paiement;

    ifstream Placefile;
    Placefile.open("Places.txt");
    if (!Placefile)
    {
        cout << "Pas de fichier trouvé !\n";
        return;
    }
    while (Placefile >> num_place >> type_place >> taillemax_place >> dispo_place)
    {
        if(type_place == 0) {place_tab.push_back(new Place());}
        else if(type_place == 1) {place_tab.push_back(new Placeservices1());}
        else if(type_place == 2) {place_tab.push_back(new Placeservices2(taillemax_place));}
        else if(type_place == 3) {place_tab.push_back(new Placecorpsmort(taillemax_place));}
    }
    Placefile.close();

    ifstream Clientfile;
    Clientfile.open("Clients.txt");
    if (!Clientfile)
    {
        cout << "Un port a été importé, mais il ne possédait pas de clients\n";
        return;
    }
    while(Clientfile >> nom_client >> prenom_client >> abo_client >> nom_bateau
    >> taille_bateau >> nb_cabine_bateau >> tarif >> dernier_paiement >> num_place
    >> type_place >> taillemax_place >> dispo_place)
    {
        Client client(nom_client, prenom_client, abo_client);
        Bateau* bateau = new Bateau(nom_bateau, taille_bateau, nb_cabine_bateau);
        client.set_bateau(bateau);
        if(tarif == 500/12) 
        {
            Facture* facture = new Facture(tarif, dernier_paiement);
            client.set_facture(facture);
        }
        else if(tarif == 20)
        {
            Factureabo* factureabo = new Factureabo(tarif, dernier_paiement);
            client.set_facture(factureabo);
        }
        vector<Place*>::iterator itr;
        for(itr = place_tab.begin(); itr != place_tab.end(); itr++)
        {
            if((*itr)->get_numero_place() == num_place)
            {
                client.set_place(*itr);
                (*itr)->set_dispo(0);
            }
        }
        clientele.insert({nom_client, client});
    }
    Clientfile.close();

    ifstream Ancienfile;
    Ancienfile.open("Anciens.txt");
    while(Ancienfile >> nom_client >> prenom_client >> abo_client >> dernier_paiement)
    {
        Client client(nom_client, prenom_client, abo_client);
        Facture* an_facture = new Facture(0, dernier_paiement);
        client.set_facture(an_facture);
        ancien_client.insert({nom_client, client});
    }
    cout << "Données chargées !\n";
}