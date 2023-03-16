#include "Component.h"

namespace ESGI
{
    Component::Component() {}

    Component::Component(Entity *entity) : m_entity(entity) {}

    Component::~Component() {}

    Entity *Component::getEntity() const
    {
        return m_entity;
    }

    void Component::Update() {}
}
