#include "Entity.h"
#include "GameObject.h"

#include <typeinfo>

namespace ESGI
{
    Entity::Entity() {}

    Entity::~Entity() {}

    void Entity::Update() {}

    std::vector<Component *> Entity::GetComponent()
    {
        return this->m_component;
    }

    template <typename T>
    T *Entity::GetComponent()
    {
        for (Component *component : this->m_component)
        {
            if (typeid(*component) == typeid(T))
                return static_cast<T *>(component);
        }
        return nullptr;
    }

    // Instanciation explicite des modèles utilisés
    template Transform *Entity::GetComponent<Transform>();
}
