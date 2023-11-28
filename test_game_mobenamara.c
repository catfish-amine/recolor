//Mohamed Amine Ben Amara
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"
#include "game_io.h"


bool test_game_restart(){
  
    color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    game g = game_new(cell,12);
    game g2 = game_new(cell,12);
    
    game_set_max_moves(g2,12);
    int c2= '0';
    game_play_one_move(g2, c2-'0');
    
    game_restart(g2);

    if (g2== NULL){
    return false;}

    if (game_nb_moves_max(g2)!=12)
    {
    game_delete(g);
    game_delete(g2);
    return false;}

    if (game_nb_moves_cur(g2)!=0) {
    game_delete(g);
    game_delete(g2);
    return false;}


    bool ok=true;
    int i=0;
    int j=0;
         while(ok && j<12)
    {
        while ((i < 12) && ok) { 
        ok=(game_cell_current_color(g2,i,j)==game_cell_current_color(g,i,j));
        i++ ;
        }

        i=0;
        j++;
    }
    if (ok==false)
     {
    game_delete(g);
    game_delete(g2);
    return false;}

    game_delete(g);
    game_delete(g2);
    return true;
}

bool test_game_is_over(){
   color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    game g = game_new(cell,12);
    game_set_max_moves(g,12);
    bool ok = game_is_over(g);
    if ((g== NULL) || ( ok )){
    game_delete(g);
    return false;}

    int tab[12] = {'3','1','3','1','0','3','1','0','1','3','2'};

    for (int i=0 ; i< 11 ; i++)
    {
    int c = tab[i];
    game_play_one_move(g, c-'0');
    if (game_is_over(g)) {
      game_delete(g);
      return false;
    }
    }
    int c2= '0';
    game_play_one_move(g, c2-'0');
    if (game_is_over(g)==false) {
    game_delete(g);
    return false;}

    int c3= '1';
    game_play_one_move(g, c3-'0');

    if (game_is_over(g)) {
    game_delete(g);
    return false;}


    game_delete(g);
    return true;
}

bool test_game_delete(){
 
    color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    game g = game_new(cell,12);
    if (g== NULL){
    return false;}

    game_delete(g);

     return true;
}

bool test_game_save(){

    color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    game g2 = game_new(cell,12);
    game_save(g2,"test_game_save.rec");
    game g1 = game_load("test_game_save.rec");  

    if ( game_height(g1)!=game_height(g2)) return false;
    if ( game_nb_moves_cur(g1)!=game_nb_moves_cur(g2)) return false;
    if ( game_nb_moves_max(g1)!=game_nb_moves_max(g2)) return false;
    if ( game_width(g1)!=game_width(g2)) return false;
    if ( game_is_wrapping(g1)!=game_is_wrapping(g2)) return false;
    for (int i = 0 ; i < game_height(g1) ; i++)
      {
        for (int j= 0 ; j < game_width(g1) ; j++)
        {
          if (game_cell_current_color(g1,j,i)!=game_cell_current_color(g2,j,i)) return false;
        }
      }

    return true;

}

bool test_game_load(){

    game g1 = game_load("default_game.rec");    
    color cell[]={0,0,0,2,0,2,1,0,1,0,3,0,0,3,3,1,1,1,1,3,2,0,1,0,1,0,1,2,3,2,3,2,0,3,3,2,2,3,1,0,3,2,1,1,1,2,2,0,2,1,2,3,3,3,3,2,0,1,0,0,0,3,3,0,1,1,2,3,3,2,1,3,1,1,2,2,2,0,0,1,3,1,1,2,1,3,1,3,1,0,1,0,1,3,3,3,0,3,0,1,0,0,2,1,1,1,3,0,1,3,1,0,0,0,3,2,3,1,0,0,1,3,3,1,1,2,2,3,2,0,0,2,2,0,2,3,0,1,1,1,2,3,0,1};
    game g2 = game_new(cell,12);
    if ( game_height(g1)!=game_height(g2)) return false;
    if ( game_nb_moves_cur(g1)!=game_nb_moves_cur(g2)) return false;
    if ( game_nb_moves_max(g1)!=game_nb_moves_max(g2)) return false;
    if ( game_width(g1)!=game_width(g2)) return false;
    if ( game_is_wrapping(g1)!=game_is_wrapping(g2)) return false;
    for (int i = 0 ; i < game_height(g1) ; i++)
      {
        for (int j= 0 ; j < game_width(g1) ; j++)
        {
          if (game_cell_current_color(g1,j,i)!=game_cell_current_color(g2,j,i)) return false;
        }
      }

    return true;
}



void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]) {
      if (argc == 1) usage(argc, argv);

  // start test
  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
  bool ok = false;
  if (strcmp("game_restart", argv[1]) == 0)
    ok = test_game_restart();
  else if (strcmp("game_is_over", argv[1]) == 0)
    ok = test_game_is_over();
  else if (strcmp("game_delete", argv[1]) == 0)
    ok = test_game_delete();
  else if (strcmp("game_save", argv[1]) == 0)
    ok = test_game_save();
  else if (strcmp("game_load", argv[1]) == 0)
    ok = test_game_load();

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
    return EXIT_FAILURE;
  }
}
