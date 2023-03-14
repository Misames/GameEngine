#include "GameObject.h"
#include <iostream>
#include <string>

namespace ESGI
{
    std::string Tag::defaultTagName = "Untagged";
    std::vector<std::string> Tag::tags = {"Untagged"};

    void Tag::AddTag(std::string newTagName)
    {
        Tag::tags.push_back(newTagName);
    }

    void Tag::DeleteTag(uint8_t index)
    {
        for (auto &&item : GameObject::gameObjects)
        {
            if (item->getTag() == tags.at(index))
                item->ChangeTag(0);
        }

        Tag::tags.erase(Tag::tags.begin() + index);
    }

    void Tag::RenamingTag(uint8_t index, std::string newTagName)
    {
        auto oldTag = Tag::tags.at(index);
        Tag::tags[index] = newTagName;
        for (auto &&i : GameObject::gameObjects)
        {
            if (i->getTag() == oldTag)
                i->ChangeTag(index);
        }
    }

    uint64_t GameObject::countGameObject = 0;
    std::vector<GameObject *> GameObject::gameObjects;

    GameObject::GameObject()
    {
        m_name = "GameObject " + std::to_string(countGameObject);
        m_transform = new Transform();
        m_tag = Tag::defaultTagName;
        GameObject::countGameObject++;
        Initialize();
    }

    bool GameObject::Initialize()
    {
        std::cout << "[GameObject] initialized\n";
        std::cout << m_name << std::endl;
        std::cout << "Count " << countGameObject << std::endl;
        return true;
    }

    GameObject::~GameObject()
    {
        delete m_transform;
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
        m_tag = Tag::tags.at(indexTag);
    }

    std::string GameObject::getTag() const
    {
        return m_tag;
    }

    std::vector<GameObject *> GameObject::FindObjectsWithTag(std::string tagName)
    {
        std::vector<GameObject *> taggedGameObjects = std::vector<GameObject *>();

        for (auto &&item : GameObject::gameObjects)
        {
            if (item->m_tag == tagName)
            {
                std::cout << "get tag !!!" << std::endl;
                taggedGameObjects.push_back(item);
            }
        }

        return taggedGameObjects;
    }

}