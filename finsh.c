#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  char *cmd = NULL;
  char *argv[3];
  size_t buflen = 0;
  ssize_t nread;

  while (1) {
    printf("$ ");
    nread = getline(&cmd, &buflen, stdin);

    if (nread == -1) {
      printf("\nEOF detected. Detaching..\n.");
      break;
    }

    if (nread > 0 && cmd[nread - 1] == '\n') {
      cmd[nread - 1] = '\0';
    }

    pid_t pid = fork();

    if (pid == -1) {
      perror("finsh: An error occurred.");
      continue;
    } else if (pid == 0) {
      execvp(cmd, argv);
    } else {
      int status;
      waitpid(pid, &status, 0);
    }
  }

  free(cmd);
  return 0;
}
