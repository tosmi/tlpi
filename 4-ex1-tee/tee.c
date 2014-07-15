#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define MAX_READ 1024

int openFile(char const *filename)
{
  int fd;
  int openFlags = O_CREAT | O_WRONLY | O_TRUNC;

  fd = open(filename, openFlags);
  if (fd == -1)
    errExit("open");

  return fd;
}

int writeToFile(int fd, char const *buffer)
{
  if ( write(fd, buffer, MAX_READ+1) == -1)
    fatal("could not write to output file");

  return 0;
}

int main(int argc, char *argv[])
{
  int outfd;
  char buffer[MAX_READ+1];

  if (argc < 1)
    usageErr("%s file", argv[0]);

  if (argc == 2)
    outfd = openFile(argv[1]);

  while( (read(STDIN_FILENO, buffer, MAX_READ)) > 0) {
    buffer[MAX_READ+1] = '\0';
    printf("%s", buffer);
    writeToFile(outfd, buffer);
  }

  return 0;
}
