#ifndef ___CUBE_SPIN__H
#define ___CUBE_SPIN__H


#include <spin_lookup.h>

#define all_spin( spin ) for ( Spin spin : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 } )

using Turn = uint8_t;

class Spin
{
  static constexpr SpinLookUp LookUp = 0;

protected:
  uint8_t m_id;

public:
  constexpr Spin()
   : m_id( 0 )
  {

  }

  constexpr Spin( const uint8_t & cid )
    : m_id( cid )
  {

  }

  constexpr bool ident() const
  {
    return 0 == m_id;
  }

  constexpr bool operator == ( const Spin spin ) const
  {
    return spin.m_id == m_id;
  }

  constexpr Spin operator * ( const Spin & spin ) const
  {
    return LookUp( m_id, spin.m_id );
  }

  constexpr void operator *= ( const Spin & spin )
  {
    m_id = LookUp( m_id, spin.m_id );
  }
  constexpr Spin inv() const
  {
    return LookUp.inv( m_id );
  }

  constexpr uint8_t id() const
  {
    return m_id; // = Perm3( m_id ).id();
  }

  const Color::Modifier color() const;
  std::string str() const;
  void plot() const;

  constexpr
  Axis what( const Axis axis ) const
  {
    return Perm3( m_id ).whatIs( axis );
  }

  constexpr
  Axis where( const Axis axis ) const
  {
    return Perm3( LookUp.inv( m_id ) ).whatIs( axis );
  }

};

struct Tilt
{
  static constexpr Spin X[4] = { 0,  3, 12, 15 };    // RUF, RFD, RDB, RBU
  static constexpr Spin Y[4] = { 0,  8,  6,  2 };   //  RUF, BUR, LUB, FUL
  static constexpr Spin Z[4] = { 0, 13, 18,  7 };  //   RUF, ULF, LDF, DRF

  static constexpr Spin get( const Axis axis, const Turn turn );
};

constexpr
Spin Tilt::get( const Axis axis, const Turn turn)
{
  switch( axis )
  {
    case 1:
      return X[turn];
    case 2:
      return Y[turn];
    case 3:
      return Z[turn];
    default:
      return 0;
  };
}

std::ostream & operator << ( std::ostream &, const Spin & );

#endif  //  ! ___CUBE_SPIN__H
