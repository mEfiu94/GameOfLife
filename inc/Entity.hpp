#pragma once
enum StateOfEntity{
    Alive,
    Dead,
};
class Entity{
public:
    Entity(StateOfEntity birthState):state_{birthState}{};
    StateOfEntity getState() const{return state_;};
    void setState(StateOfEntity newState){state_=newState;};
    bool operator==(const Entity b)const{
        return getState()==b.getState();
    }
private:
    StateOfEntity state_;
};
