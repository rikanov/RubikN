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
    Modifier() : m_code( DEFAULT ) {}
    Modifier( Code pCode ) : m_code( pCode ) {}
    
    Code code() const 
    {
      return m_code;
    }

    friend std::ostream& operator << ( std::ostream & os, const Modifier & mod ) 
    {
      SetConsoleTextAttribute( hConsole, mod.code() );
      return os << mod.code();
    }

    friend std::wostream& operator << ( std::wostream & os, const Modifier & mod ) 
    {
      SetConsoleTextAttribute( hConsole, mod.code() );
      return os;
    }
  };
  
  extern Modifier off;
  extern Modifier bold;
  extern Modifier uline;
  extern Modifier flash;
  extern Modifier black;
  extern Modifier red;
  extern Modifier blue;
  extern Modifier green;
  extern Modifier cyan;
  extern Modifier gray;
  extern Modifier dark;
  extern Modifier light;
  extern Modifier yellow;
  extern Modifier white;
}

#endif  //  ! ___COLOR_TEXT_OUTPUT_FOR_CONSOLES