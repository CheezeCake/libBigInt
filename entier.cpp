#include "entier.hpp"

using namespace std;

Entier::Entier()
{
}

Entier::Entier(unsigned int val)
{
    valeur.push_back(val);
}

Entier::Entier(const string& val)
{
    valeur.push_back(0);

    /*const unsigned int BASE=10;
    for(unsigned int i = 0; i < val.size(); i++)
    {
        valeur*=BASE;
        valeur+=val[i] - '0';
    }*/
}

Entier::Entier(const Entier& val)
{
    valeur = val.valeur;
}

Entier::~Entier()
{
}

Entier& Entier::operator=(const Entier& b)
{
    valeur = b.valeur;
    return *this;
}

Entier& Entier::operator=(const unsigned int b)
{
    valeur.clear(); //vider valeur
    valeur.push_back(b);
}

Entier& Entier::operator+=(const Entier& b)
{
    bool _retenue = false;
    unsigned int reste = 0;
    int valeur_retenue = 0;

    for(size_t i = 0; i < valeur.size(); i++)
    {

	_retenue = retenue(valeur[i], b.valeur[i], reste);

	valeur[i] = reste;
	valeur[i] += valeur_retenue;

	if(_retenue)
	    valeur_retenue = 1;
	else
	    valeur_retenue = 0;
    }

    if(b.valeur.size() > valeur.size())
    {
	for(size_t i = valeur.size(); i < b.valeur.size(); i++)
	{
	    valeur.push_back(b.valeur[i]);
	    if(_retenue)
	    {
		_retenue = retenue(valeur[i], valeur_retenue, reste);
		valeur[i] = reste;
	    }
	    else
	    {
		_retenue = false;
		valeur_retenue = 0;
	    }
	}
    }

    if(_retenue)
	valeur.push_back(valeur_retenue);

    return *this;
}

Entier& Entier::operator-=(const Entier& b)
{
    return *this;
}

Entier& Entier::operator*=(const Entier& b)
{
    return *this;
}

bool operator<(const Entier& a, const Entier& b)
{
    return true;
}

bool operator>(const Entier& a, const Entier &b)
{
    return true;
}

bool Entier::estEgal(const Entier& b) const
{
    return true;
}

bool operator==(const Entier& a, const Entier& b)
{
    return a.estEgal(b);
}

bool operator!=(const Entier& a, const Entier& b)
{
    if (a == b)
        return false;
    return true;
    //return !(a == b);
}

bool operator<=(const Entier& a, const Entier& b)
{
    return true;
}

bool operator>=(const Entier& a, const Entier& b)
{
    return true;
}

Entier operator+(const Entier& a, const Entier& b)
{
    Entier somme(a);
    somme += b;

    return somme;
}

Entier operator-(const Entier& a, const Entier& b)
{
    Entier soustraction(a);
    soustraction -= b;

    return soustraction;
}

Entier operator*(const Entier& a, const Entier& b)
{
    Entier produit(a);
    produit *= b;

    return produit;
}

ostream& operator<<(ostream& flux, const Entier& val)
{
    for(int i = val.valeur.size()-1; i >= 0; i--)
    {
        flux << val.valeur[i] << ' ';
    }
    
    return flux;
}

istream& operator>>(istream& flux, Entier& val)
{
    return flux;
}

bool additionEstSur(unsigned int a, unsigned int b)
{
    unsigned int c = a+b;
    if(c < a || c < b )
        return false;
    return true;
    //return !(c < a || c < b)
}

#include <iostream>

bool retenue(unsigned int a, unsigned int b, unsigned int& reste)
{
    unsigned long long int c = (unsigned long long int)a+b;
    reste = c%BASE;
    
    return ((c & BASE) == BASE);
}
