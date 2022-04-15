#ifndef ___CUBE_ROTATIONS__H
#define ___CUBE_ROTATIONS__H

#include <slice.h>

template< cube_size N >
class CRotationLookUp
{
  static constexpr size_t LayerSetSize = N < 6 ? 2 * N - 3 : N;

  std::array< Rotate<N>, 9 * LayerSetSize > m_rotation;
  size_t m_nextRot;

  constexpr void init( Axis );
  constexpr void init( Spin );
public:
  constexpr CRotationLookUp( int );
  void print() const;
};

template< cube_size N > constexpr
CRotationLookUp<N>::CRotationLookUp( int )
  : m_nextRot( 1 )
{
  for ( Axis axis: { _X, _Y, _Z } )
  {
    init( axis );
  }
}

template< cube_size N > constexpr
void CRotationLookUp<N>::init( Axis axis )
{
  for ( Turn turn: { 1, 2, 3 } )
  {
    init( Spin( axis, turn ) );
  }
}

template< cube_size N > constexpr
void CRotationLookUp<N>::init( Spin spin )
{
  const size_t slices = N > 5 ? N : ( N - 1 );
  for ( Layer layer = 0; layer < slices; ++ layer )
  {
    const Layers<N> layers( 1 << layer );
    m_rotation[ m_nextRot ++ ] = Rotate<N>( layers, spin );
  }

  const size_t blocks = N > 5 ? 0 : N;
  for ( Layer layer = 2; layer < blocks; ++ layer )
  {
    const Layers<N> layers( ( 1 << layer ) - 1 );
    m_rotation[ m_nextRot ++ ] = Rotate<N>( layers, spin );
  }
}

template< cube_size N >
void CRotationLookUp<N>::print() const
{
  for ( size_t id = 0; id < m_nextRot; ++ id )
  {
    clog( numR( id, 2 ), m_rotation[id] );
  }
}


template< cube_size N >
class CRotations
{

};

#endif  //  ! ___CUBE_ROTATIONS__H
