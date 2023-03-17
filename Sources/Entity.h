#pragma once

#include <vector>
#include <string>

namespace ESGI
{
	class Component;

	class Entity
	{
	protected:
		uint64_t m_entityID;
		std::vector<Component*> m_component;

	public:
		Entity() {}
		~Entity() {}
		virtual void Update();
	};
}
