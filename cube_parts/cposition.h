#ifndef ___CUBELET_POSITION__H
#define ___CUBELET_POSITION__H

#include <cposition_lookup.h>
#include <slice.h>

template< cube_size N >
class CPosition
{
  static constexpr CPositionLookUp<N> LookUp = 0;

  Coords<N>  m_coords;
  Spin       m_state;

public:
  constexpr CPosition();
  constexpr CPosition( const Coords<N> &, const Spin & );
  constexpr CPosition( const uint8_t x, const uint8_t y, const uint8_t z );

  uint32_t coords() const
  {
    return LookUp( m_coords.id(), m_state.id() );
  }

  Spin state() const
  {
    return m_state;
  }

  CPosition operator * ( const Spin & spin ) const
  {
    return CPosition( LookUp( m_coords.id(), spin ), m_state * spin );
  }

  void operator *= ( const Spin & spin )
  {
    m_coords = LookUp( m_coords.id(), spin );
    m_state *= spin;
  }

  void operator *= ( const Slice<N> & slice )
  {
    if ( m_coords.layers() & slice.layers() )
    {
      m_coords = LookUp( m_coords.id(), slice.spin() );
      m_state *= slice.spin();
    }
  }

  std::string str() const;
};

template< cube_size N > constexpr
CPosition<N>::CPosition()
  : m_coords( 0 )
  , m_state( 0 )
{

}

template< cube_size N > constexpr
CPosition<N>::CPosition( const Coords<N> & coords, const Spin & state )
  : m_coords( coords )
  , m_state( state )
{

}

template< cube_size N > constexpr
CPosition<N>::CPosition( const uint8_t x, const uint8_t y, const uint8_t z )
  : m_coords( Coords<N>( x, y, z ) )
  , m_state( 0 )
{

}

template< cube_size N >
std::string CPosition<N>::str() const
{
  return m_coords.str();
}

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const CPosition<N> & pos )
{
  return os << pos.str();
}
#endif  //  ! ___CUBELET_POSITION__H
