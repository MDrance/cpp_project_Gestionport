#ifndef BATEAU_HPP
#define BATEAU_HPP
#include<string>

class Bateau
{
    protected:
        std::string m_nom_bateau;
        float m_taille;
        int m_cabine;

    public:
        Bateau();
        Bateau(std::string nom_bateau, float taille, int cabine);
        ~Bateau();
        std::string get_nom_bateau() const;
        float get_taille() const;
        int get_cabine() const;
        void affiche_bateau() const;
        static Bateau creer_bateau();
};

#endif