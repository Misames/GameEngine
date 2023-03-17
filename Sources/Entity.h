#pragma once

#include <vector>
#include <string>
#include "ObjectArena.h" //inclut la classe ObjectArena utilisée pour gérer la mémoire

namespace ESGI
{
	//forward declaration de la classe Component utilisée dans Entity
	class Component;

	class Entity
	{
	protected:
		uint64_t m_entityID; // identifiant unique de l'entité
		std::vector<Component*> m_component; // vecteur de pointeurs vers les composants de l'entité
		static ObjectArena g_Arena; // instance statique de la classe ObjectArena utilisée pour gérer la mémoire

	public:
		Entity(); // constructeur
		~Entity(); // destructeur
		virtual void Update(); // méthode virtuelle appelée à chaque itération de la boucle principale du jeu

		// Surcharge des opérateurs new et delete pour gérer la mémoire
		void* operator new(const size_t size);
		void operator delete(void* pointer);

		// Méthode statique pour créer un pool d'objets dans ObjectArena
		static void CreatePool(const std::type_info& classInfo, int count);
		static void DeletePool();
	};
}