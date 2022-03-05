#ifndef ___CUBE_ROTATIONS__H
#define ___CUBE_ROTATIONS__H

#include <slice.h>

template< cube_size N >
class CRotationLookUp
{                                  //  0  1  2  3  4  5  6   7   8   9  10
  static constexpr size_t Layers[] = { 0, 0, 1, 3, 5, 7, 8, 10, 11, 13, 14 };
  static constexpr size_t Size = Layers[N];

  std::array< Slice<N>, 9 * Size + 1 > m_rotation;

  constexpr void init();
public:
  constexpr CRotationLookUp( int );
  void print() const;
};

template< cube_size N > constexpr
CRotationLookUp<N>::CRotationLookUp( int )
{
  init();
}

template< cube_size N > constexpr
void CRotationLookUp<N>::init()
{
  clog( "size:" , Size );
  for ( size_t id = 0; id < Size; ++ id )
  {
    const size_t layers = id < N ? ( 1ULL << id ) : ( 1ULL << ( id - N + 2 ) ) - 1;
    m_rotation[ id + 1 ] = Slice<N> ( layers, 1 );
  }
  for ( size_t id = 1; id <= Size; ++ id )
  {
    m_rotation[ Size + id ] = m_rotation[ id ] * Spin( _Z, 3 );
  }
  for ( size_t id = 1; id <= Size; ++ id )
  {
    m_rotation[ 2 * Size + id ] = m_rotation[ id ] * Spin( _Y, 1 );
  }
}

template< cube_size N >
void CRotationLookUp<N>::print() const
{
  for ( size_t id = 0; id <= 3 * Size; ++ id )
  {
    clog( m_rotation[id] );
  }
}


template< cube_size N >
class CRotations
{

};

#endif  //  ! ___CUBE_ROTATIONS__H
