/**
  @file entier.cpp
  @author Marc Pardo, Emmanuel Nicolet, Julien Alonso Jimenez
  @date 2013

 */


#include "../include/entier.hpp"

using namespace std;

Entier::Entier()
{
}

Entier::Entier(unsigned int val)
{
    valeur.push_back(val);
}

Entier::Entier(const string& nombre, unsigned int base)
{
    set(nombre);
}

Entier::Entier(const Entier& val)
{
    valeur = val.valeur;
}

Entier::~Entier()
{
}

bool Entier::set(const string& nombre, unsigned int base)
{
    valeur.clear();
    valeur.push_back(0);

    for (size_t i = 0; i < nombre.size(); ++i)
    {
        *this *= base;
        *this += nombre[i] - '0';
    }

    return true;
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

    for (size_t i = 0; i < valeur.size(); i++)
    {
        _retenue = retenue(valeur[i], b.valeur[i], reste);

        valeur[i] = reste;
        valeur[i] += valeur_retenue;

        if (_retenue)
            valeur_retenue = 1;
        else
            valeur_retenue = 0;
    }

    if (b.valeur.size() > valeur.size())
    {
        for (size_t i = valeur.size(); i < b.valeur.size(); i++)
        {
            valeur.push_back(b.valeur[i]);
            if (_retenue)
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

    if (_retenue)
        valeur.push_back(valeur_retenue);

    return *this;
}

Entier& Entier::operator+=(const unsigned int b)
{
    Entier ent(b);
    *this += ent;
    return *this;
}

Entier& Entier::operator-=(const Entier& b)
{
    if (b == 0) return *this;
    if(*this == b)
    {
	*this = 0;
	return *this;
    }

    Entier complement(b);
    const unsigned int masque = 0xffffffff;

    vector<unsigned int>::iterator it;
    for (it = complement.valeur.begin(); it != complement.valeur.end(); ++it)
        *it ^= masque;

    ++complement;
    Entier tmp(*this);
    *this += complement;
    unsigned int t = valeur.size() -1;
    if (tmp < *this)
        valeur[t]--;
    if (valeur[t] == 0) 
        valeur.erase(valeur.end()-1);
    
    return *this;
}

Entier& Entier::operator-=(const unsigned int b)
{
    Entier ent(b);
    *this -= ent;
    return *this;
}

Entier& Entier::operator*=(const Entier& b)
{
    Entier u = *this;
    Entier v = b;

    *this = karatsuba(u, v);

    return *this;
}

Entier& Entier::operator*=(const unsigned int b)
{
    Entier ent(b);
    *this *= ent;
    return *this;
    
}

void Entier::mul(long long unsigned int a, long long unsigned int b, unsigned int& retenue, unsigned int& reste)
{
    long long unsigned int masqueRetenue = 0xffffffff00000000;
    long long unsigned int masqueReste = 0x00000000ffffffff;
    a *= b;

    retenue = (a & masqueRetenue) >> 32;
    reste = a & masqueReste;
}

Entier Entier::karatsuba(Entier& u, Entier& v)
{
    //U et V doivent être de même degré
    if (u.valeur.size() > v.valeur.size())
        v.valeur.insert(v.valeur.end(), u.valeur.size() - v.valeur.size(), 0);
    else
        u.valeur.insert(u.valeur.end(), v.valeur.size() - u.valeur.size(), 0);
    
    Entier r;

    if (u.valeur.size() == 1)
    {
        unsigned int a;
        unsigned int b;
        mul(u.valeur[0], v.valeur[0], a, b);
        r.valeur.push_back(b);
        if (a != 0)
            r.valeur.push_back(a);
    }
    else
    {
        Entier ug;
        Entier ud;
        Entier vg;
        Entier vd;

        karatsuba_separer(u, ug, ud);
        karatsuba_separer(v, vg, vd);

        Entier s;
        Entier t;
        Entier p;
        s = ug + ud;
        t = vg + vd;

        Entier g;
        Entier d;
        g = karatsuba(ug, vg);
        d = karatsuba(ud, vd);

        p = karatsuba(s, t);
        Entier c;
        c = p - g - d;

        g.racourcir();
        c.racourcir();
        d.racourcir();

        r = karatsuba_recomposer(g, c, d, u.valeur.size() / 2);
        r.racourcir();
    }

    return r;
}

void Entier::karatsuba_separer(Entier& u, Entier& ug, Entier& ud)
{
    int k = u.valeur.size() / 2;
    for (int i = 0; i < k; i++)
        ug.valeur.push_back(u.valeur[i]);

    for (int i = k; i < u.valeur.size(); i++)
        ud.valeur.push_back(u.valeur[i]);
}

Entier Entier::karatsuba_recomposer(Entier& g, Entier& c, Entier& d, int k)
{
    //UV = g + c*BASE^k + d*BASE^2k

    //c*BASE^k
    c.valeur.insert(c.valeur.begin(), k, 0);
    //d*BASE^2k
    d.valeur.insert(d.valeur.begin(), 2 * k, 0);

    Entier r;
    r = g + c + d;
    
    return r;
}

//racourcir fait peter les zeros inutiles ajoutés pour
//que les polynômes soient de même degré
void Entier::racourcir()
{
    for (int i = valeur.size()-1; i > 0; i--) // i>0 car garder premier element meme si 0
    {
        if (valeur[i] != 0) return;
        valeur.pop_back();
    }
}

Entier& Entier::operator++()
{
    *this += 1;
    return *this;
}

Entier& Entier::operator--()
{
    *this -= 1;
    return *this;
}

int Entier::intcmp(const Entier& b) const
{
    if (valeur.size() < b.valeur.size()) return -1;
    if (valeur.size() > b.valeur.size()) return 1;

    vector<unsigned int>::const_reverse_iterator rita = valeur.rbegin();
    vector<unsigned int>::const_reverse_iterator ritb = b.valeur.rbegin();

    while (rita != valeur.rend())
    {
        if (*rita < *ritb) return -1;
        if (*rita > *ritb) return 1;
        ++rita;
        ++ritb;
    }
    return 0;
}

bool operator<(const Entier& a, const Entier& b)
{
    return (a.intcmp(b) == -1);
}

bool operator>(const Entier& a, const Entier &b)
{
    return (a.intcmp(b) == 1);
}

bool operator==(const Entier& a, const Entier& b)
{
    return (a.intcmp(b) == 0);
}

bool operator!=(const Entier& a, const Entier& b)
{
    return !(a == b);
}

bool operator<=(const Entier& a, const Entier& b)
{
    return !(a > b);
}

bool operator>=(const Entier& a, const Entier& b)
{
    return !(a < b);
}

Entier operator+(const Entier& a, const Entier& b)
{
    Entier somme(a);
    somme += b;
    return somme;
}

Entier operator+(const Entier& a, const unsigned int b)
{
    Entier ent(a);
    ent += b;
    return ent;   
}

Entier operator-(const Entier& a, const Entier& b)
{
    Entier soustraction(a);
    soustraction -= b;
    return soustraction;
}

Entier operator-(const Entier& a, const unsigned int b)
{
    Entier ent(a);
    ent -= b;
    return ent;   
}

Entier operator*(const Entier& a, const Entier& b)
{
    Entier produit(a);
    produit *= b;
    return produit;
}

Entier operator*(const Entier& a, const unsigned int b)
{
    Entier ent(a);
    ent *= b;
    return ent;   
}

ostream& operator<<(ostream& flux, const Entier& val)
{
    for (size_t i = val.valeur.size()-1; i > 0; i--)
        flux << val.valeur[i] << '.';
    flux << val.valeur[0];

    return flux;
}

istream& operator>>(istream& flux, Entier& val)
{
    string nombre;
    flux >> nombre;
    val.set(nombre,10);
    return flux;
}

bool retenue(unsigned int a, unsigned int b, unsigned int& reste)
{
    const unsigned long long int BASE = 0x100000000; //2^32
    unsigned long long int c = (unsigned long long int) a + b;
    reste = c % BASE;

    return ((c & BASE) == BASE);
}
