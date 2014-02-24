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
--		 Class serpent qui permet de construire l'objet serpent avec tous les elements et les interactions avec differents Objets
-- Dependencies: 		
--		Classe Point et Pomme
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/

#include "serpent.h"
/*-----------*-------------------------------------------	
-- Constructeur de la classe Serpent
-----------*-------------------------------------------*/

	serpent::serpent() {
	//Creation d'un serpent initial avec 4 blocs selon les positions initiales (XDEP,YDEP) (Constantes.h)
	(this->corp_serpent).push_back(Point(XDEP, YDEP));
	(this->corp_serpent).push_back(Point(XDEP-1, YDEP));
	(this->corp_serpent).push_back(Point(XDEP-2, YDEP));
	(this->corp_serpent).push_back(Point(XDEP-3, YDEP));

	this->pPoint = SDL_CreateRGBSurface(SDL_SWSURFACE, BLOC, BLOC, 32, 0, 0, 0, 0);
	this->direction_serpent = Right;//direction initiale du serpent (à droite)
	this->is_dead=false;
	this->agrandissement = 0;
	this->speed=INTERVALLE; // Vitesse du serpent initialement "INTERVALLE" (constantes.h)
	this->pomme=Pomme();//Creation de l'objet Pomme
	this->nextStep = SDL_GetTicks() + 10000;//temps de rafraichissement de l'écran
}

/*-----------*-------------------------------------------	
-- Méthode set_direction qui permet de modifier la direction du serpent en prenant compte de quelques contraintes
-----------*-------------------------------------------*/

	void serpent::set_direction(int direction) {

		bool autorise = true;
		//Prise en compte des contraintes
		switch (this->direction_serpent) {

			case Up :
				if (direction == Down) { autorise = false; }; break;

			case Right :
				if (direction == Left) { autorise = false; }; break;

			case Down :
				if (direction == Up) { autorise = false; }; break;

			case Left :
				if (direction == Right) { autorise = false; }; break;

		}

		//Mise à jour de la direction du serpent
		if (autorise == true) { // LJ : On écrira plutôt if(autorise), puisqu'autorise est déjà une variable booléenne
			this->direction_serpent = direction;
		}

}
/*-----------*-------------------------------------------	
-- Getters de la classe serpent
-----------*-------------------------------------------*/
	int serpent::get_speed() const {
			return this->speed;
		}

    int serpent::get_agrandissement() {
			return this->agrandissement;
		}
/*-----------*-------------------------------------------	
-- Setters de la classe serpent
-----------*-------------------------------------------*/
	void serpent::set_agrandissement(int agrandissement) {
			this->agrandissement = agrandissement;
		}
	void serpent::set_speed(int serp_speed) {
			this->speed = serp_speed;
		}
/*-----------*-------------------------------------------	
-- Méthode affiche qui permet d'afficher les elements du serpent et la pomme sur la mainwindow
-----------*-------------------------------------------*/
    
	void serpent::affiche(SDL_Surface* mainWindow) {
		//i itérateur sur les elements du snake
		for (std::list<Point>::iterator i = (corp_serpent).begin(); i != (corp_serpent).end(); i++) {
		(*i).affiche(pPoint, mainWindow,"c1.jpg"); // LJ : On écrira plutôt i->affiche...
		}

		this->pomme.affiche(pPoint,mainWindow,"apple.jpg");
		
		SDL_Flip(mainWindow);

}
/*-----------*-------------------------------------------	
-- Méthode deplace qui permet de deplacer le snake selon la direction choisie
-- avec prise en compte de la contrainte Dépassement des limites de la fenetre et mort du snake
-----------*-------------------------------------------*/
	bool serpent::deplace() {

		int new_x = (this->corp_serpent).front().get_x();
		int new_y = (this->corp_serpent).front().get_y();


		switch (this->direction_serpent) {
		case Up 	:	new_y--; break;
		case Right	:	new_x++; break;
		case Down	: 	new_y++; break;
		case Left	:	new_x--; break;
		default : break;
		}

		//Condition de dépassement des limites de la fenetre et lorsque le serpent se mord
		if (new_y < 2 || new_y >= YMAX-8 || new_x < 2 || new_x >= XMAX-2 || this->die() == true) {

		this->is_dead=true;	// retourne true si le serpent sort des limites de l'écran ou s'il se mord

		} 
		//Gestion de l'Evenement manger pomme
		else {
		if (this->eat_apple() == true) {
			(this->pomme).aleatoire();//generation de nouvelles coordonnées aléatoires de la pomme // LJ : Que se passe-t-il si ces coordonnées sont sur le corps actuel du serpent ?
			this->agrandissement = AGRANDISSEMENT;//Agrandissement du serpent(constantes.h)

		} 

		
		if (this->agrandissement == 0) {

			(this->corp_serpent).pop_back();		// supprime l'élément de tête

		} else {

			this->agrandissement--;			// diminue le nombre d'agrandissements

		}
		(this->corp_serpent).push_front(Point(new_x, new_y));	// ajoute le nouvel élement en tete

		return true;
	}


	}
/*-----------*-------------------------------------------	
-- Méthode eat_apple qui permet de gerer l'evenement serpent mange une pomme
-----------*-------------------------------------------*/
	bool serpent::eat_apple() {
		bool snake_eat_apple = false;	
		std::list<Point>::iterator i = (this->corp_serpent).begin();//itérateur i sur la liste corp_serpent

		while (snake_eat_apple == false && i != (this->corp_serpent).end()) {
			//vérification des coordonnées de la pomme avec les coordonénes de la tete du serpent
		if ( (*i).get_x() == (this->pomme.get_x()) && ((*i).get_y() == (this->pomme.get_y() ))) {
			snake_eat_apple = true;
			
		}i++;}
		return snake_eat_apple;
		}
	
/*-----------*-------------------------------------------	
-- Méthode die qui permet de gerer l'evenement mort du serpent
-----------*-------------------------------------------*/


	bool serpent::die() {
		bool snake_die = false;	// condition de sortie anticipée du while
		std::list<Point>::iterator i = (this->corp_serpent).begin();	// iterateur
		i++;	// on se déplace au second point du serpent

		/*--- vérifie si la tête du serpent ne se trouve pas sur un point ou se
		trouve déjà son corps ---*/

		while (snake_die == false && i != (this->corp_serpent).end()) {

		/*if ( (*i).get_x() == (this->corp_serpent).front().get_x() && (*i).get_y() == (this->corp_serpent).front().get_y()||new_y < 1 || new_y >= YMAX-6 || new_x < 1 || new_x >= XMAX-1 ) {
			snake_die = true;
		}*/
		if ( (*i).get_x() == (this->corp_serpent).front().get_x() && (*i).get_y() == (this->corp_serpent).front().get_y() ) {
			snake_die = true;
		}

		i++;
		}


		return snake_die;
}


