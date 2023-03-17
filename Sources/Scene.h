#pragma once

#include <string>
#include <vector>
#include "GameObject.h"

namespace ESGI
{
	class Scene
	{
	public:
		uint8_t ID;
		std::string m_name = "SampleScene";
		GameObject* currentObjectSelect;
		std::vector<GameObject*> m_gameObjects;

		Scene() {};
		Scene(std::string name, std::vector<GameObject*> lstObjects);
		~Scene() {};
	};
}
