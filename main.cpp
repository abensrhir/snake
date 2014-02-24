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
-- Class Name:     Serpent 
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		Main du Jeu snake
-- Dependencies: 		
--		 Classe Jeu
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
#include <iostream>

int main (int argc, char** argv) {

	//Creation de l'objet Jeu
	Jeu leJeu = Jeu();
	//lancement du Menu
	leJeu.gameMenu();


    return 0;
}

