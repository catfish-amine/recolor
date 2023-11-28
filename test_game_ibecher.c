#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_io.h"
#include "game.c"

bool test_game_new(void){

     color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    uint nb_moves_max=12;
    uint width = 5 ;
    uint height =6 ;
     game g =game_new(cell,nb_moves_max);
    if (g==NULL) {
	    game_delete(g);
	    return false ;
    }
    if (g->grille==NULL) {
	    game_delete(g);
	    return false ;
    }
    if (g->start==NULL) {
	    game_delete(g);
	    return false ;
    }
    if (game_width(g)!=width || game_height(g)!=height  || (g->width)*(g->height)!=g->size ) {
	    game_delete(g);
	    return false ;
    }
    if (game_nb_moves_max(g)!=nb_moves_max ){
	    game_delete(g);
	    return false ;
    }
    if (game_nb_moves_cur(g)!=0){
	    game_delete(g);    
	    return false ;
    }
   int y=0 ;
    for (uint  i= 0; i < game_height(g) ; i++){
      for (uint  j= 0; j < game_width(g); j++){
              if (game_cell_current_color(g,j,i)!= cell[y]) {
	            game_delete(g);
	            return false ;
	          }
	    y++;
      }
    }
    game_delete(g);
    return true ;  
}


bool test_game_new_empty(void){

   game g = game_new_empty();
  color c = 0;
 
  if (g == NULL ) {
    fprintf(stderr, "Error: invalid game_new_empty!\n");
    return false;
  }
  if (g->grille==NULL) {
	    game_delete(g);
	    return false ;
    }
    if (g->start==NULL) {
	    game_delete(g);
	    return false ;
    }

  for ( int x = 0; x < game_height(g) ; x++) {
    for ( int y = 0; y < game_width(g) ; y++) {
      if (game_cell_current_color(g, x, y) != c) {
        fprintf(stderr, "Error: invalid game_new_empty!\n");
        return false;
      }
    }
  }
return true ;
}

bool test_game_set_cell_init(void) {
  color cell[] = {10,20,30,40,50,60,70,80,90};
  game g = game_new(cell, 5);
  if (g == NULL ) {
    fprintf(stderr, "Error: invalid game_new!\n");
    return false;
  }
  game_set_cell_init(g, 2, 2, 2);
  if (game_cell_current_color(g, 0, 0) != 2) {
    fprintf(stderr, "Error: invalid game_set_cell_init!\n");
    return false;
  }
  game_set_cell_init(g, 2, 0, 6);
  if(game_cell_current_color(g, 2, 0) == 6){
    fprintf(stderr, "Error: invalid game_set_cell_init!\n");
    return false;
  }
  game_delete(g);
  return true;
}
bool test_game_height(){
 bool test = true;
  int height = 10;
  game g = game_new_empty_ext(10, height, true);
  if (height != game_height(g)) {
    printf("Error on value of height");
    test = false;
  }
  game_delete(g);
  return test;
}
bool test_game_width(){
 bool test = true;
  int width = 5;
  game g = game_new_empty_ext(width, 10, true);

  if (width != game_width(g)) {
    printf("Error on value of width");
    test = false;
  }
  game_delete(g);
  return test;
}

bool test_game_is_wrapping() {
  color cell[] = {10,20,30,40,50,60,70,80,90};
  game g = game_new_ext(3, 3, cell, 4, true);
  
  if (game_is_wrapping(g) != true) {
    fprintf(stderr, "Error on game_is_wrapping !\n");
    return false;
  }
  game_delete(g);
  return true;
}

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  if (argc == 1) usage(argc, argv);
 
  
  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
  bool ok = false;
  if (strcmp("game_new", argv[1]) == 0)
    ok =test_game_new();
  else if (strcmp("game_new_empty", argv[1]) == 0)
    ok = test_game_new_empty();
  else if (strcmp("game_set_cell_init", argv[1]) == 0)
    ok =  test_game_set_cell_init();
  else if (strcmp("game_height", argv[1]) == 0)
    ok =  test_game_height();
  else if (strcmp("game_width", argv[1]) == 0)
    ok =  test_game_width();
  else if (strcmp("game_is_wrapping", argv[1]) == 0)
    ok =  test_game_is_wrapping();
  else {
    fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
    exit(EXIT_FAILURE);
  }
    // print test result
  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
    return EXIT_SUCCESS;
  }
}
