#ifndef ENTIER_HPP_INCLUDED
#define ENTIER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <string>

const unsigned long long int BASE = 0x100000000; //2^32

class Entier
{
public:
    //constructeurs
    Entier();
    Entier(unsigned int);
    Entier(const std::string&);
    Entier(const Entier&);
    //destructeur
    ~Entier();
    //operateurs
    //

    Entier& operator=(const Entier&);
    Entier& operator=(const unsigned int);
    //ajout
    Entier& operator+=(const Entier&);
    //Entier &operator+=(const unsigned int);
    //soustraire
    Entier& operator-=(const Entier&);
    //Entier &operator-=(const unsigned int);
    //multiplier
    Entier& operator*=(const Entier&);
    //Entier &operator*=(const unsigned int);
	void karatsuba(Entier&, Entier&, Entier&);
	void karatsuba_separer(Entier&, Entier&, Entier&);
	void karatsuba_recomposer(Entier&, Entier&, Entier&, Entier&);

    //Incrementation
    Entier& operator++();
    //Decrementation
    Entier& operator--();
    bool estEgal(const Entier&) const;
    //affichage
    friend std::ostream& operator<<(std::ostream&, const Entier&);
    //entrée
    friend std::istream& operator>>(std::istream&, Entier&);
	//comparaison
	int intcmp(const Entier& b) const;

private:
    std::vector<unsigned int> valeur;
};

//operateurs
Entier operator+(const Entier&, const Entier&);
//Entier operator+(const Entier&, const unsgned int);
Entier operator-(const Entier&, const Entier&);
//Entier operator-(const Entier&, const unsigned int);
Entier operator*(const Entier&, const Entier&);
//Entier operator*(const Entier&, const unsigned int);
//comparaisons
bool operator<(const Entier&, const Entier&);
bool operator>(const Entier&, const Entier&);
bool operator==(const Entier&, const Entier&);
bool operator!=(const Entier&, const Entier&);
bool operator<=(const Entier&, const Entier&);
bool operator>=(const Entier&, const Entier&);

bool additionEstSur(unsigned int, unsigned int);
bool retenue(unsigned int, unsigned int, unsigned int&);

#endif // ENTIER_HPP_INCLUDED
