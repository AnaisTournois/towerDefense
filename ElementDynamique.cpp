/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2015  Guillaume L. <guillaume.lozenguez@mines-douai.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "ElementDynamique.h"


/// Contructor / Destructor :
///--------------------------

ElementDynamique::ElementDynamique(const Point& position, const float& angle, const float& rayon, bool solide, bool mobile,
                                   const Point& vitesse, const float& rotation, const float& echelle):
            ElementVisuel( position, angle, rayon, solide, mobile ),
            vitesse(vitesse), rotation(rotation), echelle(echelle) {
}

ElementDynamique::ElementDynamique(ObjetTangible* objetTangible):
    ElementVisuel(objetTangible->position, objetTangible->angle, objetTangible->rayon, objetTangible->solide, objetTangible->mobile),
    vitesse(0.f), rotation(0.f), echelle(0.f){
    
}


bool ElementDynamique::operator==( const ElementDynamique& elementDynamique ) {
    return ( this == &elementDynamique );
}

/// Process Dynamiq :
///------------------
void ElementDynamique::avancerUnPas(float temps) {
    position += vitesse * temps;
    angle += angle * temps;
    rayon += echelle * temps;
}


