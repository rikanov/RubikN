#include <turn.h>



std::ostream & operator << ( std::ostream & os, const Turn & turn )
{
  return os << (int) turn.id();
}

