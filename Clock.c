#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
void gotoxy(int x, int y)
{
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void alarm()
{
    system("cls");
    printf("Alarm : \n");
    printf("Enter time : \n");
    printf("Hours : \n");
    printf("Minutes : \n");
    printf("AM(0)/PM(1) : \n");
    printf("Enter Message : ");
    int hours, mins, ap;
    char msg[20];
    gotoxy(7, 2);
    scanf("%d", &hours);
    gotoxy(9, 3);
    scanf("%d", &mins);
    gotoxy(13, 4);
    scanf("%d", &ap);
    gotoxy(15, 5);
    fflush(stdin);
    gets(msg);
    system("cls");
    printf("Alarm set : \n");
    time_t sec;
    sec = time(NULL) + (4.5 * 3600);
    printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
    if (((sec / 3600) + 1) % 24 >= 12)
        printf("PM");
    else
        printf("AM");
    do
    {
        while (time(NULL) % 60 != 0)
            ;
        gotoxy(0, 1);
        sec = time(NULL) + (4.5 * 3600);
        printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
        if (((sec / 3600) + 1) % 24 >= 12)
            printf("PM");
        else
            printf("AM");
        sleep(1);
    } while (((sec / 3600) % 12 + 1) != hours || ((sec / 60) % 60) != mins || (((sec / 3600) + 1) % 24) / 12 != ap);
    gotoxy(0, 2);
    printf("Alarm!!! : %s", msg);
    getch();
    return;
}

void stopwatch()
{
    system("cls");
    printf("Stopwatch : \n");
    clock_t t, st;
    t = clock();
    while (!kbhit())
    {
        gotoxy(0, 1);
        st = clock() - t;
        printf("%02d : %02d : %03d", (st / 60000), (st / 1000) % 60, st % 1000);
    }
    getch();
    getch();
    return;
}

void timer()
{
    system("cls");
    printf("Timer : \n");
    int min, sec;
    printf("Enter the duration : \n");
    printf("Minutes : \n");
    printf("Seconds : ");
    gotoxy(9, 2);
    scanf("%d", &min);
    gotoxy(9, 3);
    scanf("%d", &sec);
    system("cls");
    printf("Timer : \n");
    while (min > 0 || sec > 0)
    {
        gotoxy(0, 1);
        printf("%02d : %02d", min, sec);
        usleep(999900);
        if (sec == 0)
        {
            sec = 59;
            min--;
        }
        else
            sec--;
    }
    gotoxy(0, 1);
    printf("Time Up !!!");
    getch();
    return;
}

int main()
{
    time_t sec;
    char c;
    sec = time(NULL) + (4.5 * 3600);
start:
    system("cls");
    printf("Clock\n");
    printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
    if (((sec / 3600) + 1) % 24 >= 12)
        printf("PM");
    else
        printf("AM");
    printf("\nPress 1 to set timer\n");
    printf("Press 2 to start stopwatch\n");
    printf("Press 3 to set alarm");
    while (1)
    {
        gotoxy(0, 1);
        sec = time(NULL) + (4.5 * 3600);
        printf("%02d : %02d ", (sec / 3600) % 12 + 1, (sec / 60) % 60);
        if (((sec / 3600) + 1) % 24 >= 12)
            printf("PM");
        else
            printf("AM");
        sleep(1);
        while (time(NULL) % 60 != 0 && !kbhit())
            ;
        if (time(NULL) % 60 != 0)
        {
            c = getch();
            switch (c)
            {
            case 49:
                timer();
                break;

            case 50:
                stopwatch();
                break;

            case 51:
                alarm();
                break;

            case 27:
                goto end;
            }
            goto start;
        }
    }
end:
    return 0;
}