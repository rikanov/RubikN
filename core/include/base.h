#ifndef ___PROJECT_BASE__H
#define ___PROJECT_BASE__H

#include <text_output.h>
#include <initializer_list>
#include <algorithm>
#include <iterator>

typedef const size_t cube_size;

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

#endif  //  ! ___PROJECT_BASE__H
