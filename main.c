#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "projet_c.h"
#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

/*  Declare Windows procedure  */
liste_e LE;
int ok=0;
int sor=0;
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Gestion des employés"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1400,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
          NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
          );

    /* Make the window visible on the screen */
   ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
   }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("graphic.exe") ;
        intro=0;
    }*/

switch (message)                  /* handle the messages */
{

        case WM_COMMAND:
        switch(wParam)
        {

        case 1:
            if
                (ok==0)
                {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=inserer_tete_emp(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                gotoxy(30,15);
                system("cls");
                break;
        case 2:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=inserer_queue_emp(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 3:
            if (ok==0)
               {
               MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=creation(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 4:
            if (ok==0)
               {
               MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=supprimer_tete_employe(LE);
                //system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 5:
            if (ok==0)
               {
               MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=supprimer_queue_employe(LE);
                //system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 6:
            if (ok==0)
               {
               MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);break;}
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                supprime_position(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 7:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=supp_employe(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 8:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employes est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=suppression_employe_service(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 9:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                modifier_adresse(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 10:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);
                modifier_tel(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 11:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(0,0);
                affiche(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 12:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                char mat[20];
                recherche_par_matricule(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 13:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                liste_e LT;
                LT=recherche_emp3(LE);
                affiche2(LT);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 14:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                calcul_cnss_brut(LE);
                printf("\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 15:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                recherche_par_tel(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 16:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("    BONJOUR 3   \n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 17:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("    BONJOUR 3   \n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 18:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                bulletin_de_paie(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 19:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=triage(LE);
                LE=triage(LE);
                affiche(LE);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 20:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                enregistrement(LE);
                sor=1;
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
       case 21:

                if (ok==1)
               {
                MessageBox(hwnd,"vous avez deja recuperé vous fichiers !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                LE=recuperation();
                ok=1;
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 23:
            if (ok==0)
               {
                MessageBox(hwnd," La liste des employés est vide !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                printf("    BONJOUR 3   \n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 22:
            if (sor==0)
               {
                MessageBox(hwnd," enregistre tes fichiers !", "Attention !", MB_OK|MB_ICONASTERISK);
                break;
                }
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
    addmenus(hwnd);
    //createBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"yosr.bmp",IMAGE_BITMAP,1400,700,LR_LOADFROMFILE);

            break;

        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
       default:                      /* for messages that we don't deal with */
           return DefWindowProc (hwnd, message, wParam, lParam);
   }

 return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU ajout=CreateMenu();
    HMENU supp=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU modif=CreateMenu();
    HMENU htp3=CreateMenu();

    /*******************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Mise à jour des employés");/*fait*/
    AppendMenu(htp1,MF_POPUP,(UINT_PTR)ajout,"Ajouter un nouvel employés");/*fait*/
    AppendMenu(ajout,MF_STRING,1,"Ajout en tete"); /*fait*/
    AppendMenu(ajout,MF_STRING,2,"Ajout en queue");/*fait*/
    AppendMenu(ajout,MF_STRING,3,"ajout dans une position");/*fait*/
        /*********suppression **************/
    AppendMenu(htp1,MF_POPUP,(UINT_PTR)supp,"Supprimer un employé");/*fait*/
    AppendMenu(supp,MF_STRING,4,"suppression en tete "); /*fait*/
    AppendMenu(supp,MF_STRING,5,"suppression en queue");/*fait*/
    AppendMenu(supp,MF_STRING,6,"suppression employé d'une position");/*fait*/
    AppendMenu(supp,MF_STRING,7,"suppression d'un employé donné");/*fait*/
    AppendMenu(supp,MF_STRING,8,"suppression des employés d'un service");/*fait*/
    AppendMenu(htp1,MF_POPUP,(UINT_PTR)modif,"Modifier les données d'un employé");/*fait*/
    AppendMenu(modif,MF_STRING,9,"Adresse"); /*fait*/
    AppendMenu(modif,MF_STRING,10,"Télèphone");/*fait*/

/***************************************************************/
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"Recherche,affichage et Tri");
    AppendMenu(htp2,MF_STRING,11,"Contenu de la liste des employés");/*fait*/
    AppendMenu(htp2,MF_STRING,12,"Recherche par matricule ");
    AppendMenu(htp2,MF_STRING,13,"Recherche par nom");
    AppendMenu(htp2,MF_STRING,14,"Calcul salaire brut total et CNSS total");
    AppendMenu(htp2,MF_STRING,15,"Recherche par télephone");
    AppendMenu(htp2,MF_STRING,18,"Afichage bulettin de paie ");
    AppendMenu(htp2,MF_STRING,19,"Tri");

/***************************************************************/
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"Enregistrement et chargement dans un fichier");
      AppendMenu(htp3,MF_STRING,20,"Enregistrement");/*fait*/
      AppendMenu(htp3,MF_STRING,21,"Récupération");/*fait*/


/****************************************************************/
    AppendMenu(hmenu,MF_STRING,22,"Quitter");/*fait*/
    SetMenu(hwnd,hmenu);
}
