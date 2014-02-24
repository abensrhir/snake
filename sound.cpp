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
--		 Class Sound qui permet de gérer le son dans le jeu
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

#include "sound.h"
//Initialiser le son et jouer la musique "smb-castle.mp3" (crédit supér-mario) 
int sound::Splash_sound_init(){
	
	FMOD_System_Create(&system);// Création et initialisation d'un objet système 
	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);// Initialiser le système
	/* Chargement du son et vérification du chargement */
	resultat = FMOD_System_CreateSound(system, "smb-castle.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
	if (resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire le fichier mp3\n");
		exit(EXIT_FAILURE);
	}
	FMOD_System_GetMasterChannelGroup(system,&canal);
	/* On active la répétition de la musique à l'infini */
	FMOD_Sound_SetLoopCount(musique, -1);//la musique sera  répétée à l'infini
	/* On joue la musique */
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);// Jouer le son
	}

//Gerer le pause ou la reprise du son

int sound::Splash_sound_pause(bool sound_on){
	if (sound_on){
		FMOD_ChannelGroup_SetPaused(canal,0);//On enlève la pause
	}
	else{
		FMOD_ChannelGroup_SetPaused(canal,1);// On met la pause
}
	return 0;
}
//Destructeur du son et libération du Tampon mémoire
int sound::Splash_sound_destruct(){
	/* On libère le son et on ferme et libère l'objet système */
	FMOD_Sound_Release(musique);
	FMOD_System_Close(system);
	FMOD_System_Release(system);
	return 0;
}