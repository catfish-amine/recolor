#include <stdio.h>
#include "game.h"
#include "game_io.h"

game game_load(char *filename){

FILE* f=NULL;
f = fopen(filename,"r");
char wrap;
uint w,h,max,num;
game g=NULL;

fscanf(f, "%u %u %u %c", &w, &h, &max, &wrap);
bool wrapbool = (wrap == 'S');

int n=0;
color cell[w*h];
while (!feof(f))
{  fscanf(f,"%u", &num);
   cell[n]=num;
   n++;}
g =game_new_ext(w,h,cell,max,wrapbool);
fclose(f);

return g;
}

void game_save(cgame g, char *filename){
    FILE* f=NULL;
f = fopen(filename,"w");
char c;
if (game_is_wrapping(g)) c='S'; else c='N';
fprintf(f, "%u %u %u %c\n",game_width(g) , game_height(g), game_nb_moves_max(g), c);

	for (int i=0 ; i<game_height(g) ; i++)
	{
	    for (int j=0 ; j<game_width(g); j++)
	    {
        if (j==(game_width(g)-1)) 
        fprintf(f,"%u", game_cell_current_color(g,j,i));
		else
		{
			fprintf(f,"%u ", game_cell_current_color(g,j,i));
		}
		

	    }
        fprintf(f,"\n");
	}
fclose(f);

}
