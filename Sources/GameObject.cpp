#include "GameObject.h"

namespace ESGI
{
    /**
     * Tag
     */

    std::string Tag::defaultTagName = "Untagged";
    std::vector<std::string> Tag::tags = {"Untagged"};

    void Tag::AddTag(std::string newTagName)
    {
        Tag::tags.push_back(newTagName);
    }

    void Tag::DeleteTag(uint8_t tagIndex)
    {
        for (auto &&item : GameObject::gameObjects)
        {
            if (item->getTag() == tags.at(tagIndex))
                item->ChangeTag(0);
        }

        Tag::tags.erase(Tag::tags.begin() + tagIndex);
    }

    void Tag::RenamingTag(uint8_t tagIndex, std::string newTagName)
    {
        auto oldTag = Tag::tags.at(tagIndex);
        Tag::tags[tagIndex] = newTagName;
        for (auto &&i : GameObject::gameObjects)
        {
            if (i->getTag() == oldTag)
                i->ChangeTag(tagIndex);
        }
    }

    /**
     * GameObject
     */

    uint64_t GameObject::countGameObject = 0;
    std::vector<std::shared_ptr<GameObject>> GameObject::gameObjects;

    GameObject::GameObject()
    {
        m_name = "GameObject " + std::to_string(countGameObject);
        m_component.push_back(new Transform);
        m_tag = Tag::defaultTagName;
        GameObject::countGameObject++;
        std::cout << "[GameObject] initialized\n";
        std::cout << m_name << std::endl;
        std::cout << "Count " << countGameObject << std::endl;
    }

    GameObject::~GameObject()
    {
        std::cout << "[GameObject] deinitialized\n";
        std::cout << "Count " << countGameObject << std::endl;
        countGameObject--;
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

    std::vector<std::shared_ptr<GameObject>> GameObject::FindObjectsWithTag(std::string tagName)
    {
        std::vector<std::shared_ptr<GameObject>> taggedGameObjects = std::vector<std::shared_ptr<GameObject>>();

        for (auto &&item : GameObject::gameObjects)
        {
            if (item->m_tag == tagName)
            {
                std::cout << "get tag : " << tagName << std::endl;
                taggedGameObjects.push_back(item);
            }
        }

        return taggedGameObjects;
    }

    /**
     * transform
     */

    Transform::Transform() : tx(0), ty(0), tz(0), rx(0), ry(0), rz(0), sx(0), sy(0), sz(0) {}

    Transform::~Transform() {}

    void Transform::Update() {}
}