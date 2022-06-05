#include <unistd.h>
#include "json_save_fonctions_file.h"
#define TAILLE 30


int main(){
    
    int minpogo=50;     /* initializing minimun speed of a pogoteur */
    int minclassic=20;  /* initializing minimun speed of a classical dancer */
    int n=10000;        /* initializing numbers of steps */ 
    
    
    /* ask to the user the number of dancers and create a dancer tab */
    int dancer_tab_size = How_many_dancers();
    Dancer* dancer_tab = NULL ; 
    dancer_tab = malloc( sizeof(Dancer) * dancer_tab_size );
       if ( dancer_tab == NULL){
           exit(1); 
       }

    /* place dancers randomly */
    dancer_random_placement( dancer_tab , dancer_tab_size, minpogo, minclassic ); 
    


   /* initializing dance floor to empty */
    char Piste[TAILLE][TAILLE] ; 
    for( int i = 0 ; i < TAILLE ; i++)
    {
        for( int j = 0 ; j < TAILLE ; j ++)
        {
            Piste[i][j] = 32;
        }
    } 



    FILE* save = NULL; /* opening a file to save the simulation */
    save = fopen("SAVE.pogo", "w");
    if (save == NULL){
        printf("Ouverture du fichier impossible");
        exit(1);
    }

    
    
    
    /* create and display the first step */
    creer_piste( dancer_tab , dancer_tab_size , Piste );
    afficher_piste( Piste );

    createsave(save, n, minpogo, minclassic);

    /* make moves, collisions and saves at least n times or continue as the user wishes */
     do{
		for ( int t = 0 ; t < n ; t++ ){
			savestep(save, dancer_tab, dancer_tab_size,  n, t);
			fprintf(save,",\n");
			
			displacement( dancer_tab , dancer_tab_size );
			creer_piste( dancer_tab , dancer_tab_size , Piste );
			afficher_piste( Piste );
		    
			manage_collisions ( dancer_tab , dancer_tab_size );
			
			if (t%500==0){
			dance(dancer_tab , dancer_tab_size);
			
			}
			
			printf("%d", t);

		   
		   usleep(2500);
		   printf("\033c");
		}

      /* create, display, and save the last step */		
      creer_piste( dancer_tab , dancer_tab_size , Piste );
      afficher_piste( Piste );
      savestep(save, dancer_tab, dancer_tab_size,  n, n);
      fprintf(save, " ]\n}");
      
      }while( continue_simulation () == 1 );

    
    free(dancer_tab);
    fclose(save);
    
    return 0;
}
