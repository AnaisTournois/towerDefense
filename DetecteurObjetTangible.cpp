#include "DetecteurObjetTangible.h"


ObjetTangible* DetecteurObjetTangible::detecterObjetTangible(std::vector<mia::Point> points) {
    ObjetTangible* objetTangible;
    switch(points.size()){
        case 1:
            //On crée une tour d'attaque
            objetTangible = new TourAttaque(points, points[0], 0.f, 0.8f, true, false, 10, 10, 3, 1.f);
        break;
        default:
            //On crée une tour ralentissante
            Point position = Point(0,0);
            for (int i=0; i<points.size(); i++){
                position.x += points.at(i).x;
                position.y += points.at(i).y;
            }
            position.x = position.x / points.size();
            position.y = position.y / points.size();
            objetTangible = new TourRalentissante(points, position, 0.f, 0.8f, true, false, 10, 3, 10, 1.f);
        break;    
    }
    return objetTangible;
}