#ifndef ___SPIN_LOOKUP__H
#define ___SPIN_LOOKUP__H

#include <axis.h>
#include <permutation3.h>

class SpinLookUp
{
  uint8_t m_compose [ 24 ] [ 24 ] = {};
  uint8_t m_invert  [ 24 ] = {};
  constexpr void init();

public:

  constexpr SpinLookUp( int )
  {
    init();
  }

  constexpr uint8_t operator () ( const uint8_t id1, const uint8_t id2 ) const
  {
    return m_compose[ id1 ][ id2 ];
  }

  constexpr uint8_t inv( const uint8_t id ) const
  {
    return m_invert[ id ];
  }

};

constexpr
void SpinLookUp::init()
{
  for ( size_t id1 = 0; id1 < 24; ++ id1 )
  {
    for ( size_t id2 = 0; id2 < 24; ++ id2 )
    {
      m_compose[ id1 ][ id2 ] = ( Perm3( id1 ) * Perm3( id2 ) ).id();
      if ( 0 == m_compose[ id1 ][ id2 ] )
      {
        m_invert[ id1 ] = id2;
      }
    }
  }
}

#endif  //  ! ___SPIN_LOOKUP__H
