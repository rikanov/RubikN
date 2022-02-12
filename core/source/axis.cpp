#include <axis.h>

const Color::Modifier Axis::Colors[7] = { Color::red,
                                          Color::blue,
                                          Color::yellow,
                                          Color::gray,
                                          Color::white,
                                          Color::green,
                                          Color::light
                                        };


Color::Modifier Axis::color() const
{
  return Colors[ 3 + m_id ];
}


std::ostream & operator << ( std::ostream & os, const Axis & axis )
{
  return os << axis.color() << axis.facet() << Color::off;
}

