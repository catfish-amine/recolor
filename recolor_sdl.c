

#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts     


#include "game_rand.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game_io.h"
#include "game_rand.c"
#include "model.h"
#include "game.h"
#include "game.c"
#define FONT "Arial.ttf"
#define GREEN "green.png"
#define BLUE "blue.png"
#define YELLOW "yellow.png"
#define RED "red.png"
#define DRED "dred.png"
#define PINK "pink.png"
#define BEIGE "beige.png"
#define BROWN "brown.png"
#define LBLUE "lblue.png"
#define LGREEN "lgreen.png"
#define ORANGE "orange.png"
#define PURPLE "purple.png"
#define DORANGE "dorange.png"
#define LYELLOW "lyellow.png"
#define TURQUOISE "turquoise.png"
#define GREY "grey.png"
#define BACKGROUND "background2.png"
#define RESTART "restar.png"
#define SOLLUTION "sollution.png"
#define QUIT "quit.png"
#define COMMENCER "commencer.png"
#define BG "bg.jpg"
#define CRE "cre.png"
#define RANDOM "ale.png"
#define UNDO "undo.png"
#define SAVE "save.png"
#define LOAD "load.png"
#define RETOURNE "RETURN.png"
/* **************************************************************** */
 
struct Env_t { 
  SDL_Texture * text;
  SDL_Texture * background;
  SDL_Texture * green;
  SDL_Texture * blue;
  SDL_Texture * yellow;
  SDL_Texture * red;
  bool ok ;
  SDL_Texture * dred;
  SDL_Texture * grey;
  SDL_Texture * pink;
  SDL_Texture * beige;
  SDL_Texture * brown;
  SDL_Texture * lblue;
  SDL_Texture * lgreen;
  SDL_Texture * orange;
  SDL_Texture * purple;
  SDL_Texture * dorange;
  SDL_Texture * lyellow;
  SDL_Texture * turquoise;
  SDL_Texture * bg;
  SDL_Texture * cre;
  int color_x, color_y;
  /* PUT YOUR VARIABLES HERE */
  struct Butt * butt ;
  struct Butt * alea;
  struct Butt * alea2;
  struct Butt * butt2;
  struct Butt * butt3 ;
  struct Butt * save ;
  struct Butt *  charger;
  struct Butt * retourne  ;
}; 
struct Butt { 
  SDL_Texture * Surface;
  uint h;
  uint w;
  uint x;
  uint y;
  /* PUT YOUR VARIABLES HERE */
};
/* **************************************************************** */
     
