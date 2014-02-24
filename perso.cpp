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
#include "perso.h"
/*-----------*-------------------------------------------	
-- Constructeur de la Classe perso
-----------*-------------------------------------------*/
perso::perso(){
	this->nom="snake";
	this->score=0;
	this->vies=3;// 3 vies par défaut
	this->niveau=1;
}
/*-----------*-------------------------------------------	
-- Getters de la Classe perso
-----------*-------------------------------------------*/
int perso:: getscore(){
	return this->score;
}

int perso:: getvies(){
	return this->vies;
}
int perso:: getniveau(){
	return this->niveau;
}
/*-----------*-------------------------------------------	
-- Setters de la Classe perso
-----------*-------------------------------------------*/
void perso:: setscore(){
		this->score=this->score+5;
}
void perso:: setvies(int vies){
	this->vies=vies;
}
void perso:: setniveau(int niveau){
	this->niveau=niveau;
}
/*-----------*-------------------------------------------	
-- Méthode vérifier nombre de vies disponibles
-----------*-------------------------------------------*/
bool perso:: verifiervies(){
	if (this->vies==0){
		return false;
	}
	return true;
}
