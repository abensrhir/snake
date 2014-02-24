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
--		 Class Point qui permet de Générer des points et de gérer les coordonnées et l'affichage de ces points sur la fenetre
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
#include <iostream>
#include <ctime>	// pour le nombre aléatoire

#include "SDL/SDL.h"
#include "constantes.h"
#include "Point.h"
/*-----------*-------------------------------------------	
-- Constructeurs de la classe Point
-----------*-------------------------------------------*/

Point::Point() {
	// LJ : Bien que légal, le this-> n'est pas obligatoire dans la plupart des cas	
	this->aleatoire();//Generation de coordonnées aléatoires x et y
	//(r,g,b) pour la transparence
	this->r = 255;
	this->g = 128;
	this->b = 255;
	//Coordonnées x et y
	(this->rect).x = BLOC * (this->x);
	(this->rect).y = BLOC * (this->y);

}




Point::Point(int x, int y) {
	this->x = x;
	this->y = y;

	this->r = 255;
	this->g = 128;
	this->b = 255;

	(this->rect).x = BLOC * (this->x);
	(this->rect).y = BLOC * (this->y);

}


Point::Point(int r, int g, int b) {

	this->aleatoire();

	this->r = r;
	this->g = g;
	this->b = b;

	(this->rect).x = BLOC * (this->x);
	(this->rect).y = BLOC * (this->y);
}


/*-----------*-------------------------------------------	
-- Getters de la classe Point
-----------*-------------------------------------------*/


int Point::get_x() {
	return this->x;
}
int Point::get_y() {
	return this->y;
}


/*-----------*-------------------------------------------	
-- Setters de la classe Point
-----------*-------------------------------------------*/
void Point::set_x(int x) {
	this->x = x;
	(this->rect).x = BLOC * (this->x); // LJ : Je trouve que toutes ces parenthèses inutiles alourdissent en fin de compte la lecture
}

void Point::set_y(int y) {
	this->y = y;
	(this->rect).y = BLOC * (this->y);
}

/*-----------*-------------------------------------------	
-- Méthode affiche qui permet d'afficher les points sur la mainwindow
-----------*-------------------------------------------*/

void Point::affiche(SDL_Surface* pPoint, SDL_Surface* pScreen,const char * img) {

   // Coloration des surfaces
   SDL_FillRect(pPoint, NULL, SDL_MapRGB(pScreen->format, 255, 128, 255));
   pPoint=IMG_Load(img);
   SDL_SetColorKey(pPoint, SDL_SRCCOLORKEY, SDL_MapRGB(pPoint->format, 255, 128, 255));
   
   SDL_BlitSurface(pPoint, NULL, pScreen, &(this->rect));
}
/*-----------*-------------------------------------------	
-- Méthode aléatoire qui permet de Génerer des coordonnées aléatoires pour x et y
-----------*-------------------------------------------*/

void Point::aleatoire() {
	srand(time(NULL));

	this->x =2+ rand() % (XMAX-6);
	this->y =4 + rand() % (YMAX -15);

	(this->rect).x = BLOC * (this->x);
	(this->rect).y = BLOC * (this->y);
}
/*-----------*-------------------------------------------	
-- Déstructeur de la classe Point
-----------*-------------------------------------------*/

Point::~Point() {

}
