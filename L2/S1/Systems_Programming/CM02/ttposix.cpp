#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include <unistd.h>

int main() 
{
#ifdef _POSIX_JOB_CONTROL
    std::cout << "System supports job control\n";
#else
    std::cout << "System does not support job control\n";
#endif

#ifdef _POSIX_SAVED_IDS
   std::cout << "System supports saved set-UID and saved set-GID\n";
#else
   std::cout << "System does not support saved set-UID and saved set-GID\n";
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
     std::cout << "chown restricted option is: " << _POSIX_CHOWN_RESTRICTED << std::endl;
#else
      std::cout << "System does not support system-wide chown_restricted option\n";
#endif

#ifdef _POSIX_NO_TRUNC
    std::cout << "Pathname trucnation option is: " << _POSIX_NO_TRUNC << std::endl;
#else
   std::cout << "System does not support system-wide pathname trucnation option\n";
#endif

#ifdef _POSIX_VDISABLE
    std::cout << "Disable character for terminal files is: " << _POSIX_VDISABLE << std::endl;
#else
    std::cout << "System does not support _POSIX_VDISABLE\n";
#endif

    return 0;
    }
