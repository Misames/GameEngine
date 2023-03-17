#include "Component.h"

namespace ESGI
{
	ObjectArena Component::g_Arena = ObjectArena();

	Component::Component() {}

	Component::Component(Entity* entity) : m_entity(entity) {}

	Component::~Component() {}

	Entity* Component::getEntity() const
	{
		return m_entity;
	}

	void Component::Update() {}

	void* Component::operator new(const size_t size) {
		return g_Arena.Allocate((uint32_t)size); // utilisation de la méthode Allocate de ObjectArena pour allouer de la mémoire pour l'entité
	}

	void Component::operator delete(void* pointer) {
		//g_Arena.DeallocateObject(static_cast<Component*>(pointer));
	} // implémentation vide de l'opérateur delete

	void Component::CreatePool(const std::type_info& classInfo, int count){
		g_Arena.Initialise(count * sizeof(classInfo), count); // initialisation d'un pool d'objets de taille "count" * sizeof(Entity) dans ObjectArena
	}
	void Component::DeletePool() {
		g_Arena.Destroy();
	}
}
