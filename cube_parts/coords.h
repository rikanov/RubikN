#ifndef ___CUBLET_COORDINATES__H
#define ___CUBLET_COORDINATES__H

#include <spin.h>
#include <bit64set.h>

template< cube_size N >
class Coords
{
  size_t            m_id;
  BitSet<uint32_t>  m_layers;

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
  constexpr size_t coord( const Axis ) const;
  std::string str() const;
};

template< cube_size N > constexpr
Coords<N>::Coords()
  : m_id( 0 )
  , m_layers( 0 )
{
  m_layers.add( N * 0 );
  m_layers.add( N * 1 );
  m_layers.add( N * 2 );
}

template< cube_size N > constexpr
Coords<N>::Coords( const Coords<N> & c )
  : m_id( c.m_id)
  , m_layers( c.m_layers )
{

}

template< cube_size N > constexpr
Coords<N>::Coords( const uint8_t x, const uint8_t y, const uint8_t z )
  : m_id( x + N * y + N * N * z )
  , m_layers( 0 )
{
  m_layers.add( x + N * 0 );
  m_layers.add( y + N * 1 );
  m_layers.add( z + N * 2 );
}

template< cube_size N > constexpr
Coords<N>::Coords( const size_t id )
  : Coords( id % N, ( id / N ) % N, id / ( N * N ) )
{

}

template< cube_size N > constexpr
Coords<N> & Coords<N>::operator = ( const Coords<N> & c )
{
  m_id = c.m_id;
  m_layers = c.m_layers;
  return *this;
}

template< cube_size N > constexpr
Coords<N> Coords<N>::operator * ( const Spin & spin ) const
{
  return Coords<N> ( coord( spin.what( _X ) ), coord( spin.what( _Y ) ), coord( spin.what( _Z ) ) );
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

template< size_t N > constexpr
size_t Coords<N>::coord( const Axis axis ) const
{
  switch( axis )
  {
    case _X:
      return m_id % N;
    case _X.inv():
      return N - 1 - m_id % N;

    case _Y:
      return ( m_id / N ) % N;
    case _Y.inv():
      return N - 1 - ( m_id / N ) % N;

    case _Z:
      return m_id / ( N * N );
    case _Z.inv():
      return N - 1 - m_id / ( N * N );

    default:
      ;
  }
  return 0;
}

template< cube_size N>
std::string Coords<N>::str() const
{
  std::string result( "< " );
  for ( int i : { 1, 2, 3 } )
  {
    result += numR( coord( i ), 2 );
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
