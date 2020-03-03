/**
 * C program to find file permission, size, creation and last modification date of
 * a given file.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void printFileProperties(struct stat stats);

int main()
{
    char path[100];
    struct stat stats;
    printf("Enter source file path: ");
    scanf("%s", path);
    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(path, &stats) == 0) printFileProperties(stats);
    else{
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n", path);
    }
    return 0;
}

/**
 * Function to print file properties.
 */
void printFileProperties(struct stat stats)
{
    struct tm la, dt, mt;
	
	printf("\n ST_MODE VALUE: %ld \n",stats.st_mode);
    // File permission
    printf("\n File access: ");
    if (stats.st_mode & R_OK) printf("read ");
    if (stats.st_mode & W_OK) printf("write ");
    if (stats.st_mode & X_OK) printf("execute");
    printf("\n The File : ");
    if ((stats.st_mode & F_OK) == 0) printf("Exists");
    
    printf("\n Permissions : %d",stats.st_mode & 0777);
    printf("\n Type : %d\n",stats.st_mode & 0xf000);
    if ((stats.st_mode & 0xf000) == 0x1000) printf("\nThe file is Directory");
    if ((stats.st_mode & 0xf000) == 0x2000) printf("\nThe file is Regular FILE");

    //File Owner and Group
    printf("\nFile owner: %d", stats.st_uid);
    printf("\nFile group: %d", stats.st_gid);
    printf("\n ===== \n");
    // File size
    printf("\nFile size: %ld", stats.st_size);
    printf("\n ===== \n");
    // File Access time
    printf("\nFile atime: %ld", stats.st_atime);
    la = *(gmtime(&stats.st_atime));
    printf("\nLast Access on: %d-%d-%d %d:%d:%d", la.tm_mday, la.tm_mon, la.tm_year + 1900,
                                              la.tm_hour, la.tm_min, la.tm_sec);
    printf("\n ===== \n");
    // Get file creation time in seconds and
    // convert seconds to date and time format
    printf("\nFile ctime: %ld", stats.st_ctime);
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
    printf("\n ===== \n");
    // File modification time
    printf("\nFile mtime: %ld", stats.st_mtime);
    mt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", mt.tm_mday, mt.tm_mon, mt.tm_year + 1900,
                                              mt.tm_hour, mt.tm_min, mt.tm_sec);
    printf("\n ===== \n");
    

}
