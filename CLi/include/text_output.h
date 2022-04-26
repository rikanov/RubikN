#ifndef TEXT_OUTPUT__H
#define TEXT_OUTPUT__H

#include <iostream>
#include <cstring>
#include <string>

#include <def_colors.h>

static const Color::Modifier Default = Color::off;

#define PRINT_OUT if(!LoggingON)return;

extern bool LoggingON;

// new line
inline void NL()
{
  PRINT_OUT
  std::cout << std::endl;
}

// set text color & new line
inline void NL( Color::Modifier c )
{
  PRINT_OUT
  std::cout << c << std::endl;
}

  // basic text messages
 // --------------------
template <typename T>
void clog_ ( T t ) 
{
  PRINT_OUT
  if ( typeid( t ) != typeid( Color::Modifier ) )
  {
    std::cout << t << ' ';
  }
  else
  {
    std::cout << t;
  }
  std::cout << std::flush;
}

template <typename T, typename... Args>
void clog_ ( T t, Args... args ) 
{
  PRINT_OUT
  clog_ ( t );
  clog_ ( args... );
}

template <typename T>
void clog ( T t ) 
{
  PRINT_OUT
  std::cout << t << std::endl ;
}

template<typename T, typename... Args>
void clog (T t, Args... args) // recursive variadic function
{
  PRINT_OUT
  clog_ ( t );
  clog  ( args... ) ;
}

 // basic text messages with given separator
// -----------------------------------------
template< typename T>
void slog_ ( const char * sep, T t) 
{
  PRINT_OUT
  if ( typeid( t ) != typeid( Color::Modifier ) )
  {
    std::cout << t << sep;
  }
  else
  {
    std::cout << t;
  }
}
template< typename T, typename... Args>
void slog_ ( const char * sep, T t, Args... args ) 
{
  PRINT_OUT
  slog_ ( sep, t );
  slog_ ( sep, args... );
}

template< typename T >
void slog ( const char * sep, T t) 
{
  PRINT_OUT
  std::cout << t << sep << std::endl ;
}

template< typename T, typename... Args >
void slog( const char * sep, T t, Args... args) // recursive variadic function
{
  PRINT_OUT
  slog_ ( sep, t );
  slog  ( sep, args... ) ;
}

std::string numL( const uint64_t num, const size_t size );
std::string numR( const uint64_t num, const size_t size );

// draw line
void cdraw( const char c, int p );

#undef PRINT_OUT
#endif // ! TEXT_OUTPUT__H
