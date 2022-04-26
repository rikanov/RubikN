#ifndef ___CUBE_ORIENT__H
#define ___CUBE_ORIENT__H

#include <base.h>

class Axis
{
  static constexpr const char * Facets ="FUR LDB";
  
  static constexpr Color::Modifier Colors[7] = { Color::red,
                                          Color::blue,
                                          Color::yellow,
                                          Color::gray,
                                          Color::white,
                                          Color::green,
                                          Color::light
                                        };


  int m_id;


public:
  constexpr Axis( const int & id )
    : m_id( id )
  {

  }

  constexpr Axis()
   : m_id( 0 )
  {

  }

  constexpr Axis( const Axis & axis )
   : m_id( axis.m_id )
  {

  }

  constexpr void operator = ( const Axis & axis )
  {
    m_id = axis.m_id;
  }

  constexpr Axis operator * ( const Axis & axis ) const
  {
    const int norm = 6 - abs( m_id ) - abs( axis.m_id );
    const int sign = ( abs( m_id ) % 3 == abs( axis.m_id  ) - 1 ) ? 1 : -1;
    return norm * sign * sgn( m_id * axis.m_id );
  }

  constexpr operator int () const
  {
    return m_id;
  }

  constexpr Axis inv() const
  {
    return Axis( - m_id );
  }

  constexpr void invert()
  {
    m_id *= -1;
  }

  constexpr bool reverted() const
  {
    return m_id < 0;
  }

  constexpr char facet() const
  {
    return Facets[ 3 + m_id ];
  }

  Color::Modifier color() const;

};

static constexpr Axis  _X = Axis( 1 );
static constexpr Axis  _Y = Axis( 2 );
static constexpr Axis  _Z = Axis( 3 );
static constexpr Axis _Xi = Axis( -1 );
static constexpr Axis _Yi = Axis( -2 );
static constexpr Axis _Zi = Axis( -3 );
static constexpr Axis _NA = Axis( 0 );

std::ostream & operator << ( std::ostream &, const Axis & );

#endif  //  ! ___CUBE_ORIENT__H
