#ifndef Point_h
#define Point_h

class ElementVisuel;
class Chemin;
class Virage;

class Point {


 protected:
    int abscisse;
    int ordonnee;

 public:

    /**
     * @element-type ElementVisuel
     */
    ElementVisuel *se situe à;

    /**
     * @element-type Chemin
     */
    Chemin *myChemin;

    /**
     * @element-type Chemin
     */
    Chemin *myChemin;

    /**
     * @element-type Virage
     */
    Virage *myVirage;
};

#endif // Point_h
