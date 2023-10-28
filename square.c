#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void printMagicSquare(int square[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isMagicSquare(int square[SIZE][SIZE]) {
    int targetSum = 15; // target sum for each row/column/diagonal

    // Check the sum of all rows
    // if one row != 15, then immediately return 0 , cannot be a magic square
    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];     // row = i, column = j  (j changes)
        }
        if (rowSum != targetSum) {
            return 0; // not a magic square
        }
    }   // all rows must = 15 to pass 

    // Check the sum of all columns
    for (int i = 0; i < SIZE; i++) {
        int colSum = 0;
        for (int j = 0; j < SIZE; j++) {
            colSum += square[j][i];     // column = j, row = i  (j changes)
        }
        if (colSum != targetSum) {
            return 0; // Not a magic square
        }
    }   // all columns must = 15 to pass

    // Check the sum of the two diagonals
    int diagonal1Sum = 0;
    int diagonal2Sum = 0;
    for (int i = 0; i < SIZE; i++) {
        diagonal1Sum += square[i][i];       // sum of top left to bottom right diagonal
        diagonal2Sum += square[i][SIZE - 1 - i];        // sum of top right to bottom left diagonal
    }

    return (diagonal1Sum == targetSum && diagonal2Sum == targetSum);        //return 0 if diagonals != 15 and 1 if they do
}

int main(void) {
    srand(time(NULL));
    int count = 0;

    while (1) {
        int square[SIZE][SIZE] = {0}; // Initialize a new square

        // Generate a random square with the numbers 1-9
        for (int i = 1; i <= SIZE * SIZE; i++) {
            int row, col;       // declare index variables
            do {
                row = rand() % SIZE;        // pick row index
                col = rand() % SIZE;        // pick column index
            } while (square[row][col] != 0);    // choose an empty cell to hold the value i
            square[row][col] = i;
        }

        count++;

        // Check if it's a Lo Shu Magic Square
        if (isMagicSquare(square)) {
            printf("Total squares generated and tested: %d\n", count);
            printf("Magic Square:\n");
            printMagicSquare(square);
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;        // should never reach this point if code works
}
