#include "displacement_and_collision_file.h"

/* fonctions needed for displacements and collisions */


void dance(Dancer dancer_tab[], int dancer_tab_size){
/* dance change randomly the speeds of all the dancers to simulate dance steps */

	/* the validity of the input data is checked , exit 1 if invalidity */
	if ( dancer_tab == NULL){
		puts("dispacement: no tab");
           exit(1);
       }
       
    if (dancer_tab_size <=0){
		puts("displacement: taille tab<=0");
           exit(1);
       }  
       
       
	for(int i = 0 ; i < dancer_tab_size ; i++){

		if(rand()%2==1){
			dancer_tab[i].speed_x=dancer_tab[i].speed_x*-1;
			if(rand()%2==1){
				dancer_tab[i].speed_x=dancer_tab[i].speed_x-1;
			}

		}
		if(rand()%2==1){
			dancer_tab[i].speed_y=dancer_tab[i].speed_y*-1;
			if(rand()%2==1){
				dancer_tab[i].speed_y=dancer_tab[i].speed_y-1;
			}
		}

	}



}




void wallcollision( Dancer dancer_tab[], int dancer_tab_size){
/* wallcollision manage the collisions with the edges */
    
    float deltaT = 0.0001;    /* deltaT is low for better precision, could be change */
    
    /* the validity of the input data is checked , exit 1 if invalidity */
    if ( dancer_tab == NULL){
		puts("wallcollision: no tab");
           exit(1); 
       }
       
    if (dancer_tab_size <=0){
		puts("wallcollision: taille tab<=0");
           exit(1); 
       }       
    
    /* for all the dancers, if they are too close to an edge they come back to their last position,
    and their speed is reverse in the good axe x or y */  
    for(int i = 0 ; i < dancer_tab_size ; i++){

        if(dancer_tab[i].pos_y > TAILLE - 0.5 ){
		   dancer_tab[i].pos_y = dancer_tab[i].pos_y - (dancer_tab[i].speed_y * deltaT);
		   dancer_tab[i].speed_y = -(dancer_tab[i].speed_y);
	    }
	    
        if(dancer_tab[i].pos_x > TAILLE - 0.5 ){
		   dancer_tab[i].pos_x = dancer_tab[i].pos_x - (dancer_tab[i].speed_x * deltaT);
		   dancer_tab[i].speed_x = -(dancer_tab[i].speed_x);
	    }

        if(dancer_tab[i].pos_x < 0.5){
		   dancer_tab[i].pos_x = dancer_tab[i].pos_x - (dancer_tab[i].speed_x * deltaT);
		   dancer_tab[i].speed_x = -(dancer_tab[i].speed_x);
	    }

        if(dancer_tab[i].pos_y < 0.5){
		   dancer_tab[i].pos_y = dancer_tab[i].pos_y - (dancer_tab[i].speed_y * deltaT);
		   dancer_tab[i].speed_y = -(dancer_tab[i].speed_y);
	    }

    }
}


void minspeed( Dancer dancer_tab[], int dancer_tab_size){
/* minspeed change the speed of a dancer if his too slow or too fast */

    /* the validity of the input data is checked , exit 1 if invalidity */
    if ( dancer_tab == NULL){
		puts("minspeed: no tab");
           exit(1); 
       }
       
    if (dancer_tab_size <=0){
		puts("minspeed: taille tab<=0");
           exit(1); 
       }       
    for(int i = 0 ; i < dancer_tab_size ; i++)
    {

        if (norm(dancer_tab[i])>=dancer_tab[i].minspeed){  /* minspeed depends of the type of dancer */
            dancer_tab[i].speed_x=dancer_tab[i].speed_x*0.9;
            dancer_tab[i].speed_y=dancer_tab[i].speed_y*0.9;
        }
        else {
            dancer_tab[i].speed_x=dancer_tab[i].speed_x*1.9;
            dancer_tab[i].speed_y=dancer_tab[i].speed_y*1.9;
        }

    }   

}




