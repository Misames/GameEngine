#include "Scene.h"

namespace ESGI
{
	Scene::Scene(std::string name)
	{
		m_name = name;
	}

	void Scene::CreatePoolEntity(const std::type_info &entityClass, int poolSize)
	{
		Entity::CreatePool(entityClass, poolSize);
	}
	void Scene::CreatePoolComponent(const std::type_info &componentClass, int poolSize)
	{
		Component::CreatePool(componentClass, poolSize);
	}
	void Scene::AddGameObject()
	{
		auto obj = std::shared_ptr<ESGI::GameObject>(new ESGI::GameObject());
		m_gameObjects.push_back(std::move(obj));
	}
}
