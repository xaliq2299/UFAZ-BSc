/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>

int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%ld \t %s\n", dir->d_ino, dir->d_name);
        }
        closedir(d);
    }
    return(0);
}