#pragma once

#include <vector>
#include <string>
#include "ObjectArena.h" //inclut la classe ObjectArena utilis�e pour g�rer la m�moire

namespace ESGI
{
	// forward declaration de la classe Component utilis�e dans Entity
	class Component;

	class Entity
	{
	protected:
		uint64_t m_entityID;				  // identifiant unique de l'entit�
		std::vector<Component *> m_component; // vecteur de pointeurs vers les composants de l'entit�
		static ObjectArena g_Arena;			  // instance statique de la classe ObjectArena utilis�e pour g�rer la m�moire

	public:
		Entity();			   // constructeur
		~Entity();			   // destructeur
		virtual void Update(); // m�thode virtuelle appel�e � chaque it�ration de la boucle principale du jeu

		// Surcharge des op�rateurs new et delete pour g�rer la m�moire
		void *operator new(const size_t size);
		void operator delete(void *pointer);

		// M�thode statique pour cr�er un pool d'objets dans ObjectArena
		static void CreatePool(const std::type_info &classInfo, int count);
		static void DeletePool();

		template <typename T>
		T *GetComponent();
		std::vector<Component *> GetComponent();
	};
}
