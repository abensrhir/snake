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
--		 Header de la Class Jeu qui permet de Gerer le Jeu au complet (Menu,Jeu,Game-over)
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
#include "serpent.h"
#include "perso.h"
#include "SDL/SDL.h"
#include "sound.h"
#include <iostream>
#include <string>
#include <fmod/fmod.h>

#ifndef __CSTATE__
	#define __CSTATE__
using namespace std;

class Jeu {

	private :
		SDL_Surface* pScreen;
		SDL_Surface* imageDeFond;
		SDL_Surface* texte;
		SDL_Rect positionFond;
		SDL_Rect positionScore;
		TTF_Font *police;
		bool enPause;
		bool sound_on;
		char score[100];
		int niveau_jeu;
		serpent leSerpent;
		perso personnage;
		string sccore;
		SDL_Color couleurNoire;
		sound sound;
		serpent temp_leSerpent;
		int a; // LJ : Qu'est-ce que ça représente ?
		int b;
		int c;
	public :
		Jeu();
		bool get_enPause();
		void set_enPause(bool enPause);
		void effaceEcran();
		int gameInit();
		int gameRun();
		int gameOver();
		int Jeu::gameMenu();
		~Jeu();
};


#endif