Env * init(SDL_Window* win, SDL_Renderer* ren, int argc, char* argv[])
{  
  Env * env = malloc(sizeof(struct Env_t));
  env->butt=malloc(sizeof(struct Butt));
  env->butt2=malloc(sizeof(struct Butt));
  env->butt3=malloc(sizeof(struct Butt));
  env->alea=malloc(sizeof(struct Butt));
  env->alea2=malloc(sizeof(struct Butt));
  env->save=malloc(sizeof(struct Butt));
  env->charger=malloc(sizeof(struct Butt));
  env->retourne=malloc(sizeof(struct Butt));
  env->ok=false ;
  /* get current window size */
  int w, h;
  SDL_GetWindowSize(win, &w, &h);

  /* init background texture from PNG image */
  env->background = IMG_LoadTexture(ren, BACKGROUND);
  if(!env->background) ERROR("IMG_LoadTexture: %s\n", BACKGROUND);
  /* init green texture from PNG image */
  env->green = IMG_LoadTexture(ren, GREEN);
  if(!env->green) ERROR("IMG_LoadTexture: %s\n", GREEN);
  /* init blue texture from PNG image */
  env->blue = IMG_LoadTexture(ren, BLUE);
  if(!env->blue) ERROR("IMG_LoadTexture: %s\n", BLUE);
  /* init yellow texture from PNG image */
  env->yellow = IMG_LoadTexture(ren, YELLOW);
  if(!env->yellow) ERROR("IMG_LoadTexture: %s\n", YELLOW);
  /* init red texture from PNG image */
  env->red = IMG_LoadTexture(ren, RED);
  if(!env->red) ERROR("IMG_LoadTexture: %s\n", RED);


    /* init DRED texture from PNG image */
  env->dred = IMG_LoadTexture(ren, DRED);
  if(!env->dred) ERROR("IMG_LoadTexture: %s\n", DRED);
    /* init GREY texture from PNG image */
  env->grey = IMG_LoadTexture(ren, GREY);
  if(!env->grey) ERROR("IMG_LoadTexture: %s\n", GREY);
    /* init green texture from PNG image */
  env->pink = IMG_LoadTexture(ren, PINK);
  if(!env->pink) ERROR("IMG_LoadTexture: %s\n", PINK);
    /* init green texture from PNG image */
  env->beige = IMG_LoadTexture(ren, BEIGE);
  if(!env->beige) ERROR("IMG_LoadTexture: %s\n", BEIGE);
    /* init green texture from PNG image */
  env->brown = IMG_LoadTexture(ren, BROWN);
  if(!env->brown) ERROR("IMG_LoadTexture: %s\n", BROWN);
    /* init green texture from PNG image */
  env->lblue = IMG_LoadTexture(ren, LBLUE);
  if(!env->lblue) ERROR("IMG_LoadTexture: %s\n", LBLUE);
    /* init lgreen texture from PNG image */
  env->lgreen = IMG_LoadTexture(ren, LGREEN);
  if(!env->lgreen) ERROR("IMG_LoadTexture: %s\n", LGREEN);
    /* init green texture from PNG image */
  env->orange = IMG_LoadTexture(ren, ORANGE);
  if(!env->orange) ERROR("IMG_LoadTexture: %s\n", ORANGE);
    /* init green texture from PNG image */
  env->purple = IMG_LoadTexture(ren, PURPLE);
  if(!env->purple) ERROR("IMG_LoadTexture: %s\n", PURPLE);
    /* init green texture from PNG image */
  env->dorange = IMG_LoadTexture(ren, DORANGE);
  if(!env->dorange) ERROR("IMG_LoadTexture: %s\n", DORANGE);
    /* init green texture from PNG image */
  env->lyellow = IMG_LoadTexture(ren, LYELLOW);
  if(!env->lyellow) ERROR("IMG_LoadTexture: %s\n", LYELLOW);
    /* init green texture from PNG image */
  env->turquoise = IMG_LoadTexture(ren, TURQUOISE);
  if(!env->turquoise) ERROR("IMG_LoadTexture: %s\n", TURQUOISE);

  env->butt->Surface = IMG_LoadTexture(ren, RESTART);
  if(!env->butt->Surface) ERROR("IMG_LoadTexture: %s\n", RESTART);

  env->bg = IMG_LoadTexture(ren, BG);
  if(!env->bg) ERROR("IMG_LoadTexture: %s\n", BG);
   
  env->butt2->Surface = IMG_LoadTexture(ren, QUIT);
  if(!env->butt2->Surface) ERROR("IMG_LoadTexture: %s\n", QUIT);
  env->butt3->Surface = IMG_LoadTexture(ren, COMMENCER);
  if(!env->butt3->Surface) ERROR("IMG_LoadTexture: %s\n", COMMENCER);
  
    /* init green texture from PNG image */
  env->cre = IMG_LoadTexture(ren, CRE);
  if(!env->cre) ERROR("IMG_LoadTexture: %s\n", CRE);
  
  env->alea->Surface=IMG_LoadTexture(ren, UNDO);
  if(!env->alea->Surface) ERROR("IMG_LoadTexture UNDO : \n");
  env->alea2->Surface=IMG_LoadTexture(ren, RANDOM);
    if(!env->alea2->Surface) ERROR("IMG_LoadTexturef%s\n",RANDOM);
   env->save->Surface=IMG_LoadTexture(ren, SAVE);
    if(! env->save->Surface) ERROR("IMG_LoadTexture: %s\n", SAVE);
    env->charger->Surface=IMG_LoadTexture(ren, LOAD);
     if(! env->charger->Surface) ERROR("IMG_LoadTexture: %s\n", LOAD);
    env->retourne->Surface=IMG_LoadTexture(ren,RETOURNE);
     if(!env->retourne->Surface) ERROR("IMG_LoadTexture: %s\n", RETOURNE);
  return env;

}
     
