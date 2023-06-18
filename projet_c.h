#ifndef PRO_H_INCLUDED
#define PRO_H_INCLUDED
typedef struct
{
    char mat[11]  ;
    char  nom [20] ;
    char adr[40];
    char  pren [20]  ;
    float  sb;
    char  de[11];/*date*/
    char service[3];
    char tel[8];

}  employe  ;

struct cellule
{
    employe info;
    struct cellule *suivant;
};
struct liste
{
    struct cellule * premier ;
    struct cellule * dernier ;
};
typedef struct liste  liste_e;
void changer();
void creer_liste(liste_e *);
int recherche_emp(liste_e , char []);
int taille_liste_emp (liste_e );
int BISSEXTILE(int );
int verif4(char []);
int verif_date(char []);
void aller();
int controle1(char[]);
int controle2(char[]);
liste_e supp_employe(liste_e);
void  supprime_position(liste_e);
liste_e supprimer_queue_employe( liste_e);
liste_e supprimer_tete_employe( liste_e);
liste_e suppression_employe_service (liste_e);
void insere_pos_emp(liste_e , int ,employe  );
liste_e  inserer_tete_emp(liste_e );
liste_e inserer_queue_emp(liste_e);
employe saisie_employe(liste_e);
void affiche(liste_e );
liste_e creation(liste_e );
void enregistrement(liste_e );
liste_e recuperation();
liste_e rupture_stock(liste_e , char );
void modifier_adresse(liste_e);
controle_service(char[]);
float salaire_brut(liste_e);
float salaire_Net(float);
float impot(float);
float CNSS(float);
float somme_cnss(liste_e);
controle_tel(char[]);
void modifier_tel(liste_e LE);
liste_e inserer_queue_emp2(liste_e,employe);
liste_e  inserer_tete_emp2(liste_e,employe);
int recherche_emp2(liste_e, char[]);
void bulletin_de_paie(liste_e);
liste_e triage(liste_e);
struct cellule* pos_tri(liste_e,float);
void attention();
liste_e recherche_emp3(liste_e);
void affiche2(liste_e );
void calcul_cnss_brut(liste_e);
void recherche_par_tel(liste_e);
#endif // PRO_H_INCLUDED
