#ifndef SOLVER_H
#define SOLVER_H
#include <stdbool.h>

typedef struct s_sol *solution;
typedef struct s_all_sol *all_solutions;




int solve_nb_solutions(game g);


solution solve_find_min(game g);

solution solve_find_one (game g);

uint solve_size(solution s);

uint solve_pos(solution s , uint i);

void solve_free(solution s);


bool solve_won(solution s);

#endif