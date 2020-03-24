#ifndef FACTURE_HPP
#define FACTURE_HPP

class Facture
{
    protected:
        float m_tarif;
        float m_dernier_paiement;

    public:
        Facture();
        Facture(float prix, float dernier_paiement);
        virtual ~Facture();
        float get_tarif() const;
        float get_dernier_paiement() const;
        void set_dernier_paiement();
        void set_tarif(float swap);
        virtual void affiche_tarif() const;
        void affiche_dernier_paiement() const;
        void set_eau_elec();
        void set_eau();
        void set_mult(int);
        void set_majoration1();
        void set_majoration2();
        void set_minorationcm();
};

class Factureabo : public Facture
{
    public:
        Factureabo(float prix, float dernier_paiment);
        virtual ~Factureabo();
        virtual void affiche_tarif() const override;
};


#endif