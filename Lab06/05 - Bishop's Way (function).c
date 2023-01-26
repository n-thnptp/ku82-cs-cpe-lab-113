/*
หมากรุกสากลเป็นเกมส์ที่เล่นบนกระดานตารางขนาด 8x8 ช่อง โดยตัวนักบวช (Bishop) นั้นสามารถเดินเป็นเฉียงได้สี่ทิศทาง (ซ้ายบน ขวาบน ซ้ายล่าง ขวาล่าง) และระยะการเดินนั้นไม่จำกัด (ยกเว้นสุดขอบกระดาน) ให้นิสิตเขียนฟังก์ชัน bishopMoves() ซึ่งรับตำแหน่งของนักบวชมา แล้วกำหนดตำแหน่งที่นักบวชเดินไปได้ โดยกำหนดให้ช่องซ้ายบนสุดมีตำแหน่งเป็น 0 0 และช่องขวามือล่างสุดมีตำแหน่งเป็น 7 7

จากนั้นให้นิสิตพิมพ์ตารางหมากรุกโดยแสดงตำแหน่งของนักบวชด้วยอักษร B และแสดงตำแหน่งที่นักบวชเดินไปได้ด้วยอักษร X ถ้านักบวชเดินไปยังตำแหน่งนั้นไม่ได้ให้พิมพ์ช่องว่าง (space bar)

ตัวอย่างผลลัพธ์ที่ 1
    Enter Bishop's X Y position: 3 4
      0 1 2 3 4 5 6 7
    ------------------
    0| | | | | | | |X|
    ------------------
    1|X| | | | | |X| |
    ------------------
    2| |X| | | |X| | |
    ------------------
    3| | |X| |X| | | |
    ------------------
    4| | | |B| | | | |
    ------------------
    5| | |X| |X| | | |
    ------------------
    6| |X| | | |X| | |
    ------------------
    7|X| | | | | |X| |
    ------------------
*/

#include <stdio.h>
#define BOARD_SIZE 8

void bishopMoves(int board[][BOARD_SIZE], int xPos, int yPos) {
    board[yPos][xPos] = 'B';
    for(int i = 1; i < BOARD_SIZE; i++){
        // top left
        if ( (yPos-i >= 0 && xPos-i >= 0) && (yPos-i < BOARD_SIZE && xPos-i < BOARD_SIZE) ) {
            board[yPos-i][xPos-i] = 'X';
        }
        // top right
        if ( (yPos-i >= 0 && xPos+i >= 0) && (yPos-i < BOARD_SIZE && xPos+i < BOARD_SIZE) ) {
            board[yPos-i][xPos+i] = 'X';
        }
        // bot left
        if ( (yPos+i >= 0 && xPos-i >= 0) && (yPos+i < BOARD_SIZE && xPos-i < BOARD_SIZE) ) {
            board[yPos+i][xPos-i] = 'X';
        }
        // bot right
        if ( (yPos+i >= 0 && xPos+i >= 0) && (yPos+i < BOARD_SIZE && xPos+i < BOARD_SIZE) ) {
            board[yPos+i][xPos+i] = 'X';
        }
    }
}

int main() {
    int xPos = 0, yPos = 0, board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    int row, b_row = 0, col;

    // creating 2d array
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Enter Bishop's X Y position: ");
    scanf("%d %d", &xPos, &yPos);

    bishopMoves(board, xPos, yPos);

    printf(" ");
    for (int pr_c = 0; pr_c < BOARD_SIZE; pr_c++) {
        printf(" %d", pr_c);
    }
    printf("\n");

    for (row = 0; row < BOARD_SIZE*2; row++) {
        if (row % 2 == 0) {
            printf("------------------");
        } else {
            printf("%d", b_row);
            for (col = 0; col < BOARD_SIZE; col++) {
                printf("|");
                printf("%c", board[b_row][col]);
            }
            printf("|");
            printf(" [%d]", b_row);
            b_row++;
        }
        printf("\n");
    }
    printf("------------------");
}