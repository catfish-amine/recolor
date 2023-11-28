#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts     
#include <stdio.h>
#include <stdbool.h>
#include "game_io.h"
#include "model.h"
#include "game.h"  
#include "game_box.h"
/* **************************************************************** */
     
int main(int argc, char * argv[])
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
  else if (argc == 1)   g = game_load(argv[1]);
  else if (argc == 4 || argc==5 || argc==6){
        g=Box(argc,argv);
  }
#endif

  /* initialize SDL2 and some extensions */
  if(SDL_Init(SDL_INIT_VIDEO) != 0) ERROR("Error: SDL_Init VIDEO (%s)", SDL_GetError());  
  if(IMG_Init(IMG_INIT_PNG & IMG_INIT_PNG) != IMG_INIT_PNG) ERROR("Error: IMG_Init PNG (%s)", SDL_GetError());  
  if(TTF_Init() != 0) ERROR("Error: TTF_Init (%s)", SDL_GetError());  
     
  /* create window and renderer */
  int SH=SCREEN_HEIGHT;
  int SW=SCREEN_WIDTH;
  while (SW % game_width(g)!= 0)
  {

    SW++;
  }

  while ( (SH-(SH/5)) % game_height(g)!= 0)
  {

    SH++;
  }

  SDL_Window * win = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    				      SW, SH, SDL_WINDOW_MINIMIZED );
  if(!win) ERROR("Error: SDL_CreateWindow (%s)", SDL_GetError());  
  SDL_Renderer * ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!ren) ERROR("Error: SDL_CreateRenderer (%s)", SDL_GetError());  
     
  /* initialize your environment */
  Env * env = init(win, ren, argc, argv);
     
  /* main render loop */
  SDL_Event e;
  bool quit = false;
  game g1=game_copy(g);
  while (!quit) {
     
    /* manage events */
    while (SDL_PollEvent(&e)) {
      /* process your events */
      quit = process(win, ren, env, &e,g,g1);
      if(quit) break;
    }
     
    /* background in gray */
    SDL_SetRenderDrawColor(ren, 0xA0, 0xA0, 0xA0, 0xFF); 
    SDL_RenderClear(ren);
     
    /* render all what you want */    
    render(win, ren, env , g); 
    SDL_RenderPresent(ren);
    SDL_Delay(DELAY);
  }
  
  /* clean your environment */
  clean(win, ren, env, g,g1);
  
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  IMG_Quit();
  TTF_Quit();  
  SDL_Quit();
     
  return EXIT_SUCCESS;
}

