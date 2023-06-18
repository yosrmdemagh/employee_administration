#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "projet_c.h"
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

/***** Fonction création *****/
void creer_liste(liste_e *LE)
{
    LE->premier=NULL ;
    LE->dernier=NULL ;
}
               /***** Fonction test *****/
int recherche_emp(liste_e LE, char num[])
{
    struct cellule *p=LE.premier;
   	while(p)
   	    if(strcmp((p->info).mat ,num)==0)
   	        return 1;
   	    else
   	        p=p->suivant;
   	return 0;
}
/***recjerche maytricule et affichage **/
int recherche_emp2(liste_e LE, char num[])
{
    struct cellule *p=LE.premier;
   	while(p)
   	    if(strcmp((p->info).mat ,num)==0)
   	        return p;
   	    else
   	        p=p->suivant;

}
 /***** Fonction taille *****/
int taille_liste_emp (liste_e LE )
{
    struct cellule *p=LE.premier;
    int t=0;
   	while(p)
    {
        t++;
        p=p->suivant;
    }
   	return t;
}

/**********************************/
int verif4(char ch[])
{
    int i;
    for(i=0;i<10;i++)
        if(i==2||i==5)
        {
            if(ch[i]!='/')
                return 0;
        }
        else
            if(ch[i]<'0'||ch[i]>'9')
                return 0;
    return 1;
}


/********FONCTION BISSEXTILE*******/
int BISSEXTILE(int a)
{
    if((a%4==0 && a%100!=0)|| (a%400==0))
        return 1;
    else
        return 0;

}
/*** cntrole service**/
int controle_service(char ch[1])
 {
if (strlen(ch)!=1)
      {return 0;}
    if (toupper(*ch)>='A' && toupper(*ch)<='Z')
        return 1;
    else return 0;
}

/***controle matricule***/
int controle2(char ch[10])
{

    if (strlen(ch)!=9)
      {

     return 0;}

    else{
        char *c;
    c=ch;
            while(*c!='\0')
        if (((*c)>='0' && toupper(*c)<='9' ))
            {
             c++;}
        else
        {
            return 0;}}

        return 1;
}
/***controle telephone***/
int controle_tel(char ch[9])
{

    if (strlen(ch)!=8)
      {
     return 0;}


        char *c;
    c=ch;
            while(*c!='\0')
        {if (((*c)>='0' && toupper(*c)<='9' ))
            {
             c++;}
        else
        {
            return 0;}}
    if (!(*ch=='9'||*ch=='8'||*ch=='2'||*ch=='5'||*ch=='4'))
       {return 0;}

        return 1;
}

/***controle nom ***/
int controle1(char ch[20])
{char *c;
c=ch;
    if (ch[0]==" ")
    {
        return 0;}
    if (ch[strlen(ch)-1]==" ")
       {
        return 0;}
    while(*c!='\0')
        if ((toupper(*c)>='A' && toupper(*c)<='Z' )|| (*c==' '))
            {
             c++;}
        else
        {
            return 0;}
            c=ch;
            int i;
        for (i=0;i<strlen(ch)-1;i++)
      {
        if (c[i]==' '&& c[i+1]==' ' )
            {;return 0;}
        }


    return 1;
}
/********FONCTION JOUR_MAX**********/

int verif_date(char ch[])
{
    char jj[3],mm[3],aa[5];
    int j,k,i, m, a,jmax;
    for(i=0;i<2;i++)
        jj[i]=ch[i];
    jj[i]='\0';
    for(i++,k=0;i<5;i++)
        mm[k++]=ch[i];
    mm[k]='\0';
    for(i++,k=0;ch[i];i++)
        aa[k++]=ch[i];
    aa[k]='\0';
    j=atoi(jj);
    m=atoi(mm);
    a=atoi(aa);
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            jmax =31 ;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            jmax =30 ;
            break;
        case 2:
            if(BISSEXTILE(a))
                jmax=29;
            else
                jmax=28;
    }
     return j>=1 && j<=jmax && m>=1 && m<=12 && a>=1900 && a<2022 && verif4(ch) && strlen(ch)==10;
}

                /***** Fonction saisie_employé *****/
