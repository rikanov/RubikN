#ifndef ___SPIN_LOOKUP__H
#define ___SPIN_LOOKUP__H

#include <axis.h>
#include <turn.h>
#include <permutation3.h>


class SpinLookUp
{
  static constexpr uint8_t Twist [4][4] = {
                                            { 0,  0,  0,  0 },
                                            { 0,  3, 12, 15 },    // RUF, RFD, RDB, RBU
                                            { 0,  8,  6,  2 },   //  RUF, BUR, LUB, FUL
                                            { 0, 13, 18,  7 },  //   RUF, ULF, LDF, DRF
                                          };
  uint8_t m_compose [ 24 ] [ 24 ] = {};
  uint8_t m_invert  [ 24 ] = {};
  uint8_t m_twister [ 24 ] = {};

  constexpr void init();
  constexpr void set( const uint8_t id1, const uint8_t id2 );

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

  // a * b * a'
  constexpr Perm3 conjugation ( const uint8_t coset, const uint8_t side ) const
  {
    return Perm3( side ) * Perm3( coset ) * Perm3( inv( side ) );
  }

  constexpr uint8_t twist( const Axis axis, const Turn turn ) const
  {
    return Twist[ axis ][ turn.id() ];
  }

  constexpr Axis twister( const uint8_t id ) const
  {
    return m_twister[id];
  }
};

constexpr
void SpinLookUp::set( const uint8_t id1, const uint8_t id2 )
{
  const Perm3 p1( id1 ), p2( id2 );
  m_compose[ id1 ][ id2 ] = ( p1 * p2 ).id();

  if ( 0 == m_compose[ id1 ][ id2 ] )
  {
    m_invert[ id1 ] = id2;
  }
}

constexpr
void SpinLookUp::init()
{
  for ( size_t id1 = 0; id1 < 24; ++ id1 )
  {
    for ( size_t id2 = 0; id2 < 24; ++ id2 )
    {
      set( id1, id2 );
    }
  }

  for( Axis axis : { _X, _Y, _Z } )
  {
    for( int turn : { 1, 2, 3 } )
    {
      m_twister[ Twist[ axis ][ turn ] ] = axis;
    }
  }
}

#endif  //  ! ___SPIN_LOOKUP__H
