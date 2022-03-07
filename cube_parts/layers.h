#ifndef ___CUBE_LAYERS__H
#define ___CUBE_LAYERS__H

#include <base.h>

class Layers
{
  uint8_t m_id;

public:
  constexpr Layers(): m_id( 0 ) {}
  constexpr Layers( const uint8_t & id ): m_id( id ) {}
  constexpr size_t id() const { return m_id; }

  template< cube_size N >
  constexpr size_t reverse() const;
};

template< cube_size N > constexpr inline
size_t Layers::reverse() const
{
  return ( ( m_id * 0x80200802ULL ) & 0x0884422110ULL ) * 0x0101010101ULL >> ( 40 - N );
}

#endif  //  ! ___CUBE_LAYERS__H
