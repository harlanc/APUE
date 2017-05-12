#include <fcntl.h>

int main(void)
{
    chmod("foo",S_ISGID);
    chmod("bar",S_ISGID);
    return 0;
}
