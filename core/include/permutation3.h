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
  constexpr Perm3();
  constexpr Perm3( const uint8_t & id );
  constexpr size_t id() const;

  constexpr Perm3 & operator = ( const Perm3 & perm );
  constexpr Perm3 operator * ( const Perm3 & twist ) const;

  constexpr Axis whatIs( const Axis axis ) const;
  constexpr Axis operator [] ( const Axis axis ) const;
};

// include constexpr source
#include "..\source\permutation3.cpp"
#endif  //  ! ___AXIS_PERMUTATIONS__H
