#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void install_package(const char *package_name) {
  char command[256];
  snprintf(command, sizeof(command), "sudo pacman -S %s", package_name);
  system(command);
}

void remove_package(const char *package_name) {
  char command[256];
  snprintf(command, sizeof(command), "sudo pacman -R %s", package_name);
  system(command);
}

void full_system_upgrade() { system("sudo pacman -Syu"); }

int main(int argc, char *argv[]) {

  if (strcmp(argv[1], "install") == 0) {
    install_package(argv[2]);
  } else if (strcmp(argv[1], "remove") == 0) {
    remove_package(argv[2]);
  } else if (strcmp(argv[1], "upgrade") == 0) {
    full_system_upgrade();
  } else {
    return 1;
  }

  return 0;
}
