#include"Gestionport.hpp"
#include<iostream>


void menu()
{
    std::cout << "*** Menu principal ***\n\n";
    std::cout << "0. Quitter\n";
    std::cout << "1. Création d'un port\n";
    std::cout << "2. Afficher l'ensemble des places\n";
    std::cout << "3. Afficher les places libres\n";
    std::cout << "4. Création d'un client\n";
    std::cout << "5. Afficher les infos d'un client\n";
    std::cout << "6. Enregistrer un paiement\n";
    std::cout << "7. Facturer et cloturer compte client\n";
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
            else {port.assigner_place();}
        }

        else if (choix == 5)
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.chercher_client();}
        }

        else if (choix == 6) 
        {
            if (port.get_place_tab().empty() == true)
            {
                std::cout << "Le port est vide !\n";
            }
            else {port.facturation();}
        }
    }

    return 0;
}