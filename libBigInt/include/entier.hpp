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
    
    /*!
     *  \brief Constructeur
     *
     *  Methode qui  crée un Entier à
     *  partir d'un nombre en base 10
     *
     *  \param nombre : Nombre à entrer dans la classe
     *  \param base : Base du nombre (10 par défault)
     *  \return true si la chaine est recevable,
     *  false sinon
     */
    bool set(const std::string&, unsigned int base = 10);
    
    //operateurs
    /*!
     *  \brief Affectation
     *
     *  Methode qui permet d'affecter un Entier
     *  à partir d'un autre Entier
     *
     *  \param b : Entier source
     *  \return Instance de la classe Entier
     */
    Entier& operator=(const Entier& b);
    /*!
     *  \brief Affectation
     *
     *  Methode qui permet d'affecter un Entier
     *  à partir d'un nombre en base 10
     *
     *  \param b : Entier source
     *  \return Instance de la classe Entier
     */
    Entier& operator=(const unsigned int b);
    
    //ajout
    
    /*!
     *  \brief Incrémentation
     *
     *  Methode qui ajoute un Entier passé
     *  en paramètre à l'entier courant
     *
     *  \param b : Entier à ajouter
     *  \return L'Entier courant
     */
    Entier& operator+=(const Entier&);
    //Entier &operator+=(const unsigned int);
    
    //soustraire
    
    /*!
     *  \brief Décrémentation
     *
     *  Methode qui retire un Entier passé
     *  en paramètre à l'entier courant
     *
     *  \param b : Entier à retirer
     *  \return L'Entier courant
     */
    Entier& operator-=(const Entier&);
    //Entier &operator-=(const unsigned int);
    
    //multiplier
    
    /*!
     *  \brief Produit
     *
     *  Methode qui multiplie l'entier courant
     *  par un Entier passé en paramètre
     *
     *  \param b : Entier à multiplier
     *  \return L'Entier courant
     */
    Entier& operator*=(const Entier&);
    //Entier &operator*=(const unsigned int);
    //Entier& operator/=(const Entier&);
    //Entier& operator%=(const Entier&);
    void karatsuba(Entier&, Entier&, Entier&);
    void karatsuba_separer(Entier&, Entier&, Entier&);
    void karatsuba_recomposer(Entier&, Entier&, Entier&, Entier&, int);

    //Incrementation
    
    /*!
     *  \brief Incrémentation
     *
     *  Methode qui ajoute 1 à l'Entier
     *  courant
     *
     *  \return L'Entier courant
     */
    Entier& operator++();
    
    //Decrementation
    
    /*!
     *  \brief Décrémentation
     *
     *  Methode qui retire 1 à l'Entier
     *  courant
     *
     *  \return L'Entier courant
     */
    Entier& operator--();
    
    //affichage
    friend std::ostream& operator<<(std::ostream&, const Entier&);
    //entrée
    friend std::istream& operator>>(std::istream&, Entier&);
    //comparaison
    
    /*!
     *  \brief Comparaison
     *
     *  Methode qui teste l'égalité entre
     *  l'Entier courant et celui donné en paramètre
     *
     *  \param b : Entier à comparer
     *	\return 0 si les 2 Entiers sont égaux,
     *	-1 si b est supérieur à l'Entier courant,
     *	1 sinon
     */
    int intcmp(const Entier& b) const;


	/*!
     *  \brief Simplicfication
     *
     *  Methode qui supprime les zéros inutiles
     *  dans l'expression de l'Entier
     *
     */
    void shrink_to_fit();

private:
    std::vector<unsigned int> valeur; /*!< Nombre décomposé en valeurs de base 2^32*/
    /*!
     *  \brief Multiplication
     *
     *  Methode qui multiplie 2 unsigned int
     *  et renvoie le reste et la retenue
     *	par ses paramètres
     *
     *  \param a : Premier nombre
     *	\param b : Second nombre
     *	\param retenue : adresse de la retenue de l'opération
     *	\param reste : adresse du reste de l'opération
     */
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
