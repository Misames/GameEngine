#include "ObjectArena.h"

namespace ESGI {
	void ObjectArena::Initialise(uint32_t taille, int nbElement) {

		m_totalSize = taille;
		m_nbElement = nbElement;

		m_memory = new uint8_t[m_totalSize];
		for (uint8_t i = 0; i < m_totalSize; i += m_totalSize / nbElement) {
			m_memory[i] = NULL;
		}
	}

	void ObjectArena::Destroy() { delete[] m_memory; }

	uint8_t* ObjectArena::Allocate(uint32_t taille) {
		if (&m_memory[m_cursor] != NULL) {
			int i = 0;
			while (m_memory[m_cursor] != NULL && i < m_nbElement) {
				m_cursor += taille;
				m_cursor %= m_totalSize;
				i++;
			}
		}

		if (&m_memory[m_cursor] == NULL) {
			m_cursor += taille;
			return &m_memory[m_cursor];
		}
		return ExpandAndCopy();
	}

	uint8_t* ObjectArena::ExpandAndCopy() {
		uint32_t taille = m_totalSize / m_nbElement;
		m_totalSize *= 2;

		uint8_t* newArena = new uint8_t[m_totalSize];

		m_cursor = 0;
		uint32_t tmpCursor = 0;

		for (int i = 0; i < m_nbElement; i++) {
			if (m_memory[tmpCursor] != NULL) {
				newArena[m_cursor] = m_memory[tmpCursor];
				m_cursor += taille;
				tmpCursor += taille;
			}
			else {
				tmpCursor += taille;
			}
		}

		m_nbElement *= 2;
		delete[] m_memory;
		m_memory = newArena;

		return &m_memory[m_cursor - taille];

	}

	// a ajouter dans la classe ObjectArena
	template <typename T>
	void DeallocateObject(T* pointer) {
		pointer->~T();
		*pointer = NULL;
	}

} // namespace ESGI
