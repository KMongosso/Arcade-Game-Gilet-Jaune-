#include "Game.hh"

/*Déclaration de classes*/
Menu* men;	
Map* carte;

/*SDL*/
SDL_Renderer* Game::renderer ;	
SDL_Event Game::event;
SDL_Surface *Game::text;
SDL_Texture* tex;
SDL_Rect Game::destText;

/*SDL_TTF*/
TTF_Font *Game::police;

//////////////////*Constructeur*//////////////////

Game::Game(const char* title, int x, int y, int width, int height){
	_width = width;
	_height = height;

	sdlInit(title, x, y, width, height);

	screen = new int*[height];
	for(int i=0;i<height;i++){
		screen[i] = new int[width];
	}
		
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			screen[j][i] = 0;
		}
	}

	srand(time(NULL));
	newA=rand()%5000+5000;
	newF=rand()%50+200;
	newE=rand()%200+600;
	ennemyFrequency = 600;
	flameFrequency = 200;

	textureInit();

	gameElementsInit();
}

//////////////////*Destructeur*//////////////////

Game::~Game(){
	for(int i=0;i<600;i++){
		delete[] screen[i];
	}
	
	delete[] screen;

	SDL_FreeSurface(text);
	TTF_CloseFont(police);
    TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

//////////////////*Fonctions Membres*//////////////////

/*Initialise tous les éléments SDL*/
void Game::sdlInit(const char* title, int x, int y, int width, int height){
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){	

		window = SDL_CreateWindow(title, x, y, width, height,0);	

		renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_TARGETTEXTURE);
		//SDL_SetRenderDrawColor(renderer,255,255,255,255);			//Permet de définir la couleur par défaut de la fenêtre graphique
			
		isRunning = true;
	}
	else{

		isRunning = false;
	}

	TTF_Init();
	police = TTF_OpenFont("Police/stocky.ttf", 65);
	destText = {30,590,550,30};
}

/*Initialise tous les éléments du jeu (classes)*/
void Game::gameElementsInit(){
	gameObjects.push_back(new Gas(screen,GasText,rand()%614,rand()%614,25,25));
	gameEnnemyes.push_back(new Ennemy(screen,EnnemyText,100,-44,58,43));
	player = new Player(screen,PlayerText,0,0,52,82);
	carte = new Map();
	men = new Menu();
}

/*Initialise toutes les textures*/
void Game::textureInit(){
	PlayerText = TextureManager::LoadTexture("Images/perso.png");
	EnnemyText = TextureManager::LoadTexture("Images/crs.png");
	FlameText = TextureManager::LoadTexture("Images/Voiture.png");
	GasText = TextureManager::LoadTexture("Images/Carburant.png");
	MoneyText = TextureManager::LoadTexture("Images/Argent.png");
	ProjectileText = TextureManager::LoadTexture("Images/boule.png");
}

/*Met àjour isRunning si on quitte le jeu*/
void Game::handleEvent(){
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break; 
	}
}

/*Met à jour le menu*/
void Game::menuUpdate(){
	affichage=men->update();
}

/*Met à jour le joueur*/
void Game::playerUpdate(){
	player->update(screen);

	if(player->getDamage()!=0){		//Retire des points de vie si il subit des dommages
		Player::playerData["PointDevie"]-=player->getDamage();
	}
}

/*Met à jour les ennemis*/
void Game::ennemyUpdate(){
	srand(time(NULL));
	int side;

	if(iterTot%1000==0 && ennemyFrequency>0) ennemyFrequency-=100;		//Diminue la fréquence d'apparition au bout d'un certains nombre d'itération du jeu(ne peut pas descendre end essous de 0)

	if(iterE==newE){		//Apparition d'un nouvel ennemie
		side = rand()%4;		//Défini aléatoirement le côté d'apparition du nouvel ennemie
		if(side==0)
			gameEnnemyes.push_back(new Ennemy(screen,EnnemyText,-59,rand()%520+50,58,43));	
		if(side==1)
			gameEnnemyes.push_back(new Ennemy(screen,EnnemyText,rand()%470+60,640,58,43));
		if(side==2)
			gameEnnemyes.push_back(new Ennemy(screen,EnnemyText,640,rand()%520+50,58,43));
		if(side==3)
			gameEnnemyes.push_back(new Ennemy(screen,EnnemyText,rand()%470+60,-44,58,43));
		
		newE = rand()%200+ennemyFrequency;		//Nouveau temps d'apparition du prochain ennemi
		iterE = 0;
	}
	else{
		iterE++;
	}

	for( list <Ennemy *>::iterator it = gameEnnemyes.begin(); it != gameEnnemyes.end(); it ++){
 		(*it)->update(screen);
 		if((*it)->getX()==50||(*it)->getX()==563||(*it)->getY()==19||(*it)->getY()==578){		//Envoie un projectile lorsque l'ennemie est complètement dans l'écran
 			gameProjectiles.push_back(new Projectile(screen,ProjectileText,(*it)->getX()+25,(*it)->getY(),20,20,player->getX(),player->getY()));
 		}
	}
}

