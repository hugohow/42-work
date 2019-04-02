
#include "shell.h"

int main(int argc, char **argv)
{
    char *command;
    char **copy_env;
    int fd;
    int success;

    struct termios orig_termios;
    struct termios new_termios;


    
    if ((ft_init_terminal(&orig_termios, &new_termios)) < 0)
        return (-1);
    // if (signal(SIGPIPE, signal_callback_handler) == SIG_ERR)
    //     printf("\ncan't catch SIGWINCH\n");


    success = 0;
    copy_env = copy_environ((char **)environ);

    if (argc > 1 || isatty(0) == 0)
    {
        fd = isatty(0) == 0 ? 0 : open(argv[1], O_RDONLY);
        while (ft_ask_command(fd, &command, &orig_termios) != 0)
        {
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    else
    {
        while (42)
        {
            ft_ask_command(0, &command, &orig_termios);
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    return (success);
}
