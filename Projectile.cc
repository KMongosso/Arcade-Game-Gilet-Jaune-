#include "Projectile.hh"

//////////////////*Constructeur*//////////////////

Projectile::Projectile(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h, int xplayer, int yplayer):Object(screen,objTexture,x,y,w,h){
	/*Le newPos() appelé dans le constructeur de Object fait que l eprojectile est placé aléatoirement, on redéfinit donc la position pour que le projectile parte de l'ennemi*/
	_x = x;
	_y = y;
	destRect.x = _x;	
	destRect.y = _y;

	for(int i=_y;i<_y+destRect.h;i++){		//l'écran est désormais occupé par l'item "Projectile"
		for(int j=_x;j<_x+destRect.w;j++){
			screen[j][i]=6;
		}
	}

	point = -10;
	
	if(xplayer-x>0)		//Projectile se déplace vers la droite
		dirx = 0;		
	else		//Projectile se déplace vers la gauche
		dirx =1; 		

	if(yplayer-y>0)		//Projectile se déplace vers le haut
		diry = 0;
	else
		diry =1; 		//Projectile se déplace vers le bas

	if(xplayer-x==0)		//le dénominateur de la pente ne peut pas être égale à 0 donc si le dénominateur égal 0 on incrémente la pente à 0
		pente=0;
	else 
		pente=(yplayer+26-y)/(xplayer-x);
}

//////////////////*Destructeur*//////////////////

Projectile::~Projectile(){
	
}

//////////////////*Fonctions Membres*//////////////////

/* Met à jour l'item "Projectile" :
	- si il est sorti de l'écran, il disparait (1)
	- si il existe et qu'il n'est pas attrapé, il se déplace suivant la droite d'équation : _y = _x*pente + b où b=_y au départ du projectile (2)
	- si il existe et qu'il est attrapé, il disparaît (3) 
	- si il n'existe, on le retire de l'écran 
*/
void Projectile::update(int **screen){
	
	if(_x<0||_x>619||_y<0||_y>619){		//(1)
		exist=false;
	}
	
	if(exist){
		if(!caught){		//(2)
			updateScreen(screen,0);

			if(dirx==0)
				_x+=1;
			else
				_x-=1;

			if(dirx==0)
				_y+=pente;
			else
				_y-=pente;
			 
			if(_y>0 && _y<619 && _x>0 && _x<619){		//si il est toujours dans l'écran
				destRect.x = _x;
				destRect.y = _y;
				updateScreen(screen,6);
			}
		}
		else		//(3)
			exist = false;
	}
	else{		//(4)
		if(_y>0 && _y<619 && _x>0 && _x<619)
			updateScreen(screen,0);
	}
}

/*Met à jour les coordonnées du projectile*/
void Projectile::updatePos(int **screen){		
	if(dirx==0)
		_x+=1;
	else
		_x-=1;

	if(dirx==0)			
		_y+=pente;
	else
		_y-=pente;
}

/* Détermine si l'item est attrapé */
void Projectile::catchObject(int **screen){
	if(_y>0 && _y<619 && _x>0 && _x<619){		//si l'object est dans l'écran
		for(int i=_y;i<_y+destRect.h;i++){
			for(int j=_x;j<_x+destRect.w;j++){
				if(screen[j][i]==1)			//l'écran est occupé par le joueur
					caught=true;	
			}
		}
	}
}