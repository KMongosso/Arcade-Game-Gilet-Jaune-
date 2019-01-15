#include "Ennemy.hh"

//////////////////*Constructeur*//////////////////

 Ennemy::Ennemy(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h):Character(objTexture,x,y,w,h){
			if(_x>639)		//Ennemie à droite
				dir=0;
			if(_y<0)		//Ennemie en haut
				dir=1;
			if(_x<0)		//Ennemie à gauche
				dir=2;
			if(_y>639)		//Ennemie en bas
				dir=3;
			active = 1;
			back=0;
		}

//////////////////*Destructeur*//////////////////

Ennemy::~Ennemy(){
	
}


//////////////////*Fonctions Membres*//////////////////
void Ennemy::update(int **screen){
	if(active){
		if(dir==0)
			rightEnnemyUpdate(screen);
			
		if(dir==1)
			topEnnemyUpdate(screen);

		if(dir==2)
			leftEnnemyUpdate(screen);

		if(dir==3)
			bottomEnnemyUpdate(screen);
	}
}

/*	Les fonctions update ci-dessous mettent à jour l'écran et les positions de l'ennemi
	Les ennemis qui sont initialisés à l'extérieur de l'écran rentre dans l'écran jusqu'à un certaine distance puis ressorte
*/
void Ennemy::leftEnnemyUpdate(int **screen){
	for(int i=_y;i<_y+destRect.h;i++){		//Réinitialise l'écran à 0 à la position précédente de l'ennemi
		for(int j=0;j<_x+destRect.w;j++){
			screen[j][i]=0;
		}
	}

	if(_x<50 && !back){		//On met à jour les coordonnées de l'ennemi en fonction de si il sort de l'écran ou si il rentre
		_x+=1;
		destRect.x+=1;	
	}
	else{
		_x-=1;
		destRect.x-=1;
		back=1;
	}

	for(int i=_y;i<_y+destRect.h;i++){		//On met à jour l'écran
		for(int j=0;j<_x+destRect.w;j++){
			screen[j][i]=3;			//l'écran est désormais occupé par l'ennemi
		}
	}

	if(_x==-59)		//Lorsque l'ennemie est de retour à sa position initiale, il disparait
		active=0;
}

void Ennemy::rightEnnemyUpdate(int **screen){
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<639;j++){		
			screen[j][i]=0;
		}
	}

	if(_x>640-destRect.w-19 && !back){
		_x-=1;
		destRect.x-=1;
	}
	else{
		_x+=1;
		destRect.x+=1;
		back=1;
	}
	
	for(int i=_y;i<_y+destRect.h;i++){
		for(int j=_x;j<639;j++){		
			screen[j][i]=3;
		}
	}

	if(_x==640)
		active=0;
}

void Ennemy::topEnnemyUpdate(int **screen){
	for(int i=0;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			screen[j][i]=0;
		}
	}

	if(_y<19 && !back){
		_y+=1;
		destRect.y+=1;
	}		
	else{
		_y-=1;
		destRect.y-=1;
		back=1;
	}

	for(int i=0;i<_y+destRect.h;i++){
		for(int j=_x;j<_x+destRect.w;j++){
			screen[j][i]=3;
		}
	}

	if(_y==-44)
		active=0;
}

void Ennemy::bottomEnnemyUpdate(int **screen){
	for(int i=_y;i<639;i++){
		for(int j=_x;j<_x+destRect.w;j++){				
			screen[j][i]=0;
		}
	}

	if(_y>640-destRect.h-19 && !back){
		_y-=1;
		destRect.y-=1;
	}
	else{
		_y+=1;
		destRect.y+=1;
		back=1;
	}

	for(int i=_y;i<639;i++){
		for(int j=_x;j<_x+destRect.w;j++){
						
			screen[j][i]=3;
		}
	}

	if(_y==640)
		active=0;
}

