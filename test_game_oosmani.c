#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#include "game.h"

color cells[] = {
    2, 1, 2, 3, 3, 3, 3, 2, 0, 1, 0, 0, 0, 3, 3, 0, 1, 1, 2, 3, 3, 2, 1, 3,
    1, 1, 2, 2, 2, 0, 0, 1, 3, 1, 1, 2, 1, 3, 1, 3, 1, 0, 1, 0, 1, 3, 3, 3,
    0, 3, 0, 1, 0, 0, 2, 1, 1, 1, 3, 0, 1, 3, 1, 0, 0, 0, 3, 2, 3, 1, 0, 0,
    1, 3, 3, 1, 1, 2, 2, 3, 2, 0, 0, 2, 2, 0, 2, 3, 0, 1, 1, 1, 2, 3, 0, 1};



/**********tet_game_copy********/
bool test_game_copy() {

  game g = game_new_empty();
  if (g == NULL) {
    fprintf(stderr, "Error : invalid game_copy\n");
    game_delete(g);
    return false;
  }
  game new_g = game_copy(g);
  if (new_g == NULL) {
    fprintf(stderr, "Error : invalid game_copy\n");
    game_delete(new_g);
    return false;
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++){
      if (game_cell_current_color(g, i, j) != game_cell_current_color(new_g, i, j) ) {
        fprintf(stderr, "Error : invalid game");
        game_delete(g);
        game_delete(new_g);
        return false;
      }
    }
  }
  game_delete(g);
  game_delete(new_g);

  return true;
}



/**********test_game_play_one_move*********/


bool test_game_play_one_move() {
  game g = game_new_empty();

  game_play_one_move(g, 1);
  if (game_nb_moves_cur(g) != 1){
    fprintf(stderr, "Error : invalid game\n");
    game_delete(g);
    return false;
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++){
      if (game_cell_current_color(g, i, j) != 1){
        fprintf(stderr, "Error : invalid game\n");
        game_delete(g);
      }
    }
  }
  game_delete(g);
  return true;
}


/*********nb_move_current********/


bool test_game_nb_moves_cur() {
  game g = game_new(cells, 10);

  uint c = game_nb_moves_cur(g);
  if (c > SIZE * SIZE) {
    fprintf(stderr, "Error : invalid queue!\n");
    game_delete(g);
    return false;
  }
  if (game_nb_moves_cur(g) > game_nb_moves_max(g) && game_is_over(g)) {
    fprintf(stderr, "Error game_nb_move_cur");
    game_delete(g);
    return false;
  }
  game g2 = game_new_empty();
  if (game_nb_moves_cur(g2) != 0) {
    game_delete(g2);
    return false;
  }
  
  game_delete(g);
  game_delete(g2);

  return true;
}



/*************test_game_new_ext************/




bool test_game_new_ext() {
  int heigth = rand() % 15 + 1;
  int width = rand() % 15 + 1;
  uint nb_moves_max = rand() % 15 + 1;
  bool wrapping = true;
  game g = game_new_ext(width, heigth, cells, nb_moves_max, wrapping);
  if (g == NULL) {
    fprintf(stderr, "Error : invalid game_new_ext\n");
    game_delete(g);
    return false;
  }
  if (game_width(g) != width || game_height(g) != heigth ||
      game_nb_moves_max(g) != nb_moves_max || game_is_wrapping(g) != wrapping) {
    fprintf(stderr, "Error : invalid game_new_ext\n");
    game_delete(g);
    return false;
  }
  color cells1[2 * 2] = {0, 1, 2, 3};
  game g1 = game_new_ext(2, 2, cells1, 4, true);
  cgame cg = g1;
  if (g1 == NULL || cg == NULL) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    return false;
  }
  if (game_is_wrapping(cg) != game_is_wrapping(g1)) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    game_delete(g1);
    return false;
  }
  if (game_nb_moves_max(cg) != 4) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    game_delete(g1);
    return false;
  }
  if (game_nb_moves_cur(cg) != 0) {
    fprintf(stderr, "Error: invalid game_new_ext1!\n");
    game_delete(g1);
    return false;
  }
  color c = 0;
  if (game_cell_current_color(cg, 0, 0) != c) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    game_delete(g1);
    return false;
  }
  c = 1;
  if (game_cell_current_color(cg, 1, 0) != c) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    game_delete(g1);
    return false;
  }
  c = 2;
  if (game_cell_current_color(cg, 2, 0) != c) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    return false;
  }
  c = 3;
  if (game_cell_current_color(cg, 3, 0) != c) {
    fprintf(stderr, "Error: invalid game_new_ext!\n");
    game_delete(g1);
    return false;
  }
  game_play_one_move(g1, c);
  cg = g1;
  if (game_nb_moves_cur(cg) != 1) {
    fprintf(stderr, "Error: invalid game_new_ext2!\n");
    game_delete(g1);
    return false;
  }
  if (game_cell_current_color(cg, 0, 0) != c) {
    fprintf(stderr, "Error: invalid game_new_ext3!\n");
    game_delete(g1);
    return false;
  }

  return true;
}

/*********** USAGE ***********/

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}


/* ********** MAIN ********** */

int main(int argc, char *argv[]) {
  if (argc == 1) usage(argc, argv);

  //start test

  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
  bool ok = false;
  if (strcmp("game_nb_moves_cur", argv[1]) == 0)
    ok = test_game_nb_moves_cur();
  else if (strcmp("game_play_one_move", argv[1]) == 0)
    ok = test_game_play_one_move();
  else if (strcmp("game_copy", argv[1]) == 0)
    ok = test_game_copy();
  else if (strcmp("game_new_ext", argv[1]) == 0)
    ok = test_game_new_ext();
  else {
    fprintf(stderr, "Error: test \"%s\" not found!\n\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  //print test result

  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
    return EXIT_FAILURE;
  }
}
