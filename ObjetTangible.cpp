#include "ObjetTangible.h"



void ObjetTangible::afficherPoints() const{
    for (int i=0; i< points.size() ; i++){
        std::cout << points.at(i).x << " et " << points.at(i).y << std::endl;
    }
}