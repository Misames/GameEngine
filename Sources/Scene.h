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
        GameObject *currentObjectSelect;
        std::vector<std::shared_ptr<GameObject>> m_gameObjects;

        Scene(){};
        Scene(std::string name, std::vector<std::shared_ptr<GameObject>> lstObjects);
        ~Scene(){};
    };
}
