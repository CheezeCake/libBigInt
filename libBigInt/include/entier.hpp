/*!
 * \file entier.hpp
 * \brief Librairie d'opérations sur grands entiers
 * \author Marc Pardo, Emmanuel Nicolet, Alonso Jimenez Julien, Missichini Julien
 * \date Mars 2013  
*/


#ifndef ENTIER_HPP_INCLUDED
#define ENTIER_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <string>

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
    
    /*!
     *  \brief Incrémentation
     *
     *  Methode qui ajoute un nombre passé
     *  en paramètre à l'entier courant
     *
     *  \param b : nombre à ajouter
     *  \return L'Entier courant
     */
    Entier &operator+=(const unsigned int);
    
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
    
    /*!
     *  \brief Décrémentation
     *
     *  Methode qui retire un nombre passé
     *  en paramètre à l'entier courant
     *
     *  \param b : nombre à retirer
     *  \return L'Entier courant
     */
    Entier &operator-=(const unsigned int);
    
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
    
    /*!
     *  \brief Produit
     *
     *  Methode qui multiplie l'entier courant
     *  par un nombre passé en paramètre
     *
     *  \param b : nombre à multiplier
     *  \return L'Entier courant
     */
    Entier &operator*=(const unsigned int val);
    

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
     *	\param val : Entier qui va etre formate
     *	et insere dans le flux
     *
     *  \return flux
     */
    friend std::ostream& operator<<(std::ostream& flux, const Entier& val);
    
    //entrée
    
    /*!
     *  \brief Insertion
     *
     *  Methode qui permet d'extraire l'Entier
     *  courant dans un flux
     *
     *	\param val : Entier qui va contenir la
     *	valeur extraite du flux
     *
     *  \return flux
     */
    friend std::istream& operator>>(std::istream& flux, Entier& val);
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
     *  Methode qui supprime les zéros terminaux inutiles
     *  dans l'expression de l'Entier
     *
     */
    void racourcir();

private:
    std::vector<unsigned int> valeur; /*!< Nombre décomposé en valeurs de base 2^32*/
    
    /*!
     *
     *  \brief karastuba
     *
     *  Implementation de l'algorithme de multiplication
     *  rapide de Karatsuba.
     *
     *  \param u : Entier à multiplier
     *  \param v : Entier à multiplier
     *  \return Le produit u*v
     */
    Entier karatsuba(Entier& u, Entier& v);

    /*!
     *
     *  \brief Séparation pour karatsuba
     *  
     *  Sépare un Entier u en 2 Entier g et d distincts
     *
     *  \param u : Entier à séparer
     *  \param g : Partie gauche de l'Entier u
     *  \param d : Partie droite de l'Entier u
     */
    void karatsuba_separer(Entier& u, Entier& g, Entier& d);

    /*!
     *  \brief Recomposition pour karatsuba
     *
     *  Recompose un Entier a partir de 3 autres Entiers
     *
     *  \param g : Partie gauche de l'Entier à recomposer
     *  \param c : Partie centrale de l'Entier à recomposer
     *  \param d : Partie droite de l'entier à droite
     *  \return L'entier issu de la recomposition de g, c, et d
     */
    Entier karatsuba_recomposer(Entier& g, Entier& c, Entier& d, int);
    
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

/*!
 *  \brief Addition
 *
 *  Methode qui ajoute 1 Entier à
 *  un nombre et renvoie le résultat
 *
 *  \param a : Entier
 *  \param b : nombre
 *	\return Le résultat de l'addition
 */
Entier operator+(const Entier& a, const unsgned int b);

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

/*!
 *  \brief Soustraction
 *
 *  Methode qui soustrait 1 nombre à un 
 *  Entier et renvoie le résultat
 *
 *  \param a : Entier
 *  \param b : nombre
 *	\return Le résultat de la soustraction
 */
Entier operator-(const Entier& a, const unsigned int b);

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

/*!
 *  \brief Multiplication
 *
 *  Methode qui multiplie 1 Entier à
 *  un nombre et renvoie le résultat
 *
 *  \param a : Entier
 *  \param b : nombre
 *	\return Le résultat de la multiplication
 */
Entier operator*(const Entier& a, const unsigned int b);

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
