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
-- Class Name:     Sound
-- Project Name: 
-- Targets: 	   Cross-Platform :Windows/Linux/Mac 
-- Tool versions: 	   Microsoft Visual Studio 2010
-- Description: 
--		 Header de la classe Sound qui permet de gérer le son dans le jeu
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
#include <iostream>
#include <string>
#include <fmod/fmod.h>
#ifndef __sound__
	#define __sound__
using namespace std;

class sound {

	private :
		bool enPause;
		bool sound_on;
		FMOD_SYSTEM *system;
		FMOD_SOUND *musique;
		FMOD_RESULT resultat;
		FMOD_CHANNELGROUP *canal;
		int music_i;
		
	public :
		// LJ : le "sound::" ne sert à rien ici
		int sound::Splash_sound_init();//initialiser la bibliothèque de son 
		int sound::Splash_sound_pause(bool sound_on); // faire une pause de la chanson
		int sound::Splash_sound_destruct();// libérer la mémoire 
};
#endif;