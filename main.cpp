#include"Gestionport.hpp"
#include<iostream>


int main()
{
    Gestionport port;
    port.init_places();
    port.affiche_port();
    port.assigner_place();
    port.affiche_port();
    port.chercher_client();
    port.facturation();

    // Client client;
    // Factureabo fact;
    // client.set_facture(fact);
    // client.get_facture().affiche_tarif();
    return 0;
}