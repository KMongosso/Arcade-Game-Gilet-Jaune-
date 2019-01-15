#include "Map.hh"

//////////////////*Grille de la carte*//////////////////

int carte0[20][20]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,0,0},
	{0,0,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,1,1,0,0,1,1,1,0,1,1,0,0,1,0,0,0,0},
	{0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0},
	{0,0,0,1,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0},
	{0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,0},
	{0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

//////////////////*Costructeur*//////////////////

Map::Map(){
	/*On stockera toutes les textures dans un vecteur ça évitera le switch case dans Draw*/
	brown = TextureManager::LoadTexture("Images/marron.png");
	green = TextureManager::LoadTexture("Images/vert.png");
	blue = TextureManager::LoadTexture("Images/bleu.png");
	purple = TextureManager::LoadTexture("Images/violet.png");
	yellow = TextureManager::LoadTexture("Images/jaune.png");
	white = TextureManager::LoadTexture("Images/blanc.png");
	black = TextureManager::LoadTexture("Images/noir.png");
	red = TextureManager::LoadTexture("Images/rouge.png");

	LoadMap(carte0);

	src.x = src.y = 0;
	src.w = dest.w = 32;	/*Dimensions de chaque élément du fond */
	src.h = dest.h = 32;
 	dest.x = dest.y = 0;

 	paris = TextureManager::LoadTexture("Images/paris.jpg");

 	destP.x = destP.y = 0;
 	destP.w = 640;
 	destP.h = 640;
}

//////////////////*Destructeur*//////////////////

Map::~Map(){

}

//////////////////*Fonctions Membres*//////////////////

void Map::LoadMap(int arr[20][20]){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			map[j][i] = arr[i][j];
		}
	}
}

void Map::Draw(){
	

	//////////////////*Map personnalisée*//////////////////

	/*Le nombre de colonnes * dest.w et le nombre de lignes*dest.h doivent être égales aux dimensions de la map*/
	/*int type = 0;

	for(int i=0;i<20;i++){		
		for(int j=0;j<20;j++){
			type = map[i][j];
			dest.x = i*dest.w;
			dest.y = j*dest.h;
			switch(type){
				case 0:
					TextureManager::Draw(white, src, dest);
					break;
				case 1:
					TextureManager::Draw(black, src, dest);
					break;	
				case 2:
					TextureManager::Draw(blue, src, dest);
					break;
				case 3:
					TextureManager::Draw(red, src, dest);
					break;
				case 4:
					TextureManager::Draw(purple, src, dest);
					break;
				case 5:
					TextureManager::Draw(yellow, src, dest);
					break;
				case 6:
					TextureManager::Draw(green, src, dest);
					break;
				case 7:
					TextureManager::Draw(brown, src, dest);
					break;
				default:
					break;
			}
		}
	}*/

	//////////////////*Map de Paris*//////////////////
	TextureManager::Draw(paris,src,destP);

}