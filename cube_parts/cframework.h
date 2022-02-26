#ifndef ___CUBE_FRAMEWORK__H
#define ___CUBE_FRAMEWORK__H

#include <cposition.h>

template< cube_size N >
class CFrame
{
protected:
  using Frame = std::array< CPosition<N>, N * N * N >;

  Frame m_frame;

  void init();

  CPosition<N> whereIs( const Coords<N> & pos ) const;
  Spin whatIs( const Coords<N> & pos ) const;

public:
  CFrame()
  {
    init();
  }

  void operator << ( const Slice<N> & slice );
  void printLine( const Spin spin, const size_t line ) const;
  void print() const;
};

template< cube_size N >
void CFrame<N>::init()
{
  cube_positions( x, y, z, N )
    m_frame[ Coords<N>( x, y, z ).id() ] = CPosition<N>( x, y, z );
}

template< cube_size N>
CPosition<N> CFrame<N>::whereIs( const Coords<N> & pos ) const
{
  return m_frame[ pos.id() ];
}

template< cube_size N >
Spin CFrame<N>::whatIs( const Coords<N> & pos ) const
{
  all_spin( spin )
  {
    if ( whereIs( pos * spin ).state() == spin.inv() )
    {
      return spin.inv();
    }
  }
  return 0;
}

template< cube_size N >
void CFrame<N>::operator << ( const Slice<N> & slice )
{
  for ( auto & pos : m_frame )
  {
    pos *= slice;
  }
}

template< cube_size N>
void CFrame<N>::printLine( const Spin spin, const size_t line ) const
{
  for( size_t x = 0; x < N; ++ x )
  {
    const auto state = whatIs( Coords<N>( x, line, N - 1 ) * spin );
    ( state * spin.inv() ).plot();
  }
  clog_( " " );
}

template< cube_size N>
void CFrame<N>::print() const
{
  for ( size_t line = 0; line < N; ++ line )
  {
    clog_( std::string( 2 * N + 1, ' ' ) );
    printLine( Spin( _X, 1), N - 1 - line );
    NL();
  }
  NL();
  for ( size_t line = 0; line < N; ++ line )
  {
    printLine( Spin( _Y, 1 ), N - 1 - line );
    printLine( Spin( _Y, 0 ), N - 1 - line );
    printLine( Spin( _Y, 3 ), N - 1 - line );
    printLine( Spin( _Y, 2 ), N - 1 - line );
    NL();
  }
  NL();
  for ( size_t line = 0; line < N; ++ line )
  {
    clog_( std::string( 2 * N + 1, ' ' ) );
    printLine( Spin( _X, 3), N - 1 - line );
    NL();
  }
  NL();
}

#endif  //  ! ___CUBE_FRAMEWORK__H
