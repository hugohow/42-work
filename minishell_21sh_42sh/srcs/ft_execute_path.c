#include "ft_execute_path.h"

int ft_execute_path(char *path, char **argv, char ***p_environ, int fd0, int fd1, int fd2)
{
    pid_t pid;
    struct stat fileStat;
    int waitstatus;
    int i;
    i = 0;
    if (stat(path, &fileStat) < 0)
    {
        ft_putstr_fd("Command not found\n", fd2);
        return (-1);
    }
    if (access(path, X_OK) == -1)
    {
        ft_putstr_fd("Permission denied\n", fd2);
        return (-1);
    }
    pid = fork();
    if (pid < 0) 
    {
        ft_putstr_fd("Failed to fork process 1\n", fd2);
        exit(1);
    }
    if (pid == 0)
    {
        if (fd0 != 0)
        {
            dup2(fd0, STDIN_FILENO);    
            close(fd0);
        }
        if (fd1 != 1)
        {
            dup2(fd1, STDOUT_FILENO);
            close(fd1);
        }
        if (execve(path, argv, *p_environ) < 0)
            ft_putstr_fd("erreure\n", fd2);
        exit(0);
    }
    if (fd0 != 0)
        close(fd0);
    if (fd1 != 1)
        close(fd1);
    do {
        int w;
        w = waitpid(pid, &waitstatus, WUNTRACED | WCONTINUED);
        if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(waitstatus)) {
            // printf("terminé, code=%d\n", WEXITSTATUS(waitstatus));
        } else if (WIFSIGNALED(waitstatus)) {
            printf("tué par le signal %d\n", WTERMSIG(waitstatus));
        } else if (WIFSTOPPED(waitstatus)) {
            printf("arrêté par le signal %d\n", WSTOPSIG(waitstatus));
        } else if (WIFCONTINUED(waitstatus)) {
            printf("relancé\n");
        }
    } while (!WIFEXITED(waitstatus) && !WIFSIGNALED(waitstatus));
    // parent
    i = WEXITSTATUS(waitstatus);

    return (i);
}