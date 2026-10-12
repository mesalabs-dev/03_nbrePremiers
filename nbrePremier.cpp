/*
  ------------------------------------------------------------------------------
  Fichier     : nbre_1er.cpp
  Auteur(s)   : Sam Nait Abbou
  Date        : 7.10.2026

  But         : identifier tous les nombres premiers compris
                et une valeur choisie par l'utilisateur

  Remarque(s) : les erreurs de saisie ne sont pas vérifiées

  Compilateur : gcc
  ------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    const int n_col = 5; // nombre de chiffre à afficher par ligne
    char restart;
    cout << "Ce programme ..." << endl;
    do
    {
        int limit;
        // Initalisation de la valeur par l'utilisateur
        do
        {
            cout<< "entrer une valeur [2-1000] : ";
            cin >> limit;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }while (limit < 2  || limit > 1000);

        cout << "Voici la liste des nombres premiers" << endl;
        int c_col = 0;
        for (int i = 2; i <= limit; i++)
        {
            bool isPrime = true;

            // Controle si le nombre est premier en essayant de factoriser depuis la valeur la plus proche de sa racine carré
            for (int j = static_cast<int>(sqrt(i)); j > 1; j--)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            // Affichage du nombre premier
            if (isPrime)
            {
                cout << setw(3) << i << " ";
                c_col++;
                if (c_col % n_col == 0){cout<<endl;} // retour à la ligne tous les 5 chiffres
            }
        }
        if (c_col % n_col != 0){cout<<endl;} // retour à la ligne si la colonne n'était pas arrivé au bout

        // demande à l'utilisateur s'il veut recommencer
        do
        {
            cout <<" Voulez-vous recommencer [O/N] : " ;
            cin >> restart;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

        }while (restart != 'O' && restart != 'N' && restart != 'o' && restart != 'n');

    }while (restart == 'O' || restart == 'o');
    cout << "Fin de programme" << endl;

    return EXIT_SUCCESS;
}

