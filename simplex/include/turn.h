#ifndef ___TURN_GROUP__H
#define ___TURN_GROUP__H

#include <base.h>

class Turn
{
  uint8_t m_id;
public:
  constexpr Turn(): m_id( 0 ) {}
  constexpr Turn( const uint8_t & id ): m_id( id ) {}

  constexpr Turn operator + ( const Turn & turn ) const
  {
    return ( m_id + turn.m_id ) % 4;
  }

  constexpr uint8_t id() const
  {
    return m_id;
  }
};

std::ostream & operator << ( std::ostream &, const Turn & );

#endif  //  ! ___TURN_GROUP__H
