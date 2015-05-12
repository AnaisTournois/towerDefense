#include "ObjetTangible.h"

ObjetTangible::ObjetTangible(){
    std::cout << "objet contruit\n";
}

void ObjetTangible::afficherPoints() const{
    for (int i=0; i< points.size() ; i++){
        std::cout << points.at(i).x << " et " << points.at(i).y << std::endl;
    }
}