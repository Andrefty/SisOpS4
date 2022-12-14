#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool varalarma = true;
void handle_alarm(int sig)
{
    printf("Primit semnal alarma\n");
    varalarma = false;
}

int main()
{
    signal(SIGALRM, handle_alarm);
    alarm(2);

    while (1)
    {
        if (varalarma == false)
            break;
        printf("In bucla infinita\n");
        sleep(1);
    }

    printf("Continui dupa bucla\n");
    return 0;
}