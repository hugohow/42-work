#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à écrire */

void read_write(void)
{
    char message[TAILLE_MESSAGE];
    
    read(0, message, TAILLE_MESSAGE);
    write(1, message, 2);
    return ;
}

int main(void)
{
    pid_t pid_fils;
    pid_t pid_fils2;
    int descripteurTube1[2];
    int descripteurTube2[2];

    char message[TAILLE_MESSAGE];

    pipe(descripteurTube1);
    pipe(descripteurTube2);

    pid_fils = fork();

    write(descripteurTube1[1], "ok", 2);

    if (pid_fils == 0)
    {
        close(descripteurTube1[1]);
        close(descripteurTube2[0]);
        dup2(descripteurTube1[0], 0);
        dup2(descripteurTube2[1], 1);
        close(descripteurTube1[0]);
        close(descripteurTube2[1]);

        read_write();
        exit(0);
    }
    wait(NULL);
    // read(descripteurTube1[0], message, TAILLE_MESSAGE);

    pid_fils2 = fork();
    if (pid_fils2 == 0)
    {
        close(descripteurTube2[1]);
        dup2(descripteurTube2[0], 0);
        close(descripteurTube2[0]);

        read_write();
        exit(0);
    }
    wait(NULL);
    return EXIT_SUCCESS;
}
