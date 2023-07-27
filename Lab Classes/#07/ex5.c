#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void handler_parent()
{ printf("%d: Parent received signal\n", getpid()); }

static void handler_child()
{ printf("%d: Child received signal\n", getpid()); }

int main(int argc, char* argv[]) {
  pid_t pid;

  if(signal(SIGUSR1, handler_parent) == SIG_ERR){
    fprintf(stderr, "Can't catch the signal that the parent received: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (signal(SIGUSR2, handler_child) == SIG_ERR){
    fprintf(stderr, "Can't catch the signal that the child received: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if ((pid = fork()) < 0){
    perror("fork error");
    exit(EXIT_FAILURE);
  }

  else if (pid > 0) {
    /* parent’s code */
    kill(pid, SIGUSR2);
    pause();
  } else {
    /* child’s code */
    kill(getppid(), SIGUSR1);
    pause();
  }
}
