#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.h"
#include "game_io.h"
#include "solver.h"

struct s_sol {
	color* res;
    uint size;
	bool won;

};

void find_one(game g,uint n, solution sol , uint nbr_colors_max)
{
	if (game_is_over(g) ) 
    {
        sol->size=n;
        sol->won=true;
    }
    else if (game_nb_moves_max(g)>n )
    {


        for (int i = 0; i<nbr_colors_max;i++)
        {
            if (i!=game_cell_current_color(g,0,0) && sol->won!=true )
            {
                game g2= game_copy(g);
                game_play_one_move(g2,i);
                sol->res[n]=i;
                if (sol->won!=true)
                {
                    find_one(g2,n+1,sol,nbr_colors_max);
                }
                game_delete(g2);
            }

        }
    }
}

solution solve_find_one (game g)
{

    solution sol = malloc( sizeof(color *) + sizeof(uint)+ sizeof(char));
    if ( sol == NULL ){
        exit(EXIT_FAILURE);
    }
    sol->res= malloc( game_nb_moves_max(g)* sizeof(color));
    if ( sol->res == NULL )
    {
        exit(EXIT_FAILURE);
    }
    sol->size=0;
    sol->won=false;
    uint nbr_colors_max= game_get_nb_colors(g);
    find_one(g,0,sol,nbr_colors_max);
    return sol;

}


void solve_free(solution sol)
{
    if (sol==NULL){
        return  ;
    }
    free(sol->res);
    free(sol);
}


void nb_solutions(game g , uint n , uint* p_nb , uint nbr_colors_max)
{

	if (game_is_over(g) ) {
        *p_nb=*p_nb+1;
    }
    else if (game_nb_moves_max(g)>n)

    {

        for (int i = 0; i< nbr_colors_max ;i++)
        {
            if (i!=game_cell_current_color(g,0,0) )
            {
                game g2= game_copy(g);
                game_play_one_move(g2,i);
                nb_solutions(g2,n+1,p_nb,nbr_colors_max);
                game_delete(g2);
            }

        }
    }
}



int solve_nb_solutions(game g)
{
    solution sol = malloc( sizeof(color *) + sizeof(uint)+ sizeof(char));
    if ( sol == NULL ){
        exit(EXIT_FAILURE);
    }
    sol->res= malloc( game_nb_moves_max(g)* sizeof(color));
    if ( sol->res == NULL )
    {
        exit(EXIT_FAILURE);
    }
    uint nbr_colors_max= game_get_nb_colors(g);
    uint nb =0;
    uint * p_nb = &nb;
    nb_solutions(g,0,p_nb,nbr_colors_max);
    solve_free(sol);
    return nb;
}

void find_min(game g,uint n, solution sol , solution min_sol , uint* min_n , uint nbr_colors_max)
{

    if (game_is_over(g) && (n<=*min_n))
    {   
            min_sol->size=n;
            min_sol->won=true;
            *min_n=n;
            for (int i = 0 ;i < n ; i++)
            { 
                min_sol->res[i]=sol->res[i];
            }

    }
    else if (game_nb_moves_max(g)>n)
    {

        for (int i = 0; i<nbr_colors_max;i++)
        {
            if (i!=game_cell_current_color(g,0,0))
            {
                game g2= game_copy(g);
                game_play_one_move(g2,i);
                sol->res[n]=i;
                find_min(g2,n+1,sol,min_sol,min_n,nbr_colors_max);
                game_delete(g2);
            }

        }
    }

}

solution solve_find_min (game g)
{
    solution sol = malloc( sizeof(*sol));
    if ( sol == NULL ){
        exit(EXIT_FAILURE);
    }
    sol->res= malloc( game_nb_moves_max(g)* sizeof(color));
    if ( sol->res == NULL )
    {
        exit(EXIT_FAILURE);
    }
    sol->size=0;
    sol->won=false;

    solution min_sol = malloc( sizeof(*min_sol));
    if ( min_sol == NULL ){
        exit(EXIT_FAILURE);
    }
    min_sol->res= malloc( game_nb_moves_max(g)* sizeof(color));
    if ( min_sol->res == NULL )
    {
        exit(EXIT_FAILURE);
    }
    uint min_n=game_nb_moves_max(g);
    uint *p_min_n = &min_n;
    uint nbr_colors_max= game_get_nb_colors(g);
    min_sol->won=false;
    find_min(g,0,sol,min_sol,p_min_n,nbr_colors_max);
    min_sol->size=min_n;
    solve_free(sol);
    return min_sol;

}

uint solve_size(solution s)
{
    return s->size;
}

color solve_pos(solution s , uint i)
{
    return s->res[i];
}

bool solve_won (solution s )
{
    return s->won;
}
