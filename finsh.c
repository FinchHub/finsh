#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_ARGS 64

int main() {
    char *cmd = NULL;
    char *token;
    size_t buflen = 0;
    ssize_t nread;

    while (1) {
        printf("$ ");
        nread = getline(&cmd, &buflen, stdin);
        char *str;

        if (nread == -1) {
            printf("\nEOF detected. Detaching...\n");
            break;
        }

        if (nread > 0 && cmd[nread - 1] == '\n') {
            cmd[nread - 1] = '\0';
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            continue;
        } else if (pid == 0) {
            char *args[MAX_ARGS];
            int i = 0;
            for (token = strtok_r(cmd, " ", &str); token != NULL;
                 token = strtok_r(NULL, " ", &str)) {
                printf("%s", token);
                args[i] = token;
                i++;
            }
            args[i] = NULL;
            execvp(cmd, args);
            perror("finsh");
            exit(EXIT_FAILURE);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    free(cmd);
    return 0;
}
