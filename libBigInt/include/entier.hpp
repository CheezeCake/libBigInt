/**
    \file entier.hpp
    \brief Librairie d'opérations sur grands entiers
    \author Marc Pardo, Emmanuel Nicolet, Alonso Jimenez Julien, Missichini Julien
    \date Mars 2013
    
*/


#ifndef ENTIER_HPP_INCLUDED
#define ENTIER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <string>

const unsigned long long int BASE = 0x100000000; //2^32

/* \class Entier
 * \brief classe représentant le nombre
 * La classe gère un entier de grnade taille
 */
 
class Entier
{
public:

    //constructeurs
    Entier();
    /*!
     *  \brief Constructeur à partir d'un entier
     *
     *  Constructeur de la classe Entier
     *
     *  \param val : Entier en base 10 à convertir
     */
    Entier(unsigned int val);
    /*!
     *  \brief Constructeur à partir d'une chaine de caractères 
     *
     *  Constructeur de la classe Entier
     *
     *  \param nombre : Chaine contenant l'entier
     *  \param base : Base de l'entier dans la chaine nombre (10 par défault)
     */
    Entier(const std::string& nombre, unsigned int base = 10);
    /*!
     *  \brief Constructeur à partir d'un objet de la classe Entier 
     *
     *  Constructeur de la classe Entier
     *
     *  \param val : Entier source
     */
    Entier(const Entier&);
    
    
    //destructeur
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Entier
     */
    ~Entier();
    
    
    //modulateurs
    bool set(const std::string&, unsigned int base = 10);
    //operateurs
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
    Entier& operator/=(const Entier&);
    Entier& operator%=(const Entier&);
    void karatsuba(Entier&, Entier&, Entier&);
    void karatsuba_separer(Entier&, Entier&, Entier&);
    void karatsuba_recomposer(Entier&, Entier&, Entier&, Entier&, int);

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

    void shrink_to_fit();

private:
    std::vector<unsigned int> valeur; /*!< Nombre décomposé en valeurs de base 2^32*/
	void mul(long long unsigned int a, long long unsigned int b, unsigned int& retenue, unsigned int& reste);
};

//operateurs
Entier operator+(const Entier&, const Entier&);
//Entier operator+(const Entier&, const unsgned int);
Entier operator-(const Entier&, const Entier&);
//Entier operator-(const Entier&, const unsigned int);
Entier operator*(const Entier&, const Entier&);
//Entier operator*(const Entier&, const unsigned int);
Entier operator/(const Entier&, const Entier&);
Entier operator%(const Entier&, const Entier&);
//comparaisons
bool operator<(const Entier&, const Entier&);
bool operator>(const Entier&, const Entier&);
bool operator==(const Entier&, const Entier&);
bool operator!=(const Entier&, const Entier&);
bool operator<=(const Entier&, const Entier&);
bool operator>=(const Entier&, const Entier&);

bool retenue(unsigned int, unsigned int, unsigned int&);

#endif // ENTIER_HPP_INCLUDED