employe saisie_employe(liste_e LE  )
{
    employe E;
int rep=0,aj;
aj=0;
gotoxy(10,3);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(10,4);printf("  ³       matricule          ³                       ³");
gotoxy(10,5);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,6);printf("  ³       nom                ³                       ³");
gotoxy(10,7);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,8);printf("  ³       prenom             ³                       ³");
gotoxy(10,9);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,10);printf("  ³       salaire brut       ³                       ³");
gotoxy(10,11);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,12);printf("  ³       telephone          ³                       ³");
gotoxy(10,13);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,14);printf("  ³       date d'embauche    ³                       ³");
gotoxy(10,15);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,16);printf("  ³       service            ³                       ³");
gotoxy(10,17);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,18);printf("  ³       adresse            ³                       ³");
gotoxy(10,19);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
fflush(stdin);
gotoxy(41,4);printf("              ");
gotoxy(41,4);
gotoxy(41,6);printf("              ");
gotoxy(41,6);
gotoxy(41,8);printf("              ");
gotoxy(41,8);
gotoxy(41,10);printf("              ");
gotoxy(41,10);
gotoxy(41,12);printf("             ");
gotoxy(41,12);
gotoxy(41,14);printf("             ");
gotoxy(41,14);
gotoxy(50,16);printf("             ");
gotoxy(41,16);
gotoxy(41,18);printf("             ");
gotoxy(41,18);
gotoxy(62,21);
fflush(stdin);
printf("                   ");
gotoxy(62,21);
/**matric**/
do
    {
    gotoxy(41,4);
    fflush(stdin);
    gets(E.mat);
    rep=(recherche_emp(LE, E.mat)==0)&&(controle2(E.mat)!=0);
    if(rep==0)
    {
        gotoxy(41,4);
        fflush(stdin);
        printf("                     ");
        gotoxy(41,4);
        fflush(stdin);
    }
}while(rep==0);
/**nom**/
do
{
    gotoxy(41,6);
    fflush(stdin);
    gets(E.nom);
    rep=controle1(E.nom);
    if(rep==0)
    {
    gotoxy(41,6);
    fflush(stdin);
    printf("                     ");
    gotoxy(41,6);
    fflush(stdin);}
}while(rep==0);
/***pren**/
do
    {
    gotoxy(41,8);
    fflush(stdin);
    gets(E.pren);
    rep=controle1(E.pren);
    if(rep==0)
    {
    gotoxy(41,8);
    fflush(stdin);
    printf("                     ");
    gotoxy(41,8);
    fflush(stdin);
    }
}while(rep==0);
/**salaire brut**/
int v=1;
do
    {

    gotoxy(41,10);
    fflush(stdin);
    scanf("%f",&E.sb);
    v=(E.sb>90)&&(E.sb<5000);
    //v=E.sb<5000;
    //printf("%d",v);
    if(v==0)
    {v=0;
    gotoxy(41,10);
    fflush(stdin);
    printf("                     ");
    gotoxy(41,10);
    fflush(stdin);
    }
}while(v==0);

/**tel**/
do
{
gotoxy(41,12);
fflush(stdin);
gets(E.tel);
rep=controle_tel(E.tel);
if(rep==0)
{
gotoxy(41,12);
fflush(stdin);
printf("                     ");
gotoxy(41,12);
fflush(stdin);}
}while(rep==0);

/**date embauche**/
do
{
gotoxy(41,14);
fflush(stdin);
gets(E.de);
rep=verif_date(E.de);
if(rep==0)
{
gotoxy(41,14);
fflush(stdin);
printf("                     ");
gotoxy(41,14);
fflush(stdin);}
}while(!(verif_date(E.de)));
/**service**/
do
{
gotoxy(41,16);
fflush(stdin);
gets(E.service);
rep=controle_service(E.service);
if(rep==0)
{
gotoxy(41,16);
fflush(stdin);
printf("                     ");
gotoxy(41,16);
fflush(stdin);}
   } while(!( controle_service(E.service)==1));
   /***adr***/
   do
{
gotoxy(42,18);
fflush(stdin);
gets(E.adr);
rep=controle1(E.adr);
if(rep==0)
{
gotoxy(42,18);
fflush(stdin);
printf("                     ");
gotoxy(42,18);
fflush(stdin);}
}while(rep==0);
/**/

   /**aff**/

    return E;
}


 /***** Fonction inserer_queue_employe *****/
