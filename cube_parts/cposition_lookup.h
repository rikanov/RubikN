#ifndef ___CUBELET_POSITION_LOOKUP__H
#define ___CUBELET_POSITION_LOOKUP__H


#include <coords.h>

#define cube_positions( x, y ,z, N ) \
  for( size_t x = 0; x < N; ++ x )    \
    for( size_t y = 0; y < N; ++ y )   \
      for( size_t z = 0; z < N; ++ z )  \


template< cube_size N >
class CPositionLookUp
{
  Coords<N> m_coords[ N * N * N ][ 24 ];

  constexpr void init();
public:
  constexpr CPositionLookUp( int );
  const Coords<N> & operator () ( const size_t , const Spin & ) const;
};

template< cube_size N > constexpr
CPositionLookUp<N>::CPositionLookUp( int )
{
  init();
}

template< cube_size N > constexpr
void CPositionLookUp<N>::init()
{
  cube_positions( x, y, z, N )
  {
    Coords<N> next( x, y, z );
    all_spin( spin )
    {
      m_coords[ next.id() ][ spin.id() ] = next * spin;
    }
  }
}

template< cube_size N >
const Coords<N> & CPositionLookUp<N>::operator () ( const size_t id, const Spin & spin ) const
{
  return m_coords[ id ][ spin.id() ];
}

#endif  //  ! ___CUBELET_POSITION_LOOKUP__H
