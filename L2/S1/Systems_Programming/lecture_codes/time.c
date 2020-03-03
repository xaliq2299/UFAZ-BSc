#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char*argv[])
{
  int res;
  struct stat b;
  if (argc!=2)
    {
      fprintf(stderr,"usage: %s arg1 (exepects only 1 argument)\n", argv[0]);
      exit(2);}
  printf("The chosen file is : %s\n", argv[1]);
  res=stat(argv[1], &b);
  if (res!=0)
    {
      fprintf(stderr, "error : no such file !!!\n");
      exit(3);
    }
  printf("st_mtime = %ld, st_ctime = %ld, st_atime = %ld\n", b.st_mtime, b.st_ctime, b.st_atime);
  return 0;
}
