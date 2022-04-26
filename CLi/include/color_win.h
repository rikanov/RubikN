#ifndef ___COLOR_TEXT_OUTPUT_FOR_CONSOLES
#define ___COLOR_TEXT_OUTPUT_FOR_CONSOLES

#include <iostream>
#include <windows.h>   // WinApi header

namespace Color 
{
  static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  enum Code {
    DEFAULT       = 7, 
    BOLD          = FOREGROUND_INTENSITY,
    ULINE         = FOREGROUND_INTENSITY,
  	FLASH         = FOREGROUND_INTENSITY,
    BLACK         = 0,
    BLUE          = 1,
    GREEN         = 2,
    CYAN          = 3,
    RED           = 4,
    MAGENTA       = 5,
    BROWN         = 6,
    LIGHT_GRAY    = 7, 
    DARK_GRAY     = 8, 
    LIGHT_BLUE    = 9, 
    LIGHT_GREEN   = 10, 
    LIGHT_CYAN    = 11,
    LIGHT_RED     = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_YELLOW  = 14,
    WHITE         = 15
  };

  class Modifier 
  {
    Code m_code;
  public:
    constexpr Modifier() : m_code( DEFAULT ) {}
    constexpr Modifier( Code pCode ) : m_code( pCode ) { }
    
    Code code() const 
    {
      return m_code;
    }

    friend std::ostream& operator << ( std::ostream & os, const Modifier & mod ) 
    {
      SetConsoleTextAttribute( hConsole, mod.code() );
      return os;
    }

    friend std::wostream& operator << ( std::wostream & os, const Modifier & mod ) 
    {
      SetConsoleTextAttribute( hConsole, mod.code() );
      return os;
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

#endif  //  ! ___COLOR_TEXT_OUTPUT_FOR_CONSOLES