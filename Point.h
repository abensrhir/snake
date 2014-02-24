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
-- Class Name:     Point 
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Header de la Class Point qui permet de Générer des points et de gérer les coordonnées et l'affichage de ces points sur la fenetre
-- Dependencies: 		
--		Aucune
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <string>	


#ifndef __Point__
	#define __Point__
 
using namespace std;
 
class Point {

	private :
		int x;
		int y;
		int r, g, b;
		SDL_Rect rect;	// définit la position du point pr l'affichage via SDL


	public :
		Point();
		Point(int x, int y);
		Point(int r, int g, int b);
		int get_x(); // LJ : Cette fonction devrait être constante
		void set_x(int x);
		int get_y();
		void set_y(int y);
		void affiche(SDL_Surface* pPoint, SDL_Surface* pScreen,const char * img);
		void aleatoire(); // LJ : Le nom de cette fonction n'est pas très clair. Qu'est-ce qui est aléatoire ?

		~Point();
};


#endif
