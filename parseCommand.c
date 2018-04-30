#include <stdlib.h>

typedef enum {
    MONTH =0,
    DAY   =1,   
    HOUR  =2,
    MINUTE=3}Unit;
void parseCommand(char *command,Unit *u,int *value)
{
    *u = (Unit)(command[0]-'0');
    *value = atoi(command+1);
}

int main(int argc,char **argv)
{
    char *test = "234";
    Unit aa=0;
    int value;
    parseCommand(test,&aa,&value);
}
