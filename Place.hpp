#ifndef PLACE_HPP
#define PLACE_HPP
#include<fstream>

class Place
{   
    protected:
        int m_numero_place;
        int m_type;
        float m_taille_max;
        bool m_dispo;

    public:
        static int nbr_place;
        Place();
        virtual ~Place();
        int get_numero_place() const;
        int get_type() const;
        float get_taille_max() const;
        bool get_dispo() const;
        void set_dispo(bool); 
        virtual void affiche_place() const;  
        void save_places(std::ofstream& file) const;   
};

class Placeservices1 : public Place
{
    public:
        Placeservices1();
        virtual ~Placeservices1();
        virtual void affiche_place() const override;
};

class Placeservices2 : public Placeservices1
{
    public:
        Placeservices2(float taille_max);
        virtual ~Placeservices2();
        virtual void affiche_place() const override;
};

class Placecorpsmort : public Place
{
    public:
        Placecorpsmort(float taille_max);
        virtual ~Placecorpsmort();
        virtual void affiche_place() const override;
};

#endif