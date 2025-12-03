//Enobi Modifies

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawBorder() {
    setColor(11);
    printf("|-----------|\n");  
    setColor(7);
}

int main() {
    srand(time(0));

    int x = 1;              
    int step = 0;           
    int obstaclePos = rand() % 3;
    int score = 0;
    int lives = 3;
    int highScore = 0;
    int speed = 150;

    FILE *f = fopen("highscore.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", &highScore);
        fclose(f);
    }

START:
    x = 1;
    step = 0;
    obstaclePos = rand() % 3;
    score = 0;
    lives = 3;
    speed = 150;

    while (1) {
        if (_kbhit()) {
            int ch = getch();

            if (ch == 'p' || ch == 'P') {
                printf("\nGame Paused. Press any key to continue...");
                getch();
            }

            if (ch == 'q' || ch == 'Q') {
                printf("\nQuitting Game...\n");
                return 0;
            }

            if (ch == 224) {
                ch = getch();
                if (ch == 75 && x > 0) x--;
                if (ch == 77 && x < 2) x++;
            }
        }

        system("cls");
        drawBorder();

        // FROM HERE GAME AREA BEGINS
        for (int i = 0; i < 10; i++) {
            if (i == step) {
                setColor(12);
                if (obstaclePos == 0)      printf("| @         |\n");
                else if (obstaclePos == 1) printf("|     @     |\n");
                else                       printf("|         @ |\n");
                setColor(7);
            } else {
                printf("|           |\n");
            }
        }

        // PLAYER FIXED alignment(no extra spaces)
        setColor(10);
        if (x == 0)      printf("| ^         |\n");
        else if (x == 1) printf("|     ^     |\n");
        else             printf("|         ^ |\n");
        setColor(7);

        printf("Score: %d   Lives: %d   High Score: %d\n", score, lives, highScore);
        printf("[P] Pause   [Q] Quit\n");

        if (lives == 0) break;

        Sleep(speed);
        step++;

        if (step >= 10) {
            if (x == obstaclePos) {
                lives--;
                Beep(400, 150);

                setColor(12);
                printf("\n!! You hit an obstacle! Lives left: %d\n", lives);
                setColor(7);

                Sleep(500);
            } else {
                score++;
                Beep(700, 50);

                if (score % 5 == 0 && speed > 60)
                    speed -= 10;
            }

            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    system("cls");
    setColor(12);
    printf("\n=== GAME OVER ===\n");
    setColor(7);

    if (score > highScore) {
        FILE *fw = fopen("highscore.txt", "w");
        if (fw != NULL) {
            fprintf(fw, "%d", score);
            fclose(fw);
        }
        printf("\n*** New High Score! ***\n");
        highScore = score;
    }

    printf("\nFinal Score: %d\n", score);
    printf("High Score: %d\n", highScore);

    printf("\nPress R to Restart or Q to Quit: ");
    char ch = getch();

    if (ch == 'r' || ch == 'R')
        goto START;
    else
        return 0;
}


