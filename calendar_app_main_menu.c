#include <stdio.h>
#include <conio.h>
#include "calendar_app_menu_choices.h"

int main()
{
    char choice;

    do
    {
        system("cls");
        printf("\nCALENDAR APPLICATION:\n");
        printf("\nEnter your choice of activity:");
        printf("\n\t  '1': Enter a date in dd/mm/yyyy format and\n\t       print the day on that date. The user can\n\t       also traverse between dates after the date\n\t       input.");
        printf("\n\t  '2': Enter a year/month number and print\n\t       the number of days in that year/month.");
        printf("\n\t'esc': Exit the program.\n");
        choice = getch();

        switch(choice)
        {
            case '1': date_traversal(); break;
            case '2': len_month_year(); break;
            case 27 : system("cls"); break;
            default : continue;
        }

    } while (choice != 27);

    return 0;
}