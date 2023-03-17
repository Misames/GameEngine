#pragma once
#include <cstdint>
namespace ESGI {
	class ObjectArena {
		// allocateur lineaire (linear allocator)
		// tips: on peut desallouer le contenu en remettant le curseur a zero
		uint8_t* m_memory;
		uint32_t m_cursor; // position du premier octet libre
		int m_nbElement;
		uint32_t m_totalSize;

	public:
		void Initialise(uint32_t taille, int nbElement);
		void Destroy();
		uint8_t* Allocate(uint32_t taille);
		uint8_t* ExpandAndCopy();
		// la desallocation est plus complexe car laisse des "trous" dans l'arena
		// idealement il faudrait limiter l'utilisation d'un allocateur lineaire aux
		// seuls cas ou on n'a que peu de desallocation ou si on peut simplement reset
		// le curseur a zero
		// a ajouter dans la classe ObjectArena
		template<typename T>
		void DeallocateObject(T* pointeur);
	};

} // namespace ESGI