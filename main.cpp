#include <cframework.h>
#include <cube_rotations.h>

int main(int argc, char **argv)
{
  clog( Spin( _X, 1 ) | Spin( _Z, 3 ) );
  CRotationLookUp<5> cl(0);
  cl.print();

  CFrame<4> frame;
  frame.print();
  Slice<4> a( 3, 1 );

  clog( a );
  frame << a;
  frame.print();
  clog( a * Spin( _Z, 3 ) );
  frame << ( a * Spin( _Z, 3 ) );
  frame.print();
  return 0;
}
