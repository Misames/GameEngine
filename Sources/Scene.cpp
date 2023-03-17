#include "Scene.h"

namespace ESGI
{
	Scene::Scene(std::string name, int nbGameObjects)
	{
		m_name = name;
		m_nbGameObjects = nbGameObjects;
		GameObject::CreatePool(m_nbGameObjects);

		for (size_t i = 0; i < m_nbGameObjects; i++)
		{
			auto obj = new ESGI::GameObject();
			ESGI::GameObject::gameObjects.push_back(obj);
		}
	}
}
