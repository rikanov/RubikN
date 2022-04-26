#ifndef ___COLOR_FOR_POSIX_CONSOLES__H
#define ___COLOR_FOR_POSIX_CONSOLES__H

#include <iostream>

// clear screen ToDo
#if defined (__APPLE__)
inline void CLS()
{
  system("clear");
}
#else
inline void CLS()
{
  std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
}
#endif

namespace Color 
{
  enum Code {
    DEFAULT       = 0,
    BOLD          = 1,
    ULINE         = 4,
    FLASH         = 5,
    BLACK         = 30, 
    RED           = 31, 
    GREEN         = 32, 
    YELLOW        = 33, 
    BLUE          = 34, 
    MAGENTA       = 35, 
    CYAN          = 36, 
    LIGHT_GRAY    = 37, 
    DARK_GRAY     = 90, 
    LIGHT_RED     = 91, 
    LIGHT_GREEN   = 92, 
    LIGHT_YELLOW  = 93, 
    LIGHT_BLUE    = 94, 
    LIGHT_MAGENTA = 95, 
    LIGHT_CYAN    = 96, 
    WHITE         = 97
  };

  class Modifier 
  {
    Code m_code;
  public:
    constexpr Modifier() : m_code( DEFAULT ) {}
    constexpr Modifier( Code pCode ) : m_code( pCode ) {}
    
    Code code() const 
    {
      return m_code;
    }
    
    friend std::ostream& operator << ( std::ostream & os, const Modifier & mod ) 
    {
      return os << "\033[" << mod.code() << "m";
    }
    
    friend std::wostream& operator << ( std::wostream & os, const Modifier & mod ) 
    {
      return os << "\033[" << mod.code() << "m";
    }
    
  };
  

  constexpr Modifier off    ( DEFAULT    );
  constexpr Modifier bold   ( BOLD       );
  constexpr Modifier uline  ( ULINE      );
  constexpr Modifier flash  ( FLASH      );
  constexpr Modifier black  ( BLACK      );
  constexpr Modifier red    ( LIGHT_RED  );
  constexpr Modifier blue   ( LIGHT_BLUE );
  constexpr Modifier green  ( GREEN      );
  constexpr Modifier cyan   ( LIGHT_CYAN );
  constexpr Modifier gray   ( LIGHT_GRAY );
  constexpr Modifier dark   ( DARK_GRAY  );
  constexpr Modifier light  ( LIGHT_MAGENTA );
  constexpr Modifier yellow ( LIGHT_YELLOW  );
  constexpr Modifier white  ( WHITE         );
}

#endif  //  ! ___COLOR_FOR_POSIX_CONSOLEs__H
