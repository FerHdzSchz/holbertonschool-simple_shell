#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - get PID
*/

int main(void)
{
    pid_t my_pid;
    pid_t my_ppid;
    const char *fname;
    char* max_pid;

    my_pid = getpid();
    my_ppid = getppid();
    fname = "/proc/sys/kernel/pid_max";

    printf("Current pid: %u\n",my_pid);
    printf("Parent pid: %u\n",my_ppid);
    max_pid = read_textfile(fname, 6);
    printf("Max number of pid: %s", max_pid);
    free(max_pid);

    return (0);

}