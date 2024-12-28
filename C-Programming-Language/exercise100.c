#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

// Function to initialize the board
void createBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print the board
void printBoard(int board[ROWS][COLS]) {
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
}

// Check if the column is valid
bool isValidLocation(int board[ROWS][COLS], int col) {
    return board[ROWS - 1][col] == 0;
}

// Get the next open row in the column
int getNextOpenRow(int board[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == 0) {
            return i;
        }
    }
    return -1;
}

// Drop the piece into the board
void dropPiece(int board[ROWS][COLS], int row, int col, int piece) {
    board[row][col] = piece;
}

// Check for a win condition
bool winningMove(int board[ROWS][COLS], int piece) {
    // Check horizontal locations
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == piece && board[i][j + 1] == piece && board[i][j + 2] == piece && board[i][j + 3] == piece) {
                return true;
            }
        }
    }

    // Check vertical locations
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == piece && board[i + 1][j] == piece && board[i + 2][j] == piece && board[i + 3][j] == piece) {
                return true;
            }
        }
    }

    // Check positively sloped diagonals
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == piece && board[i + 1][j + 1] == piece && board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece) {
                return true;
            }
        }
    }

    // Check negatively sloped diagonals
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == piece && board[i - 1][j + 1] == piece && board[i - 2][j + 2] == piece && board[i - 3][j + 3] == piece) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int board[ROWS][COLS];
    createBoard(board);

    bool gameOver = false;
    int turn = 0;

    printf("Welcome to Connect Four!\n");
    printBoard(board);

    while (!gameOver) {
        int col;
        printf("Player %d, choose a column (1-7): ", turn + 1);
        scanf("%d", &col);
        col--;

        if (col >= 0 && col < COLS && isValidLocation(board, col)) {
            int row = getNextOpenRow(board, col);
            dropPiece(board, row, col, turn + 1);

            printBoard(board);

            if (winningMove(board, turn + 1)) {
                printf("Player %d wins!\n", turn + 1);
                gameOver = true;
            }

            turn = (turn + 1) % 2;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
