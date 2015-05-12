#include "DetecteurObjetTangible.h"


ObjetTangible* DetecteurObjetTangible::detecterObjetTangible(std::vector<mia::Point> points, World* monde) {
    ObjetTangible* objetTangible;
    Point position;
    switch(points.size()){
        case 1:
            //On crée une tour d'attaque
            position = Point( points[0].x * 64, (1 - points[0].y) * 33);
            objetTangible = new TourAttaque(points, position, 0.f, 0.7f, false, false, 10, 10, 3, 1.f);
            objetTangible->tirerBalle(monde);
        break;
        default:
            //On crée une tour ralentissante
            position = Point(0,0);
            for (int i=0; i<points.size(); i++){
                position.x += points.at(i).x;
                position.y += points.at(i).y;
            }
            position.x = position.x / points.size() * 64;
            position.y = (1 - position.y / points.size()) * 33;
            objetTangible = new TourRalentissante(points, position, 0.f, 1.f, false, false, 10, 3, 10, 1.f);
            objetTangible->tirerBalle(monde);
        break;    
    }
    return objetTangible;
}
