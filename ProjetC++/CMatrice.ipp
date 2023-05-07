/*****************************************************************//**
 * \file   CMatrice.ipp
 * \brief  Corps de la classe CMatrice.
 *		   Cette classe permet de créer des matrices de type quelconque
           et de les manipuler.
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

// CORPS

// Constructeurs - Destructeur

/**************************************************************
Nom : CMatrice
***************************************************************
Constructeur par défaut de la classe CMatrice qui permet
d’initialiser un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : La matrice est initialisée.
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
d’initialiser un objet à partir de dimensions données.
***************************************************************
Entrée : Matrice de type quelconque
Nécessite : néant
Sortie : néant
Entraîne : La matrice est initialisée à partir de dimensions données.
***************************************************************/
template <class MType>
CMatrice<MType>::CMatrice(unsigned int uiNumCol, unsigned int uiNumLigne)
{
	uiMATNbLignes = uiNumLigne;
	uiMATNbCol = uiNumCol;

	// Allocation dynamique du tableau à deux dimensions
	ppmtMATTableau = new MType * [uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		ppmtMATTableau[i] = new MType[uiMATNbCol];
	}

	// Initialisation des valeurs du tableau à zéro
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
d’initialiser un objet à partir d'un autre objet de la classe CMatrice.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : La matrice est initialisée.
***************************************************************/
template <class MType>
CMatrice<MType>::CMatrice(const CMatrice<MType>& mtMATParam)
{
	uiMATNbLignes = mtMATParam.uiMATNbLignes;
	uiMATNbCol = mtMATParam.uiMATNbCol;

	// Allouer de la mémoire pour la copie du tableau à deux dimensions
	ppmtMATTableau = new MType * [uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; ++i) {
		ppmtMATTableau[i] = new MType[uiMATNbCol];
	}

	// Copier les éléments de l'objet source dans le tableau de la nouvelle instance
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
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : La matrice est détruite.
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
Entrée : néant
Nécessite : néant
Sortie : Nombre de lignes
Entraîne : Le nombre de lignes est retourné.
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
Entrée : néant
Nécessite : néant
Sortie : Nombre de colonnes
Entraîne : Le nombre de colonnes est retourné.
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
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : La matrice est affichée à l'écran.
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
Cette fonction permet de lire un élément à une position donnée.
***************************************************************
Entrée : Numéro de la ligne, numéro de la colonne
Nécessite : néant
Sortie : L'élément à cette position
Entraîne : L'élément à la position donnée est retourné.
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
Cette fonction permet de modifier un élément à une position donnée.
***************************************************************
Entrée : Numéro de la ligne, numéro de la colonne, nouvel élément
Nécessite : néant
Sortie : néant
Entraîne : L'élément à la position donnée est modifié.
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