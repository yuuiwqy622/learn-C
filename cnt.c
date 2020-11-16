#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("invalid number of argumens. 1 argument expected.\n");
    return 1;
  }

  DIR *dirp = opendir(argv[1]);
  if (!dirp) {
    printf("Folder does not exist: %s\n", argv[1]);
    return 1;
  }

  int fcnt = 0;
  struct dirent *e;

  while ((e = readdir(dirp)))
    fcnt += e->d_type == DT_REG;

  printf("%d\n", fcnt);
  return 0;
}