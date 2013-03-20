/**
   \file calculatrice.cpp
   \brief Calculatrice test
   \author Marc Pardo, Emmanuel Nicolet, Julien Alonso, Julien Missichini
   \date Mars 2013
    
*/

#include <iostream>
#include <fstream>
#include "../libBigInt/include/entier.hpp"

using namespace std;

Entier calcul(const Entier& a, const Entier& b, unsigned char operateur)
{
    if (operateur == '+')
	return a + b;
	    
    else if (operateur == '-')
	return a - b;
	
    else if (operateur == '*')
	return a * b;
	    
    else if (operateur == '/')
    	return a / b;
	    
    else (operateur == '%')
	return a % b;	   
}

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

int main()
{
    unsigned int choix;
    Entier op1;
    Entier op2;
    unsigned char operateur;
    string fichier;

    do
    {
	cout <<"Entrez une ou plusieurs expressions arithmetiques à partir d'un: "<< endl;
	cout <<"1) clavier		2) fichier"<< endl;
	cin>>choix;
    }
    while(choix != 1 && choix != 2);

    if(choix == 1)
    {
	cout <<"Entrez une suite d'expression"<< endl;
	//cout << "Entrez la premiere operande :" << endl;
	cin >> op1;
	//cout << endl << "Entrez l'operateur :" << endl;
	cin >> operateur;
	//cout << endl << "Entrez la seconde operande :" << endl;
	cin >> op2;
	cout << endl << op1 <<' '<< operateur <<' '<< op2 <<" = "<< calcul(op1, op2, operateur) << endl;

    }
    else
    {
	cout << "Entrez le nom du fichier contenant la (les) expression(s) :" << endl;
	cin >> fichier;
	cout <<  endl;

	ifstream source(fichier.c_str(), ios::in);
	//if (!source) cerr << "Error";
	//else
	//{
	while(!source.eof())
	{
	    source >> op1;
	    source >> operateur;
	    source >> op2;
	    cout << op1 << ' ' << operateur << ' ' << op2 << " = " << calcul(op1, op2, operateur) << endl;
	}
	source.close();

	//}
    }

    /*cin >> op1;
      cin >> operateur;
      cin >> op2;

      cout << op1 << ' ' << operateur << ' ' << op2 << endl;
      if(comparer(op1, op2, operateur)) cout << "OUI";
      else cout << "NON" << endl;*/

    return 0;
}
