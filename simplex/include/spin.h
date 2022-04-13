#ifndef ___CUBE_SPIN__H
#define ___CUBE_SPIN__H


#include <spin_lookup.h>

#define all_spin( spin ) for ( Spin spin( 0 ); spin.id() < 24; ++ spin )

class Spin
{
  static constexpr SpinLookUp LookUp = 0;

  uint8_t m_id;

public:
  constexpr Spin()
   : m_id( 0 )
  {

  }

  constexpr explicit Spin( const uint8_t & cid )
    : m_id( cid )
  {

  }

  constexpr Spin( const Axis axis, const Turn turn )
    : m_id( LookUp.twist( axis, turn ) )
  {

  }

  constexpr bool operator == ( const Spin spin ) const
  {
    return spin.m_id == m_id;
  }

  constexpr Spin operator * ( const Spin & spin ) const
  {
    return Spin( LookUp( m_id, spin.m_id ) );
  }

  constexpr void operator *= ( const Spin & spin )
  {
    m_id = LookUp( m_id, spin.m_id );
  }

  constexpr Spin operator | ( const Spin & spin ) const
  {
    return spin.inv() * *this * spin;
  }

  constexpr Spin operator ++ ()
  {
    return Spin( m_id ++ );
  }

  constexpr Spin inv() const
  {
    return Spin( LookUp.inv( m_id ) );
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
  constexpr Axis twister() const
  {
    return LookUp.twister( m_id );
  }

};

std::ostream & operator << ( std::ostream &, const Spin & );

#endif  //  ! ___CUBE_SPIN__H
