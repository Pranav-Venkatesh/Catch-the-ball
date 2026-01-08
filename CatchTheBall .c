#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    int ballX, ballY;
    int basketX = WIDTH / 2;
    int score = 0;
    char ch;

    srand(time(NULL));

    ballX = rand() % WIDTH;
    ballY = 0;

    while (1) {
        // Clear screen
        system("cls");

        // Draw top border
        for (int i = 0; i < WIDTH; i++) printf("-");
        printf("\n");

        // Draw game area
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (x == ballX && y == ballY) {
                    printf("O");   // the falling ball
                } else if (y == HEIGHT - 1 && (x == basketX || x == basketX + 1 || x == basketX - 1)) {
                    printf("U");   // the basket
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Draw score
        printf("\nScore: %d\n", score);
        printf("Use A/D to move, Q to quit\n");

        // Ball movement
        ballY++;

        // If ball reaches bottom
        if (ballY == HEIGHT - 1) {
            if (ballX >= basketX - 1 && ballX <= basketX + 1) {
                score++;
            }
            ballX = rand() % WIDTH;
            ballY = 0;
        }

        // Player input
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a' || ch == 'A') basketX--;
            if (ch == 'd' || ch == 'D') basketX++;
            if (ch == 'q' || ch == 'Q') break;
        }

        // Boundaries
        if (basketX < 1) basketX = 1;
        if (basketX > WIDTH - 2) basketX = WIDTH - 2;

        // control falling speed
        Sleep(170);
    }

    printf("\nGame Over! Final Score = %d\n", score);
    return 0;
}


