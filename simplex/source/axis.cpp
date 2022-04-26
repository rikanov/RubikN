#include <axis.h>

Color::Modifier Axis::color() const
{
  return Colors[ 3 + m_id ];
}


std::ostream & operator << ( std::ostream & os, const Axis & axis )
{
  return os << axis.color() << axis.facet() << Color::off;
}

