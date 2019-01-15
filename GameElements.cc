#include "GameElements.hh"

//////////////////*Constructeur*//////////////////

GameElements::GameElements(SDL_Texture* objTexture, int x, int y, int w, int h){
	_objTexture = objTexture;
	_x = x;
	_y = y;

	srcRect.h = w;	
	srcRect.w = h;

	srcRect.x = 0;		
	srcRect.y = 0;

	destRect.x = _x;	
	destRect.y = _y;
	destRect.w = w;	
	destRect.h = h;
}

//////////////////*Destructeur*//////////////////

GameElements::~GameElements(){
	
}

//////////////////*Fonctions Membres*//////////////////

/*Redéfinit les coordonnées de l'élément si il est en dehors de l'écran en le mettant sur le bord*/
void GameElements::resetPos(){
	if(_x<0){
		_x = 0;
		destRect.x = _x;
	}
		
	if(_x+destRect.w>639){
		_x = 639-destRect.w;
		destRect.x = _x;
	}
		
	if(_y<0){
		_y = 0;
		destRect.y = _y;
	}
		
	if(_y+destRect.h>639){
		_y = 639-destRect.h;
		destRect.y = _y;
	}
}

/*Met à jour l'écran avec le chiffre associé à l'élément (ou avec 0 pour le réinitialiser)*/
void GameElements::updateScreen(int **screen, int val){
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			screen[j][i]=val;
		}
	}
}
