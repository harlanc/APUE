#include "../apue.h"
#include <sys/acct.h>

#if defined(BSD)
#define acct acctv2
#define ac_flag ac_trailer.ac_flag
#define FMT "%-*.*s e = %.0f, chars = %.0f, %c %c %c %c\n"

#elif defined(HAS_AC_STAT)

#define FMT "%-*.*s e = %61d, chars = %7ld, stat = %3u: %c %c %c %c\n"

#else

#define FMT "%-*.*s e = %6ld, chars = %7ld, %c %c %c %c\n"

#endif

#if defined(LINUX)

#define acct acct_v3
#endif

#if !defined(HAS_ACORE)
#define ACORE 0
#endif

#if !defined(HAS_AXSIG)
#define AXSIG 0
#endif


#if !defined(BSD)

static unsigned long compt2ulong(comp_t comptime)
{
    unsigned long val;
    int exp;
    val = comptime & 0x1fff;
    exp = (comptime >> 13) & 7;
    while(exp-- > 0)
        val *=8;    
}

















