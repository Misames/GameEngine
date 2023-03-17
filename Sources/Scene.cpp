#include "Scene.h"

namespace ESGI
{
	Scene::Scene(std::string name)
	{
		m_name = name;
		
		for (size_t i = 0; i < m_nbGameObjects; i++)
		{
			auto obj = new ESGI::GameObject();
			ESGI::GameObject::gameObjects.push_back(obj);
		}
	}

	void Scene::CreatePoolEntity(const std::type_info& entityClass, int poolSize) {
		Entity::CreatePool(entityClass, poolSize);

	}
	void Scene::CreatePoolComponent(const std::type_info& componentClass, int poolSize) {
		Component::CreatePool(componentClass, poolSize);
	}
}