liste_e inserer_queue_emp(liste_e LE)
{int aj,ok;
 do{
    employe x;
    gotoxy(62,20);
fflush(stdin);
printf("                   ");
    x=saisie_employe(LE);
    struct cellule *q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = NULL ;
    if(LE.dernier==NULL)
        LE.premier=q;
    else
        (LE.dernier)->suivant=q;
    LE.dernier = q;
     ok=0;
gotoxy(10,20);
printf("voulez vous ajouter un autre employe(0:non|1:oui) : ");
do
{
gotoxy(62,20);
fflush(stdin);
scanf("%d",&aj);
gotoxy(20,22);
if (!(aj==0 || aj==1))
    ok=0;
else ok=1;

if(ok==0)
{
gotoxy(62,20);
fflush(stdin);
printf("                   ");
gotoxy(62,20);
fflush(stdin);}
   } while(!(aj==0 || aj==1));


}while(aj==1);
    return LE;
}
/***** Fonction inserer_tete_employe*****/
liste_e  inserer_tete_emp(liste_e LE)
{int aj,ok;
    do
    {employe x;
    gotoxy(62,20);
fflush(stdin);
printf("                   ");
    x=saisie_employe(LE);
    struct cellule * q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = LE.premier ;
    if(LE.premier==NULL)
        LE.dernier=q;
    LE.premier = q;
    ok=0;
gotoxy(10,20);
printf("voulez vous ajouter un autre employe(0:non|1:oui) : ");
do
{
gotoxy(62,20);
fflush(stdin);
scanf("%d",&aj);
if (!(aj==0 || aj==1))
    ok=0;
else ok=1;

if(ok==0)
{
gotoxy(62,20);
fflush(stdin);
printf("                   ");
gotoxy(62,20);
fflush(stdin);}
   } while(!(aj==0 || aj==1));


}while(aj==1);
    return LE;
}
/****************************hiiiiiiiiiii******************************************************/
/***** Fonction inserer_queue_employe *****/
liste_e inserer_queue_emp2(liste_e LE,employe x)
{int aj,ok;

    struct cellule *q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = NULL ;
    if(LE.dernier==NULL)
        LE.premier=q;
    else
        (LE.dernier)->suivant=q;
    LE.dernier = q;
     ok=0;

    return LE;
}
/***** Fonction inserer_tete_employe*****/
liste_e  inserer_tete_emp2(liste_e LE,employe x)
{int aj,ok;

    struct cellule * q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = LE.premier ;
    if(LE.premier==NULL)
        LE.dernier=q;
    LE.premier = q;
    return LE;
}
/***INSERE POS***/

void insere_pos_emp(liste_e LE, int pos,employe x )
{
    struct cellule * p2;
    struct cellule *p1=LE.premier;
    int i=1;
    while(i<pos-1)
    {
        p1=p1->suivant;
        i++;
    }
    p2=(struct cellule*)malloc(sizeof(struct cellule));
    p2->info=x;
    p2->suivant=p1->suivant;
    p1->suivant=p2;
}
                      /***** Fonction affiche *****/
