#ifndef ElementCombattant_h
#define ElementCombattant_h

using namespace std;

class ElementCombattant {
    
protected:
    int pointsDeVie;
    int attaque;
    int defense;
    float frequence;
    
public :
    ElementCombattant(const int pointsDeVie, const int attaque, const int defense, const float& frequence);
    void SetPointsDeVie(int pointsDeVie) {
        this->pointsDeVie = pointsDeVie;
    }
    int GetPointsDeVie() const {
        return pointsDeVie;
    }
 
    void SetAttaque(int attaque) {
        this->attaque = attaque;
    }
    int GetAttaque() const {
        return attaque;
    }

    void SetDefense(int defense) {
        this->defense = defense;
    }
    int GetDefense() const {
        return defense;
    }

    void SetFrequence(float frequence) {
        this->frequence = frequence;
    }
    float GetFrequence() const {
        return frequence;
    }
 
};

#endif // ElementCombattant_h
