#pragma once

#include "Component.h"
#include "Entity.h"

#include <vector>
#include <string>
#include <iostream>

namespace ESGI
{
    class Tag
    {
    private:
        Tag();

    public:
        static std::string defaultTagName;
        static std::vector<std::string> tags;
        static void AddTag(std::string newTagName);
        static void DeleteTag(uint8_t tagIndex);
        static void RenamingTag(uint8_t tagIndex, std::string newTagName);
    };

    class Transform : public Component
    {
    public:
        double tx, ty, tz;
        double rx, ry, rz;
        double sx, sy, sz;

        Transform();
        ~Transform();
        void Update() final;
    };

    class GameObject : public Entity
    {
    public:
        static uint64_t countGameObject;
        static std::vector<GameObject *> gameObjects;
        static std::vector<GameObject *> FindObjectsWithTag(std::string tagName);

    public:
        std::string m_name;
        std::string m_tag;
        std::vector<GameObject *> m_gameObjectChild;

        GameObject();
        ~GameObject();
        void Update() final;
        void ChangeTag(uint8_t indexTag);
        std::string getTag() const;
    };
}
