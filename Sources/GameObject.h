#pragma once

#include "InfraStructure.h"

namespace ESGI
{
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
        Transform *positon;

        bool Initialize() final;
        void DeInitialize() final;

    public:
        GameObject();
        ~GameObject();
        void Update();
    };
}
