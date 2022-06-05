#include "pogo_scanf_file.h"

/* fonctions needed to interact with the user */


int How_many_dancers (){
/* ask to the user the number of dancers he want, (between 1 and 150)
 and return this number of dancers */
    
    int dancer_number = 0;

    do{
        
        printf("How many dancers ? (150 max)\n");
        printf("Give a number between 1 and 150.\n");

        if (scanf("%d" , &dancer_number) != 1){
           printf("error");
           exit(1); 
        }
        if ( dancer_number < 1 || dancer_number > 150 ){
            puts("input invalid");
            
        }
        
    }while( dancer_number < 1 || dancer_number > 150 );
    
    return dancer_number ; 
}


int continue_simulation (){
/* ask to the user if he want to continue the simulation, return 1 if yes, 0 if no */

   int b = 0 ; 

     do{

       printf("Do you want to continue the simulation ? \n\n");
       printf("     1 for yes      0 for no ");


       if( scanf("%d" , &b) != 1 ){
   
       printf(" error : invalid input ");  
       exit(1); 

       }

       }while( b != 1 && b != 0  ); 
   
    return b ;  
} 


