#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *cmd = NULL;
  size_t buflen = 0;
  ssize_t nread;

  while (1) {
    printf("$ ");
    nread = getline(&cmd, &buflen, stdin);

    if (nread == -1) {
      printf("\nEOF detected. Detaching..\n.");
      break;
    }

    printf("%s", cmd);
  }

  free(cmd);
  return 0;
}
