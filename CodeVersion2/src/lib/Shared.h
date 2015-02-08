#ifndef __GFA_SHARED_H__
#define __GFA_SHARED_H__

#if defined _WIN32 || defined __CYGWIN__
  #ifdef GFA_BUILDING_DLL
    #ifdef __GNUC__
      #define GFA_DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define GFA_DLL_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define GFA_DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define GFA_DLL_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define GFA_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define GFA_DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define GFA_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define GFA_DLL_PUBLIC
    #define GFA_DLL_LOCAL
  #endif
#endif

#endif

