#include <unistd.h>
#include <signal.h>
#include <stdio.h>


/* My alarm func for print */
static unsigned int my_alarm(unsigned int nsec)
{
    printf("Wait for %u secs to alarm\n ", nsec);
    return alarm(nsec);
}

/* My sleep func for print */
static unsigned int my_sleep(unsigned int nsec)
{
    printf("Sleep for %u secs\n ", nsec);
    return sleep(nsec);
}

/* SIGALRM handler */
static void sig_alarm(int signo)
{
    printf("SIGALRM \n");
}

int main()
{
    /* Check alarm return value */
    unsigned int ret1, ret2;

    /* Signal handle */
    if (signal(SIGALRM, sig_alarm) < 0)
        perror("signal");

    printf("Alarm start:\n ");

    /* First alarm */
    ret1 = my_alarm(5);
    my_sleep(3);
    
    printf("New alarm:\n ");
    
    /* Second alarm */
    ret2 = my_alarm(1);
    my_sleep(4);

    printf("Alarm end\n ");

    /* Show the two return values */
    printf("First  return: %u \n", ret1);
    printf("Second return: %u \n", ret2);

    return 0;
}
