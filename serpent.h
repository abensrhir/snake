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
-- Class Name:     serpent 
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Header de la Class serpent qui permet de construire l'objet serpent avec tous les elements et les interactions avec differents Objets
-- Dependencies: 		
--		Classe Point , Pomme
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/
#include <list>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Point.h"
#include "constantes.h"
#include "Pomme.h"


#ifndef __SERPENT__
	#define __SERPENT__
using namespace std;

class serpent
{
	  
	private:
		std::list <Point> corp_serpent;		// liste des points constituant le corps
		SDL_Surface* pPoint;			// surface correspondant a un point du corps
		int speed;
		int agrandissement;
		SDL_Surface* serpent_shape; // LJ : Est-ce utilis� ?
		int direction_serpent;
		Pomme pomme; // LJ : Je trouve �trange que Serpent g�re l'objet Pomme, n'est-ce pas plut�t � la classe jeu de le faire ?
		bool snake_die;
		Uint32 nextStep;
	public:

	serpent::serpent();

	void serpent::set_direction(int direction);

		
	void serpent::set_agrandissement(int agrandissement);

    int serpent::get_agrandissement();
	void serpent::affiche(SDL_Surface* mainWindow);
	bool serpent::deplace();
	bool serpent::eat_apple(); // LJ : Le nom de cette fonction est ambigu : On pourrait croire qu'il g�re ce que l'on fait quand une pomme est mang�e,
	// LJ : alors qu'en fait, il d�tecte si une pommee est mang�e. Un nom comme "is_apple_eaten" me semblerait plus appropri�
	void serpent::set_speed(int serp_speed);
	int serpent::get_speed() const;
	bool serpent::die();
	bool is_dead;

}; 
#endif

