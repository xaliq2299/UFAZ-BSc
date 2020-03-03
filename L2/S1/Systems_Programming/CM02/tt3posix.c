#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main()
{
#ifdef _POSIX_CHILD_MAX
    printf("System CHILD MAX : %d \n", _POSIX_CHILD_MAX);
#else
    printf("System does not HAVE limit\n");
#endif

#ifdef _POSIX_OPEN_MAX
    printf("System OPEN MAX : %d \n",_POSIX_OPEN_MAX);
#else
    printf("NOT DEFINED\n");
#endif

#ifdef _POSIX_STREAM_MAX
    printf("System STREAM MAX : %d \n",_POSIX_STREAM_MAX);
#else
    printf("NOT DEFINED\n");
#endif

#ifdef _POSIX_LINK_MAX
    printf("System LINK MAX : %d \n",_POSIX_LINK_MAX);
#else
    printf("NOT DEFINED\n");
#endif
return 0;
}
