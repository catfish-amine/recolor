#include "game.h"
#include "game_rand.h"
#include "game_io.h"
#include <stdlib.h>



game Box(int argc, char *arg[]){
        game g;
        char *na = arg[1];
        int n1 = atoi(na);
        char *nb=arg[2];
        int n2=atoi(nb);
        char *nc=arg[3];
        int n3=atoi(nc);
        if (argc==4) g = game_random_ext(n1,n2,false,4,n3);
        else if (argc==5 || argc==6){
            char *nd=arg[4];
            int n4=atoi(nd);
            if (argc==5) g = game_random_ext(n1,n2,false,n4,n3);
            else g = game_random_ext(n1,n2,*arg[5]=='S',n4,n3);
        }
        return g ;
}