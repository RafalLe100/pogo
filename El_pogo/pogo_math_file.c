#include "pogo_math_file.h"

/* geometry fonctions needed */


float distance ( Dancer P1 , Dancer P2 ){
/* calculate the distance between 2 dancers, return this distance */
        
    float D = sqrt( (P2.pos_x - P1.pos_x)*(P2.pos_x - P1.pos_x) + (P2.pos_y - P1.pos_y)*(P2.pos_y - P1.pos_y) );
        
    return D ; 
}
    
    
float norm ( Dancer A ){
/*calculates the norm of the velocity vector of a dancer, return the norm */

    float vx = A.speed_x ;
    float vy = A.speed_y ; 
    
    int norm = sqrt( vx*vx + vy*vy );
    
    return ( norm );  
} 
