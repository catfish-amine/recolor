//Oussama osmani
//Marouane OURICHE
//Mohamed Amine Ben Amara
//Iheb Becher

#include "game.h"
#include "game_io.h"
#include "solver.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

   if (argc!=4) 
    {
        printf("%s","WRONG ARGUMENTS");
        return EXIT_SUCCESS;
    }
    else
    {

        game g = game_load(argv[2]);
            	if (g == NULL ) exit(EXIT_FAILURE);
        FILE* f=NULL;
        char *filename = argv[3];
        if (strcmp(argv[1],"NB_SOL") ==0) strcat(filename, ".nbsol");
        else strcat(filename, ".sol");

        f = fopen(filename,"w");
        		if (f == NULL ) exit(EXIT_FAILURE);


            if (strcmp(argv[1],"FIND_ONE") ==0) 
            {
                    solution sol = solve_find_one(g);
                  if (solve_won(sol))
                    {
                        for (int i =0 ; i < solve_size(sol)-1; i++)
                        {
                            fprintf(f,"%d ",solve_pos(sol,i));
                        }
                        int i= solve_size(sol)-1;
                        fprintf(f,"%d",solve_pos(sol,i));
                   }
                    else fprintf(f,"%s","NO SOLUTION");
                    solve_free(sol);
            }
                
            

            else if (strcmp(argv[1],"NB_SOL") ==0) fprintf(f,"%d",solve_nb_solutions(g));


            else if (strcmp(argv[1],"FIND_MIN") ==0)
            {                
                    solution sol = solve_find_min(g);
                    if (solve_won(sol))
                    {
                        for (int i =0 ; i < solve_size(sol)-1; i++)
                        {
                            fprintf(f,"%d ",solve_pos(sol,i));
                        }
                        int i= solve_size(sol)-1;
                        fprintf(f,"%d",solve_pos(sol,i));
                    }
                    else fprintf(f,"%s","NO SOLUTION");
                    solve_free(sol);
            
            }
    
        fclose(f);
        game_delete(g);
        return EXIT_SUCCESS;
    }
}
