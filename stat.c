#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>

// print_permissions
// prints permissions in rwxrwxrwx form
void print_permissions(int i) {
  char p[10];
  int ctr = 8;
  while (i) {
    p[ctr] = (i % 2) ? 'x' : '-'; i /= 2; ctr--;
    p[ctr] = (i % 2) ? 'w' : '-'; i /= 2; ctr--;
    p[ctr] = (i % 2) ? 'r' : '-'; i /= 2; ctr--;
  }
  p[9] = 0;
  printf("%s\n", p);
}

int main() {
  // I like meta
  struct stat *metadata = (struct stat *)malloc(sizeof(struct stat));
  int ret = stat("stat.c", metadata);
  if (ret == -1) {
    printf("Error #%d: %s", errno, strerror(errno));
  }

  printf("Size: %.3f KB\n", metadata->st_size / 1024.0); // Size
  print_permissions(metadata->st_mode & 0777); // Permissions
  printf("Time of Last Access: %s\n", ctime(&(metadata->st_atime)));

  free(metadata);
  return 0;
}
