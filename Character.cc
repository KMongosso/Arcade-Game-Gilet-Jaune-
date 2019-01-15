#include "Character.hh"



//////////////////*Destructeur*//////////////////

Character::~Character(){
	
}


//////////////////*Fonctions Membres*//////////////////

/*Ajoute la texture du personnage sur le renderer*/
void Character::render(SDL_Renderer* renderer){		
	SDL_RenderCopy(renderer, _objTexture, NULL, &destRect);
}

