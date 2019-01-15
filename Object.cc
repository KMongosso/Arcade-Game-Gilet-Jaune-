#include "Object.hh"

//////////////////*Constructeur*//////////////////

Object::Object(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h):GameElements(objTexture,x,y,w,h){
	if(this->occupe(screen))
		newPos(screen);
}

//////////////////*Destructeur*//////////////////

Object::~Object(){
	
}

//////////////////*Fonctions Membres*//////////////////

/*Ajouter la texture de l'objet sur le renderer*/
void Object::render(SDL_Renderer* renderer){
	if(!caught && exist)
		SDL_RenderCopy(renderer, _objTexture, NULL, &destRect);	
}

/*Redéfinit les coordonnées de l'objet tant que les coordonnées assignées à l'objet sont déjà occupées par un autre objet sur l'écran*/
void Object::newPos(int **screen){
	do{
		_x = rand()%614;
		_y = rand()%614;
		destRect.x = _x;
		destRect.y = _y;

	}
	while(this->occupe(screen));
}

/*Indique si l'écran est déjà occupé*/
bool Object::occupe(int **screen){
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			if(screen[j][i]!=0)
				return 1;
		}
	}

	return 0;
}


