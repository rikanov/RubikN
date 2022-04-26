#ifndef ___CUBE_ROTATION_LAYERS__H
#define ___CUBE_ROTATION_LAYERS__H

#include <base.h>

using Layer = uint8_t;

template< cube_size N >
class Layers
{
  Layer m_id;

public:
  constexpr Layers(): m_id( 0 ) {}
  constexpr Layers( const Layer & id ): m_id( id ) {}
  constexpr size_t id() const
  {
    return m_id;
  }

  constexpr size_t reverse() const
  {
    return ( ( m_id * 0x80200802ULL ) & 0x0884422110ULL ) * 0x0101010101ULL >> ( 40 - N );
  }
};

#endif  //  ! ___CUBE_ROTATION_LAYERS__H
