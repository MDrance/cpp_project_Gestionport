#include"Gestionport.hpp"
#include<iostream>


void menu()
{
    std::cout << "\n*** Menu principal ***\n\n";
    std::cout << "0. Quitter\n";
    std::cout << "1. Création d'un port\n";
    std::cout << "2. Afficher l'ensemble des places\n";
    std::cout << "3. Afficher les places libres\n";
    std::cout << "4. Afficher les places dont la taille minimum est : \n";
    std::cout << "5. Création d'un client\n";
    std::cout << "6. Afficher les infos d'un client\n";
    std::cout << "7. Afficher l'ensemble des clients du port\n";
    std::cout << "8. Enregistrer un paiement\n";
    std::cout << "9. Facturer et cloturer compte client\n";
    std::cout << "10. Chercher dans les anciens clients\n";
    std::cout << "11. Sauvegarder les données\n";
    std::cout << "12. Charger des données\n";
}

int main()
{
    Gestionport port;

    while (true)
    {
        menu();
        std::cout << "-> ";
        int choix;
        std::cin >> choix;

        if (choix == 0) {return 0;}
        else if (choix == 1) 
        {
            if (port.get_place_tab().empty() == true) {port.init_places();}
            else {std::cout << "Un port est déja en cours de gestion\n";}
        }

        else if (choix == 2) 
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.affiche_port();}
        }

        else if (choix == 3) 
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.affiche_place_libre();}
        }

        else if (choix == 4)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.affiche_place_taille();}
        }

        else if (choix == 5) 
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.assigner_place();}
        }

        else if (choix == 6)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.chercher_client();}
        }

        else if (choix == 7)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.affiche_allclients();}
        }

        else if (choix == 8) 
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else 
            {
                std::cout << "Entrez le nom du client à facturer : \n";
                std::string nom;
                std::cin >> nom;
                port.facturation(nom);
            }
        }

        else if (choix == 9)
        {
           if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else 
            {
                std::cout << "Entrez le nom du client qui quitte le port : \n";
                std::string nom;
                std::cin >> nom;
                port.suppr_client(nom);
            } 
        }

        else if (choix == 10)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else 
            {
            port.afficher_ancienclient();
            }
        }
        
        else if (choix == 11)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else 
            {
            port.savedata();
            }
        }

        else if (choix == 12)
        {
            if(port.get_place_tab().empty() == true) {port.loaddata();}
            else
            {
                std::cout << "Un port est déja en cours de gestion, le remplacer ? (y/n)\n";
                std::string choix;
                std::cin >> choix;
                if (choix == "y")
                {
                    port.get_place_tab().clear();
                    port.get_clientele().clear();
                    port.loaddata();
                }
            }        
        }
    }
    return 0;
}