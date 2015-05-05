#ifndef Vague_h
#define Vague_h

#include <vector>

#include "Monstre.h"

class Jeu;

class Vague {

 public:

    virtual void lancer();


 protected:
    int niveau;

 public:

    /**
     * @element-type Monstre
     */
    Monstre myMonstre;

    Jeu *d�clenche;

    /**
     * @element-type Monstre
     */
    std::vector< Monstre* > est compos�e de;
};

#endif // Vague_h
