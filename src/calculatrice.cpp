#include <iostream>
#include "../libBigInt/include/entier.hpp"

using namespace std;

Entier calcul(const Entier& a, const Entier& b, unsigned char operateur)
{
	switch(operateur)
	{
		case '+':
		return a+b;
		break;

		case '-':
		return a-b;
		break;

		case '*':
		return a*b;
		break;

		case '/':
		return a/b;
		break;

		case '%':
		return a%b;
		break;
	}
}

int main()
{
	unsigned int choix;
	Entier op1;
	Entier op2;
	unsigned char operateur;
	
	do
	{
	cout<<"Entrez une ou plusieurs expressions arithmetiques à partir d'un: "<<endl;
	cout<<"1) clavier		2) fichier"<<endl;
	cin>>choix;
	}while(choix != 1 && choix != 2);

	if(choix == 1)
	{
		cin>>op1;
		cin>>operateur;
		cin>>op2;
		cout<<op1<<' '<<operateur<<' '<<op2<<" = "<<calcul(op1, op2, operateur)<<endl;

	}
	else
	{

	}

    return 0;
}
