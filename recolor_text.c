//Oussama osmani
//Marouane OURICHE
//Mohamed Amine Ben Amara
//Iheb Becher

#include "game.h"
#include "game_rand.h"
#include "game_io.h"
#include "game_box.h"
#include <stdlib.h>


void printgame(game g){
    printf("nb coups joués : %u ; nb coups max : %u\n", game_nb_moves_cur(g),game_nb_moves_max(g));
    for (uint y = 0; y < game_height(g); y++){
        for (uint x = 0; x < game_width(g); x++){
            int i = game_cell_current_color(g,x,y);
            if (i < 10) printf("%u", game_cell_current_color(g,x,y));
            else
            {
                char c;
                    switch(i)
                    {
                     case 10:
                     c = 'A';
                     break;

                     case 11:
                     c = 'B';
                     break;
                        case 12:
                      c = 'C';
                      break;

                     case 13:
                        c = 'D';
                        break;
                    case 14:
                       c = 'E';
                       break;
                    case 15:
                        c = 'F';
                        break;

                     }
            printf("%c",c);
        }
        }
        printf("\n");
    }

}

int main(int argc, char *arg[])
{
    game g;
    
    if (argc == 1)
    {
    color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
   
    g = game_new(cell,12);
    }
#ifdef __ANDROID__
/*RIEN*/
#else
    else if (argc == 2) g = game_load(arg[1]);
    else if (argc == 4 || argc==5 || argc==6){
        g=Box(argc,arg);
    }
#endif
    int c;
    while (game_is_over(g)==false ){ 
        
            printgame(g);
            printf("Jouer un coup: (r ou q ;  r pour redémarrer ou q pour quitter) : \n");
            do {
            c = getchar();
            } while ( (c == '\n') || (c== 32));
        
            if (c == 'r') game_restart(g);
            else if ( c == 'q' || c == EOF){
            game_delete(g);
            printf("DOMMAGE\n");
            return EXIT_SUCCESS;
            }
            else if ( (c>=48 && c<=57) )game_play_one_move(g, c-'0');
            else if (c>=65 && c<=70) game_play_one_move(g, c-55);
    }
    printgame(g);
    printf("BRAVO\n");
    game_delete(g);
    return EXIT_SUCCESS;
}
