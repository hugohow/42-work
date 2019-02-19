#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à écrire */

int main(void)
{
    pid_t pid_fils;
    int descripteurTube[2];

    char messageEcrire[TAILLE_MESSAGE];

    pipe(descripteurTube);

    pid_fils = fork();

    if(pid_fils != 0) /* Processus père */
    {
        sprintf(messageEcrire, "Bonjour, fils. Je suis ton père !"); /* La fonction sprintf permet de remplir une chaîne de caractère avec un texte donné */
        write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);
    }

    return EXIT_SUCCESS;
}
