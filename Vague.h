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

    Jeu *déclenche;

    /**
     * @element-type Monstre
     */
    std::vector< Monstre* > est composée de;
};

#endif // Vague_h
