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

Entier& Entier::operator+=(const Entier& b)
{
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
    Entier somme;

    return somme;
}

Entier operator-(const Entier& a, const Entier& b)
{
    Entier soustraction;

    return soustraction;
}

Entier operator*(const Entier& a, const Entier& b)
{
    Entier produit;

    return produit;
}

ostream& operator<<(ostream& flux, const Entier& val)
{
    for(unsigned int i=val.valeur.size()-1; i!=0; i--)
    {
        flux<<val.valeur[i]<<' ';
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
    //return (c < a || c < b) ? false : true;
    //return !(c < a || c < b)
}

bool retenue(unsigned int a, unsigned int b)
{
	const unsigned long long int MASK = 0x0000000100000000; //2^32
	unsigned long long int c = (unsigned long long int)a+b;
		
	return ((c & MASK) == MASK);
}
