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
--		 Class perso qui permet de gérer toutes les données du joueur(score,vies,niveau)
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
#include <cstdio>
#include <string>



#ifndef __perso__
	#define __perso__
using namespace std;

class perso
{
	  
	private:
		std::string nom;		// nom joueur
		int score;
		int vies;
		int niveau;
		
		
	public:
		perso::perso();
		int perso:: getscore();
		void perso:: setscore();
		void perso:: setvies(int vies);
		int perso:: getvies();
		void perso:: bananer_score();
		bool perso:: verifiervies();
		int perso:: getniveau();
		void perso:: setniveau(int niveau);
}; 
#endif
