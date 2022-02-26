#ifndef ___RUBIK_SLICE__H
#define ___RUBIK_SLICE__H

#include <spin.h>
#include <bitset>

template < cube_size N >
class Slice
{
  using Layers = uint32_t;

  Layers  m_layers;
  Spin    m_spin;

  constexpr Slice( const Layers layers, const Spin spin )
    : m_layers( layers )
    , m_spin( spin )
  {

  }

public:

  constexpr Slice() : m_layers(0), m_spin() {}
  constexpr Slice( const Axis axis, const Layers layers, const Turn turn )
    : m_layers( layers )
    , m_spin( Spin( axis, turn ) )
  {

  }

  Layers layers () const
  {
    return m_layers;
  }

  Axis axis() const
  {
    return m_spin.where( _X );
  }

  Spin spin() const
  {
    return m_spin;
  }

  constexpr
  Slice operator * ( const Spin spin ) const
  {
    return Slice<N>( m_layers, m_spin | spin );
  }
};

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const Slice<N> & slice )
{
  return os << slice.axis() << std::bitset<8> ( slice.layers() ) << slice.spin() << Color::off;
}

#endif  //  ! ___RUBIK_SLICE__H
