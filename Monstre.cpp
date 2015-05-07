#include "Monstre.h"

Monstre::Monstre(
        Chemin* cheminSuivi, const Point& position, const float& angle, const float& rayon,
        bool solide, bool mobile,
        const Point& vitesse, const float& rotation, const float& echelle,
        const int pointsDeVie, const int attaque, const int defense, const float frequence):
    ElementDynamique(vitesse, rotation, echelle, position, angle, rayon, solide, mobile),
    ElementCombattant(pointsDeVie, attaque, defense, frequence),
    cheminSuivi(cheminSuivi)
{
}

//ElementDynamique::ElementDynamique ( const ElementDynamique& elementDynamique ):
//    position(elementDynamique.position), angle(elementDynamique.angle), rayon(elementDynamique.rayon),
//    solide(elementDynamique.solide), mobile(elementDynamique.mobile),
//    vitesse(elementDynamique.vitesse), rotation(elementDynamique.rotation), echelle(elementDynamique.echelle)
//{
//}
///// Assignement :
/////--------------
//const ElementDynamique & ElementDynamique::operator=(const ElementDynamique& elementDynamique) {
//    position = elementDynamique.position;
//    angle = elementDynamique.angle;
//    rayon = elementDynamique.rayon;
//    
//    solide = elementDynamique.solide;
//    mobile = elementDynamique.mobile;
//
//    vitesse = elementDynamique.vitesse;
//    rotation = elementDynamique.rotation;
//    echelle = elementDynamique.echelle;
//
//    return *this;
//}


void Monstre::avancerUnPas() {

}

void Monstre::attaquerTour() {
}

void Monstre::mourir() {
}

Chemin* Monstre::getCheminSuivi() const {
    return cheminSuivi;
}
