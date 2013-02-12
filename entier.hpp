#ifndef ENTIER_HPP_INCLUDED
#define ENTIER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <string>

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
    Entier& operator=(const int);
    //ajout
    Entier& operator+=(const Entier&);
    //Entier &operator+=(const unsigned int);
    //soustraire
    Entier& operator-=(const Entier&);
    //Entier &operator-=(const unsigned int);
    //multiplier
    Entier& operator*=(const Entier&);
    //Entier &operator*=(const unsigned int);
    bool estEgal(const Entier&) const;
    //affichage
    friend std::ostream& operator<<(std::ostream&, const Entier&);
    //entrée
    friend std::istream& operator>>(std::istream&, Entier&);

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

bool additionEstSur(unsigned int a, unsigned int b);

#endif // ENTIER_HPP_INCLUDED
