#include "Money.hh"

//////////////////*Constructeur*//////////////////

Money::Money(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h):Object(screen,objTexture,x,y,w,h){
	updateScreen(screen,5);
	point = 20;
	duree = 500;
}

//////////////////*Destructeur*//////////////////

Money::~Money(){
	
}

//////////////////*Fonctions Membres*//////////////////


/* Met à jour l'item "Money" :
	- si le nombre d'iteration atteint la duree d'apparition de l'objet, il disparait (1)
	- si il n'est pas attrapé, on met à jour la grille représentant l'écran (2)
	- si il est attrapé, l'objet disparait (3)
*/
void Money::update(int **screen){
	iter++;

	if(iter==duree){//(1)
		exist = false;
		updateScreen(screen,0);
	}	

	if(!caught){	//(2)
		updateScreen(screen,5);
	}
	else	//(3)	
		exist = false;
}

/* Détermine si l'item est attrapé */
void Money::catchObject(int **screen){	
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			if(screen[j][i]==1) 		//l'écran est occupé par le joueur
				caught=true;
		}
	}
}