#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>
#include <bitset>

using namespace std;

class Component;
class Entity;

using componentID = size_t;

inline componentID getComponentTypeID()
{
    static ComponentID typeID = getComponentTypeID();
    return typeID();
}

contexpr size_t maxComponents = 32;

using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual ~Component(){}
    
};

class Entity
{
private:
    bool active = true;
    
    vector<unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitset componentBitset;
    
public:
    void update()
    {
        for(auto& c: components) c->update();
        for(auto& c: components) c->draw();
    }
    void draw(){}
    bool isActive()const {return active;}
    void destroy(){active = false;}
    
    template <typename T,typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(forward<TArgs>(mArgs)...));
        c->entity = this;
        unique _ptr<Component> uPtr{c};
        components.emplace_back(move(uPtr));
        
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }
    
    template <typename T>T& getComponent() const
    {
        auto ptr(componentAray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    vector<unique_ptr<Entity>> entities;
    
public:
    void update()
    {
        for(auto& e: entities)e->update();
        for(auto& e: entities)e->draw();
    }
    
    void refresh()
    {
        entities.erase(remove_if(begin(entities), end(entities), [](const unique_ptr<Entity>)&mEntity)
                       {
                           return !mEntity->isActive();
                       }),
        end(entities);
    }
    Entity& addEntity()
    {
        Entity* e = new Entity();
        unique_ptr<Entity> uPtr{e};
        entities.emplace_back(move(uPtr));
        return *e;
    }
};

#endif /* ECS_hpp */
