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
-- Class Name:     Pomme 
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Header de la class Pomme qui h�rite de la classe Point et qui sert � g�rer les pommes.
-- Dependencies: 		
--		 Class Point
-- Revision: 
-- Revision 0.01 - 
-- Additional Comments: 
--
------------------------------------------------------------------------------ 
/*-----------*-------------------------------------------	
-- Declaration des Librairies
-----------*-------------------------------------------*/
#include "Point.h"

#ifndef __POMME__
	#define __POMME__
        		
	
class Pomme : public Point { // LJ : L'heritage entre Point et Pomme me semble suspect. 
	// LJ : Dire qu'une pomme poss�de un point, oui. Dire que Pomme est un point (ce que signifie l'h�ritage),
	// LJ : m�me si dans le cas pr�sent ne pose pas de probl�mes, me semble philospohiquement douteux. Par exemple
	// LJ : selon le LSP, on pourrait vouloir mettre des Pommes dans la liste corps_serpent

	private :
		int score;// LJ : A priori, ne sert � rien...
		
	public : 
		Pomme();//Constructeur
		~Pomme();//Destructeur
};

#endif
