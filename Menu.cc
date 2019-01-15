#include "Menu.hh"

//////////////////*Constructeur*//////////////////

Menu::Menu(){
	map = new Map();
	start = TextureManager::LoadTexture("Images/start.png");
	menu = TextureManager::LoadTexture("Images/Menu.png");	

	destStart.x = 220;	//Définir les dimensions de l'objet
	destStart.y = 330;
	destStart.w = 200;	//Définir sa position initiale
	destStart.h = 200;

	destMenu.x = 120;	//Définir les dimensions de l'objet
	destMenu.y = 70;
	destMenu.w = 400;	//Définir sa position initiale
	destMenu.h = 200;
}

//////////////////*Destructeur*//////////////////

Menu::~Menu(){
	
}

//////////////////*Fonctions Membres*//////////////////

/*Met à jour les évènements du milieu*/
bool Menu::update(){
	if(Game::event.type == SDL_MOUSEBUTTONDOWN){		//Si on clique sur la zone ci-dessous on lance le jeu
			if(Game::event.button.y>330 && Game::event.button.y<530 &&Game::event.button.x>220 &&Game::event.button.x<420){
				return 1;
			}
		}
	return 0;
}

/*Ajoute les textures du menu sur le renderer*/
void Menu::render(){
	map->Draw();
	SDL_RenderCopy(Game::renderer, start, NULL, &destStart);
	SDL_RenderCopy(Game::renderer, menu, NULL, &destMenu);
}