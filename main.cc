#include <SDL2/SDL.h> 
#include "Game.hh"
#include "Player.hh"

Game *game;

ostream& operator<<( ostream &out, Game* game){
    out << game->getInfo() << endl;
    return out;
}

ostream& operator<<( ostream &out, Player* player){
    int diff;
    out << "";
    if(player->getData()["PointDevie"]==player->getOldData()["PointDevie"]+20)
        out << "Vous avez attrapé le sac d'argent (+20 PDV/+20 Score)" << endl;

    else if(player->getData()["Score"]==player->getOldData()["Score"]+1)
        out << "Vous avez attrapé du carburant (+1 Score)" << endl;

    else if(player->getData()["PointDevie"]<player->getOldData()["PointDevie"]){
        //out << "PDV1 = " << player->getData()["PointDeVie"] << endl;
        if(player->getData()["PointDevie"]==player->getOldData()["PointDevie"]-5)
            out << "Vous vous êtes brûlés (-5 PDV)" << endl;
        else if(player->getData()["PointDevie"]==player->getOldData()["PointDevie"]-10)
            out << "Vous avez été touché par un projectile (-10 PDV)" << endl;
        else{
            diff = player->getData()["PointDevie"]-player->getOldData()["PointDevie"];
            out << "Vous vous êtes confrontés au forces de l'ordre (" << diff << " PDV)" <<endl;
        } 
    }


    return out;
}

int main(int argc,const char * argv[]){
    /*Vitesse du jeu*/
    const int FPS = 60, FrameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

    /*Mis en place de la musique*/
    Mix_Music *musique;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4); 
    musique = Mix_LoadMUS("Sons/theme.wav"); 
    Mix_PlayMusic(musique, -1); 
    
    /*Initialisation du jeu*/
    game = new Game("Projet",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,640);

    /*Boucle de jeu*/
    while(game->getRunning()){
            game->handleEvent();
            game->update();
            game->render();
            cout << game->getPlayer();
    	frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks()-frameStart;

        if(FrameDelay>frameTime){ 
        	SDL_Delay(FrameDelay-frameTime);
        }
    }
    //cout << game->getInfo();
    cout << endl<<endl<<endl; 
    cout << game;
    Mix_CloseAudio();
    return 0; 
}