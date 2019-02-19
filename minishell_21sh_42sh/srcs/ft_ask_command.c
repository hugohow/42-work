#include "ft_ask_command.h"

char **list_historic;
int *k;


int is_quote_closed(char *cmd)
{
    int i;
    int count_opened;
    int count_closed;

    count_opened = 0;
    count_closed = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '"')
        {
            count_opened++;
        }
        i++;
    }
    return (count_opened % 2 != 0);
}


int ft_ask_command(int fd, char **command, struct termios *p_orig_termios)
{
    int key;
    char *cmd;
    int index;
    int historic_index;
    int original_row;
    char *command_tmp;
    char *command_tmp1;

    if (list_historic == NULL)
        list_historic = malloc(999*sizeof(char *));
    if (k == NULL)
    {
        k = malloc(sizeof(int));
        *k = 0;
    }
    if (fd == 0 && isatty(0) == 1)
    {
        cmd = malloc(sizeof(char) * 2);
        cmd = "";
        ft_putstr("----------🍄---------------\n");
        print_cmd(cmd);
        if (ft_get_pos(&index, &original_row) < 0)
            return (0);
        index = 0;
        historic_index = *k;
        // not enough !! for the simple ou double quote
        while (42)
        {
            key = ft_read_key();
            // printf("key : %d", key);
            if (key == 10)
            {
                // check if it's closed
                if (is_quote_closed(cmd) == 0)
                {
                    historic_index = *k + 1;
                    break;
                }
            }
            if (key == ('i' & 0x1f))
                ft_exit_terminal(p_orig_termios);
            if (key == ARROW_UP && historic_index - 1 >= 0)
            {
                // to clean
                if (cmd)
                    delete_n_lines(count_nb_line(cmd));
                cmd = list_historic[--historic_index];
                index = ft_strlen(cmd);
            }
            else if (key == ARROW_DOWN && historic_index < *k)
            {
                // to clean
                if (cmd)
                    delete_n_lines(count_nb_line(cmd));
                cmd = list_historic[++historic_index];
                index = ft_strlen(cmd);
            }
            add_to_stdout(&cmd, key, &index);
        }
        *command = cmd;
        list_historic[*k] = cmd;
        *k = *k + 1;
        list_historic[*k] = "";
        ft_putstr("\r\n");
        return (0);
    }
    int ret;
    command_tmp = malloc(9999*sizeof(char));
    ret = get_next_line(fd, &command_tmp);
    while (is_quote_closed(command_tmp) != 0 && ret >= 0)
    {
        ret = get_next_line(fd, &command_tmp1);
        command_tmp = ft_strjoin(command_tmp, "\n");
        command_tmp = ft_strjoin(command_tmp, command_tmp1);
    }
    *command = command_tmp;
    return (ret);
}