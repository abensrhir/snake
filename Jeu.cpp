/*--------------------------------------------------------------------------                                                                    
--  ,-----.,------.,--.  ,--.,--------.,------.   ,---.  ,--.   ,------.  --
-- '  .--./|  .---'|  ,'.|  |'--.  .--'|  .--. ' /  O  \ |  |   |  .---'  --
-- |  |    |  `--, |  |' '  |   |  |   |  '--'.'|  .-.  ||  |   |  `--,   --
-- '  '--'\|  `---.|  | `   |   |  |   |  |\  \ |  | |  ||  '--.|  `---.  --
--- `-----'`------'`--'  `--'   `--'   `--' '--'`--' `--'`-----'`------' ---
----------------------------------------------------------------------------                                                                    
---------------------------------------------------------------------------
-- Company: 		  Ecole Centrale Paris ( MS Embedded Systems )
-- Engineer: 		  Anass Bensrhir  ---   Alain Tchiegang   ---   Marouane Ben amor
-- 
-- Create Date:    01:58:31 10/02/2011 
-- Design Name:    Centrale Snake V1.0
-- Class Name:     Jeu
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Class Jeu qui permet de Gerer le Jeu au complet (Menu,Jeu,Game-over)
-- Dependencies: 		
--		toute
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/
#include "Jeu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Point.h"
/*-----------*-------------------------------------------	
-- Constucteur de la classe Jeu
-----------*-------------------------------------------*/

Jeu::Jeu() {
	this->enPause = false;
	this->sound_on=true;
	this->niveau_jeu=1;//niveau initial du jeu
	this->a=0;//Attribut pour le niveau a 
	this->b=0;//Attribut pour le niveau b
	this->c=0;//Attribut pour le niveau c 
}
/*-----------*-------------------------------------------	
-- Méthodes pour gérer les Evenements pause et reprise
-----------*-------------------------------------------*/

bool Jeu::get_enPause() {
	return this->enPause;
}

void Jeu::set_enPause(bool enPause) {
	this->enPause = enPause;
}

/*-----------*-------------------------------------------	
-- Méthode pour Effacer la fenetre
-----------*-------------------------------------------*/

void Jeu::effaceEcran() {

	// Coloration des surfaces par 0,0,0
   SDL_FillRect(this->pScreen, NULL, SDL_MapRGB((this->pScreen)->format, 0, 0, 0));

   // Blit de la surface à l'écran et affichage
   SDL_BlitSurface(this->pScreen, NULL, this->pScreen, NULL);
   
}
/*-----------*-------------------------------------------	
-- Méthode Gamerun pour Lancer le jeu
-----------*-------------------------------------------*/

int Jeu::gameRun() {

	bool continuer = true;
	SDL_Event event;
	Uint32 nextStep = SDL_GetTicks() + leSerpent.get_speed();//Refrech
	// Initialisation de SDL Audio/video
	SDL_Color couleurNoire = {0, 0, 0};//couleur noire du texte
	positionFond.x = 0;
    positionFond.y = 0;
	if (SDL_Init (SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		fprintf (stderr, "Erreur d'initialisation de SDL: %s\n", SDL_GetError ());
		return 1;
	}

	atexit (SDL_Quit); // Pour quitter proprement avec libbération de mémoire



	// Initialisation de SDL_Video 640 x 480
	this->pScreen = SDL_SetVideoMode ((640), (480), 32, SDL_SWSURFACE);
	if (this->pScreen == NULL) {
		fprintf (stderr, "Erreur d'init du mode video: %s\n", SDL_GetError ());
		return 2;
	}
	

	// Titre de fenêtre
	SDL_WM_SetCaption ("Centrale Snake", NULL);
	SDL_WM_SetIcon(IMG_Load("snake.ico"), NULL);//Icone
	imageDeFond = IMG_Load("back.jpg");//Fon de la fenetre
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, pScreen, &positionFond);


	// Initialisation de SDL TTF
	if (TTF_Init() < 0) {
		fprintf (stderr, "Erreur d'init de SDL_TTF\n");
		return 3;
	}
	this->couleurNoire.b=0;
	this->couleurNoire.g=0;
	this->couleurNoire.r=0;
	positionScore.x=80;
	positionScore.y=420;
	police = TTF_OpenFont("police.ttf", 25);//initialisation de la police
	texte = TTF_RenderText_Blended(police, score, couleurNoire);
	(this->leSerpent).affiche(this->pScreen);//Affichage du serpent sur la fenetre

	while (continuer == true) {

		while (SDL_PollEvent(&event)) {

			switch(event.type) {

				case SDL_QUIT 	://Gestion de l'evenemnt QUIT
					SDL_FreeSurface(imageDeFond); 
					sound.Splash_sound_destruct();
					continuer=false;
					TTF_CloseFont(police);
					TTF_Quit();
					SDL_Quit();
					break;
				//Gestion des interactions avec le clavier (Up,Down..) et Pause
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_UP	: if (this->enPause == false) { (this->leSerpent).set_direction(Up);} ; break;
						case SDLK_RIGHT	: if (this->enPause == false) { (this->leSerpent).set_direction(Right);} ; break;
						case SDLK_DOWN	: if (this->enPause == false) { (this->leSerpent).set_direction(Down);} ; break;
						case SDLK_LEFT 	: if (this->enPause == false) { (this->leSerpent).set_direction(Left);} ; break;
						case SDLK_SPACE: this->enPause = !this->enPause;
							this->sound.Splash_sound_pause(!this->enPause);
							break;
					}
					break;

			}

		}	// while (sdl_pollevents)



		if (this->enPause == false && SDL_GetTicks() >= nextStep) {
			//deplacement du snake selon la direction voulue
			continuer = (this->leSerpent).deplace();
		
			this->effaceEcran();

			SDL_BlitSurface(imageDeFond, NULL, pScreen, &positionFond);
						
			
			(this->leSerpent).affiche(this->pScreen);//Affichage du serpent sur la fenetre
			//Gestion de l'Evenement Serpent Mange Pomme
			if ((this->leSerpent).eat_apple()){
				personnage.setscore();//Incrémentation du score
			}
			//Gestion de l'Evenement Serpent MORT
			if ((this->leSerpent).is_dead ||this->leSerpent.die()){
				if (personnage.getvies()>0){// si il y'a encore des vies disponibles
					personnage.setvies(personnage.getvies()-1);
					this->leSerpent = temp_leSerpent;
					continuer = 1;
					
				}
				else if (personnage.getvies()==0) {//Sinon Game OVER
				continuer = 0;
				this->gameOver();}
			}
			//Gestion du NIVEAU DE JEU
			//si le joueur Obtient un score multiple de 30 on Incrémente le niveau de difficulté du Jeu (Vitesse su serpent)
			if ((personnage.getscore()/30)==this->niveau_jeu){
				personnage.setniveau(personnage.getniveau()+1);
				this->niveau_jeu++;
			}
			if (personnage.getniveau()==2 && this->a==0){
				leSerpent.set_speed(leSerpent.get_speed()-10);
				this->a=1;
			}
			if (personnage.getniveau()==3&& this->b==0){
				leSerpent.set_speed(leSerpent.get_speed()-20);
				this->b=1;}
			if (personnage.getniveau()==4&& this->c==0){
				leSerpent.set_speed(leSerpent.get_speed()-25);
				this->c=1;
			}
			nextStep = SDL_GetTicks() + leSerpent.get_speed();//Refrech
		}

		//Affichage du Score et d'autres information sur la Fenetre
		// LJ : Il est plus simple d'utiliser des strings pour gérer des chaines de caractères, et pout l'affichage dans 
		// LJ : une string, on peut utiliser un ostringstream.
		sprintf_s(score, "Score  : %d       Vies : %d      Niveau : %d", personnage.getscore(),personnage.getvies(),personnage.getniveau());
		SDL_FreeSurface(texte);
		texte = TTF_RenderText_Blended(police, score, couleurNoire);
		SDL_BlitSurface(texte, NULL, pScreen, &positionScore); /* Blit du texte par-dessus */
		SDL_Flip(pScreen);
	}	// while (continue)

}

