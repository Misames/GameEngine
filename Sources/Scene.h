#pragma once

#include <string>
#include <vector>
#include "GameObject.h"

namespace ESGI
{
    class Scene
    {
    public:
        uint8_t m_id;
        std::string m_name = "SampleScene";
        GameObject *m_currentObjectSelect;

        Scene();
        Scene(std::string name);
        ~Scene();
    };
}