/*Met à jour les Objets du jeu*/
void Game::gameObjectsUpdate(){
	addNewFlame();

	addNewStack();

	for( list <Object *>::iterator it = gameObjects.begin(); it != gameObjects.end(); it ++){
		(*it)->catchObject(screen);

		if((*it)->getCaught() && (*it)->getExist()){		//Si l'objet touche le joueur et qu'il existe
			if((*it)->getPoint()<0) 		//Si l'objet est "Flame", le joueur perd des points de vie
				Player::playerData["PointDevie"]+=(*it)->getPoint();
			
			else if((*it)->getPoint()==20){		//Si l'objet est "Money", le joueur gagne des points de vie et augmente son score
				Player::playerData["Score"]+=(*it)->getPoint();
				Player::playerData["PointDevie"]+=(*it)->getPoint();
			}
			else{		//Si l'objet est "Gas", le joueur augmente son score
				Player::playerData["Score"]+=(*it)->getPoint();
				gameObjects.push_back(new Gas(screen,GasText,rand()%614,rand()%614,25,25));
			}
		}
  		(*it)->update(screen);
	}
}

/*Ajoute un nouvel item "Flame" dans la liste des objets*/
void Game::addNewFlame(){
	srand(time(NULL));
	if(iterF==newF){
		gameObjects.push_back(new Flame(screen,FlameText,rand()%614,rand()%614,25,25));
		newF = rand()%50+flameFrequency;		//Nouveau temps d'apparition du prochain ennemi
		iterF = 0;
		if(iterTot%500==0){
			if(flameFrequency>0)	//Augmentation de la duree et fréquence d'apparition de "Flame" au bout d'un certains nombre d'itération du jeu
				flameFrequency -= 50;
			Flame::duree += 200 ;
		}
	}
	else 
		iterF++;
}

/*Ajoute un nouvel item "Money" dans la liste des objets*/
void Game::addNewStack(){
	srand(time(NULL));
	if(iterA==newA){
		gameObjects.push_back(new Money(screen,MoneyText,rand()%614,rand()%614,25,25));
		newA = rand()%10000+5000;		//Nouveau temps d'apparition du prochain "Money"
		iterA = 0;
	}
	else 
		iterA++;
}

/*Met à jour le jeu*/
void Game::update(){
	srand(time(NULL));
	if(affichage==0)	menuUpdate();	//Menu

	else if(affichage==1){		//Ecran de jeu
		iterTot++;
		playerUpdate();
		ennemyUpdate();
		gameObjectsUpdate();

		for( list <Projectile *>::iterator it = gameProjectiles.begin(); it != gameProjectiles.end(); it ++){
 			(*it)->catchObject(screen);		

 			if((*it)->getCaught() && (*it)->getExist())		//Si le projectile touche le joueur et qu'il existe, le joueur perd des points de vie
				Player::playerData["PointDevie"]+=(*it)->getPoint();
 			(*it)->update(screen); 				
		}

		info_string= "Score : " + to_string(Player::playerData["Score"]) + "                            Point de vie : " + to_string(Player::playerData["PointDevie"]);
		info_char = info_string.c_str();
		
		SDL_FreeSurface(text);
		text = TTF_RenderText_Blended(police,info_char, {0, 0, 0});		//Incrémentation de test qui permettra d'afficher les données du joueur en bas de l'écran 

		if(Player::playerData["PointDevie"]<0)		//Si les points de vie deviennent négatifs, le joueur a perdu et on passe sur l'écran de fin 
			affichage =  2;
	}
	else{		//Ecran de fin
		playerUpdate();
		info_string = "Vous avez perdu avec un score de " + to_string(Player::playerData["Score"]);
		info_char = info_string.c_str();
		
		/*Affiche le texte et met fin au jeu au bout d'un certains nombre d'itération*/
		SDL_FreeSurface(text);
		text = TTF_RenderText_Blended(police,info_char, {0, 0, 0});
		iterEnd++;
		destText.y = 300;
		if(iterEnd==200)
			isRunning=false;
	}
}

/*Ajoute toutes les textures sur le render*/
void Game::render(){
	SDL_RenderClear(renderer);
	if(affichage==0){		//Menu
		carte->Draw();
		men->render();
	}
	else if(affichage==1){		//Ecran de jeu
		carte->Draw();
		player->render(renderer);

		for( list <Object *>::iterator it = gameObjects.begin(); it != gameObjects.end(); it ++){
  			(*it)->render(renderer);
		}

		for( list <Ennemy *>::iterator it = gameEnnemyes.begin(); it != gameEnnemyes.end(); it ++){
  			(*it)->render(renderer);
		}

		for( list <Projectile *>::iterator it = gameProjectiles.begin(); it != gameProjectiles.end(); it ++){
 			(*it)->render(renderer);
 		
		}
	}

	else{		//Ecran de fin
		carte->Draw();
	}

	tex = SDL_CreateTextureFromSurface(renderer,text);
	SDL_RenderCopy(renderer, tex,NULL, &destText);
	SDL_RenderPresent(renderer);
}


