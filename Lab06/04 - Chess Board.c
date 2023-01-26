/*
------------------
  0 1 2 3 4 5 6 7
0| | | | |k| | | |
1| | | | | | | | |
2| | | | | | | | |
3| | | | | | | | |
4| | | |b| | | | |
5| | | | |B| | | |
6| | | | | | | | |
7| | | | |K| | | |
*/

#include <stdio.h>
#define BOARD_SIZE 8

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos);

int main() {
    int numPieces, yPos = 0, xPos = 0, i, j, board[BOARD_SIZE][BOARD_SIZE];
    char pieceStr = 0;

    // for creating the board array
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    scanf("%d", &numPieces);
    for (i = 0; i < numPieces; i++) {
        scanf("\n%c(%d, %d)", &pieceStr, &xPos, &yPos);
        setPieceOnTable(board, pieceStr, xPos, yPos);
    } // xPos is column, yPos is row

    
    printf("------------------\n");

    for (yPos = 0; yPos <= 8; yPos++) {
        if (yPos == 0) {
            printf(" ");
            for (xPos = 0; xPos < BOARD_SIZE; xPos++) {
                printf(" %d", xPos);
            }
        } else {
            printf("%d", yPos - 1);
            for (xPos = 0; xPos < BOARD_SIZE; xPos++) {
                printf("|");
                printf("%c", board[yPos-1][xPos]);
                // printf("%d", xPos);
            }
            printf("|", yPos);
        }
        printf("\n");
    }
}

void setPieceOnTable(int board[][BOARD_SIZE], char piece, int xPos, int yPos) {
    board[yPos][xPos] = piece;
    // printf("%c (%d, %d)\n", piece, xPos, yPos);
}