#include "ObjectArena.h"

namespace ESGI {
void ObjectArena::Initialise(uint32_t taille) {
  m_memory = new uint8_t[taille];
}

void ObjectArena::Destroy() { delete[] m_memory; }

uint8_t *ObjectArena::Allocate(uint32_t taille) {
  uint8_t *data = &m_memory[m_cursor];
  m_cursor += taille;
  return data;
}

} // namespace ESGI
