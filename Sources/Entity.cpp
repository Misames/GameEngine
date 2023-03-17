#include "Entity.h"

namespace ESGI {

	ObjectArena Entity::g_Arena = ObjectArena(); // initialisation de l'instance statique de ObjectArena

	Entity::Entity() {
		m_entityID = NULL; // initialisation de l'identifiant de l'entité à NULL
	}

	Entity::~Entity() {}

	void Entity::Update() {} // implémentation vide de la méthode Update

	void* Entity::operator new(const size_t size) {
		return g_Arena.Allocate((uint32_t)size); // utilisation de la méthode Allocate de ObjectArena pour allouer de la mémoire pour l'entité
	}

	void Entity::operator delete(void* pointer) {} // implémentation vide de l'opérateur delete

	void Entity::CreatePool(int count) {
		g_Arena.Initialise(count * sizeof(Entity)); // initialisation d'un pool d'objets de taille "count" * sizeof(Entity) dans ObjectArena
	}
}