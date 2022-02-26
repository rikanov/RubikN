#include <cframework.h>
#include <group.h>

Spin operator / ( const Spin spin, const Axis axis )
{
  Spin result;
  return result;
}

Spin operator % ( const Spin spin, const Axis axis )
{
  Spin result;
  return result;
}

int main(int argc, char **argv)
{
  clog( Spin( _X, 1 ) | Spin( _Z, 3 ) );
  CRotationLookUp<5> cl(0);
  cl.print();

  return 0;
}
