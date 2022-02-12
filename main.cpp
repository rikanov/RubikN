#include <cframework.h>

int main(int argc, char **argv)
{


  Axis test( GetAxis::Y.inv() );
  Spin a( 1 ), b( 22 ), c( 0 );
  clog( a, (int) a.id(), b, (int)b.id(), c, (int) c.id() );
  all_spin( spin1 )
  {
    NL();
    all_spin( spin2 )
     clog_( spin1 * spin2 );
  }
  NL();
  all_spin( spin )
  {
    clog( spin.inv() );
  }
  clog( test );

  CPosition<4> c4( 1, 2, 3 );
  clog( c4, c4 * Tilt::Y[3] * Tilt::Z[1] );
  c4 *= Tilt::Y[3] * Tilt::Z[1];
  clog( c4 );
  CFrame<4> frame;
  frame.print();
  frame << Slice<4>( GetAxis::X, 6, 1 );
  frame.print();
  frame << Slice<4>( GetAxis::Y, 1, 1 );
  frame.print();
  frame << Slice<4>( GetAxis::Y, 8, 1 );
  frame.print();
  clog( Color::off, "Press", Color::white, Color::bold, "ENTER", Color::off,"to start." );
  std::cin.get();

  return 0;
}
