#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include <unistd.h>
int main(void){
    #ifdef _POSIX_VERSION
       std::cout << "System conforms to POSIX: " << _POSIX_VERSION << std::endl;
    #else
       std::cout << "_POSIX_VERSION is undefined\n";
    #endif
    return 0;
}
