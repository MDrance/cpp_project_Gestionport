#ifndef FACTURE_HPP
#define FACTURE_HPP

class Facture
{
    protected:
        float m_tarif;
        float m_dernier_paiement;

    public:
        Facture();
        Facture(int prix, int dernier_paiement);
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
};

class Facture1 : public Facture
{
    public:
        Facture1();
        virtual ~Facture1();
        virtual void affiche_tarif();
};

class Facture2 : public Facture
{
    public:
        Facture2();
        virtual ~Facture2();
        virtual void affiche_tarif();
};

class Facturecm : public Facture
{
    public:
        Facturecm();
        virtual ~Facturecm();
        virtual void affiche_tarif();
};

#endif