#include <stdio.h>
#include <stdlib.h>

int month_len[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
    int dd;
    int mm;
    int yyyy;
};

int isLeap(int yyyy)
{
    return (((yyyy%4 == 0 && yyyy%100 != 0) || yyyy%400 == 0)?1:0);
}

int num_of_days(int dd, int mm, int yyyy)
{
    int nod = 0;
    int y = yyyy-1;
    
    nod = nod + (y/400)*146097;
    y %= 400;
    nod = nod + (y/100)*36524;
    y %= 100;
    nod = nod + (y/4)*1461;
    y %= 4;
    nod = nod + (365*y);

    month_len[2] = (isLeap(yyyy) == 1)?29:28;

    for(int i = 1; i < mm; i++) {nod += month_len[i];}
    nod += dd;

    return (nod);
}

char * day_of_date(int nod)
{
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[nod%7];
}