/*-----------*-------------------------------------------	
-- Méthode GameOver pour Finir le Jeu et afficher le score final
-----------*-------------------------------------------*/

int Jeu::gameOver() {
	int continuer = 1;
    SDL_Event event;
	this->effaceEcran();
	SDL_FreeSurface(imageDeFond);
	SDL_FreeSurface(texte);
	sound.Splash_sound_destruct();
    imageDeFond = IMG_Load("game_over.jpg");
	police = TTF_OpenFont("police.ttf", 25);
	texte = TTF_RenderText_Blended(police, score, couleurNoire);
	positionScore.x=300;
	positionScore.y=420;
    SDL_BlitSurface(imageDeFond, NULL, pScreen, &positionFond);
	sprintf_s(score, "Score  : %d", personnage.getscore());
	SDL_FreeSurface(texte);
	texte = TTF_RenderText_Blended(police, score, couleurNoire);
	SDL_BlitSurface(texte, NULL, pScreen, &positionScore); /* Blit du texte par-dessus */
    SDL_Flip(pScreen);
     while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
	 SDL_FreeSurface(texte);
	 SDL_FreeSurface(imageDeFond);
    SDL_Quit();
    return 0;
}
/*-----------*-------------------------------------------	
-- Méthode GameMenu pour Afficher le Menu
-----------*-------------------------------------------*/
int Jeu::gameMenu(){

    Action action;
    int continuer = 1;
    SDL_Event event;
    SDL_Surface *ecran_menu = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    ecran_menu = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Centrale Snake", NULL);
	SDL_WM_SetIcon(IMG_Load("snake.ico"), NULL);
    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = IMG_Load("snake_splash.jpg");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran_menu, &positionFond);
    SDL_Flip(ecran_menu);
	sound.Splash_sound_init();
     while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
			//Gestion de l'evenement curseur au dessus d'une zone cliquable
            case SDL_MOUSEMOTION:
                if((event.motion.x > 44) && (event.motion.x < 202) && (event.motion.y < 391) && (event.motion.y > 124))
                    action = jouer;
                else if((event.motion.x > 257) && (event.motion.x < 416) && (event.motion.y < 391) && (event.motion.y > 124))//doivent etre changer
                    action = music;
                else if((event.motion.x > 470) && (event.motion.x < 628) && (event.motion.y < 391) && (event.motion.y > 124))//doivent etre changers
                    action = quit;
                else action = rien;
                      
            
            break;
			//Gestion de l'evenement curseur clique sur une zone cliquable
            case SDL_MOUSEBUTTONUP:
            if (action == jouer) {
                SDL_FreeSurface(imageDeFond); /* On libère la surface */
                SDL_Quit();
                continuer = 0;
                this->gameRun();
            }
            else if (action == music){
				if (this->sound_on){
				this->sound.Splash_sound_destruct();
				this->sound_on=false;}
				else{
				this->sound.Splash_sound_init();
				this->sound_on=true;}

            }
            else if (action == quit) {
                SDL_FreeSurface(imageDeFond); /* On libère la surface */
                SDL_Quit();
                continuer = 0;
            } 
            break;
        }
    }
     SDL_Quit();
    return 0;
}



Jeu::~Jeu() {

	SDL_FreeSurface(this->pScreen);
	TTF_Quit();

}
