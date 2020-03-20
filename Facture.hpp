#ifndef FACTURE_HPP
#define FACTURE_HPP

class Facture
{
    protected:
        float m_tarif;
        float m_dernier_paiement;

    public:
        Facture();
        virtual ~Facture();
        float get_tarif() const;
        float get_dernier_paiement() const;
        void set_dernier_paiement();
        virtual void affiche_tarif() const;
        void set_majoration1();
        void set_majoration2();
        void set_minorationcm();
        void set_eau_elec();
        void set_eau();
        void set_mult(int);
};

class Factureabo : public Facture
{
    public:
        Factureabo();
        virtual ~Factureabo();
        void affiche_tarif() const override;
};

#endif