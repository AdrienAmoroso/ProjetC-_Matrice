/*****************************************************************//**
 * \file   CException.cpp
 * \brief  Corps de la classe CException.
 *		   Cette classe permet de créer des objets qui sont remontés
 *		   lors de la levée d’exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/


/**************************************************************
Nom : EXCModifierValeur
***************************************************************
Cette fonction permet de modifier la valeur de l’exception.
***************************************************************
Entrée : La nouvelle valeur de l’exception
Nécessite : néant
Sortie : néant
Entraîne : L’exception est modifiée.
***************************************************************/
inline void CException::EXCModifierValeur(unsigned int uiNvValeur)
{
	uiEXCValeur = uiNvValeur;
}

/**************************************************************
Nom : EXCLireValeur
***************************************************************
Cette fonction permet de consulter la valeur de l’exception.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : La valeur de l’exception
Entraîne : La valeur de l'exception est retournée.
***************************************************************/
inline const unsigned int CException::EXCLireValeur()
{
	return(uiEXCValeur);
}