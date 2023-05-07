// ProjetC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include "CLecteurMatrice.h"
#define MAX_NB_MATRICES 100

int main(int argc, char* argv[])
{
    cout << "Debut du Programme!\n\n";

    if (argc < 2) {
        cerr << "Aucun nom de fichier n'a ete passe en parametre." << endl;
        return 1;
    }

    // Creation des matrices à partir des fichiers 
	unsigned int iTailleListe = argc - 1;
    CMatrice<double> *pMATListeMatrice[MAX_NB_MATRICES];
	int iNbMatrices = 0;

    try
    {
        for (int i = 1; i < argc; i++)
        {
            cout << "Fichier : " << argv[i] << endl;

            CLecteurMatrice LECMat;
            CMatrice<double> mtMATcree = LECMat.LECCreerMatDepuisFichier(argv[i]);
            pMATListeMatrice[iNbMatrices++] = new CMatrice<double>(mtMATcree);
        }
    }
    catch (CException EXCErreurFichier)
    {
        EXCErreurFichier.EXCAfficherErreur();
        exit(1);
    }
    

    //Multiplications et divisions des matrices par une constante demandée à l'utilisateur
    double dConstante;
    cout << "Entrer une constante : \n";
    cin >> dConstante;                                      //Demande à l'utilisateur

    /*while (!dConstante)                                     //Test tant que la constante
    {                                                       //n'est pas correcte
        cout << "Veuillez reessayer d'entrer une constante : ";
        cin >> dConstante;
    }*/
        

    cout << "Resultat des multiplications des matrices par la constante : " << dConstante << endl;
	
	
	for (int i = 0; i < iNbMatrices; i++)
	{
		cout << "Matrice numero " << i + 1 << endl;
		(*pMATListeMatrice[i] * dConstante).MATAfficherMatrice();
	}
	


    cout << "Resultat des divisions des matrices par la constante : " << dConstante << endl;
    try
	{ 
		for (unsigned int i = 0; i < iTailleListe; i++)
		{
			cout << "Matrice numero : " << i+1 << endl;
			(*pMATListeMatrice[i] / dConstante).MATAfficherMatrice();
		}
	}
	catch (CException EXCMauvaiseConstante)
	{
		EXCMauvaiseConstante.EXCAfficherErreur();
		exit(1);
	}

    //Récupération des dimensions pour créer une matrice résultat
    unsigned int uiNbLignes = pMATListeMatrice[0][0].MATGetNbLignes();
    unsigned int uiNbCol = pMATListeMatrice[0][0].MATGetNbCol();

    //Création des objets nécessaires
    CUtilitaireMatrice<double> dUTISommeMat;  //Permet le calcul de somme
    CMatrice<double> dMATResultSommeMat(uiNbCol, uiNbLignes); //Création de la matrice résultat avec le constructeur de confort
    
    
    //Boucle calcul de la Somme

	try
	{
		for (unsigned int i = 0; i < iTailleListe; i++)
		{
			dMATResultSommeMat = dUTISommeMat.UTISommeMatrice(dMATResultSommeMat, *pMATListeMatrice[i]);
		}
	}
	catch (CException EXCMauvaisesDimensions)
	{
		EXCMauvaisesDimensions.EXCAfficherErreur();
		exit(1);
	}
    cout << "Somme des matrices : " << endl;
    dMATResultSommeMat.MATAfficherMatrice();

    //Même principe que pour la somme des matrices mais pour le produit
    CUtilitaireMatrice<double> dUTIMultMat;
    CMatrice<double> dMATResultMultMat(uiNbCol, uiNbLignes);

    //On transforme la matrice en matrice identité
	try 
	{
		for (unsigned int i = 0; i < dMATResultMultMat.MATGetNbLignes(); i++)
		{
			for (unsigned int j = 0; j < dMATResultMultMat.MATGetNbLignes(); j++)
			{
				if (i == j) dMATResultMultMat.MATModifierElement(i, j, 1);
			}
		}
	}
	catch (CException EXCProblemeIndice)
	{
		EXCProblemeIndice.EXCAfficherErreur();
		exit(1);
	}
	
	try
	{
		for (unsigned int i = 0; i < iTailleListe; i++)
		{
			dMATResultMultMat = dUTIMultMat.UTIProduitMatrice(dMATResultMultMat, *pMATListeMatrice[i]);
		}
	}
	catch (CException EXCProduitImpossible)
	{
		EXCProduitImpossible.EXCAfficherErreur();
		exit(1);
	}
    
    cout << "Produit des matrices : " << endl;
    dMATResultMultMat.MATAfficherMatrice();


    //On procède à la somme alternée des matrices

    CUtilitaireMatrice<double> dUTISommeAltMat;
    CMatrice<double> dMATResultSommeAltMat(uiNbCol, uiNbLignes);
   
   

    for (int i = 0; i <= argc - 2; i+=2)
    {
        
		dMATResultSommeAltMat = dUTISommeAltMat.UTISommeMatrice(dMATResultSommeAltMat, *pMATListeMatrice[i]);
    }
   
    
    for (int i = 1; i <= argc - 1; i+=2)
    {
        
		dMATResultSommeAltMat = dUTISommeAltMat.UTISoustractionMatrice(dMATResultSommeAltMat, *pMATListeMatrice[i]);
    }

    cout << "Somme alternee des matrices : " << endl;
	dMATResultSommeAltMat.MATAfficherMatrice();
}