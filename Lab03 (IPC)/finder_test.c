#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256

#define BASH_EXEC  "/bin/bash"
#define FIND_EXEC  "/bin/find"
#define XARGS_EXEC "/usr/bin/xargs"
#define GREP_EXEC  "/bin/grep"
#define SORT_EXEC  "/bin/sort"
#define HEAD_EXEC  "/usr/bin/head"

int main(int argc, char *argv[])
{
  int status;
  pid_t pid_1, pid_2, pid_3, pid_4;

  if (argc != 4) {
    printf("usage: finder DIR STR NUM_FILES\n");
    exit(0);
  }
  
  char cmdbuf[BSIZE];
  bzero(cmdbuf, BSIZE);
  char buf;

  int pipe1[2];
  int pipe2[2];
  int pipe3[2];
  
  int pipe(pipe1);
  int pipe(pipe2);
  int pipe(pipe3);
  

  pid_1 = fork();
  if (pid_1 == 0) {
    /* First Child */
    close(pipe1[0]);
    
    bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -name \'*\'.[ch]", FIND_EXEC, argv[1]);
    
    if ( (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, (char *) 0)) < 0) {
      fprintf(stderr, "\nError execing find. ERROR#%d\n", errno);
      return EXIT_FAILURE;
    }
    
    dup2(pipe1[1],STDOUT_FILENO);
    close(pipe1[1]);
    
    exit(0);
  }

  pid_2 = fork();
  if (pid_2 == 0) {
    /* Second Child */
    close(pipe1[1]);
    
    dup2(STDIN_FILENO,pipe1[0]);
    
    while (read(STDIN_FILENO, &buf, 1)>0)
      printf(&buf);
    
    /*bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -c %s", XARGS_EXEC, GREP_EXEC, argv[2]);*/
        
    
    
    /*dup2(pipe2[1],STDOUT_FILENO);*/
    exit(0);
  }

  pid_3 = fork();
  if (pid_3 == 0) {
    /* Third Child */
    
    /*dup2(STDIN_FILENO,pipe2[0]);
    dup2(pipe3[1],STDOUT_FILENO);*/
    printf("zxcv\n");
    exit(0);
  }

  pid_4 = fork();
  if (pid_4 == 0) {
    /* Fourth Child */
  }

  if ((waitpid(pid_1, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_2, &status, 0)) == -1) {
    fprintf(stderr, "Process 2 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_3, &status, 0)) == -1) {
    fprintf(stderr, "Process 3 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_4, &status, 0)) == -1) {
    fprintf(stderr, "Process 4 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }

  return 0;
}
