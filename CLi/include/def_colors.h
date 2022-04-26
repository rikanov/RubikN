#ifndef ___DEFINE_COLORS__H
#define ___DEFINE_COLORS__H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  #include <color_win.h>
  constexpr char FChar[] = { char(254), char(0) };

#else
  #include <color_nix.h>
  constexpr char FChar[] = "▄";
#endif

#endif // ___DEFINE_COLORS__H
