#include <spin.h>

const Color::Modifier Spin::color() const
{
  return Perm3( m_id ) [ _Z.inv() ].color();
}

std::string Spin::str() const
{
  std::string result;
  Perm3 perm( m_id );
  for ( auto orient : { _X.inv(), _Y.inv(), _Z.inv() } )
  {
    result.push_back( perm[ orient ].facet() );
  }
  result.push_back( '(' );
  result += numR( m_id, 2 );
  result.push_back( ')' );
  return result;
}

void Spin::plot() const
{
  clog_( color(), FChar, Color::off );
}


std::ostream & operator << ( std::ostream & os, const Spin & spin )
{
  return os << spin.color()<< spin.str() << Color::off;
}
