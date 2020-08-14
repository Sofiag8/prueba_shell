#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{

	pid_t proc1, proc2, proc3, proc4, proc5, parent;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int status;

	printf("wait for process 1\n");
	proc1 = fork();
	if (proc1 == -1)
	{
		perror("Error:");
		return (1);
	}
	if (proc1 == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		sleep(3);
		proc1 = wait(&status);
		printf("process1 done, PID: %d\n", proc1);
		proc1 = getppid();
		printf("process1 PPID: %d\n", proc1);
		printf("process 1 finished\n");
		printf("************************************\n");
	}
	printf("wait for process 2\n");
	proc2 = fork();
	if (proc2 == -1)
	{
		perror("Error:");
		return (1);
	}
	if (proc2 == 0)
        {
                execve(argv[0], argv, NULL);
	}
        else
        {
                sleep(3);
		proc2 = wait(&status);
		printf("process 2 done, PID: %d\n", proc2);
                proc2 = getppid();
                printf("process2 PPID: %d\n", proc2);
                printf("process 2 finished\n");
		printf("************************************\n");
        }
	printf("wait for process 3\n");
        proc3 = fork();
        if (proc3 == -1)
        {
                perror("Error:");
                return (1);
        }
        if (proc3 == 0)
        {
                execve(argv[0], argv, NULL);
        }
        else
        {
                sleep(3);
		proc3 = wait(&status);
		printf("process 3 done, PID: %d\n", proc3);
                proc3 = getppid();
                printf("process3 PPID: %d\n", proc3);
                printf("process 3 finished\n");
		printf("************************************\n");
        }
	printf("wait for process 4\n");
        proc4 = fork();
        if (proc4 == -1)
        {
                perror("Error:");
                return (1);
        }
        if (proc4 == 0)
        {
                execve(argv[0], argv, NULL);
        }
        else
        {
                sleep(3);
		proc4 = wait(&status);
		printf("process 4 done, PID: %d\n", proc4);
                proc4 = getppid();
                printf("process 4 PPID: %d\n", proc4);
                printf("process 4 finished\n");
		printf("************************************\n");
        }
	printf("wait for process 5\n");
        proc5 = fork();
        if (proc5 == -1)
        {
                perror("Error:");
                return (1);
        }
        if (proc5 == 0)
        {
                execve(argv[0], argv, NULL);
        }
        else
        {
                sleep(3);
		proc5 = wait(&status);
		printf("process 5 done, PID: %d\n", proc5);
                proc5 = getppid();
                printf("process 5 PPID: %d\n", proc5);
                printf("process 5 finished\n");
		printf("************************************\n");
        }
	return (0);
}
