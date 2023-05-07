/*****************************************************************//**
 * \file   CMatrice.ipp
 * \brief  Corps de la classe CMatrice.
 *		   Cette classe permet de cr�er des matrices de type quelconque
           et de les manipuler.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l�exception.
		 Structure : Cette classe contient une m�thode de modification de la valeur
					 de l'exception, une m�thode de consultation de celle-ci et 
					 une m�thode d'affichage des messages d'erreurs.
		 M�thode : n�ant
		 Modules internes:*/

// CORPS

// Constructeurs - Destructeur

/**************************************************************
Nom : CMatrice
***************************************************************
Constructeur par d�faut de la classe CMatrice qui permet
d�initialiser un objet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La matrice est initialis�e.
***************************************************************/
template <class MType>
CMatrice<MType>::CMatrice()
{
	uiMATNbLignes = 0;
	uiMATNbCol = 0;
	ppmtMATTableau = nullptr;
}

/**************************************************************
Nom : CMatrice
***************************************************************
Constructeur de confort de la classe CMatrice qui permet
d�initialiser un objet � partir de dimensions donn�es.
***************************************************************
Entr�e : Matrice de type quelconque
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La matrice est initialis�e � partir de dimensions donn�es.
***************************************************************/
template <class MType>
CMatrice<MType>::CMatrice(unsigned int uiNumCol, unsigned int uiNumLigne)
{
	uiMATNbLignes = uiNumLigne;
	uiMATNbCol = uiNumCol;

	// Allocation dynamique du tableau � deux dimensions
	ppmtMATTableau = new MType * [uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		ppmtMATTableau[i] = new MType[uiMATNbCol];
	}

	// Initialisation des valeurs du tableau � z�ro
	for (unsigned int i = 0; i < uiMATNbLignes; i++) 
	{
		for (unsigned int j = 0; j < uiMATNbCol; j++) 
		{
			ppmtMATTableau[i][j] = MType();					
		}
	}
}

/**************************************************************
Nom : CMatrice
***************************************************************
Constructeur de recopie de la classe CMatrice qui permet
d�initialiser un objet � partir d'un autre objet de la classe CMatrice.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La matrice est initialis�e.
***************************************************************/
template <class MType>
CMatrice<MType>::CMatrice(const CMatrice<MType>& mtMATParam)
{
	uiMATNbLignes = mtMATParam.uiMATNbLignes;
	uiMATNbCol = mtMATParam.uiMATNbCol;

	// Allouer de la m�moire pour la copie du tableau � deux dimensions
	ppmtMATTableau = new MType * [uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; ++i) {
		ppmtMATTableau[i] = new MType[uiMATNbCol];
	}

	// Copier les �l�ments de l'objet source dans le tableau de la nouvelle instance
	for (unsigned int i = 0; i < uiMATNbLignes; ++i) {
		for (unsigned int j = 0; j < uiMATNbCol; ++j) {
			ppmtMATTableau[i][j] = mtMATParam.ppmtMATTableau[i][j];
		}
	}
}

/**************************************************************
Nom : ~CMatrice
***************************************************************
Destructeur de la classe CMatrice
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La matrice est d�truite.
***************************************************************/
template <class MType>
CMatrice<MType>::~CMatrice()
{
	/*if (ppmtMATTableau == nullptr)
	{
		CException EXCtableauNull;
		EXCtableauNull.EXCModifierValeur(TABLEAU_NULL);
		throw(EXCtableauNull);
	}
	*/
	for (unsigned int i = 0; i < uiMATNbLignes; ++i) 
	{
		delete[] ppmtMATTableau[i];
	}
	delete[] ppmtMATTableau;
	ppmtMATTableau = nullptr;

	uiMATNbLignes = 0;
	uiMATNbCol = 0;
}


// Accesseurs en Lecture


/**************************************************************
Nom : MATGetNbLignes
***************************************************************
Cette fonction permet de retourner le nombre de lignes de la
matrice.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre de lignes
Entra�ne : Le nombre de lignes est retourn�.
***************************************************************/
template <class MType>
inline const unsigned int CMatrice<MType>::MATGetNbLignes()
{
	return uiMATNbLignes;
}

/**************************************************************
Nom : MATGetNbCol
***************************************************************
Cette fonction permet de retourner le nombre de colonnes de la
matrice.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre de colonnes
Entra�ne : Le nombre de colonnes est retourn�.
***************************************************************/
template <class MType>
inline const unsigned int CMatrice<MType>::MATGetNbCol()
{
	return uiMATNbCol;
}

/**************************************************************
Nom : MATAfficherMatrice
***************************************************************
Cette fonction permet d'afficher la matrice.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La matrice est affich�e � l'�cran.
***************************************************************/
template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	//cout << "Nombre de Colonnes : " << uiMATNbCol << endl;
	//cout << "Nombre de Lignes : " << uiMATNbLignes << "\n"<<endl;

	for (unsigned int i = 0; i < uiMATNbLignes; ++i)
	{
		for (unsigned int j = 0; j < uiMATNbCol; ++j)
		{
			cout << ppmtMATTableau[i][j] << " ";
		}
		cout << endl;
	}
}

/**************************************************************
Nom : MATLireElement
***************************************************************
Cette fonction permet de lire un �l�ment � une position donn�e.
***************************************************************
Entr�e : Num�ro de la ligne, num�ro de la colonne
N�cessite : n�ant
Sortie : L'�l�ment � cette position
Entra�ne : L'�l�ment � la position donn�e est retourn�.
***************************************************************/
template <class MType>
inline const MType CMatrice<MType>::MATLireElement(unsigned int uiMATNumLigne, unsigned int uiMATNumCol)
{
	if (uiMATNumLigne >= uiMATNbLignes || uiMATNumLigne < 0)
	{
		CException EXCHorsIndexLigne;
		EXCHorsIndexLigne.EXCModifierValeur(INDEX_LIGNE_DEPASSE);
		throw(EXCHorsIndexLigne);
	}

	if (uiMATNumCol >= uiMATNbCol || uiMATNumCol < 0)
	{
		CException EXCHorsIndexColonne;
		EXCHorsIndexColonne.EXCModifierValeur(INDEX_COLONNE_DEPASSE);
		throw(EXCHorsIndexColonne);
	}

	return ppmtMATTableau[uiMATNumLigne][uiMATNumCol];
}

// Accesseur en Ecriture

/**************************************************************
Nom : MATModifierElement
***************************************************************
Cette fonction permet de modifier un �l�ment � une position donn�e.
***************************************************************
Entr�e : Num�ro de la ligne, num�ro de la colonne, nouvel �l�ment
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L'�l�ment � la position donn�e est modifi�.
***************************************************************/
template <class MType>
inline void CMatrice<MType>::MATModifierElement(unsigned int uiMATNumLigne, unsigned int uiMATNumCol, MType mtNvElement)
{
	if (uiMATNumLigne >= uiMATNbLignes || uiMATNumLigne < 0)
	{
		CException EXCHorsIndexLigne;
		EXCHorsIndexLigne.EXCModifierValeur(INDEX_LIGNE_DEPASSE);
		throw(EXCHorsIndexLigne);
	}

	if (uiMATNumCol >= uiMATNbCol || uiMATNumCol < 0)
	{
		CException EXCHorsIndexColonne;
		EXCHorsIndexColonne.EXCModifierValeur(INDEX_COLONNE_DEPASSE);
		throw(EXCHorsIndexColonne);
	}

	ppmtMATTableau[uiMATNumLigne][uiMATNumCol] = mtNvElement;
}