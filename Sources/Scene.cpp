#include "Scene.h"

namespace ESGI
{
    Scene::Scene(std::string name, std::vector<GameObject *> lstObjects)
    {
        this->m_name = name;
        this->m_gameObjects = lstObjects;
    }
}
