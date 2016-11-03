// Work with Directories in C

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int total_size(DIR *d) {
  struct dirent *dirdata = (struct dirent *)calloc(sizeof(struct dirent), 1);
  struct dirent *tmp = dirdata;
  struct stat *metadata = (struct stat *)calloc(sizeof(struct stat), 1);
  int size = 0;
  while (dirdata = readdir(d)) {
    stat(dirdata->d_name, metadata);
    size += metadata->st_size;
    // printf("File Name: %s\n", dirdata->d_name); // Debugging
  }
  free(metadata); free(tmp);
  rewinddir(d);
  return size;
}

int print_size(int i) {
  printf("Total Size: ");
  if (i > 1024 * 1024 * 1024) {
    printf("%.3f GB", i / (1024 * 1024 * 1024.));
  } else if (i > 1024 * 1024) {
    printf("%.3f MB", i / (1024 * 1024.));
  } else if (i > 1024) {
    printf("%.3f KB", i / 1024.);
  } else {
    printf("%d B", i);
  }
  printf("\n");
}

void print_contents(DIR *d) {
  struct dirent *dirdata = (struct dirent *)calloc(sizeof(struct dirent), 1);
  struct stat *metadata = (struct stat *)calloc(sizeof(struct stat), 1);
  struct dirent *tmp = dirdata;
  printf("Directories:\t");
  while (dirdata = readdir(d)) { // Directories
    stat(dirdata->d_name, metadata);
    if (S_ISDIR(metadata->st_mode))
      printf("%s\n\t\t", dirdata->d_name);
  }
  printf("\n");
  rewinddir(d);
  printf("Regular Files:\t");
  while (dirdata = readdir(d)) { // Directories
    stat(dirdata->d_name, metadata);
    if (S_ISREG(metadata->st_mode))
      printf("%s\n\t\t", dirdata->d_name);
  }
  printf("\n");
  free(metadata); free(tmp);
  rewinddir(d);
}

int main() {
  // Setting Errno
  errno = 0;

  // Open Directory
  DIR *d = opendir(".");

  // Read Files
  int total = total_size(d);
  print_size(total);
  print_contents(d);

  // Close Directory
  closedir(d);

  // printf("Error %d: %s\n", errno, strerror(errno));
}
