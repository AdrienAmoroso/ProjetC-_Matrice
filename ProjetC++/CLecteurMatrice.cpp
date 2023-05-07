/*****************************************************************//**
 * \file   CLecteurMatrice.h
 * \brief  Corps de la classe CLecteurMatrice.
 *		   Cette classe permet de créer des matrices de type quelconque
		   à partir d'un fichier texte.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l’exception.
		 Structure : Cette classe contient une méthode de modification de la valeur
					 de l'exception, une méthode de consultation de celle-ci et
					 une méthode d'affichage des messages d'erreurs.
		 Méthode : néant
		 Modules internes:*/

#include "CLecteurMatrice.h"

#define OUVERTURE_ECHOUEE 106

// CORPS


/**************************************************************
Nom : LECCreerMatDepuisFichier
***************************************************************
Cette fonction permet de créer une matrice à partir d'un fichier.
***************************************************************
Entrée : Nom du fichier
Nécessite : néant
Sortie : Un objet de la classe CMatrice
Entraîne : Une matrice extraite du fichier est retournée.
***************************************************************/
CMatrice<double> CLecteurMatrice::LECCreerMatDepuisFichier(const char *sFichier)
{
	ifstream ISMonFichier(sFichier);

	if (ISMonFichier.fail())
	{
		CException EXCOuvertureEchouee;
		EXCOuvertureEchouee.EXCModifierValeur(OUVERTURE_ECHOUEE);
		throw(EXCOuvertureEchouee);
	}

	// Teste si le type est bon
	char pcType[256];
	char pcTypeRecherche[] = "double";
	ISMonFichier.getline(pcType, 256);

	for (int i = 0; i < strlen(pcType); i++)
	{
		pcType[i] = tolower(pcType[i]);
	}

	char* cPos = strstr(pcType, pcTypeRecherche);

	if (cPos == nullptr)
	{
		cout << "MAUVAIS TYPE !" << endl;
	}
	else cout << "BON TYPE ! " << endl;

	// Récupération du nombre de lignes et du nombre de colonnes 

	ISMonFichier.getline(pcType, 256);
	unsigned int uiNbrLignes = stoi(strchr(pcType, '=') + 1);

	ISMonFichier.getline(pcType, 256);
	unsigned int uiNbrColonnes = stoi(strchr(pcType, '=') + 1);

	if (!uiNbrColonnes)
	{
		cout << "Nombre de colonnes non renseigné" << endl;
	}
	if (!uiNbrLignes)
	{
		cout << "Nombre de lignes non renseigné" << endl;
	}

	CMatrice<double> dMATTestMat(uiNbrColonnes, uiNbrLignes);
	ISMonFichier.getline(pcType, 256);

	/*	
		Le code suivant va nous permettre d'extraire les éléments de la matrice 
		s'ils respectent le format imposé.
	*/

	for (unsigned int i = 0; i < uiNbrLignes; i++) 
	{
		ISMonFichier.getline(pcType, 256);				// Permet de passer à la ligne suivante
		char* pCurseur = pcType;
		for (unsigned int j = 0; j < uiNbrColonnes; j++)
		{
			while (*pCurseur == ' ') pCurseur++;						// Ignore les espaces indésirables
			double dVal = 0.0;											// On initialise dVal à chaque itération, c'est cette variable qui sera ajoutée à notre matrice
			bool bNegatif = false;										// Permet de savoir si l'élément est un nombre négatif

			// Teste si l'élément est négatif 
			if (*pCurseur == '-')
			{
				bNegatif = true;
				pCurseur++;

				if ((*pCurseur < '0' || *pCurseur > '9') && *pCurseur != 32 && *pCurseur != '\0')
				{
					CException EXCFormatIncorrect;
					EXCFormatIncorrect.EXCModifierValeur(FORMAT_INCORRECT);
					throw(EXCFormatIncorrect);
				}
			}
			// cette boucle gère le cas où l'élément est une valeur numérique
			
			while (*pCurseur >= '0' && *pCurseur <= '9')
			{
				dVal = dVal * 10.0 + (*pCurseur - '0');
				pCurseur++;

				// Ce test permet d'afficher une erreur si le format n'est pas bon
				if (*pCurseur != '.' && *pCurseur != ',' && (*pCurseur < '0' || *pCurseur > '9') && *pCurseur != 32 && *pCurseur != '\0')
				{
					CException EXCFormatIncorrect;
					EXCFormatIncorrect.EXCModifierValeur(FORMAT_INCORRECT);
					throw(EXCFormatIncorrect);
				}
					

			}

			// On teste ici si l'élément est décimal
			if (*pCurseur == '.' || *pCurseur == ',')
			{
				double dDec = 10.0;
				pCurseur++;
				while (*pCurseur >= '0' && *pCurseur <= '9')
				{
					dVal += (*pCurseur - '0') / dDec;
					dDec *= 10.0;
					pCurseur++;

					if (*pCurseur != '.' && *pCurseur != ',' && (*pCurseur < '0' || *pCurseur > '9') && *pCurseur != 32 && *pCurseur != '\0')
					{
						CException EXCFormatIncorrect;
						EXCFormatIncorrect.EXCModifierValeur(FORMAT_INCORRECT);
						throw(EXCFormatIncorrect);
					}
				}
			}

			// Enfin, dVal devient négatif si un moins '-' a été détecté auparavant
			if (bNegatif)
			{
				dVal = -dVal;
			}
			dMATTestMat.MATModifierElement(i, j, dVal);
		}
	}
	return dMATTestMat;
}