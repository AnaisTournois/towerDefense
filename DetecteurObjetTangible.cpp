#include "DetecteurObjetTangible.h"


ObjetTangible DetecteurObjetTangible::detecterObjetTangible(std::vector<mia::Point> points) {
    ObjetTangible objetTangible(points);
    return objetTangible;
}