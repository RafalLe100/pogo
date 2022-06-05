#include <time.h>
#include "random_placement_file.h"

/* functions needed for the random placement of dancers */


int collision_at_start( Dancer dancer_tab[] , int j ){
/* collision_at_start count the number of collision at start, and return this number */

    /* the validity of the input data is checked , exit 1 if invalidity */
    if ( dancer_tab == NULL){
		puts("collision_at_start: no tab");
           exit(1); 
       }
    
    int number_of_collisions = 0 ; 
    int d = 0; 
    
    for(int i = 0 ; i < j - 1 ; i++ ){
        
        d = distance ( dancer_tab[i] , dancer_tab[j] ) ; 
        
        if( d < 1.1 ){
            
            number_of_collisions = number_of_collisions + 1 ; 
            
        }
    }
    
    return number_of_collisions ;

}



void dancer_random_placement( Dancer dancer_tab[] , int dancer_tab_size, int minpogo, int minclassic){
/* dancer_random_placement initialize the parameters of the dancers randomly */
    
    srand(time(NULL));

    /* the validity of the input data is checked , exit 1 if invalidity */
    if ( dancer_tab == NULL){
		puts("dancer random placement: no tab");
           exit(1); 
    }
    if (dancer_tab_size <=0){
		puts("dancer_random_placement : taille tab<=0");
           exit(1); 
       }
    
    /* we go trought the dancer table, initialize the dancers parameters randomly,
    and start again if the dancer is in collision with another one */ 
    for( int i = 0 ; i < dancer_tab_size ; i++ ){
        
        do{
        dancer_tab[i].type = (rand()%2)+1;    
        dancer_tab[i].pos_x = 1 + rand()%(TAILLE - 1) ; /* place the dancer not too close to the edges */
        dancer_tab[i].pos_y = 1 + rand()%(TAILLE - 1) ;
        dancer_tab[i].speed_x = (rand()%17) - 8 ; 
        dancer_tab[i].speed_y = (rand()%17) - 8 ; 

        if (dancer_tab[i].type==2){
            dancer_tab[i].minspeed=minpogo;

        }
        else{
            dancer_tab[i].minspeed=minclassic;
        }
        if (norm(dancer_tab[i])==0){
            dancer_tab[i].speed_x = 1;
            dancer_tab[i].speed_y = 1;
        }
        
        
        }while( collision_at_start ( dancer_tab , i ) != 0 ); 
    }

}
