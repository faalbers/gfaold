#include "Utils.h"

GFA::Error::Error()
{
    std::cout << "[GFA Error:] ";
}

GFA::Error::Error(const char *procName)
{
    std::cout << "[GFA Error: " << procName << " ]" << std::endl;
}

GFA::Error::Error(const char *procName, const char *msg)
{
    std::cout << "[GFA Error: " << procName << " ]" << std::endl;
    if (msg[0] != '\0')
        std::cout << "- " << msg << std::endl;
}

const char * GFA::Error::what(const char *msg) const throw ()
{
    std::cout << "- " << msg << std::endl;
    return msg;
}


