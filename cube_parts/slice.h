#ifndef ___RUBIK_SLICE__H
#define ___RUBIK_SLICE__H

#include <spin.h>
#include <layers.h>
#include <bitset>

template < cube_size N >
class Slice
{
  Layers<N>  m_layers;
  Spin       m_spin;

public:

  constexpr Slice()
    : m_layers(0), m_spin()
  {

  }

  constexpr Slice( const Layers<N> layers, const Spin spin )
    : m_layers( layers )
    , m_spin( spin )
  {

  }

  constexpr Slice( const Layers<N> layers, const Turn turn )
    : m_layers( layers )
    , m_spin( Spin( _X, turn ) )
  {

  }

  size_t layers () const
  {
    return m_layers.id() << N * ( twister() - 1 );
  }

  Axis twister() const
  {
    return m_spin.twister();
  }

  Spin spin() const
  {
    return m_spin;
  }

  constexpr
  Slice operator * ( const Spin spin ) const
  {
    return Slice<N>( spin.where( twister() ) < 0 ? m_layers.reverse() : m_layers, m_spin | spin );
  }
};

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const Slice<N> & slice )
{
  return os << slice.twister() << " [" << std::bitset< 3*N > ( slice.layers() ) << "] " << slice.spin() << Color::off;
}

#endif  //  ! ___RUBIK_SLICE__H