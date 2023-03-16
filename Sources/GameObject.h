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
        static void DeleteTag(uint8_t indexTag);
        static void RenamingTag(uint8_t index, std::string newTagName);
    };

    class Transform : public Component
    {
    public:
        double tx, ty, tz;
        double rx, ry, rz;
        double sx, sy, sz;

        Transform() : tx(0), ty(0), tz(0), rx(0), ry(0), rz(0), sx(0), sy(0), sz(0) {}
        ~Transform() {}
        void Update() final;
    };

    class GameObject : public Entity
    {
    private:
        std::string m_name;
        std::string m_tag;
        Transform *m_transform;
        std::vector<GameObject *> m_gameObjectChild;

    public:
        static uint64_t countGameObject;
        static std::vector<GameObject *> gameObjects;
        static std::vector<GameObject *> FindObjectsWithTag(std::string tagName);

        GameObject();
        ~GameObject();
        void Update() final;
        void ChangeTag(uint8_t indexTag);
        std::string getTag() const;
    };
}
