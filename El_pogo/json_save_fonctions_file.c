
#include "json_save_fonctions_file.h"


// JSON SAVE FONCTIONS


// Writing a Dancer Block
void savedancer(FILE* save, Dancer dancer_tab[], int i){
    char* type;
    if(dancer_tab[i].type==2){
        type= "Pogo";
    }
    else{
        type= "Classic";
    }
    fprintf(save, "             {\n                 \"id\": \"Dancer%d\" \n", i);
    fprintf(save, "                 \"type\": \"%s\" \n", type);
    fprintf(save, "                 \"x\": %d \n", (int)dancer_tab[i].pos_x);
    fprintf(save, "                 \"y\": %d \n", (int)dancer_tab[i].pos_y);
    fprintf(save, "                 \"vx\": %f \n", dancer_tab[i].speed_x);
    fprintf(save, "                 \"vy\": %f \n               }", dancer_tab[i].speed_y);
}

//Writing a Step Block with an array of all Dancer Blocks

void savestep(FILE*save, Dancer tab[], int dancer_tab_size, int n, int j){
    int i;
    if (tab == NULL){
	    puts("save: no tab");
        exit(1); 
    }
    if (dancer_tab_size <=0){
		puts("save: taille tab<=0");
        exit(1); 
    }

    fprintf(save, "     {\n         \"stepID\": %d \n", j);
    fprintf(save, "         \"nbDancer\": %d \n", dancer_tab_size);
    fprintf(save, "         \"dancerList\":[\n");
    for(i = 0 ; i < dancer_tab_size-1 ; i++){
        savedancer(save, tab, i);
        fprintf(save,",\n");
    }
    savedancer(save, tab, i);
    fprintf(save, "\n          ]\n     }");

    // dancer_tab_size-1 so there is no comma after the last Dancer Block.


}






//Writes the first line of the Save File.


void createsave(FILE* save, int n, int minpogo, int minclassic){
    
    
    fprintf(save, "{\n \"classicMinSpeed\": %d \n", minclassic);
    fprintf(save, " \"pogoMinSpeed\": %d \n", minpogo);
    fprintf(save, " \"nbSteps\": %d \n", n);
    fprintf(save, " \"step\":[ \n");
    
    
    
    
    
    
    
    
    
    
    
     
}