/* **************************************************************** */
     
void render(SDL_Window* win, SDL_Renderer* ren, Env * env, game g)
{
  SDL_Rect rect;

  /* get current window size */
  int w, h;
  SDL_GetWindowSize(win, &w, &h);
  /* render color texture */
  int cmp=0 ;
  int g_h=game_height(g);
  int g_w=game_width(g);
  
  if(SDL_GetTicks()<6000){
    
    SDL_Texture * txte = IMG_LoadTexture(ren, "bckg.jpg");;
    SDL_QueryTexture(txte, NULL, NULL, &rect.w, &rect.h);
    rect.w = w;
    rect.h =h;
    rect.x =0; 
    rect.y =0; 
    SDL_RenderCopy(ren, txte, NULL, &rect);
    /////////
    TTF_Font * font = TTF_OpenFont("Arial.ttf", 64); 
  if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  char msgg[128]= "CREATED BY ";
  SDL_Color col = { 0,0,0 };
  SDL_Surface * surf5 = TTF_RenderText_Blended(font,msgg, col);
  
  SDL_Texture * txt2 = SDL_CreateTextureFromSurface(ren, surf5);
    
    if (SDL_GetTicks()>=1500){
    SDL_QueryTexture(txt2, NULL, NULL, &rect.w, &rect.h);
    rect.w = 2*w/3;
    rect.h = h/10;
    rect.x =w/6; 
    rect.y =h/10; 
    SDL_RenderCopy(ren, txt2, NULL, &rect);
    }
    
  /////iheb////
  if(SDL_GetTicks()>2000){
  TTF_Font * font = TTF_OpenFont("Arial.ttf", 64);
  
  SDL_Color color = {0,0,0}; 
  if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  char msg[128]= "BECHER Iheb";
  SDL_Surface * surf1 = TTF_RenderText_Blended(font,msg, color); // blended rendering for ultra nice text
  SDL_Texture * txt1 = SDL_CreateTextureFromSurface(ren, surf1);
  SDL_QueryTexture(txt1, NULL, NULL, &rect.w, &rect.h);
  rect.w = 2*w/3;
  rect.h = h/10;
  rect.x =w/6; 
  rect.y = 2*h/10; 
  SDL_RenderCopy(ren, txt1, NULL, &rect);
  ////////
    if(SDL_GetTicks()>2500){
      char msg1[128]= "OURICHE Marouane";
      surf1 = TTF_RenderText_Blended(font,msg1, color); // blended rendering for ultra nice text
      txt1 = SDL_CreateTextureFromSurface(ren, surf1);
      SDL_QueryTexture(txt1, NULL, NULL, &rect.w, &rect.h);
      rect.w = 2*w/3;rect.h = h/10; rect.x =w/6; rect.y = 3* h/10; 
      SDL_RenderCopy(ren, txt1, NULL, &rect);
      if(SDL_GetTicks()>3000){
        char msg2[128]= "OSMANI Oussama";
        surf1 = TTF_RenderText_Blended(font,msg2, color); // blended rendering for ultra nice text
        txt1 = SDL_CreateTextureFromSurface(ren, surf1);
        SDL_QueryTexture(txt1, NULL, NULL, &rect.w, &rect.h);
        rect.w = 2*w/3;rect.h = h/10; rect.x =w/6; rect.y = 4*h/10; 
        SDL_RenderCopy(ren, txt1, NULL, &rect);
        if(SDL_GetTicks()>3500){
          char msg3[128]= "BENAMARA MOHAMED AMINE";
          surf1 = TTF_RenderText_Blended(font,msg3, color); // blended rendering for ultra nice text
          txt1 = SDL_CreateTextureFromSurface(ren, surf1);
          SDL_QueryTexture(txt1, NULL, NULL, &rect.w, &rect.h);
          rect.w = 2*w/3;rect.h = h/10; rect.x =w/6; rect.y = 5*h/10; 
          SDL_RenderCopy(ren, txt1, NULL, &rect);  
        }
      }
    }
  }
  }
  else{ 
   /* render background texture */
  SDL_RenderCopy(ren, env->background, NULL, NULL); /* stretch it */
  if (env->ok==false){
    SDL_QueryTexture(env->bg, NULL, NULL, &rect.w, &rect.h); 
    rect.y = 0; 
    rect.x = 0;
    rect.w=w ;rect.h=h;
    SDL_RenderCopy(ren, env->bg, NULL, &rect);
  /***description de jeux *///
  TTF_Font * font = TTF_OpenFont("Arial.ttf", 64);
  
  SDL_Color color = { 0,0,0 }; 
  if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  char msg[128]= "Try to get the whole grid to be the same colour with in the given number";
  SDL_Surface * surf = TTF_RenderText_Blended(font,msg, color); // blended rendering for ultra nice text
  SDL_Texture * txt = SDL_CreateTextureFromSurface(ren, surf);
  SDL_QueryTexture(txt, NULL, NULL, &rect.w, &rect.h);
  rect.w = w-w/20;
  rect.h = 20;
  rect.x =w/20; 
  rect.y = h/10+h/5; 
  SDL_RenderCopy(ren, txt, NULL, &rect);
  ///////////
  char msg2[128]= "moves, by repeatedly flood-filling the top left corner in different colours.";
   surf = TTF_RenderText_Blended(font,msg2, color); // blended rendering for ultra nice text
   txt = SDL_CreateTextureFromSurface(ren, surf);
  SDL_QueryTexture(txt, NULL, NULL, &rect.w, &rect.h);
  rect.w = w-w/20;
  rect.h = 20;
  rect.x =w/20; 
  rect.y = h/10+20+h/5; 
  SDL_RenderCopy(ren, txt, NULL, &rect);
  //////
  char msg3[128]= "Click in a square to flood-fill the top left corner with that square's colour.";
  surf = TTF_RenderText_Blended(font,msg3, color); // blended rendering for ultra nice text
  txt = SDL_CreateTextureFromSurface(ren, surf);
  SDL_QueryTexture(txt, NULL, NULL, &rect.w, &rect.h);
  rect.w = w-w/20;
  rect.h = 20;
  rect.x = w/20;
  rect.y = h/10+20+20+h/5; 
  SDL_RenderCopy(ren, txt, NULL, &rect);
  /***button commencer *///
  SDL_QueryTexture(env->butt3->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =h/2-h/20 ;
  rect.x =w/4;
  rect.w =w/2;
  rect.h =h/10;
  env->butt3->x=rect.x;
  env->butt3->y=rect.y;
  env->butt3->h=rect.h;
  env->butt3->w=rect.w;
  SDL_RenderCopy(ren, env->butt3->Surface, NULL, &rect);
/*****B-commencer***/
 //////button_ale/////
 SDL_QueryTexture(env->alea2->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =h/2-h/20+h/10+5 ;
  rect.x =w/4;
  rect.w =w/2;
  rect.h =h/10;
  env->alea2->x=rect.x;
  env->alea2->y=rect.y;
  env->alea2->h=rect.h;
  env->alea2->w=rect.w;
  SDL_RenderCopy(ren, env->alea2->Surface, NULL, &rect);
//////B-ALEA/////
//////button-charger////
#ifdef __ANDROID__
/* rien */
#else
SDL_QueryTexture(env->charger->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =h/2-h/20+h/5+5 ;
  rect.x =w/4;
  rect.w =w/2;
  rect.h =h/10;
  env->charger->x=rect.x;
  env->charger->y=rect.y;
  env->charger->h=rect.h;
  env->charger->w=rect.w;
  SDL_RenderCopy(ren, env->charger->Surface, NULL, &rect);
#endif
 
  }
  else {


  for(int i=h/10; i<h-h/10; i=i+((h-2*(h/10))/g_h)){
    for(int j=0; j< w; j=j+(w/g_w)){
      if(g->grille[cmp] == 1){
        SDL_QueryTexture(env->green, NULL, NULL, &rect.w, &rect.h); 
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->green, NULL, &rect); 
      }

      if(g->grille[cmp] == 2){
        SDL_QueryTexture(env->blue, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->blue, NULL, &rect);
      }
      if(g->grille[cmp] == 3){
        SDL_QueryTexture(env->yellow, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->yellow, NULL, &rect);
      }
      if(g->grille[cmp] == 0){
        SDL_QueryTexture(env->red, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->red, NULL, &rect);
      }

      if(g->grille[cmp] == 4){
        SDL_QueryTexture(env->dred, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->dred, NULL, &rect);
      }
        if(g->grille[cmp] == 15){
        SDL_QueryTexture(env->grey, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->grey, NULL, &rect);
      }
            if(g->grille[cmp] == 5){
        SDL_QueryTexture(env->pink, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->pink, NULL, &rect);
      }
            if(g->grille[cmp] == 6){
        SDL_QueryTexture(env->beige, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->beige, NULL, &rect);
      }
            if(g->grille[cmp] == 7){
        SDL_QueryTexture(env->brown, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->brown, NULL, &rect);
      }
            if(g->grille[cmp] == 8){
        SDL_QueryTexture(env->lblue, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->lblue, NULL, &rect);
      }
            if(g->grille[cmp] == 9){
        SDL_QueryTexture(env->lgreen, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->lgreen, NULL, &rect);
      }
            if(g->grille[cmp] == 10){
        SDL_QueryTexture(env->orange, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->orange, NULL, &rect);
      }
            if(g->grille[cmp] == 11){
        SDL_QueryTexture(env->purple, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->purple, NULL, &rect);
      }
            if(g->grille[cmp] == 12){
        SDL_QueryTexture(env->dorange, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->dorange, NULL, &rect);
      }
            if(g->grille[cmp] == 13){
        SDL_QueryTexture(env->lyellow, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->lyellow, NULL, &rect);
      }
            if(g->grille[cmp] == 14){
        SDL_QueryTexture(env->turquoise, NULL, NULL, &rect.w, &rect.h);
        rect.y = i; 
        rect.x = j;
        SDL_RenderCopy(ren, env->turquoise, NULL, &rect);
      }
      /******HACHAGE-DU-GRILLE*****/
      if (cmp<game_width(g) && cmp>0 ){
        if(/*g->grille[cmp]!=g->grille[cmp+1]&&*/ g->grille[cmp]!=g->grille[cmp-1] ){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE); 
          SDL_RenderDrawLine(ren, j, i, j,i+((h-2*(h/10))/g_h));
        }
        
      }
      else if (cmp%game_width(g)==0 && cmp>0){
        if(  g->grille[cmp]!=g->grille[cmp-g_w] ){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE); 
          SDL_RenderDrawLine(ren, j,i,j+w/g_w,i);
        }
        SDL_RenderDrawLine(ren, j, i, j,i+((h-2*(h/10))/g_h));
      }
      else if ((cmp+1)%game_width(g)==0){
        if(  g->grille[cmp]!=g->grille[cmp-g_w] ){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE); 
          SDL_RenderDrawLine(ren, j,i,j+w/g_w,i);
        }
        if( g->grille[cmp]!=g->grille[cmp-1]){
        SDL_RenderDrawLine(ren, j, i, j,i+((h-2*(h/10))/g_h));
        }
        
      }
      else if(cmp+g_w>g->size){
        if(  g->grille[cmp]!=g->grille[cmp-g_w] ){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE); 
          SDL_RenderDrawLine(ren, j,i,j+w/g_w,i);
        }
        if( g->grille[cmp]!=g->grille[cmp-1]){
        SDL_RenderDrawLine(ren, j, i, j,i+((h-2*(h/10))/g_h));
        }
        
      }
      else{
        if(  g->grille[cmp]!=g->grille[cmp-g_w] ){
          SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE); 
          SDL_RenderDrawLine(ren, j,i,j+w/g_w,i);
        }
        if( g->grille[cmp]!=g->grille[cmp-1]){
        SDL_RenderDrawLine(ren, j, i, j,i+((h-2*(h/10))/g_h));

      }
      }
      /*****h-GRILLE*/
  cmp++;
  }
  }
  int i=h/10 ;
  SDL_RenderDrawLine(ren, 0,i,w,i);
  SDL_RenderDrawLine(ren, 0,i,0,h-i);
  SDL_RenderDrawLine(ren,0,h-i-1,w,h-i-1);
  SDL_RenderDrawLine(ren,w-1,i,w-1,h-i-1);

  SDL_QueryTexture(env->background, NULL, NULL, &rect.w, &rect.h);
  rect.y = h - (h/10);
  rect.x = 0;
  SDL_RenderCopy(ren, env->background, NULL, &rect);
