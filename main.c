#include <stdio.h>
#include <stdlib.h>
char* days[] = {"SUN","MON","TUE","WED","THUR","FRI","SAT"};
char* months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int noOfDays[] ={31,28,31,30,31,30,31,31,30,31,30,31};
//Funtion to find day 
int findDay(int d, int m, int y)
{
    if(!(m>=1 && m<=12)){
        printf("Invalid month value");
        return -1;
    }
    if(!(d>=1 && d<=noOfDays[m-1])){
        printf("Invalid date");
        return -1;
    }
    if(y>=1600)
    {
        static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
        y -= m < 3;
        int dayNumber = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
        return dayNumber;
    }
    else
    {
        printf("Please give year more than 1600");
        return -1;;
    }



}
void yearCalendar(int year)
{
    system("cls");
    int month;
    int count=0;
    int firstDayOfYear = findDay(1,1,year);
    count = firstDayOfYear;
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
       {
           noOfDays[1] = 29;
       }
    for(month=0;month<12;month++)
    {
        int days = noOfDays[month];
        printf("\n----------------%s----------------\n\n",months[month]);
        printf("    S    M    T    W    T    F    S\n");
        for(int i=0;i<count;i++)
        {
            printf("     ");
        }
        for(int i=1;i<=days;i++)
        {
            printf("%5d",i);
            count++;
            {
                if(count>6)
                {
                    printf("\n");
                    count=0;
                }
            }
        }
        printf("\n\n");
    }
}
void monthCalendar(int month, int year)
{
    while(1)
    {
        system("cls");
        int count=0;
        int firstDayOfMonth = findDay(1,month,year);
        count = firstDayOfMonth;
        if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
       {
           noOfDays[1] = 29;
       }
        int days = noOfDays[month-1];
        printf("\n----------------%s----------------\n\n",months[month-1]);
        printf("    S    M    T    W    T    F    S\n");
        //for printing 
        for(int i=0;i<count;i++)
        {
            printf("     ");
        }
        for(int i=1;i<=days;i++)
        {
            printf("%5d",i);
            count++;
            {
                if(count>6)
                {
                    printf("\n");
                    count=0;
                }
            }
        }
        printf("\n\n");
        char ch;
        printf("Enter n for next month and p for previous month: ");
        scanf("%c", &ch);
        if(ch=='n')
            month++;
        else if(ch=='p')
            month--;

    }

}
int main()
{
    system("Color 3F");
    while(1)
    {
        system("cls");
        int choice;
        int day,month,year;
        printf("\n\n1.Find out the day\n");
        printf("2.Year calendar\n");
        printf("3.Month calendar\n");
        printf("4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter Day Month Year: ");
            scanf("%d %d %d",&day,&month,&year);
            printf("Day: %s\n",days[findDay(day,month,year)]);
            printf("Enter any key");
            getch();
            break;
        case 2:
            printf("Enter the year: ");
            scanf("%d", &year);
            yearCalendar(year);
            getch();
            break;
        case 3:
            printf("Enter the Month Year: ");
            scanf("%d %d",&month,&year);
            monthCalendar(month,year);
        case 4:
            exit(0);
        default:
            printf("Please Enter the right option");
            getch();
        }

    }
    return 0;
}
