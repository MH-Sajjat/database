#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
  pid_t q = fork();
  if (q == 0) {
    for (int i = 0; i < 20; ++i) {
      printf("I'm a child process id %d %d\n", getpid(), q);
    }
  } else {
    for (int i = 0; i < 20; ++i) {
      printf("I'm a parent process id %d %d\n", getpid(), q);
    }
  }
  return 0;
}
