#include "Player.hh"

map <string,int> Player::playerData;		
map <string,int> Player::playerOldData;		


//////////////////*Constructeur*//////////////////

Player::Player(int **screen,SDL_Texture* objTexture, int x, int y, int w, int h) : Character(objTexture,x,y,w,h){
			dir = new bool[4];
			for(int i=0;i<4;i++){
				 dir[i] = 0;
			}
			resetPos();
			updateScreen(screen,1);
			playerData["Score"] = 0;
			playerData["PointDevie"] = 100;
		}

//////////////////*Destructeur*//////////////////

Player::~Player(){
	delete[] dir;
}


//////////////////*Fonctions Membres*//////////////////

/* Met à jour le personnage "Player" */
void Player::update(int **screen){
	damage = 0;
	playerOldData=playerData;

	resetPos();
	updateScreen(screen,0);	//Réinitialise l'écran à 0 sur la position précédente du joueur

	updateEvent2KEYDOWN();	//Si une 2ième flèche est appuyée, le joueur va se déplace dans une 2ième direction
	updateEventKEYDOWN();	//Si une flèche est appuyée, le joueur va se déplace dans la direction associée
	updateEventKEYUP();		//Si la flèche est relachée, le joueur ne se déplace plus dans la direction 

	resetPos();

	for(int i=_y;i<_y+destRect.h;i++){		//Met à jour l'écran et damage si le cas est
		for(int j=_x;j<_x+destRect.w;j++){
			if(screen[j][i]==3)			//Indique si le joueur entre en contact avec un ennemie
				damage = true;

			screen[j][i]=1;
		}
	}
}

/*Evenement KEYDOWN (flèche appuyée dans notre cas)*/
void Player::updateEventKEYDOWN(){
	if(Game::event.type == SDL_KEYDOWN){
		switch(Game::event.key.keysym.sym){
			case SDLK_LEFT:		//Flèche Gauche
				destRect.x-=2;
				_x-=2;
				dir[0]=2;
				break;
			case SDLK_DOWN:		//Flèche Bas
				destRect.y+=2;
				_y+=2;
				dir[1]=2;
				break;
			case SDLK_RIGHT:	//Flèche Droite
				destRect.x+=2;
				_x+=2;
				dir[2]=2;
				break;
			case SDLK_UP:		//Flèche Haute
				destRect.y-=2;
				_y-=2;
				dir[3]=2;
				break;
			default:
				break;
		}
	}
}

/*Evenement KEYUP (flèche relachée dans notre cas)*/
void Player::updateEventKEYUP(){
	if(Game::event.type == SDL_KEYUP){
		switch(Game::event.key.keysym.sym){
			case SDLK_LEFT:	//Gauche
				dir[0]=0;	
				break;
			case SDLK_DOWN:	//Bas
				dir[1]=0;
				break;
			case SDLK_RIGHT:	//Droite
				dir[2]=0;
				break;
			case SDLK_UP:
				dir[3]=0;		//Haut
				break;
			default:
				break;
		}
	}
}

/*Evenement KEYUP (2ième flèche appuyée dans notre cas)*/
void Player::updateEvent2KEYDOWN(){
	if(dir[0]){
		destRect.x-=2;
		_x-=2;
	}
	if(dir[1]){
		destRect.y+=2;
		_y+=2;
	}
	if(dir[2]){
		destRect.x+=2;
		_x+=2;
	}
	if(dir[3]){
		destRect.y-=2;
		_y-=2;
	}
}


