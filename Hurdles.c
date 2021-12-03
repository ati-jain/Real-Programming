#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void man1()
{
    printf("   (%c) \n", 1);
    printf("   /|\\/\n");
    printf("  / |_ \n");
    printf("   / / \n");
    printf("  /    ");
}

void man2()
{
    printf("   (%c) \n", 1);
    printf("   /|\\/\n");
    printf("  / |_ \n");
    printf("  _/  \\\n");
    printf("       ");
}

void man3()
{
    printf("   (%c) \n", 1);
    printf("   /|\\_\n");
    printf("  | |  \n");
    printf("  _/ \\ \n");
    printf("     | ");
}

void man4()
{
    printf("   (%c) \n", 1);
    printf("   /|\\ \n");
    printf("   \\| \\\n");
    printf("  \\/|  \n");
    printf("    |  ");
}

void jump()
{
    printf("       \n");
    printf("   (%c) \n", 1);
    printf("   /|\\/\n");
    printf("  / |_ \n");
    printf("  _/  \\\n");
    printf("       ");
}

int main()
{
    system("cls");
    printf("---------------------------------------------------  HURDLE RACE  -----------------------------------------------------\n");
    printf("Instructions : \n");
    printf("i)Use space bar to jump.\n");
    printf("ii)Speed will increase with your score.\n");
    printf("iii)Press any key to start.\n");
    man1();
    getch();
    system("cls");
    srand(time(NULL));
    int n = 0, a = 1, y = 4;
    int x[4] = {0}, in = 0, hrdl;
    int score = 0;
    x[in] = 119;
    hrdl = 3 + (rand() % 3);
    gotoxy(0, 10);
    for (int i = 0; i < 120; i++)
        printf("%c", 196);
    gotoxy(x[in], 8);
    printf("%c", 178);
    gotoxy(x[in], 9);
    printf("%c", 178);
    gotoxy(53, 11);
    printf("Score : %d", score);
    time_t t = time(NULL);
    while (1)
    {
        if (kbhit())
        {
            if (a <= 3)
                gotoxy(0, y--);
            else if (a <= 10)
                gotoxy(0, y);
            else if (a <= 13)
                gotoxy(0, ++y);
            jump();
            a++;
            if (a >= 14)
            {
                a = 1;
                while (kbhit())
                    getch();
            }
        }

        else
        {
            gotoxy(0, 5);
            switch (n % 5)
            {
            case 0:
                man1();
                break;

            case 1:
                man2();
                break;

            case 2:
                man3();
                break;

            case 3:
                man4();
                break;

            case 4:
                man3();
                break;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (x[i] > 0)
            {
                gotoxy(--x[i], 8);
                printf("%c ", 178);
                gotoxy(x[i], 9);
                printf("%c ", 178);
                if (x[i] <= 6 && x[i] >= 2 && y > 3)
                {
                    gotoxy(x[i], 8);
                    printf("%c", 176);
                    gotoxy(53, 12);
                    printf("Game Over!!!");
                    while (getch() != 13)
                        ;
                    exit(0);
                }
                else if (x[i] == 1)
                {
                    score++;
                    gotoxy(53, 11);
                    printf("Score : %d", score);
                }
            }
            else
            {
                gotoxy(0, 8);
                printf(" \n ", 178);
            }
        }

        if (time(NULL) - t >= hrdl)
        {
            hrdl = 3 + (rand() % 3);
            t = time(NULL);
            in++;
            if (in == 4)
                in = 0;
            x[in] = 119;
        }
        usleep(100000 - (50 * score));
        n++;
    }

    return 0;
}