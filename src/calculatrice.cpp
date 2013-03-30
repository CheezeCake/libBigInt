/*!
  \file calculatrice.cpp
  \brief Calculatrice test
  \author Marc Pardo, Emmanuel Nicolet, Julien Alonso Jimenez, Julien Missichini
  \date Mars 2013

 */

#include <iostream>
#include <fstream>
#include "../libBigInt/include/entier.hpp"

using namespace std;

/*!
 *  \brief Calcul
 *
 *  Methode qui effectue l'opération correspondante
 *  à l'opérateur passé en paramètre et renvoie le
 *	résultat
 *
 *  \param a : Premier Entier
 *	\param b : Deuxième Entier
 *	\param operateur : Opérateur
 *  \return Résultat de l'opération d'Entiers
 */
Entier calcul(const Entier& a, const Entier& b, unsigned char operateur)
{
    if (operateur == '+')
        return a + b;

    else if (operateur == '-')
        return a - b;

    else if (operateur == '*')
        return a * b;
}

/*!
 *  \brief Comparer
 *
 *  Methode qui effectue une comparaison sur 2
 *  2 Entiers à partir de l'opérateur passé
 *	en paramètre et renvoie le résultat
 *
 *  \param a : Premier Entier
 *	\param b : Deuxième Entier
 *	\param operateur : Opérateur
 *  \return true si la comparaison est vraie,
 *	false sinon
 */
bool comparer(const Entier& a, const Entier& b, string operateur)
{
    if(operateur == "<")
        return a < b;
    if(operateur == ">")
        return a > b;
    if(operateur == "<=")
        return a <= b;
    if(operateur == ">=")
        return a >= b;
    if(operateur == "=")
        return a == b;
    if(operateur == "!=")
        return a != b;
}

int main(int argc, char *argv[])
{
    unsigned int choix;
    Entier op1;
    Entier op2;
    unsigned char operateur;
    string fichier;

    if(argc == 2)
    {
	ifstream source(argv[1], ios::in);
	if(!source)	cerr << "Error";
	else
	{
	    cout << "OK\n";
	    source >> op1;
	    source >> op2;
	   // cout << op1 + op2 << '\n';
	    cout << op1 - op2 << '\n';
	   // cout << op1 * op2 << endl;
	}
	return 0;
    }

    if(argc == 4)
    {
	op1 = string(argv[1]);
	operateur = *argv[2];
	op2 = string(argv[3]);
	cout << calcul(op1, op2, operateur) << endl;

	return 0;
    }

    do
    {
        cout <<"Entrez une ou plusieurs expressions arithmetiques à partir d'un: "<< endl;
        cout <<"1) clavier		2) fichier"<< endl;
        cin>>choix;
    }
    while(choix != 1 && choix != 2);

    if(choix == 1)
    {
        cout <<"Entrez une operation :"<< endl;
        cin >> op1;
        cin >> operateur;
        cin >> op2;
        cout << endl << op1 <<' '<< operateur <<' '<< op2 <<" = "<< calcul(op1, op2, operateur) << endl;

    }
    else
    {
        cout << "Entrez le nom du fichier contenant la (les) expression(s) :" << endl;
        cin >> fichier;
        cout <<  endl;

        ifstream source(fichier.c_str(), ios::in);
        if (!source) cerr << "Error";
        else
        {
            while(!source.eof())
            {
                source >> op1;
                source >> operateur;
                source >> op2;
                cout << op1 << ' ' << operateur << ' ' << op2 << " = " << calcul(op1, op2, operateur) << endl;
            }
            source.close();

        }
    }
    return 0;
}
