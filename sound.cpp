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
--		 Class Sound qui permet de g�rer le son dans le jeu
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
//Initialiser le son et jouer la musique "smb-castle.mp3" (cr�dit sup�r-mario) 
int sound::Splash_sound_init(){
	
	FMOD_System_Create(&system);// Cr�ation et initialisation d'un objet syst�me 
	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);// Initialiser le syst�me
	/* Chargement du son et v�rification du chargement */
	resultat = FMOD_System_CreateSound(system, "smb-castle.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
	if (resultat != FMOD_OK)
	{
		fprintf(stderr, "Impossible de lire le fichier mp3\n");
		exit(EXIT_FAILURE);
	}
	FMOD_System_GetMasterChannelGroup(system,&canal);
	/* On active la r�p�tition de la musique � l'infini */
	FMOD_Sound_SetLoopCount(musique, -1);//la musique sera  r�p�t�e � l'infini
	/* On joue la musique */
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);// Jouer le son
	}

//Gerer le pause ou la reprise du son

int sound::Splash_sound_pause(bool sound_on){
	if (sound_on){
		FMOD_ChannelGroup_SetPaused(canal,0);//On enl�ve la pause
	}
	else{
		FMOD_ChannelGroup_SetPaused(canal,1);// On met la pause
}
	return 0;
}
//Destructeur du son et lib�ration du Tampon m�moire
int sound::Splash_sound_destruct(){
	/* On lib�re le son et on ferme et lib�re l'objet syst�me */
	FMOD_Sound_Release(musique);
	FMOD_System_Close(system);
	FMOD_System_Release(system);
	return 0;
}