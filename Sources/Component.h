#pragma once

#include "Entity.h"

namespace ESGI
{
	class Component
	{
	protected:
		Entity* m_entity;

	public:
		Component();
		Component(Entity* entity);
		virtual ~Component();
		virtual void Update();
		Entity* getEntity() const;
	};
}