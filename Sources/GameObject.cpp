#include "GameObject.h"
#include <iostream>
#include <string>

namespace ESGI
{
    int GameObject::countGameObject = 0;
    std::vector<GameObject *> GameObject::gamesObjects;

    std::string Tag::defaultTagName = "Untagged";
    std::vector<std::string> Tag::tags;

    void Tag::AddTag(std::string newTagName)
    {
        Tag::tags.push_back(newTagName);
    }

    void Tag::ChangeAllTag(uint8_t indexNew)
    {
        for (auto &&i : GameObject::gamesObjects)
        {
        }
    }

    void Tag::DeleteTag(uint8_t index)
    {
        Tag::tags.erase(tags.begin() + index);
    }

    GameObject::GameObject()
    {
        this->name = "GameObject " + std::to_string(countGameObject);
        this->positon = new Transform();
        this->m_tag = Tag::defaultTagName;
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

    void GameObject::ChangeTag(uint8_t indexTag)
    {
        this->m_tag = Tag::tags.at(indexTag);
    }

    std::string GameObject::getTag() const
    {
        return this->m_tag;
    }
}