#ifndef ___RUBIK_SLICE__H
#define ___RUBIK_SLICE__H

#include <spin.h>
#include <bitset>

class Layers
{
  uint8_t m_id;

public:
  constexpr Layers(): m_id( 0 ) {}
  constexpr Layers( const uint8_t & id ): m_id( id ) {}
  constexpr size_t id() const { return m_id; }
  constexpr size_t reverse() const;
};

constexpr inline
size_t Layers::reverse() const
{
  return ( ( m_id * 0x80200802ULL ) & 0x0884422110ULL ) * 0x0101010101ULL >> 32 ;
}

template < cube_size N >
class Slice
{
  Layers  m_layers;
  Spin    m_spin;

  constexpr Slice( const Layers layers, const Spin spin )
    : m_layers( layers )
    , m_spin( spin )
  {

  }

public:

  constexpr Slice() : m_layers(0), m_spin() {}
  constexpr Slice( const Layers layers, const Turn turn )
    : m_layers( layers )
    , m_spin( Spin( _X, turn ) )
  {

  }

  size_t layers () const
  {
    if ( twister() < 0 )
    {
      return m_layers.reverse() << N * ( - twister() - 1 );
    }
    else
    {
      return m_layers.id() << N * ( twister() - 1 );
    }
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
  Slice operator * ( const Spin spin )
  {
    return Slice<N>( m_layers, m_spin | spin );
  }
};

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const Slice<N> & slice )
{
  return os << slice.twister() << " [" << std::bitset< 3*N > ( slice.layers() ) << "] " << slice.spin() << Color::off;
}

#endif  //  ! ___RUBIK_SLICE__H
