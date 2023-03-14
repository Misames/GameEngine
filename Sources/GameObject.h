#pragma once

#include "InfraStructure.h"
#include <vector>

namespace ESGI
{
    struct Tag
    {
        static std::string defaultTagName;
        static std::vector<std::string> tags;
        static void AddTag(std::string newTagName);
        static void DeleteTag(uint8_t indexTag);
        static void RenamingTag(uint8_t index, std::string newTagName);
    };

    struct Transform
    {
        double tx, ty, tz;
        double rx, ry, rz;
        double sx, sy, sz;
        Transform() : tx(0), ty(0), tz(0), rx(0), ry(0), rz(0), sx(0), sy(0), sz(0) {}
    };

    class GameObject : public InfraStructure
    {
    private:
        std::string m_name;
        std::string m_tag;
        Transform *m_transform;

        bool Initialize() final;
        void DeInitialize() final;

    public:
        static uint64_t countGameObject;
        static std::vector<GameObject *> gameObjects;
        static std::vector<GameObject *> FindObjectsWithTag(std::string tagName);

        GameObject();
        ~GameObject();
        void Update();
        void ChangeTag(uint8_t indexTag);
        std::string getTag() const;
    };
}