void displacement(  Dancer dancer_tab[] , int dancer_tab_size ){
/* displacement change the position of all the dancers based on their speeds, 
 also execute wallcollision and minspeed fonctions */

        /* the validity of the input data is checked , exit 1 if invalidity */
	if ( dancer_tab == NULL){
		puts("dispacement: no tab");
           exit(1); 
       }
       
    if (dancer_tab_size <=0){
		puts("displacement: taille tab<=0");
           exit(1); 
       } 

      
    float deltaT = 0.0001 ; /* deltaT is low for better precision, could be change */  
    
   for(int i = 0 ; i < dancer_tab_size ; i++)
   {
       wallcollision(dancer_tab,dancer_tab_size);

       dancer_tab[i].pos_x = dancer_tab[i].pos_x + (dancer_tab[i].speed_x * deltaT);
       dancer_tab[i].pos_y = dancer_tab[i].pos_y + (dancer_tab[i].speed_y * deltaT);
	   
	   
	    minspeed(dancer_tab,dancer_tab_size);

	  }
	  
}



int collisionYN ( Dancer P1 , Dancer P2 ){
/* collisionYN return 1 if the distance between P1 and P2 is under 1, return -1 if not */

     if ( distance ( P1 , P2 ) < 1 ) 
     {
         return(1);
     }
     else 
     {
         return(-1);
     }
} 






void make_collision ( Dancer tab[] , int a , int b ){
/* make_collision change speeds of 2 dancers colliding like 2 billiard balls */
/* demo link :    https://lucidar.me/fr/mechanics/elastic-collision-equations-simulation-part-1/     */


           /* the validity of the input data is checked , exit 1 if invalidity */
	   if ( tab == NULL){
		   puts("make_collision: no tab");
           exit(1); 
       }
 
	   
       float alpha1 = atan2f ( tab[b].pos_y - tab[a].pos_y , tab[b].pos_x - tab[a].pos_x ); 
       float beta1 = atan2f ( tab[a].speed_y , tab[a].speed_x ); 
       float gamma1 = beta1 - alpha1 ; 
       float alpha2 = atan2f ( tab[a].pos_y - tab[b].pos_y , tab[a].pos_x - tab[b].pos_x ); 
       float beta2  = atan2f ( tab[b].speed_y , tab[b].speed_x ); 
       float gamma2 = beta2 - alpha2 ;
       
       float u12 = norm(tab[a])*cosf( gamma1 );           
       float u11 = norm(tab[a])*sinf( gamma1 );   
       float u21 = norm(tab[b])*cosf( gamma2 ); 
       float u22 = norm(tab[b])*sinf( gamma2 );
       
       
       tab[a].speed_x = -sinf(alpha1)*u11 - cosf(alpha1)*u21 ; 
       tab[a].speed_y = cosf(alpha1)*u11 - sinf(alpha1)*u21 ;
       
       tab[b].speed_x = -sinf(alpha2)*u22 - cosf(alpha2)*u12 ; 
       tab[b].speed_y = cosf(alpha2)*u11 - sinf(alpha2)*u12 ;

       
       
   }





void manage_collisions ( Dancer dancer_tab[] , int dancer_tab_size ){
/* manage_collision make 2 dancers collide if collisionYN return 1 */

   /* the validity of the input data is checked , exit 1 if invalidity */
   if ( dancer_tab == NULL){
	   puts("manage_collision: no tab");
           exit(1); 
       }
   if (dancer_tab_size <=0){
		puts("manage_colllision: taille tab<=0");
           exit(1); 
       }
   
   /* we test collisionYN only if the 2 dancers are in a distance under 1 in x and 1 in y */
   for ( int i = 0 ; i < dancer_tab_size ; i ++ )
   {
       for ( int j = i + 1 ; j < dancer_tab_size ; j ++ )
       {
          if ( dancer_tab[i].pos_x - 1 < dancer_tab[j].pos_x  &&  dancer_tab[j].pos_x < dancer_tab[i].pos_x + 1 )
            {
               if ( dancer_tab[i].pos_y - 1 < dancer_tab[j].pos_y  &&  dancer_tab[j].pos_y < dancer_tab[i].pos_y + 1 )
                 {
                    if ( collisionYN ( dancer_tab[i] , dancer_tab[j] ) == 1 ) 
                    {
                        make_collision ( dancer_tab , i , j); 
                    }
                 }
            }
       }
   }
}
