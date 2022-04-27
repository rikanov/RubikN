#ifndef ___RUBIK_SUBSPACE__H
#define ___RUBIK_SUBSPACE__H

#include <crotation_lookup.h>

using StateID = uint32_t;

template< cube_size N >
class RSubspace
{
  const StateID * m_states;
  size_t          m_size;

public:
  constexpr RSubspace()
    : m_states( nullptr )
    , m_size( 0 )
  {

  }

  RSubspace & operator << ( const CPosition<N> & pos );

  ~RSubspace()
  {
    delete[] m_states;
  }
};

template< cube_size N >
RSubspace<N> & RSubspace<N>::operator << ( const CPosition<N> & pos)
{
  StateID * states = new StateID [ pow24( m_size ) * CRotationLookUp<N>::Size() ];
  return *this;
}

#endif  //  ! ___RUBIK_SUBSPACE__H
