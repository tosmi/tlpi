#include <sys/stat.h>
#include <tlpi_hdr.h>

#define MAX_READ 1024

int main(int argc, char *argv[])
{

  char buffer[MAX_READ+1];

  if (argc < 1)
    usageErr("%s file", argv[0]);

  /* fd = open(STDIN_FILENO, O_RDONLY); */
  /* if (fd == -1) */
  /*   errExit("open"); */

  while( (read(STDIN_FILENO, buffer, MAX_READ)) > 0) {
    buffer[MAX_READ+1] = '\0';
    printf("%s", buffer);
  }

  return 0;
}
