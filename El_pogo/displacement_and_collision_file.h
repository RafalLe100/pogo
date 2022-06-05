#include "random_placement_file.h"


#define TAILLE 30

void dance(Dancer dancer_tab[], int dancer_tab_size);

void wallcollision( Dancer dancer_tab[], int dancer_tab_size); 

void minspeed( Dancer dancer_tab[], int dancer_tab_size); 

void displacement(  Dancer dancer_tab[] , int dancer_tab_size );

int collisionYN ( Dancer P1 , Dancer P2 );

void make_collision ( Dancer tab[] , int a , int b ); 

void manage_collisions ( Dancer dancer_tab[] , int dancer_tab_size );
