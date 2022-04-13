#ifndef ___AXIS_PERMUTATIONS__H
#define ___AXIS_PERMUTATIONS__H

#include <base.h>

class Perm3
{
  static constexpr Axis Permutations[ 6 ][ 4 ] = { { 0, 1, 2, 3 },
                                                   { 0, 2, 1, 3 },
                                                   { 0, 3, 2, 1 },
                                                   { 0, 1, 3, 2 },
                                                   { 0, 2, 3, 1 },
                                                   { 0, 3, 1, 2 }
                                                 };

  Axis m_perm[4] = {};

public:
  constexpr Perm3()
    : Perm3( 0 )
  {

  }
  constexpr Perm3( const uint8_t & id )
  {
    const size_t pid = id % 6;;
    for( int i : { 1, 2, 3 } )
    {
      m_perm[i] = Permutations[ pid ][i];
    }

    const bool sign1 = ( id / 6 ) & 1 ;
    const bool sign2 = ( id / 6 ) & 2 ;

    if ( sign1 )
    {
      m_perm[1].invert();
    }
    if ( sign2 )
    {
      m_perm[2].invert();
    }
    m_perm[3] = m_perm[1] * m_perm[2];
  }

  constexpr size_t id() const
  {
    const int pos = abs( m_perm[1] ) - 1;
    const size_t base = Permutations[ pos ][2] == abs( m_perm[2] ) ? pos : pos + 3;
    const size_t sign1 = m_perm[1].reverted() ? 1 : 0 ;
    const size_t sign2 = m_perm[2].reverted() ? 2 : 0 ;
    return base + 6 * ( sign1 + sign2 );
  }

  constexpr Perm3 & operator = ( const Perm3 & perm )
  {
    for( int i : { 1, 2, 3 } )
    {
      m_perm[i] = perm.m_perm[i];
    }
    return *this;
  }

  constexpr Perm3 operator * ( const Perm3 & twist ) const
  {
    Perm3 result;
    for( int i : { 1, 2, 3 } )
    {
      const Axis axis = twist.m_perm[i];
      result.m_perm[i] = m_perm[ abs( axis ) ];
      if ( axis.reverted() )
      {
        result.m_perm[i].invert();
      }
    }
    return result;
  }

  constexpr Axis whatIs( const Axis axis ) const
  {
    return axis.reverted() ? m_perm[ -axis ].inv() : m_perm[ axis ];
  }

  constexpr Axis operator [] ( const Axis axis ) const
  {
    return whatIs( axis );
  }
};

#endif  //  ! ___AXIS_PERMUTATIONS__H