void affiche(liste_e LE)
{int t;
int i=5;
int j=0;
struct cellule *P=LE.premier;
if(P==NULL)
    printf("Liste vide\n");
    else
    {
gotoxy(2,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(2,3);printf("  ³ matricule  ³  Nom         ³   prenom    ³Saliare brut ³ Telephone  ³ Date d'embauche³ Service³ Adresse      ³");
gotoxy(2,4);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(2,5);printf("  ³            ³              ³             ³             ³            ³                ³        ³              ³");

    t=taille_liste_emp (LE);
    while (P)
    {
    gotoxy(5,i);
    fflush(stdin);

    puts((P->info).mat);
    gotoxy(18,i);
    fflush(stdin);
    puts((P->info).nom);
    gotoxy(35,i);
    fflush(stdin);
    puts((P->info).pren);
    gotoxy(49,i);
    fflush(stdin);
    printf("%0.2f",(P->info).sb);
    gotoxy(63,i);
    fflush(stdin);
    puts((P->info).tel);
    gotoxy(76,i);
    fflush(stdin);
    puts((P->info).de);
    gotoxy(97,i);
    fflush(stdin);
    puts((P->info).service);
    gotoxy(102,i);
    fflush(stdin);
    puts((P->info).adr);

    P=P->suivant;
    j++;i++;

 if (j!=t)   //gotoxy(2,i);
{
gotoxy(2,i);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
i++;
gotoxy(2,i);printf("  ³            ³              ³             ³             ³            ³                ³        ³              ³");

}
else
{fflush(stdin);

gotoxy(2,i);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   } }
  }
  printf("\n");
}
/***********insertion employe dans une position *********/
liste_e creation(liste_e LE)
{
    int rep,pos,t;
    employe x;
    int aj,ok;
do{
    t=taille_liste_emp(LE);

    gotoxy(5,0);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(5,1);printf("  ³ position d'insersion:(entre 1 et %d )     ³                       ³",t+1);
    gotoxy(5,2);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do{
        gotoxy(52,1);
        scanf("%d",&pos);
        if (!(pos>=1 && pos<=t+1))
               {
                rep=0;
                gotoxy(52,1);
                printf("             ");
                }
            else rep=1;

        }while(rep==0);
        gotoxy(63,20);
        fflush(stdin);
        printf("                   ");
        x=saisie_employe(LE);
        if(pos==1)
            LE=inserer_tete_emp2(LE,x);
        else
            if(pos==t+1)
                LE=inserer_queue_emp2(LE,x);
            else
                insere_pos_emp(LE,pos,x);
gotoxy(10,20);
printf("voulez vous ajouter un autre employe(0:non|1:oui) : ");
do
{
gotoxy(63,20);
fflush(stdin);
scanf("%d",&aj);
if (!(aj==0 || aj==1))
    ok=0;
else ok=1;
printf("%d",aj);
if(ok==0)
{
gotoxy(63,20);
fflush(stdin);
printf("                   ");
gotoxy(63,20);
fflush(stdin);}
   } while(!(aj==0 || aj==1));


}while(aj==1);

    return LE;
}
/********** enregistrement **********/
void enregistrement(liste_e LE)
{
    FILE *f;
    struct cellule *P=LE.premier;
    f=fopen("employe.txt","w");
    while(P)
    {
        fprintf(f,"%s|%s|%s|%f|%s|%s|%s|%s|\n",(P->info).mat,(P->info).nom,(P->info).pren,(P->info).sb,(P->info).adr,(P->info).de,(P->info).service,(P->info).tel);
        P=P->suivant;
    }
    fclose(f);
}
/***********Fonction recuperation**************/
liste_e recuperation()
{
    FILE * f;
    f = fopen("employe.txt", "r");
    employe e;
    liste_e LE;
    creer_liste(&LE);
    while(!feof(f))
    {
        fscanf(f,"%[^|]|%[^|]|%[^|]|%f|%[^|]|%[^|]|%[^|]|%[^|]|\n", e.mat, e.nom,e.pren, &e.sb,e.adr,e.de,e.service,e.tel);
        LE=inserer_queue_emp2(LE,e);
    }
    fclose(f);
    return LE;
}
/*** suppression service donne***/
liste_e suppression_employe_service (liste_e LE)
{
int rep;
int res=0;
char ch[2];
    struct cellule *p, *prec;
    prec=NULL,p=LE.premier;
    gotoxy(10,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,3);printf("  ³ service a supprimer:     ³                       ³");
    gotoxy(10,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do
{
gotoxy(41,3);
fflush(stdin);
gets(ch);
rep=controle_service(ch);
if(rep==0)
{
gotoxy(41,3);
fflush(stdin);
printf("                ");
gotoxy(41,3);
fflush(stdin);}
   } while(!( controle_service(ch)==1));
    while(p)
    {

        if(strcmp(tolower(p->info.service),tolower(ch))==0)
        {
            if(prec==NULL)
            {
                LE.premier=LE.premier->suivant;

                free(p);
                res=1;
                p=LE.premier;
            }
            else
            {
                 prec->suivant=p->suivant;
                 free(p);
                 res=1;
                 p=prec->suivant;
            }
        }
        else
        {
             prec=p;
             p=p->suivant;
        }
    }
    if (LE.dernier!=prec)
        LE.dernier=prec;
        gotoxy(25,6);
        if (res!=0)
        {gotoxy(25,6);
        printf("\n** supprime **\n\n");}
        else
            printf("\n**pas d'employe dans ce service**\n\n");
    return LE;
}
/*****Fonction suppression tete*******/
liste_e supprimer_tete_employe( liste_e LE)
{
int t;
struct cellule * s;
    t=taille_liste_emp (LE);
    if(t!=1)
    {
        s= LE.premier;
        LE.premier = s->suivant;
        free(s);
    }
    else
    {
    /* exception une liste formée d’un seul élément */
        LE.premier= NULL;
        LE.dernier= NULL;
    }
    return LE;
}
/***Fonction suppression queue***/
liste_e supprimer_queue_employe( liste_e LE)
{
struct cellule * p; /*pour parcourir ll */
    if(LE.premier==LE.dernier) /* liste formé d’un seul élément*/
        LE=supprimer_tete_employe(LE);
    else
    {
        p=LE.premier;
        while(p->suivant!= LE.dernier)
            p=p->suivant;
        p->suivant=NULL; /* mise à jour */
        free(LE.dernier); /* libérer de dernier */
        LE.dernier=p; /* mise à jour */

    }
    return LE;
}
/***supprimer position employé***/

void  supprime_position(liste_e LE )
{
struct cellule * p1=LE.premier;
struct cellule *p2 ;

int rep,pos,t;
    employe x;
    int aj,ok;
    t=taille_liste_emp(LE);

    gotoxy(20,3);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(20,4);printf("  ³ position d'insersion:(entre 1 et %d )     ³                       ³",t);
    gotoxy(20,5);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do{
        gotoxy(69,4);
        scanf("%d",&pos);
        if (!(pos>=1 && pos<=t+1))
               {
                rep=0;
                gotoxy(69,4);
                printf("             ");
                }
            else rep=1;

        }while(rep==0);

int  i =1;
while(i<pos-1)
    {
        i ++;
        p1=p1->suivant ;
    }
p2=p1->suivant ;
p1->suivant=p2->suivant ;
free (p2) ;
gotoxy(50,7);
printf("**supprime**");
printf("\n\n\n");
}
/***Suppression employe donné*****/

liste_e supp_employe(liste_e LE)
{int rep=0;
int val;
char ch[9];
struct cellule *p=LE.premier,*q;
int ok=0;
    gotoxy(10,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,3);printf("  ³       matricule          ³                       ³");
    gotoxy(10,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

do
    {

    gotoxy(41,3);
    fflush(stdin);
    gets(ch);
    rep=(recherche_emp(LE,ch)!=0)&&(controle2(ch)!=0);

    if(rep==0)
    {
        fflush(stdin);
        gotoxy(41,3);
        printf("                  ");
        gotoxy(41,3);

    }
}while(rep==0);
val = atoi(ch);
    if(atoi((p->info).mat)==atoi(ch))
    {   LE.premier=p->suivant;
        free(p);
        gotoxy(20,5);
        printf("** employe supprime **\n\n");

    }
    else
    {    while(p->suivant)
            if(atoi((p->suivant)->info.mat)==atoi(ch))
            {
                ok=1;
                break;
            }
            else
                p=p->suivant;
        if(ok)
        {   q=p->suivant;
            if(q==LE.dernier)
                LE.dernier=p;
            p->suivant=q->suivant;
            free(q);
            gotoxy(20,6);
        printf("** employe supprime **\n\n");
        }
        else
        {
            gotoxy(4,10);
            printf("%d n'existe pas dans la liste\n",atoi(ch));}
    }
    return LE;
}
void modifier_adresse(liste_e LE)
{int rep;
struct cellule *p=LE.premier;
char matri[40];
char adre[40];
gotoxy(10,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(10,3);printf("  ³      matricule:          ³                       ³");
gotoxy(10,4);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,5);printf("  ³      Nouvelle adresse:   ³                       ³");
gotoxy(10,6);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
do
    {
    gotoxy(41,3);
    fflush(stdin);
    gets(matri);
    rep=(recherche_emp(LE,matri)!=0)&&(controle2(matri)!=0);
    if(rep==0)
    {
        gotoxy(41,3);
        fflush(stdin);
        printf("                     ");
        gotoxy(41,3);
        fflush(stdin);
    }
}while(rep==0);
while(p)
   	   {
   	       if(strcmp((p->info).mat ,matri)==0)
   	       {
            gotoxy(41,5);
   	        gets((p->info).adr);

   	        gotoxy(25,8);
        printf("** adresse modifie **\n\n");

   	        return;
   	       }
   	    else
   	        p=p->suivant;}
gotoxy(20,8);
printf("matricule non trouve");

}
void modifier_tel(liste_e LE)
{
struct cellule *p=LE.premier;
char matri[40];
int rep;
char tel[40];
gotoxy(10,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(10,3);printf("  ³      matricule:          ³                       ³");
gotoxy(10,4);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(10,5);printf("  ³      nouveau telephone   ³                       ³");
gotoxy(10,6);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
do
    {
    gotoxy(41,3);
    fflush(stdin);
    gets(matri);
    rep=(recherche_emp(LE,matri)!=0)&&(controle2(matri)!=0);
    if(rep==0)
    {
        gotoxy(41,3);
        fflush(stdin);
        printf("                     ");
        gotoxy(41,3);
        fflush(stdin);
    }
}while(rep==0);
while(p)
   	   {
   	       if(strcmp((p->info).mat ,matri)==0)
   	       {
   	           do
                {
                    gotoxy(41,5);
                    fflush(stdin);
                    gets(tel);
                    rep=controle_tel(tel);
                    if(rep==0)
                        {
                            gotoxy(41,5);
                            fflush(stdin);
                            printf("                ");
                            gotoxy(41,5);
                            fflush(stdin);}
                }while(rep==0);

            strcpy((p->info.tel),tel);
            gotoxy(25,8);
            printf("** Telephone modifie **\n\n");
   	        return;
   	       }
   	    else
   	        p=p->suivant;}
printf("matricule non trouvé");

}
/****************************************************************************************************/
float CNSS(float sb)
{
    float cnss;
    if (sb<200)
        cnss=0;
    else cnss=(sb*10)/100;
    return cnss;

}
/***Calcul impots**/
float impot(float sb)
{
 float cnss;
 float impot;
 float salaire_imposable;
  salaire_imposable=sb-CNSS(sb);
    if (salaire_imposable<=200)
    impot=(salaire_imposable*5)/10;
    else if (salaire_imposable<=400 &&salaire_imposable>200)
    impot=(salaire_imposable*10)/100;
    else if (salaire_imposable<=600 &&salaire_imposable>400)
    impot=(salaire_imposable*20)/100;
    else if (salaire_imposable<=800 &&salaire_imposable>600)
  impot=(salaire_imposable*30)/100;
    else if (salaire_imposable>800)
  impot=(salaire_imposable*40)/100;
return impot;
}
/***salaire Net***/
float salaire_Net(float sb)
{
    float net;
    net=sb-CNSS(sb)-impot(sb);
    return net;
}
/***calcul salaire brut***/
float salaire_brut(liste_e LE)
{
    struct cellule *p=LE.premier,*q;
    float total=0;
    while(p)
    {
        total=total+(p->info).sb;

        p=p->suivant;
    }
    return total;
}
float somme_cnss(liste_e LE)
{
    struct cellule *p=LE.premier,*q;
    float total=0;
    while(p)
    {
        total=total+CNSS((p->info).sb);

        p=p->suivant;
    }
    return total;
}
/****recherche par matricule**/
void recherche_par_matricule(liste_e LE)
{
int rep=0;
int val;
char ch[9];
    gotoxy(20,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(20,3);printf("  ³       matricule          ³                       ³");
    gotoxy(20,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do
    {

    gotoxy(51,3);
    fflush(stdin);
    gets(ch);
    rep=(recherche_emp(LE,ch)!=0)&&(controle2(ch)!=0);

    if(rep==0)
    {
        fflush(stdin);
        gotoxy(51,3);
        printf("                  ");
        gotoxy(51,3);

    }
}while(rep==0);
gotoxy(20,6);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(20,7);printf("  ³       nom :              ³                       ³");
gotoxy(20,8);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,9);printf("  ³       prenom :           ³                       ³");
gotoxy(20,10);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,11);printf("  ³       salaire brut :     ³                       ³");
gotoxy(20,12);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,13);printf("  ³       telephone :        ³                       ³");
gotoxy(20,14);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,15);printf("  ³       date d'embauche :  ³                       ³");
gotoxy(20,16);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,17);printf("  ³       service  :         ³                       ³");
gotoxy(20,18);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,19);printf("  ³       adresse  :         ³                       ³");
gotoxy(20,20);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
fflush(stdin);
struct cellule *p;
p=recherche_emp2(LE,ch);

gotoxy(51,7);puts((p->info).nom);
gotoxy(51,9);puts((p->info).pren);
gotoxy(51,11);printf("%.2f",(p->info).sb);
gotoxy(51,13);puts((p->info).tel);
gotoxy(51,15);puts((p->info).de);
gotoxy(51,17);puts((p->info).service);
gotoxy(51,19);puts((p->info).adr);
printf("\n\n\n");

}
void bulletin_de_paie(liste_e LE)
{
int rep=0;
int val;
int sal_b;
char ch[9];
    gotoxy(30,1);printf("Bulletin de paie");
    gotoxy(20,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(20,3);printf("  ³       matricule :        ³                       ³");
    gotoxy(20,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do
    {

    gotoxy(51,3);
    fflush(stdin);
    gets(ch);
    rep=(recherche_emp(LE,ch)!=0)&&(controle2(ch)!=0);

    if(rep==0)
    {
        fflush(stdin);
        gotoxy(51,3);
        printf("                  ");
        gotoxy(51,3);

    }
}while(rep==0);
gotoxy(20,6);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(20,7);printf("  ³       nom :              ³                       ³");
gotoxy(20,8);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,9);printf("  ³       prenom :           ³                       ³");
gotoxy(20,10);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,11);printf("  ³       salaire brut     = ³                       ³");
gotoxy(20,12);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,13);printf("  ³       CNSS             = ³                       ³");
gotoxy(20,14);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,15);printf("  ³       Impots           = ³                       ³");
gotoxy(20,16);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,17);printf("  ³       Salaire imposable= ³                       ³");
gotoxy(20,18);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,19);printf("  ³       Salaire net      = ³                       ³");
gotoxy(20,20);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
fflush(stdin);
struct cellule *p;
p=recherche_emp2(LE,ch);

