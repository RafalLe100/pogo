#include "print_dance_floor_file.h"

/* fonctions needed to display the dance floor in the terminal */


void creer_piste( Dancer tab[] , int taille_tab , char Piste[][TAILLE]){
/* create the 2D characters table Piste using the dancer tab in entry */

        /* the validity of the input data is checked , exit 1 if invalidity */
	if (tab == NULL){
		puts("créer piste: no tab?");
           exit(1); 
       }
    if (taille_tab <=0){
		puts("créer piste: taille tab<=0");
           exit(1); 
       }   
      
    /* we initialize the Piste with spaces */       
    for( int i = 0 ; i < TAILLE ; i++)
    {
        for( int j = 0 ; j < TAILLE ; j ++)
        {
            Piste[i][j] = 32 ;
        }
    }

    /* we go trought the table of dancers and fill the Piste accordingly,
       0 if it's a pogoteur, @ if it's a classical dancer */    
    for( int j = 0 ; j < taille_tab ; j++)
    {    
        int b = (int)tab[j].pos_x ;
        int a = (int)tab[j].pos_y ;
        

        if (a>=0 && a<TAILLE){
            if (b>=0 && b<TAILLE){
                switch(tab[j].type){
                    case 1:
                        Piste[a][b] = 64 ;
                        break;
                    case 2:
                        Piste[a][b] = 79;
                    break;
                }
            }
        }
             
    }
}



void afficher_piste(char Piste[][TAILLE]){
/* print the Piste in the terminal */
   
     for( int i = 0 ; i < TAILLE ; i++)
    {
        for( int j = 0 ; j < TAILLE ; j ++)
        {
            printf(" %c", Piste[i][j]);
        }
        
        printf("|\n");
    } 
}
