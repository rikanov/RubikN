#ifndef ___CUBE_ROTATIONS__H
#define ___CUBE_ROTATIONS__H

#include <slice.h>

template< cube_size N >
class CRotationLookUp
{
  static constexpr size_t LayerSetSize = N - 1 + ( ( N < 6 ) ? N - 2 : 0 );

  std::array< Slice<N>, 9 * LayerSetSize > m_rotation;
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
  for ( Layer layer = 0; layer < N - 1; ++ layer )
  {
    Layers<N> layers( 1 << layer );
    m_rotation[ m_nextRot ++ ] = Slice<N>( layers, spin );
  }
  for ( Layer layer = 2; N < 6 && layer < N; ++ layer )
  {
    Layers<N> layers( ( 1 << layer ) - 1 );
    m_rotation[ m_nextRot ++ ] = Slice<N>( layers, spin );
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
