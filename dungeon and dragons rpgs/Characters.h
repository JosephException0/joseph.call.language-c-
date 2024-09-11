// Start typing your code here
#include<iostream>
using namespace std;
class Character{

private:
    int health;
    int damage;
    int shield;
    
public: 
    Character(int health, int damage, int shield){
        this->health=health;
        this->damage=damage;
        this->shield=shield;
    }
    int getHealth(){
        return health;
    }
    int getDamage(){
        return damage;
    }
    int getShield(){
        return shield;
    }
    void setHealth(int health){
        this->health=health;
    }
    void receiveDamage(int damage){
        this->health=(this->health+this->shield)-damage;
        if(this->health <= 0){
            cout<<"Character has died";
        }
    }
   
};
 class Swordsman: public Character{
    public: 
    Swordsman():Character(100, 10, 10){
          
    }
};
class Paladin: public Swordsman{
    private:
    bool hasResurrected;
    public:
    Paladin() : Swordsman() {
        this->hasResurrected = false;
    }

    void receiveDamage(int damage){
        if(damage%2==0){
            damage/=2;
        }
        Swordsman::receiveDamage(damage);
        if(getHealth()<=0){
            resurrect();
        }
    }
    void resurrect(){
        if(hasResurrected==false){
            hasResurrected=true;
            setHealth(100);
            
        }else{
            cout<<"Paladin has died";
        }
    }
    
};
    
