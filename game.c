#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "game_io.h"


struct game_s {
	uint nb_moves_max;
	uint nb_moves_cur;
	uint nb_colors ;	
	color* grille;
	color* start;
	uint width;
  	uint height;
	bool wrapping;
	uint size;
};

game game_new(color *cells, uint nb_moves_max) {
	game g=game_new_ext(12,12,cells,nb_moves_max,false);
    return g;
}

game game_new_empty() {
    game g = game_new_empty_ext(12,12,false);
    return g;
}

game game_new_ext( uint width, uint height, color *cells, uint nb_moves_max, bool wrap){
	if (cells==NULL){
		fprintf(stderr,"Error!");
		exit(EXIT_FAILURE);
	}
	game g = (game)malloc(sizeof(struct game_s));
	if (g==NULL){
		fprintf(stderr,"Error!");
		exit(EXIT_FAILURE);
	}
	g-> nb_moves_max = nb_moves_max;
	g-> nb_moves_cur = 0;
	g->width=width;
	g->height=height;
	g->size=width*height;
	g->wrapping=wrap;
	g->grille = (color *)malloc(width * height * sizeof(color));
	g->start = (color *)malloc(width * height * sizeof(color));
	for (int i=0 ; i<width*height ; i++)
	{
		g->grille[i]= cells[i];
		g->start[i]= cells[i];

	}
	g->nb_colors=nb_colors(g);
	return g;
}

game game_new_empty_ext(uint width, uint height, bool wrap){

	game g = (game)malloc(sizeof(struct game_s));
	if (g==NULL){
		fprintf(stderr,"Error!");
		exit(EXIT_FAILURE);
	}
	g-> nb_moves_max = 0;
	g-> nb_moves_cur = 0;
	g-> nb_colors = 1 ;
	g->width=width;
	g->height=height;
	g->size=height*width;
	g->wrapping=wrap;
	
	g->grille = (color *)malloc(width * height * sizeof(color));
	if (g->grille==NULL){
		fprintf(stderr,"Error!");
		exit(EXIT_FAILURE);
	}
	g->start = (color *)malloc(width * height * sizeof(color));
	if (g->start==NULL){
		fprintf(stderr,"Error!");
		exit(EXIT_FAILURE);
	}

	for (int i=0 ; i<width*height ; i++ ){
		g->grille[i]= 0;
		g->start[i]= 0;

	}
	return g;
}

void game_set_max_moves(game g, uint nb_max_moves){
	if (g==NULL || g->grille==NULL || g->nb_moves_max<0) exit(EXIT_FAILURE);
	g->nb_moves_max = nb_max_moves;	
}

uint game_nb_moves_max(cgame g)
{
	if (g==NULL || g->grille==NULL ) exit(EXIT_FAILURE);
	return 	g->nb_moves_max ;
}

color game_cell_current_color(cgame g, uint x, uint y){
	if (g==NULL || g->grille==NULL || x>=g->width || y>=g->height) exit(EXIT_FAILURE);
	return g->grille[(y*g->width)+x];
}

uint game_nb_moves_cur(cgame g){
	if (g==NULL) exit(EXIT_FAILURE);
	return g->nb_moves_cur;
}

void game_restart(game g){
	if(g == NULL){
    	fprintf(stderr, "Not enough memory !\n");
		exit(EXIT_FAILURE);
  	}
	g->nb_moves_cur = 0;
  	for(uint i = 0; i < g->size ; i++){
    	g->grille[i] = g->start[i];
	}

}

void game_delete(game g) {
	if (g->grille != NULL) free(g->grille);
	if (g->start != NULL) free(g->start);
	if(g != NULL) free(g);

}

void game_set_cell_init(game g, uint x, uint y, color c){
	if(g==NULL || x>=g->width || y>=g->height ) exit(EXIT_FAILURE);
	g->grille[(y*g->width)+x] = c;
}


