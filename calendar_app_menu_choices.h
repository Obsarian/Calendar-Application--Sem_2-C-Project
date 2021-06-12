#include <stdio.h>
#include <conio.h>
#include "calendar_app_functions.h"

void date_traversal()
{
    struct date inp_date;
    char ch = '\0';
    system("cls");
    printf("\nEnter the date: ");
    scanf("%d/%d/%d", &inp_date.dd, &inp_date.mm, &inp_date.yyyy);

    while(inp_date.mm < 1 || inp_date.mm > 12 || inp_date.dd < 1 || inp_date.dd > month_len[inp_date.mm])
    {
        printf("\nINVALID INPUT!\n");
        printf("\nEnter the date: ");
        scanf("%d/%d/%d", &inp_date.dd, &inp_date.mm, &inp_date.yyyy);
    }

    do
    {
        int nod = num_of_days(inp_date.dd, inp_date.mm, inp_date.yyyy);
        char *day = day_of_date(nod);
        system("cls");
        printf("\nDate:\t\t(p)<-- %d/%d/%d -->(n)\n", inp_date.dd, inp_date.mm, inp_date.yyyy);
        printf("\nDay of Date:\t(p)<-- %s -->(n)\n", day);
        printf("\nPress:\n\t  'p' to go to previous date\n\t  'n' to go to the next date\n\t'esc' to return to main menu");

        month_len[2] = (isLeap(inp_date.yyyy) == 1)?29:28;

        ch = getch();

        switch(ch)
        {
            case 'n':
                if(inp_date.mm == 12 && inp_date.dd == 31)
                {
                    inp_date.yyyy++;
                    inp_date.dd = 1;
                    inp_date.mm = 1;
                }
                else if(inp_date.mm != 12 && inp_date.dd == month_len[inp_date.mm])
                {
                    inp_date.mm++;
                    inp_date.dd = 1;
                }
                else {inp_date.dd++;}
                break;

            case 'p':
                if(inp_date.dd == 1 && inp_date.mm == 1)
                {
                    inp_date.yyyy--;
                    inp_date.dd = 31;
                    inp_date.mm = 12;
                }
                else if(inp_date.dd == 1 && inp_date.mm != 1)
                {
                    inp_date.mm--;
                    inp_date.dd = month_len[inp_date.mm];
                }
                else {inp_date.dd--;}
                break;

            case 27 : system("cls"); break;
            default : continue;
        }

    } while (ch != 27);
}

void len_month_year()
{
    char ch = '\0';
    char cont;

    do
    {
        int year, month;
        system("cls");
        printf("\nPress:\n\t  '1': to find no. of days of entered year\n\t  '2': to find no. of days of entered month\n\t'esc': to return to main menu\n");
        ch = getch();

        switch(ch)
        {
            case '1':
                printf("\nEnter year: ");
                scanf("%d", &year);
                printf("No. of days: %d\n", (isLeap(year)==1)?366:365);
                printf("\nPress any key to continue:");
                cont = getch();
                break;

            case '2': 
                printf("\nEnter month number: ");
                scanf("%d", &month);

                while(month < 1 || month > 12)
                {
                    printf("\nINVALID INPUT!\n");
                    printf("\nEnter month number again: ");
                    scanf("%d", &month);
                }
                
                if(month == 2) {printf("No. of days: 28 (29 on leap years)\n");}
                else {printf("No. of days: %d\n", month_len[month]);}
                printf("\nPress any key to continue:");
                cont = getch();
                break;

            case 27 : system("cls"); break;
            default : continue;
        }
    } while (ch != 27);
    
}