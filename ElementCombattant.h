#ifndef ElementCombattant_h
#define ElementCombattant_h

using namespace std;

class ElementCombattant {
    
protected:
    int pointsDeVie;
    int defense;
    float frequence;
    int attaque;
    
public : 
    void SetAttaque(int attaque) {
        this->attaque = attaque;
    }

    int GetAttaque() const {
        return attaque;
    }

    void SetFrequence(float frequence) {
        this->frequence = frequence;
    }

    float GetFrequence() const {
        return frequence;
    }

    void SetDefense(int defense) {
        this->defense = defense;
    }

    int GetDefense() const {
        return defense;
    }

    void SetPointsDeVie(int pointsDeVie) {
        this->pointsDeVie = pointsDeVie;
    }

    int GetPointsDeVie() const {
        return pointsDeVie;
    }

 
};

#endif // ElementCombattant_h