/***button restart*///
  SDL_QueryTexture(env->butt->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y = 0;
  rect.x = 0;
  rect.w = w/4;
  rect.h = h/10;
  env->butt->x=rect.x;
  env->butt->y=rect.y;
  env->butt->h=rect.h;
  env->butt->w=rect.w;
  SDL_RenderCopy(ren, env->butt->Surface, NULL, &rect);

/*****B-R***/


/***button QUIT */
  SDL_QueryTexture(env->butt2->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y = 0;
  rect.x = w-w/4;
  rect.w = w/4;
  rect.h = h/10;
  env->butt2->x=rect.x;
  env->butt2->y=rect.y;
  env->butt2->h=rect.h;
  env->butt2->w=rect.w;
  SDL_RenderCopy(ren, env->butt2->Surface, NULL, &rect);

///////////////////   TEXTE  ///////////////////
TTF_Font * font = TTF_OpenFont("Arial.ttf", 64);
uint nb_moves_cur = game_nb_moves_cur(g);
uint nb_moves_max = game_nb_moves_max(g);
char msg[128]; 
SDL_Color color = { 255,0,0}; 
sprintf(msg,"numbre of current moves: %u/%u",nb_moves_cur,nb_moves_max);
if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
TTF_SetFontStyle(font, TTF_STYLE_BOLD);
SDL_Surface * surf = TTF_RenderText_Blended(font,msg, color); // blended rendering for ultra nice text
env->text = SDL_CreateTextureFromSurface(ren, surf);
SDL_QueryTexture(env->text, NULL, NULL, &rect.w, &rect.h);
  rect.w = w-w/4-7;
  rect.h = h/10-5;
  rect.x = 5;
  rect.y = h-h/10+5; 
  
  SDL_RenderCopy(ren, env->text, NULL, &rect);


   /* render blue texture */
   
  /* PUT YOUR CODE HERE TO RENDER TEXTURES, ... */
  ///////////////// GAME OVER //////////////
  if (game_is_over(g)== true){
      TTF_Font * font = TTF_OpenFont("Arial.ttf", 64);

  SDL_Color color = { 0,0,0 }; 
  if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  SDL_Surface * surf = TTF_RenderText_Blended(font,"BRAVOS!", color); // blended rendering for ultra nice text
  env->text = SDL_CreateTextureFromSurface(ren, surf);
  SDL_QueryTexture(env->text, NULL, NULL, &rect.w, &rect.h);
  rect.w = 200;
  rect.h = 100;
  rect.x = w/2 - rect.w/2; 
  rect.y = h/2 - rect.h/2; 
  SDL_RenderCopy(ren, env->text, NULL, &rect);

  }
  if(nb_moves_cur>nb_moves_max){
    TTF_Font * font = TTF_OpenFont("Arial.ttf", 64);
    SDL_Color color = { 0,0,0 }; 
    if(!font) ERROR("TTF_OpenFont: %s\n", FONT);
    TTF_SetFontStyle(font, TTF_STYLE_BOLD);
    SDL_Surface * surf = TTF_RenderText_Blended(font,"FAILD!", color); // blended rendering for ultra nice text
    env->text = SDL_CreateTextureFromSurface(ren, surf);
    SDL_QueryTexture(env->text, NULL, NULL, &rect.w, &rect.h);
    rect.w = w/2-2;
    rect.h = h/10-2;
    rect.x = w/4+1; 
    rect.y = 1; 
    SDL_RenderCopy(ren, env->text, NULL, &rect);

  }
  if(nb_moves_max>=nb_moves_cur){
  SDL_QueryTexture(env->alea->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =0 ;
  rect.x =w/2;
  rect.w =w/4;
  rect.h =h/10;
  env->alea->x=rect.x;
  env->alea->y=rect.y;
  env->alea->h=rect.h;
  env->alea->w=rect.w;
  SDL_RenderCopy(ren, env->alea->Surface, NULL, &rect);
  
  #ifdef __ANDROID__
  /*rien */
  #else
  SDL_QueryTexture(env->save->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =0 ;
  rect.x =w/4;
  rect.w =w/4;
  rect.h =h/10;
  env->save->x=rect.x;
  env->save->y=rect.y;
  env->save->h=rect.h;
  env->save->w=rect.w;
  SDL_RenderCopy(ren, env->save->Surface, NULL, &rect);
  #endif
  }
  SDL_QueryTexture(env->retourne->Surface, NULL, NULL, &rect.w, &rect.h);
  rect.y =h-h/10 ;
  rect.x =w-w/4;
  rect.w =w/4;
  rect.h =h/10;
  env->retourne->x=rect.x;
  env->retourne->y=rect.y;
  env->retourne->h=rect.h;
  env->retourne->w=rect.w;
  SDL_RenderCopy(ren, env->retourne->Surface, NULL, &rect);
  }
  }
}

   
  /* PUT YOUR CODE HERE TO RENDER TEXTURES, ... */

     
/* **************************************************************** */
     
     
bool process(SDL_Window* win, SDL_Renderer* ren, Env * env, SDL_Event * e, game g,game g1)
{     
  int w, h;
  SDL_GetWindowSize(win, &w, &h);
  game g2=game_copy(g);
  FILE* f=NULL;
  FILE* f2=NULL;
  if (e->type == SDL_QUIT) {
    return true;
  }


  else if (e->type == SDL_FINGERDOWN) {    
    env->color_x = e->tfinger.x * w;  /* tfinger.x, normalized in [0..1] */
    env->color_y = e->tfinger.y * h; /*  tfinger.y, normalized in [0..1] */
  }

  else if (e->type == SDL_MOUSEBUTTONDOWN) {
    SDL_Point mouse; 
    SDL_GetMouseState(&mouse.x, &mouse.y);

    int pos_x;
    int pos_y;
  int g_h=game_height(g);
  int g_w=game_width(g);
  
  int a,b,d,u ;
  a=5;
  b=5;
  color c ;
  if(env->ok==false){
  if(mouse.y>env->butt3->y && (env->butt3->x+env->butt3->w)>mouse.x && (env->butt3->y+env->butt3->h)>mouse.y &&mouse.x>env->butt3->x ){
    env->ok=true ;
  }
  if(mouse.y>env->alea2->y && (env->alea2->x+env->alea2->w)>mouse.x && (env->alea2->y+env->alea2->h)>mouse.y &&mouse.x>env->alea2->x ){
    a=rand() % 10 +rand() % 2 + rand() % 3 +5 ;
    b=rand() % 15+5 ;   
  while (w % a!= 0)
  {

    w++;
  }

  while ( (h-(h/5)) % b!= 0)
  {

    h++;
  }  
    if (a>b) d=rand()%3+a ;
    else d=rand()%3+b ; 
  g2=game_random_ext(a,b, false,rand()%14+2,d);
  g->nb_moves_max=g2->nb_moves_max;
	g->nb_moves_cur=g2->nb_moves_cur;
	g->nb_colors=g2->nb_colors;	
  g->grille = (color *)malloc(g2->size * sizeof(color));
	g->start = (color *)malloc(g2->size * sizeof(color));
  for (int i=0 ; i<g2->size ; i++)
	{
		g->grille[i]= g2->grille[i];
		g->start[i]= g2->grille[i];

	}
	g->width=g2->width;
  g->height=g2->height;
	g->wrapping=g2->wrapping;
	g->size=g2->size;
  game_delete(g2);
  SDL_SetWindowSize(win , w , h);
    env->ok=true ;
  }

#ifdef __ANDROID__
/* rien */
#else
if(mouse.x >env->charger->x && (env->charger->w+env->charger->x)>mouse.x && mouse.y >env->charger->y && (env->charger->h+env->charger->y)>mouse.y){
      g2=game_load("test"); 
      FILE* f2=NULL;
      f2 = fopen("save_nb_moves_cur","r");
      fscanf(f2, "%u", &u);
      fclose(f2);
       g->width=g2->width;
      g->height=g2->height;
      while (w % g->width!= 0)
      {

      w++;
      }

       while ( (h-(h/5)) % g->height!= 0)
       {

    h++;
      }
      SDL_SetWindowSize(win , w , h);
      g->nb_moves_max=g2->nb_moves_max;
	    g->nb_moves_cur=u;
	    g->nb_colors=g2->nb_colors;	
      
      g->grille = (color *)malloc(g2->size * sizeof(color));
	    g->start = (color *)malloc(g2->size * sizeof(color));
      for (int i=0 ; i<g2->size ; i++)
    	{
		  g->grille[i]= g2->grille[i];
		  g->start[i]= g2->grille[i];
      }
	    g->wrapping=g2->wrapping;
	    g->size=g2->size;
    
    
    env->ok=true ;

  }
  #endif


  }
  else{
  if(mouse.x >env->butt->x && (env->butt->w+env->butt->x)>mouse.x && mouse.y >env->butt->y && (env->butt->h+env->butt->y)>mouse.y){
      game_restart(g);
  }
  if(mouse.x >env->retourne->x && (env->retourne->w+env->retourne->x)>mouse.x && mouse.y >env->retourne->y && (env->retourne->h+env->retourne->y)>mouse.y){
       env->ok=false ;
  }

#ifdef __ANDROID__
/* rien */
#else
  if(mouse.x >env->save->x && (env->save->w+env->save->x)>mouse.x && mouse.y >env->save->y && (env->save->h+env->save->y)>mouse.y){
      game_save(g, "test");
      f = fopen("save_nb_moves_cur","w");
      fprintf(f, "%u\n",g->nb_moves_cur);
      fclose(f);
  }
#endif

  if(mouse.x >env->butt2->x && (env->butt2->w+env->butt2->x)>mouse.x && mouse.y >env->butt2->y && (env->butt2->h+env->butt2->y)>mouse.y){
      /*clean(win,ren,env,g);*/
        game_delete(g2);
      return true;
  }
  if(g->nb_moves_max>=g->nb_moves_cur){
  if(mouse.y>env->alea->y && (env->alea->x+env->alea->w)>mouse.x && (env->alea->y+env->alea->h)>mouse.y &&mouse.x>env->alea->x ){
	  g->nb_moves_cur=g1->nb_moves_cur;
    for (int i=0 ; i<g1->size ; i++)
	  {
		  g->grille[i]= g1->grille[i];
		  g->start[i]= g1->grille[i];
    }
  }
  }
  if (game_is_over(g)==false){
  for(int i=h/10; i<(h-h/10) ; i=i+(h-h/10-h/10)/g_h)
  {
    for(int j=0; j< w ; j=j+(w/g_w))
    { 
      if ( (i<=mouse.y) && (mouse.y<(i+(h-h/10)/g_h)) && (j<=mouse.x) && (mouse.x<(j+(w/g_w) ))) {
                 pos_y = (i-h/10)/((h-2 * h/10)/g_h);
                 pos_x = j/((w/g_w));
                 c = g->grille[(pos_y*g->width)+pos_x];
                 if (c!=g->grille[0])
                 {
                	g1->nb_moves_cur=g->nb_moves_cur;
                for (int i=0 ; i<g->size ; i++)
	                {
		                g1->grille[i]= g->grille[i];
                		g1->start[i]= g->grille[i];
                  }
                  game_play_one_move(g,c);
                 }
            }
      
      
      
    }
  }
  }


  }
  }

  
  return false; 
}

/* **************************************************************** */

void clean(SDL_Window* win, SDL_Renderer* ren, Env * env,game g,game g1)
{
  free(env->butt);
  free(env->butt2);
  free(env->butt3);

  free(env->alea);
  free(env->alea2);
  free(env->save);
  free(env->charger);
  free(env->retourne);
  game_delete(g);
  game_delete(g1);
  free(env);
}
     
/* **************************************************************** */
