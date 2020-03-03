#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include <unistd.h>
#include <climits>

int main() 
{
#ifdef _POSIX_CHILD_MAX
    std::cout << "System CHILD MAX : " << _POSIX_CHILD_MAX << std::endl;
#else
    std::cout << "System does not HAVE limit\n";
#endif

#ifdef _POSIX_OPEN_MAX
    std::cout << "System OPEN MAX : " << _POSIX_OPEN_MAX << std::endl;
#else
    std::cout << "NOT DEFINED\n";
#endif

#ifdef _POSIX_STREAM_MAX
    std::cout << "System STREAM MAX : " << _POSIX_STREAM_MAX << std::endl;
#else
    std::cout << "NOT DEFINED" << std::endl;
#endif
return 0;
}
