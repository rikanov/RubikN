#ifndef ___CUBLET_COORDINATES__H
#define ___CUBLET_COORDINATES__H

#include <spin.h>
#include <bit64set.h>

template< cube_size N >
class Coords
{
  uint8_t     m_coords[4] = {};
  size_t      m_id;

  BitSet<uint32_t>  m_layers;

  constexpr void setID();
  constexpr void setMask();

public:
  constexpr Coords();
  constexpr Coords( const uint8_t x, const uint8_t y, const uint8_t z );
  constexpr Coords( const size_t id );
  constexpr Coords( const Coords & );
  constexpr Coords( Coords && ) = default;

  constexpr Coords & operator = ( const Coords & );
  constexpr Coords operator * ( const Spin & ) const;

  constexpr size_t id() const;
  constexpr size_t layers() const;
  std::string str() const;
};

template< cube_size N > constexpr
Coords<N>::Coords()
  : m_id( 0 )
  , m_layers( 0 )
{
}

template< cube_size N > constexpr
Coords<N>::Coords( const Coords<N> & c )
  : m_id( c.m_id)
  , m_layers( c.m_layers )
{
  for ( size_t i : { 1, 2, 3} )
  {
    m_coords[i] = c.m_coords[i];
  }
}

template< cube_size N > constexpr
Coords<N>::Coords( const uint8_t x, const uint8_t y, const uint8_t z )
  : m_id( 0 )
  , m_layers( 0 )
{
  m_coords[1] = x;
  m_coords[2] = y;
  m_coords[3] = z;
  setID();
  setMask();
}

template< cube_size N > constexpr
Coords<N>::Coords( const size_t id )
  : m_id( id )
  , m_layers( 0 )
{
  m_coords[1] = id % N;
  m_coords[2] = ( id / N ) % N;
  m_coords[3] = id / ( N * N );
  setMask();
}

template< cube_size N > constexpr
Coords<N> & Coords<N>::operator = ( const Coords<N> & c )
{
  m_id = c.m_id;
  m_layers = c.m_layers;
  for ( size_t i : { 1, 2, 3} )
  {
    m_coords[i] = c.m_coords[i];
  }
  return *this;
}

template< cube_size N > constexpr
Coords<N> Coords<N>::operator * ( const Spin & spin ) const
{
  Coords result;
  for ( Axis a : { _X, _Y, _Z } )
  {
    const Axis   axis  = spin.what( a );
    const size_t layer = m_coords[ abs( axis ) ];

    result.m_coords[a] = axis < 0 ? N - 1 - layer : layer;
  }
  result.setID();
  result.setMask();
  return result;
}

template< cube_size N > constexpr
size_t Coords<N>::id() const
{
  return m_id;
}

template< cube_size N > constexpr
size_t Coords<N>::layers() const
{
  return m_layers;
}

template< cube_size N > constexpr
void Coords<N>::setID()
{
  m_id = m_coords[1] + N * m_coords[2] + N * N * m_coords[3];
}

template< cube_size N > constexpr
void Coords<N>::setMask()
{
  m_layers = 0;
  for ( int i : { 0, 1, 2 } )
  {
    m_layers.add( m_coords[ i + 1 ] + N * i );
  }
}

template< cube_size N>
std::string Coords<N>::str() const
{
  std::string result( "< " );
  for ( int i : { 1, 2, 3 } )
  {
    result += numR( m_coords[i], 2 );
    result += " ";
  }
  result += " >";
  return result;
}

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const Coords<N> & coords )
{
  return os << coords.str();
}
#endif  //  ! ___CUBLET_COORDINATES__H
