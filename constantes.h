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
-- Class Name:     **********
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Header qui sert a stocker les constantes initiales du jeu
-- Dependencies: 		
--		 Aucune
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/
#ifndef __CONSTANTES__
	#define __CONSTANTES__

	/* Dimensions de l'aire de jeu */
	#define XMAX 	64 // LJ : Utiliser des constante plutôt que des macros permet d'avoir des vérifiactions de type (int const XMAX = 64;)
	#define YMAX 	48

	/* Point de départ du snake sur l'aire de jeu */
	#define XDEP 	10
	#define YDEP 	5

	/* Largeur et hauteur d'un bloc */
	#define BLOC 	10

	/* Directions */ // LJ : Ici, une enum serait plus appropriée
	#define Up	0
	#define Right 	1
	#define Down 	2
	#define Left 	3

	/* Intervalle entre deux steps */
	#define INTERVALLE	80

	/* Nombre de points dont s'agrandit serpent quand mange une pomme */
	#define AGRANDISSEMENT 1
	/* Ennumérateur des avtion du menu */
	enum Action {
		jouer,
		music,
		quit,
		rien};

#endif;

