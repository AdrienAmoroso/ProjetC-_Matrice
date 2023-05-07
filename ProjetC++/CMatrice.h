/*****************************************************************//**
 * \file   CMatrice.h
 * \brief  Interface de la classe CMatrice.
 *		   Cette classe permet de cr�er des matrices de type quelconque
 *		   et de les manipuler.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef C_MATRICE_H
#define C_MATRICE_H 10

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "CException.h"

#define DIVISION_PAR_ZERO 102
#define TABLEAU_NULL 103
#define INDEX_LIGNE_DEPASSE 104
#define INDEX_COLONNE_DEPASSE 105
#define FORMAT_INCORRECT 107

using namespace std;



template <class MType>
class CMatrice
{
	/******** Attributs *********/

private:
	unsigned int uiMATNbLignes;

	unsigned int uiMATNbCol;

	MType **ppmtMATTableau;

public:

	/******** Constructeurs - Destructeur *********/

	CMatrice<MType>();
	/* Constructeur par d�faut de la classe.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La matrice est initialis�e.
	*/
	CMatrice<MType>(unsigned int uiNumCol, unsigned int uiNumLigne);
	/* Constructeur de confort de la classe qui cr�� une matrice � partir de dimensions donn�es.
		E : Matrice de type quelconque
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La matrice est initialis�e � partir de dimensions donn�es.
	*/
	
	CMatrice<MType>(const CMatrice<MType>& mtMATParam);
	/* Constructeur de recopie de la classe.
		E : Objet CMatrice
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La matrice est initialis�e � partir d'une matrice d'un objet CMatrice donn�.
	*/

	~CMatrice<MType>();
	/* Destructeur de la classe CMatrice.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La matrice est d�truite.
	*/


	/********  M�thodes *********/


	// Accesseurs en lecture

	const unsigned int MATGetNbLignes();
	/* Cette fonction permet de consulter le nombre de lignes.
		E : n�ant
		N�cessite : n�ant
		S : Nombre de lignes
		Entra�ne : La valeur du nombre de lignes est retourn�e.
	*/

	const unsigned int MATGetNbCol();
	/* Cette fonction permet de consulter le nombre de colonnes.
		E : n�ant
		N�cessite : n�ant
		S : Nombre de colonnes
		Entra�ne : La valeur du nombre de colonnes est retourn�e.
	*/

	void MATAfficherMatrice();
	/* Cette fonction permet d'afficher les �l�ments de la matrice.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La matrice s'affiche � l'�cran.
	*/

	const MType MATLireElement(unsigned int uiNumLigne, unsigned int uiNumCol);
	/* Cette fonction permet de consulter un �l�ment de la matrice � une position donn�e.
		E : Num�ro de ligne et num�ro de colonne
		N�cessite : n�ant
		S : L'�l�ment � cette position
		Entra�ne : L'�l�ment � la position donn�e est retourn�.
	*/

	// Accesseur en �criture

	void MATModifierElement(unsigned int uiMATNumLigne, unsigned int uiMATNumCol, MType mtNvElement);
	/* Cette fonction permet de modifier un �l�ment � la position donn�e.
		E : Num�ro de ligne, num�ro de colonne ainsi que le nouvel �l�ment
		N�cessite : n�ant
		S : n�ant
		Entra�ne : L'�l�ment � la position donn�e est modifi�.
	*/
	

	// Surcharge des Op�rateurs


	/**************************************************************
	Nom : operator*
	***************************************************************
	Surcharge de l'op�rateur * qui permet de multiplier une matrice
	� une constante.
	***************************************************************
	Entr�e : Constante
	N�cessite : n�ant
	Sortie : CMatrice multipli�e par la constante.
	Entra�ne : La matrice est multipli�e par la constante.
	***************************************************************/
	CMatrice<MType> operator*(const MType& mtValeur)
	{
		CMatrice<MType> mtMATResultat(uiMATNbCol, uiMATNbLignes);

		for (unsigned int i = 0; i < uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < uiMATNbCol; j++)
			{
				mtMATResultat.ppmtMATTableau[i][j] = ppmtMATTableau[i][j] * mtValeur;
			}
		}

		return mtMATResultat;
	}

	/**************************************************************
	Nom : operator/
	***************************************************************
	Surcharge de l'op�rateur / qui permet de diviser une matrice par
	une constante.
	***************************************************************
	Entr�e : Constante
	N�cessite : n�ant
	Sortie : CMatrice divis�e par la constante.
	Entra�ne : La matrice est divis�e par la constante.
	***************************************************************/
	CMatrice operator/(const MType& mtValeur)
	{
		if (mtValeur == 0)
		{
			CException ValeurNulle;
			ValeurNulle.EXCModifierValeur(DIVISION_PAR_ZERO);
			throw(ValeurNulle);
		}
		
		CMatrice<MType> mtMATResultat(uiMATNbCol, uiMATNbLignes);

		for (unsigned int i = 0; i < uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < uiMATNbCol; j++)
			{
				mtMATResultat.ppmtMATTableau[i][j] = ppmtMATTableau[i][j] / mtValeur;
			}
		}

		return mtMATResultat;
	}

	/**************************************************************
	Nom : operator<<
	***************************************************************
	Surcharge de l'op�rateur << qui permet d'afficher le contenu 
	d'un objet CMatrice avec la fonction cout dans notre cas (et
	g�n�ralement avec un objet de la classe ostream).
	***************************************************************
	Entr�e : Objet CMatrice
	N�cessite : n�ant
	Sortie : CMatrice
	Entra�ne : La matrice est affich�e � l'�cran avec cout.
	***************************************************************/
	friend ostream& operator<<(ostream& os, const CMatrice<MType>& mtMATParam)
	{
		for (unsigned int i = 0; i < mtMATParam.uiMATNbLignes; i++)
		{
			for (unsigned int j = 0; j < mtMATParam.uiMATNbCol; j++)
			{
				os << mtMATParam.ppmtMATTableau[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	/**************************************************************
	Nom : operator=
	***************************************************************
	Surcharge de l'op�rateur = qui permet d'affecter le contenu d'un
	objet CMatrice dans un autre.
	***************************************************************
	Entr�e : Objet CMatrice
	N�cessite : n�ant
	Sortie : n�ant
	Entra�ne : La matrice est affect�e � l'objet pass� en param�tre.
	***************************************************************/
	CMatrice<MType>& operator=(const CMatrice<MType>& mtMATParam)
	{
		if (this != &mtMATParam) {
			// Copie des valeurs de l'autre matrice dans la matrice actuelle
			for (unsigned int i = 0; i < uiMATNbLignes; i++) {
				for (unsigned int j = 0; j < uiMATNbCol; j++) {
					ppmtMATTableau[i][j] = mtMATParam.ppmtMATTableau[i][j];
				}
			}
		}

		uiMATNbLignes = mtMATParam.uiMATNbLignes;
		uiMATNbCol = mtMATParam.uiMATNbCol;

		return *this;
	}
};

#include "CMatrice.ipp"
#endif