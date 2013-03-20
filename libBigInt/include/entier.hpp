/*!
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

/*! \class Entier
 * \brief classe représentant le nombre
 * La classe gère un entier de grande taille
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
    Entier(const Entier& val);
    
    
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
    bool set(const std::string& nombre, unsigned int base = 10);
    
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
    Entier& operator+=(const Entier& b);
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
    Entier& operator-=(const Entier& b);
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
    Entier& operator*=(const Entier& b);
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
    
    /*!
     *  \brief Affichage
     *
     *  Methode qui permet d'extraire l'Entier
     *  courant dans un flux
     *
     *  \return ?????
     */
    friend std::ostream& operator<<(std::ostream&, const Entier&);
    
    //entrée
    
    /*!
     *  \brief Insertion
     *
     *  Methode qui permet d'extraire l'Entier
     *  courant dans un flux
     *
     *  \return ?????
     */
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
/*!
 *  \brief Addition
 *
 *  Methode qui ajoute 2 Entiers
 *  et renvoie le résultat
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return Le résultat de l'addition
 */
 
Entier operator+(const Entier& a, const Entier& b);
//Entier operator+(const Entier&, const unsgned int);

/*!
 *  \brief Soustraction
 *
 *  Methode qui soustrait 2 Entiers
 *  et renvoie le résultat
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return Le résultat de la soustraction
 */
 
Entier operator-(const Entier& a, const Entier& b);
//Entier operator-(const Entier&, const unsigned int);

/*!
 *  \brief Multiplication
 *
 *  Methode qui multiplie 2 Entiers
 *  et renvoie le résultat
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return Le résultat de la multiplication
 */
 
Entier operator*(const Entier& a, const Entier& b);
//Entier operator*(const Entier&, const unsigned int);


//Entier operator/(const Entier&, const Entier&);
//Entier operator%(const Entier&, const Entier&);

//comparaisons

/*!
 *  \brief Infériorité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si le premier est
 *	plus petit que le second
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est inférieur à b,
 	false sinon
 */
bool operator<(const Entier& a, const Entier& b);

/*!
 *  \brief Superiorité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si le premier est
 *	plus grand que le second
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est supérieur à b,
 	false sinon
 */
bool operator>(const Entier& a, const Entier& b);

/*!
 *  \brief Egalité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si ils sont égaux
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est égal à b,
 	false sinon
 */
bool operator==(const Entier& a, const Entier& b);

/*!
 *  \brief Inégalité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si ils sont différents
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est différent de b,
 	false sinon
 */
bool operator!=(const Entier& a, const Entier& b);

/*!
 *  \brief Infériorité ou égalité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si le premier est
 *	inférieur ou égal au second
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est inférieur ou égal à b,
 	false sinon
 */
bool operator<=(const Entier& a, const Entier& b);

/*!
 *  \brief Superiorité ou égalité
 *
 *  Methode qui compare 2 Entiers
 *  pour savoir si le premier est
 *	superieur ou égal au second
 *
 *  \param a : Premier Entier
 *	\param b : Second Entier
 *	\return true si a est superieur ou égal à b,
 	false sinon
 */
bool operator>=(const Entier& a, const Entier& b);


/*!
 *  \brief Présence de retenue
 *
 *  Methode qui multiplie 2 nombres
 *  et renvoie vrai si l'opération
 *	entraine une retenue
 *
 *  \param a : Premier nombre
 *	\param b : Second nombre
 *	\param reste : adresse du reste de l'opération
 *	\return true si a * b donne une retenue,
 	false sinon
 */
bool retenue(unsigned int a, unsigned int b, unsigned int& reste);

#endif // ENTIER_HPP_INCLUDED
