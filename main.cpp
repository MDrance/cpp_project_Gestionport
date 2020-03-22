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

    return 0;
}