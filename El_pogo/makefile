pogo : main.o pogo_scanf_file.o print_dance_floor_file.o pogo_math_file.o random_placement_file.o displacement_and_collision_file.o json_save_fonctions_file.o
	gcc -lm main.o pogo_scanf_file.o print_dance_floor_file.o pogo_math_file.o random_placement_file.o displacement_and_collision_file.o json_save_fonctions_file.o -o pogo 


pogo_scanf_file.o : pogo_scanf_file.c 
	gcc -c pogo_scanf_file.c -o pogo_scanf_file.o 
	
print_dance_floor_file.o : print_dance_floor_file.c 
	gcc -c print_dance_floor_file.c -o print_dance_floor_file.o

pogo_math_file.o : pogo_math_file.c 
	gcc -c -lm pogo_math_file.c -o pogo_math_file.o
	
random_placement_file.o : random_placement_file.c 
	gcc -c -lm random_placement_file.c -o random_placement_file.o
	
displacement_and_collision_file.o : displacement_and_collision_file.c 
	gcc -c -lm displacement_and_collision_file.c -o displacement_and_collision_file.o
	
json_save_fonctions_file.o : json_save_fonctions_file.c 
	gcc -c -lm json_save_fonctions_file.c -o json_save_fonctions_file.o

main.o : main.c
	gcc -c -lm main.c -o main.o 
