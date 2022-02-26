#ifndef ___RUBIKS_GROUP__H
#define ___RUBIKS_GROUP__H

#include <cposition.h>
#include <cube_rotations.h>

#include <vector>

template< cube_size N >
class GroupMap
{

};
template< cube_size N >
class Group
{
  using Stack = std::vector< Coords<N> >;

  Stack    m_members;
  uint32_t m_groupID;

public:

  CPosition<N> member( const size_t ) const;
};

template< cube_size N >
CPosition<N> Group<N>::member( const size_t id ) const
{
  return CPosition<N>( m_members[id], ( m_groupID % pow24( id + 1 ) ) / pow24( id ) );
}

#endif  //  ! ___RUBIKS_GROUP__H