bool static NextToTrue (bool* mat , int i, int x, int y , int height, int width , bool wrap)
{
	if (wrap==false)
	{
		if (y==0) 
		{

					if ( x == width-1 ) {
								if ( (mat[i-1]==true) || (mat[i+width]==true) ){
											return true;
												}
										else return false;
											}
					else {
								if ( (mat[i-1]==true) || (mat[i+width]==true) || (mat[i+1]==true) ){
											return true;
												}
												else return false;
											}
		}



		else if ((y < height-1 ) && (y > 0)) 
		{

						if(x==0) {
												if ( (mat[i+1]==true) || (mat[i-width]==true) || (mat[i+width]==true) ){
														return true;
													}
            						else return false;
												}
					 else if(x==width-1) {
												if ( (mat[i-1]==true) || (mat[i-width]==true) || (mat[i+width]==true) ){
												return true;
													}
 												else return false;
												}
					  else {
								if ( (mat[i+1]==true) || (mat[i-1]==true) || (mat[i-width]==true) || (mat[i+width]==true) ){
												return true;
													}
									else return false;
												}

		}

		else
		{
					if(x==0) {
									if ( (mat[i+1]==true) || (mat[i-width]==true) ){
												return true;
												}
									else return false;
											}
				  else if(x==width-1) {
												if ( (mat[i-1]==true) || (mat[i-width]==true) ){
													return true;
												}
													else return false;
												}
					else {
									if ( (mat[i+1]==true) || (mat[i-1]==true) || (mat[i-width]==true) ){
										return true;
								}
								  else return false;
							}
		}
	}
	/* case when wrapping option is ON */
	else
	{
		if (y==0) 
		{

					if ( x == width-1 ) return true;
					else {
								if ( (mat[i-1]==true) || (mat[i+width]==true) || (mat[i+1]==true) || (mat[i+(width*(height-1))]==true)  ) return true;
								else return false;
						}
		}



		else if ((y < height-1 ) && (y > 0)) 
		{

						if(x==0) {
												if ( (mat[i+1]==true) || (mat[i-width]==true) || (mat[i+width]==true) || (mat[i+width-1]==true)){
														return true;
													}
            						else return false;
												}
					 else if(x==width-1) {
												if ( (mat[i-1]==true) || (mat[i-width]==true) || (mat[i+width]==true) || (mat[i-width+1]==true) ){
												return true;
													}
 												else return false;
												}
					  else {
								if ( (mat[i+1]==true) || (mat[i-1]==true) || (mat[i-width]==true) || (mat[i+width]==true) ){
												return true;
													}
									else return false;
												}

		}

		else
		{
					if(x==0) return true;

				  else if(x==width-1) {
												if ( (mat[i-1]==true) || (mat[i-width]==true) || (mat[i-width+1]==true) || (mat[i-(width*(height-1))]==true) ){
													return true;
												}
													else return false;
												}
					else {
									if ( (mat[i+1]==true) || (mat[i-1]==true) || (mat[i-width]==true) || (mat[i-(width*(height-1))]==true) ){
										return true;
								}
								  else return false;
							}
		}
	}


}


void game_play_one_move(game g, color c){

	/*Generate a boolean table*/
	bool mat[g->size];
	for (int i = 0; i <g->size; i++){
		mat[i]=false ;
	}
	mat[0]=true;
	/******END********/

bool change=true;
color c_int=g->grille[0];
while (change){
		change=false;
		for (int i = 1; i <g->size; i++)
		{
			if (mat[i]==false)
				{	int y = i/g->width;
					int x = i -(y*g->width);
					if ( (g->grille[i]==c_int) && (NextToTrue(mat,i,x,y,g->height,g->width,g->wrapping)>0) ) {
				change = true;
				mat[i]=true;
			}
			}
}
}	
	/*Generate the new Grille*/
	for (int i = 0; i <g->size; i++){
		if (mat[i]==true) g->grille[i]=c;
	}
	/******END********/

	g->nb_moves_cur = g->nb_moves_cur+1; 

}
/* play one move function */

game game_copy(cgame g)
	{
		if(g == NULL){
				fprintf(stderr, "Not enough memory !\n");
				exit(EXIT_FAILURE);

			}
			game g2 = game_new_ext(g->width,g->height,g->grille,g->nb_moves_max,g->wrapping);

		return g2;
	}
bool game_is_over(cgame g){
	if(g == NULL || g->grille == NULL ){
    	fprintf(stderr, "memory Problem !\n");
    	exit(EXIT_FAILURE);
 	}
  	if(g->nb_moves_cur > g->nb_moves_max){
    	return false;
 	}
 	color init_color=game_cell_current_color(g,0,0);

	for (int i =1 ; i< g->size ; i++)
    {
		if (g->grille[i]!=init_color) return false;
    }
    return true;

}
	uint game_height(cgame g) { 
		if (g==NULL) exit(EXIT_FAILURE);	
		return g->height; 
	}

uint game_width(cgame g) { 
	if (g==NULL) exit(EXIT_FAILURE);
	return g->width; 
}


bool game_is_wrapping(cgame g){
		if (g == NULL ) {
    exit(EXIT_FAILURE);}

  return g->wrapping;
}

uint nb_colors(cgame g){
	color mx_color = g->start[0];
	for(int i=1 ; i<(g->width*g->height) ; i++){
		if (g->start[i]>mx_color) 
		mx_color = g->start[i];
		
	}
	return mx_color + 1;
}
uint game_get_nb_colors (cgame g) { 
	if (g==NULL) exit(EXIT_FAILURE);
	return g->nb_colors; 
}





