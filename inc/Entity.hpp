#pragma once
enum StateOfEntity{
    Alive,
    Dead,
};
class Entity{
public:
    Entity(StateOfEntity birthState):state_{birthState}{};
    StateOfEntity getState() const{return state_;};
    bool operator==(const Entity b)const{
        return getState()==b.getState();
    }
private:
    StateOfEntity state_;
};
