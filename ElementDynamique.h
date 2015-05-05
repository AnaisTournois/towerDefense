#ifndef ElementDynamique_h
#define ElementDynamique_h

#include "ElementVisuel.h"


class ElementDynamique : public ElementVisuel {

 public:

    virtual void avancerUnPas()  = 0;


 protected:
    float vitesse;
    float angle;
};

#endif // ElementDynamique_h
