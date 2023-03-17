#include <typeinfo>
#include "Entity.h"

namespace ESGI {

	ObjectArena Entity::g_Arena = ObjectArena(); // initialisation de l'instance statique de ObjectArena

	Entity::Entity() {
		m_entityID = NULL; // initialisation de l'identifiant de l'entit� � NULL
	}

	Entity::~Entity() {}

	void Entity::Update() {} // impl�mentation vide de la m�thode Update

	void* Entity::operator new(const size_t size) {
		return g_Arena.Allocate((uint32_t)size); // utilisation de la m�thode Allocate de ObjectArena pour allouer de la m�moire pour l'entit�
	}

	void Entity::operator delete(void* pointer) {
		//g_Arena.DeallocateObject(static_cast<Entity*>(pointer));
	} // impl�mentation vide de l'op�rateur delete

	void Entity::CreatePool(const std::type_info& classInfo,int count) {
		g_Arena.Initialise(count * sizeof(classInfo), count); // initialisation d'un pool d'objets de taille "count" * sizeof(Entity) dans ObjectArena
	}
	void Entity::DeletePool() {
		g_Arena.Destroy(); // initialisation d'un pool d'objets de taille "count" * sizeof(Entity) dans ObjectArena
	}
}