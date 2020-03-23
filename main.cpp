#include"Gestionport.hpp"
#include<iostream>


void menu()
{
    std::cout << "*** Menu principal ***\n\n";
    std::cout << "0. Quitter\n";
    std::cout << "1. Création d'un port\n";
    std::cout << "2. Afficher l'ensemble des places\n";
    std::cout << "3. Afficher les places libres\n";
    std::cout << "4. Afficher les places dont la taille minimum est : \n";
    std::cout << "5. Création d'un client\n";
    std::cout << "6. Afficher les infos d'un client\n";
    std::cout << "7. Enregistrer un paiement\n";
    std::cout << "8. Facturer et cloturer compte client\n";
    std::cout << "9. Sauvegarder les données\n";
    std::cout << "10. Charger des données\n";
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
        else if (choix == 1) {port.init_places();}

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
            else 
            {
                std::cout << "Entrez le nom du client à facturer : \n";
                std::string nom;
                std::cin >> nom;
                port.facturation(nom);
            }
        }

        else if (choix == 8)
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

        else if (choix == 9)
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

        else if (choix == 10)
        {
            port.loaddata();
        }
    }

    return 0;
}