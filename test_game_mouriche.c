#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "game.h"


color cells[] = {
    0, 0, 0, 2, 0, 2, 1, 0, 1, 0, 3, 0, 0, 3, 3, 1, 1, 1, 1, 3, 2, 0, 1, 0,
    1, 0, 1, 2, 3, 2, 3, 2, 0, 3, 3, 2, 2, 3, 1, 0, 3, 2, 1, 1, 1, 2, 2, 0,
    2, 1, 2, 3, 3, 3, 3, 2, 0, 1, 0, 0, 0, 3, 3, 0, 1, 1, 2, 3, 3, 2, 1, 3,
    1, 1, 2, 2, 2, 0, 0, 1, 3, 1, 1, 2, 1, 3, 1, 3, 1, 0, 1, 0, 1, 3, 3, 3,
    0, 3, 0, 1, 0, 0, 2, 1, 1, 1, 3, 0, 1, 3, 1, 0, 0, 0, 3, 2, 3, 1, 0, 0,
    1, 3, 3, 1, 1, 2, 2, 3, 2, 0, 0, 2, 2, 0, 2, 3, 0, 1, 1, 1, 2, 3, 0, 1};

/* ********** TEST SET MAX MOVES ********** */

bool test_game_set_max_moves(void) {
  game g = game_new(cells, 12);
  game_set_max_moves(g, 12);
  if (game_nb_moves_max(g) == 12) {
    game_delete(g);
    return true;
  } else {
    game_delete(g);
    return false;
  }
}

/* ********** TEST NB MOVES MAX *********** **/

bool test_game_nb_moves_max(void) {
  game g = game_new(cells, 15);
  if (game_nb_moves_max(g) == 15) {
    game_delete(g);
    return true;
  } else {
    game_delete(g);
    return false;
  }
}

/* ********** TEST CELL CURRENT COLOR ********** */

bool test_game_cell_current_color(void) {
  game g = game_new(cells, 12);

  if (g == NULL) {
    fprintf(stderr, "Error: invalid queue init!\n"); /* test existence du jeu*/
    game_delete(g);
    return false;
  }

  game_set_cell_init(g, 0, 0,
                     1); /* on initialise la couleur d'une cellule */

  if (game_cell_current_color(g, 0, 0) ==
      1) { /*si la couleur obtenue est identique Ã  la couleur initialisÃ©e
                 alors la fonction retourne la bonne couleur */
    game_delete(g);
    return true;
  } else {
    game_delete(g);
    return false;
  }
}



/*********** TEST GAME NEW EMPTY EXT ***********/

bool test_game_new_empty_ext() {
  bool warpping = true;
  uint height = 6;
  uint width = 9;
  game g = game_new_empty_ext(width, height, warpping);
  if (g == NULL) {
    fprintf(stderr, "Error: game is NULL");
    return false;
  }
  if (game_nb_moves_cur(g) != 0) {
    fprintf(stderr, "Error: game_nb_moves_cur is %u but %d was expected \n",
            game_nb_moves_cur(g), 0);
    game_delete(g);
    return false;
  }
  if (game_nb_moves_max(g) != 0) {
    fprintf(stderr, "Error: game_nb_moves_max is %u but %d was expected \n",
            game_nb_moves_max(g), 0);
    game_delete(g);
    return false;
  }
  game_set_max_moves(g, 20);
  if (game_nb_moves_max(g) != 20) {
    fprintf(stderr, "Error: game_nb_moves_max is %u but %d was expected \n",
            game_nb_moves_max(g), 20);
    game_delete(g);
    return false;
  }
  if (game_is_wrapping(g) != warpping) {
    fprintf(stderr,
            "Error: game_is_wrapping is false but true was expected \n");
    game_delete(g);
    return false;
  }
  if (game_height(g) != height) {
    fprintf(stderr, "Error: game_height is %u but %u was expected \n",
            game_height(g), height);
    game_delete(g);
    return false;
  }
  if (game_width(g) != width) {
    fprintf(stderr, "Error: game_width is %u but %u was expected \n",
            game_width(g), width);
    game_delete(g);
    return false;
  }
  uint x = 0;

  while (x < game_width(g)) {
    uint y = 0;
    while (y < game_height(g)) {
      if (game_cell_current_color(g, x, y) != 0) {
        fprintf(stderr,
                "Error: cell_current_color is %u but %d was expected \n",
                game_cell_current_color(g, x, y), 0);
        game_delete(g);
        return false;
      }
      y++;
    }
    x++;
  }
  game_delete(g);
  return true;
}

/************** USAGE ***************/

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

/* ****** MAIN **** */
int main(int argc, char *argv[]) {
  if (argc == 1) usage(argc, argv);

  // start test
  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);

  bool ok = false;

  if (strcmp("game_set_max_moves", argv[1]) == 0)
    ok = test_game_set_max_moves();

  else if (strcmp("game_nb_moves_max", argv[1]) == 0)
    ok = test_game_nb_moves_max();

  else if (strcmp("game_cell_current_color", argv[1]) == 0)
    ok = test_game_cell_current_color();

  else if (strcmp("test_game_new_empty_ext", argv[1]) == 0)
    ok = test_game_new_empty_ext();

  else {
    fprintf(stderr, "Error: test \"%s\" not found!\n\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  // print test result
  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n\n", argv[1]);
    return EXIT_FAILURE;
  }
}
