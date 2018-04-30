#include <time.h>
#include <stdio.h>

/*void time()
{
    const char *time_details = "24 11 2017 11:12";
struct tm tm;
strptime(time_details, "%d %m %Y %H:%M", &tm);
time_t t = mktime(&tm);  // t is now your desired time_t


}*/


void convertTime2Str(const time_t * time,char * str )
{
    struct tm *t = localtime(time);
    strftime(str, 19, "%Y %m %d %H:%M:%S", t);
}

void convertStr2Time(const char * str,time_t * time)
{
    struct tm tmt;
    strptime(str, "%Y %m %d %H:%M:%S", &tmt);
    *time = mktime(&tmt);
}

void getCurTimeStr(char * dateresult)
{
    time_t now = time(NULL);
    convertTime2Str(&now,dateresult);
}


void printTime(struct tm *tt)
{

printf("tm_sec:%d",tt->tm_sec);
printf("tm_min:%d",tt->tm_min);
printf("tm_hour:%d",tt->tm_hour);
printf("tm_mday:%d",tt->tm_mday);
printf("tm_mon:%d",tt->tm_mon);
printf("tm_year:%d",tt->tm_year);
printf("tm_wday:%d",tt->tm_wday);
printf("tm_yday:%d",tt->tm_yday);
printf("tm_isdst:%d",tt->tm_isdst);



}


int main(int argc,char **argv){

char text[20]={0};

getCurTimeStr(text);


printf("Current Date: %s\n", text);

time_t tie;
convertStr2Time(text,&tie);

    printf("now time1 : %lld\n",(long long)tie);
char test2[20]={0};
convertTime2Str(&tie,test2);
time_t now = time(NULL);

    printf("now time2 : %lld\n",(long long)now);
printf("Current Date: %s\n", test2);
/*const char *time_details = "24 11 2017 11:12";
struct tm tmt;
strptime(text, "%d %m %Y %H:%M:%S", &tmt);
time_t tt = mktime(&tmt);  // t is now your desired time_t
printTime(&tmt);*/
double rv = difftime(now+3,tie);

printf("results: %.f\n",rv);

return 0;
}
