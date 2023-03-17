#pragma once

#include <string>
#include <vector>
#include <typeinfo>
#include "GameObject.h"
#include <map>

namespace ESGI
{
	class Scene
	{
	public:
		uint8_t ID;
		std::string m_name = "SampleScene";

		// GameObject variables
		int m_nbGameObjects;

		GameObject* currentObjectSelect;
		std::vector<GameObject*> m_gameObjects;
		//std::map<std::type_info,int> m_typeEntity;
		//std::map<std::type_info,int> m_typeComponent;


		Scene() {};
		Scene(std::string name);
		void CreatePoolEntity(const std::type_info& entityClass, int poolSize);
		void CreatePoolComponent(const std::type_info& componentClass, int poolSize);


		~Scene() {};
	};
}
