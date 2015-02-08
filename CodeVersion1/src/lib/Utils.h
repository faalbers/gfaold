#ifndef _GFA_UTILS_H__
#define _GFA_UTILS_H__

#include <iostream>

namespace GFA
{
    const bool LOG_DEBUG = true;
    
    class Error : public std::exception
    {
    public:
        Error(void);
        Error(const char *procName);
        Error(const char *_procName, const char *msg);
        const char * what(const char *msg) const throw ();
    };
}

#endif

