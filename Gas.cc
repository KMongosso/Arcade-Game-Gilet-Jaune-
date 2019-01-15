#include "Gas.hh"

//////////////////*Constructeur*//////////////////

Gas::Gas(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h):Object(screen,objTexture,x,y,w,h){
	updateScreen(screen,4);
	point = 1;
}

//////////////////*Destructeur*//////////////////

Gas::~Gas(){
	
}


//////////////////*Fonctions Membres*//////////////////


/* Met à jour l'item "Gas" :
	- si il n'est pas attrapé, on met à jour la grille représentant l'écran (1)
	- si il est attrapé, l'objet disparait (2)
*/

void Gas::update(int **screen){
	if(!caught)		//(1)
		updateScreen(screen,4);

	else		//(2)
		exist = false;
}

/* Détermine si l'item est attrapé */
void Gas::catchObject(int **screen){		
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			if(screen[j][i]==1)		//l'écran est occupé par le joueur
				caught=true;
		}
	}
}