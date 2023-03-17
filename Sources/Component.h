#pragma once

#include "Entity.h"

namespace ESGI
{
    class Component
    {
    public:
        Component();
        virtual ~Component();
        virtual void Update();
    };
}