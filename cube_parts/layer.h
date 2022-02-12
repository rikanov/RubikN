#ifndef ___CUBE_LAYER__H
#define ___CUBE_LAYER__H

#include <spin.h>
#include <array>

template< cube_size N >
class CLayer
{
  using Layer = std::array< Spin, N * N >;

  Layer m_layer;

public:
  CLayer( Layer && array )
    : m_layer( array )
  {

  }
};
#endif  //  ! ___CUBE_LAYER__H
