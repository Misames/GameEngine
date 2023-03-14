#pragma once

#include "InfraStructure.h"
#include <vector>

namespace ESGI
{
    struct Tag
    {
        static std::string defaultTagName;
        static std::vector<std::string> tags;
        void AddTag(std::string newTagName);
        void DeleteTag(std::string tagName);
    };

    class Transform
    {
    private:
        double tx, ty, tz;
        double rx, ry, rz;
        double sx, sy, sz;

    public:
        Transform() : tx(0), ty(0), tz(0), rx(0), ry(0), rz(0), sx(0), sy(0), sz(0) {}
    };

    class GameObject : public InfraStructure
    {
    private:
        static int countGameObject;

        std::string name;
        std::string m_tag;
        Transform *positon;

        bool Initialize() final;
        void DeInitialize() final;

    public:
        GameObject();
        ~GameObject();
        void Update();
    };
}
