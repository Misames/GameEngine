#pragma once
#include <typeinfo>
#include "Entity.h"

namespace ESGI
{
	class Component
	{
	protected:
		Entity* m_entity;
		static ObjectArena g_Arena;

	public:
		Component();
		Component(Entity* entity);
		virtual ~Component();
		virtual void Update();
		Entity* getEntity() const;

		// Surcharge des opérateurs new et delete pour gérer la mémoire
		void* operator new(const size_t size);
		void operator delete(void* pointer);

		static void CreatePool(const std::type_info& classInfo, int count);
		static void DeletePool();
	};
}