gotoxy(51,7);puts((p->info).nom);
gotoxy(51,9);puts((p->info).pren);
gotoxy(51,11);printf("%.2f",(p->info).sb);
sal_b=(p->info).sb;
float cns;
cns=CNSS(sal_b);
float imp;
imp=impot(sal_b);
float sal_impos;
sal_impos=sal_b-cns;
float sal_net;
sal_net=salaire_Net(sal_b);
gotoxy(51,13);printf("%.2f",cns);
gotoxy(51,15);printf("%.2f",imp);
gotoxy(51,17);printf("%.2f",sal_impos);
gotoxy(51,19);printf("%.2f",sal_net);
printf("\n\n\n");
}
/***posssssss tri ****/
struct cellule * pos_tri(liste_e L,float sab)
{
 struct cellule *p,*c;
 p=(L.premier);
 employe x;
c=p;
    while(p)
      {
        x=p->info;

        if ((x.sb)>(sab))
            {c=p;
            p=p->suivant;}
        else

            return c;
      }

 return c;


}

liste_e triage(liste_e LE)
{
    liste_e LT;
    creer_liste(&LT);
    struct cellule *p;
    p=(LE.premier);
    employe x;
    struct cellule *pos,*q;
    float sab;
    x=p->info;
    LT=inserer_queue_emp2(LT,x);
    p=p->suivant;
    while(p)
      {
        x=p->info;
        sab=x.sb;
        //printf("%f",sab);
        pos=pos_tri(LT,sab);
        if (pos==LT.premier)
           {
            LT=inserer_tete_emp2(LT,x);

           }
        else if(pos->suivant==LT.dernier)
            { LT=inserer_queue_emp2(LT,x);}
        else
        {
        q=(struct cellule*)malloc(sizeof(struct cellule));
        q->suivant=pos->suivant;
        pos->suivant=q;
        q->info=x;
        }
        p=p->suivant;
      }
      return LT;
}
/**recherche par nom**/
 liste_e recherche_emp3(liste_e LE)
{

 int rep=0;

    gotoxy(20,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(20,3);printf("  ³       nom :              ³                       ³");
    gotoxy(20,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    char ch[20];
    do
    {
    gotoxy(51,3);
    fflush(stdin);
    gets(ch);
    rep=controle1(ch);
    if(rep==0)
    {
    gotoxy(51,3);
    fflush(stdin);
    printf("                     ");
    gotoxy(51,3);
    fflush(stdin);}
    }while(rep==0);
    liste_e LF;
    creer_liste(&LF);
    employe x;

    struct cellule *p=LE.premier;
   	while(p)
        {
        x=p->info;
   	    if(strcmp((p->info).nom,ch)==0)
   	      LF=inserer_queue_emp2(LF,x);
   	    p=p->suivant;}
return LF;

}
/***affichage***/
void affiche2(liste_e L)
{int t;
    struct cellule *P=L.premier;
    if(P==NULL)
        printf("Liste vide\n");
    else
    {
gotoxy(2,6);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(2,7);printf("  ³ matricule  ³  Nom         ³   prenom    ³Saliare brut ³ Telephone  ³ Date d'embauche³ Service³ Adresse      ³");
gotoxy(2,8);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(2,9);printf("  ³            ³              ³             ³             ³            ³                ³        ³              ³");

    t=taille_liste_emp (L);
    //printf("%d",t);
    int i=9;
    int j=0;
    while (P)
    {
    gotoxy(5,i);
    fflush(stdin);

    puts((P->info).mat);
    gotoxy(18,i);
    fflush(stdin);
    puts((P->info).nom);
    gotoxy(35,i);
    fflush(stdin);
    puts((P->info).pren);
    gotoxy(49,i);
    fflush(stdin);
    printf("%0.2f",(P->info).sb);
    gotoxy(63,i);
    fflush(stdin);
    puts((P->info).tel);
   gotoxy(76,i);
    fflush(stdin);
    puts((P->info).de);
    gotoxy(97,i);
    fflush(stdin);
    puts((P->info).service);
    gotoxy(102,i);
    fflush(stdin);
    puts((P->info).adr);

    P=P->suivant;
    j++;i++;

 if (j!=t)
{
gotoxy(2,i);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
i++;
gotoxy(2,i);printf("  ³            ³              ³             ³             ³            ³                ³        ³              ³");

}
else
{fflush(stdin);

gotoxy(2,i);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   } }
  }
  printf("\n");
}
/****calcul somme cnss et somme salire brut***/
void calcul_cnss_brut(liste_e LE)
{
gotoxy(34,2);printf("** Le total des salaires et des CNSS **");
gotoxy(25,4);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(25,5);printf("  ³ Total des salaires bruts:³                        ³");
gotoxy(25,6);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(25,7);printf("  ³      Total CNSS :        ³                        ³");
gotoxy(25,8);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

gotoxy(60,5);printf("%.2f",salaire_brut(LE));
gotoxy(60,7);printf("%.2f",somme_cnss(LE));
printf("\n\n\n");
}
/****recherche par telephone**/
void recherche_par_tel(liste_e LE)
{
int rep=0;
int val;
char te[9];
    gotoxy(20,2);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(20,3);printf("  ³       telephone          ³                       ³");
    gotoxy(20,4);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    do
{
gotoxy(51,3);
fflush(stdin);
gets(te);
rep=controle_tel(te);
if(rep==0)
{
gotoxy(51,3);
fflush(stdin);
printf("                     ");
gotoxy(51,3);
fflush(stdin);}
}while(rep==0);

struct cellule *p=LE.premier;
employe x;
   	while(p)
        {
        x=p->info;
   	    if(strcmp(x.tel,te)==0)



{
gotoxy(20,6);printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
gotoxy(20,7);printf("  ³       matricule :        ³                       ³");
gotoxy(20,8);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,9);printf("  ³       nom :              ³                       ³");
gotoxy(20,10);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,11);printf("  ³       prenom :           ³                       ³");
gotoxy(20,12);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,13);printf("  ³       salaire brut :     ³                       ³");
gotoxy(20,14);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,15);printf("  ³       date d'embauche :  ³                       ³");
gotoxy(20,16);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,17);printf("  ³       service  :         ³                       ³");
gotoxy(20,18);printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
gotoxy(20,19);printf("  ³       adresse  :         ³                       ³");
gotoxy(20,20);printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
fflush(stdin);
gotoxy(51,9);puts((p->info).nom);
gotoxy(51,13);puts((p->info).pren);
gotoxy(51,11);printf("%.2f",(p->info).sb);
gotoxy(51,7);puts((p->info).mat);
gotoxy(51,15);puts((p->info).de);
gotoxy(51,17);puts((p->info).service);
gotoxy(51,19);puts((p->info).adr);
break;}

 else
    p=p->suivant;}
    if (p==NULL)
    {gotoxy(35,6);printf(" ** numero inexixtant**");}

printf("\n\n\n");


}
