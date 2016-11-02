// Work with Directories in C

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

int total_size(DIR *d) {
  struct dirent *dirdata;
  struct stat *metadata;
  int size = 0;
  while (dirdata = readdir(d)) {
    stat(dirdata->d_name, metadata);
    size += metadata->st_size;
    // printf("File Name: %s\n", dirdata->d_name); // Debugging
  }
  printf("Size: %d\n", size);
  return size;
}

int main() {
  // Open Directory
  DIR *d = opendir(".");

  // Read Files
  int total = total_size(d);

  // Close Directory

  printf("I think this runs?\n");
}
