#ifndef ___PROJECT_BASE__H
#define ___PROJECT_BASE__H

#include <text_output.h>
#include <initializer_list>
#include <algorithm>
#include <iterator>

typedef const size_t cube_size;



 // Signum
//--------
template < typename Type > inline constexpr
int sgn( Type x, std::false_type is_signed )
{
  return Type( 0 ) < x;
}

template < typename Type > inline constexpr
int sgn(Type x, std::true_type is_signed)
{
  return ( Type( 0 ) < x) - ( x < Type( 0 ) );
}

template < typename Type > inline constexpr
int sgn( Type x )
{
  return sgn ( x, std::is_signed<Type>() );
}


 // Powers of 24
//--------------
constexpr inline
size_t pow24( const int pow )
{
  constexpr size_t _pow24[] = { 1, 24, 576, 13824, 331776, 7962624, 191102976 };
  return _pow24[ pow ];
}
#endif  //  ! ___PROJECT_BASE__H
