#pragma once

#include <vector>
#include <string>

namespace ESGI
{
    class Component;

    class Entity
    {
    public:
        uint64_t m_entityID;
        std::vector<Component *> m_component;

        Entity();
        ~Entity();

        virtual void Update();

        template <typename T>
        T *GetComponent();
        std::vector<Component *> GetComponent();
    };
}
