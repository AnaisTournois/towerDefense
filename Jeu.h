#ifndef Jeu_h
#define Jeu_h

#include <vector>


class Joueur;
class Vague;

class Jeu {

 public:

    virtual void lancer();

    virtual void arreter();

    virtual void terminer();


 protected:
    bool etat;

 public:

    /**
     * @element-type Joueur
     */
    std::vector< Joueur* > participe à;

    /**
     * @element-type Vague
     */
    std::vector< Vague* > déclenche;
};

#endif // Jeu_h
