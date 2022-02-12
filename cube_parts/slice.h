#ifndef ___RUBIK_SLICE__H
#define ___RUBIK_SLICE__H

#include <spin.h>

using Layers = uint32_t;

template < cube_size N >
class Slice
{
  Layers  m_layers;
  Axis    m_axis;
  Spin    m_spin;

public:

  Slice( const Axis axis, const Layers layers, const Turn turn )
    : m_layers( layers )
    , m_axis( axis )
    , m_spin( Tilt::get( axis, turn ) )
  {

  }

  Layers layers () const
  {
    return m_layers << ( abs( m_axis - 1 ) * N );
  }

  Spin twist() const
  {
    return m_spin;
  }
};

#endif  //  ! ___RUBIK_SLICE__H
