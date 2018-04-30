#include "../apue.h"

int main(void)
{
    printf("real uti = %d,effective uid = %d\n",getuid(),geteuid());
    exit(0);
}
