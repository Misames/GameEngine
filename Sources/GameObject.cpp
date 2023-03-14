#include "GameObject.h"
#include <iostream>
#include <string>

namespace ESGI
{
    int GameObject::countGameObject = 0;

    GameObject::GameObject()
    {
        this->name = "GameObject " + std::to_string(countGameObject);
        this->positon = new Transform();
        GameObject::countGameObject++;
        Initialize();
    }

    bool GameObject::Initialize()
    {
        std::cout << "[GameObject] initialized\n";
        std::cout << this->name << std::endl;
        std::cout << "Count " << countGameObject << std::endl;
        return true;
    }

    GameObject::~GameObject()
    {
        delete positon;
        DeInitialize();
        countGameObject--;
    }

    void GameObject::DeInitialize()
    {
        std::cout << "[GameObject] deinitialized\n";
        std::cout << "Count " << countGameObject << std::endl;
    }

    void GameObject::Update()
    {
        std::cout << "[GameObject] upadte\n";
    }
}