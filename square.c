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
    int sum = 0;
    int targetSum = 15; // The sum for Lo Shu Magic Square

    // Calculate the sum of the first row for comparison
    for (int j = 0; j < SIZE; j++) {
        sum += square[0][j];
    }

    // Check the sum of all rows
    for (int i = 1; i < SIZE; i++) {
        int rowSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];
        }
        if (rowSum != targetSum) {
            return 0; // Not a magic square
        }
    }

    // Check the sum of all columns
    for (int j = 0; j < SIZE; j++) {
        int colSum = 0;
        for (int i = 0; i < SIZE; i++) {
            colSum += square[i][j];
        }
        if (colSum != targetSum) {
            return 0; // Not a magic square
        }
    }

    // Check the sum of the two diagonals
    int diag1Sum = 0;
    int diag2Sum = 0;
    for (int i = 0; i < SIZE; i++) {
        diag1Sum += square[i][i];
        diag2Sum += square[i][SIZE - 1 - i];
    }

    return (diag1Sum == targetSum && diag2Sum == targetSum && sum == targetSum);
}

int main() {
    srand(time(NULL));
    int count = 0;

    while (1) {
        int square[SIZE][SIZE] = {0}; // Initialize a new square
        int numbers[SIZE * SIZE] = {0}; // Initialize a new numbers array

        // Generate a valid Lo Shu Magic Square
        for (int i = 1; i <= SIZE * SIZE; i++) {
            int row, col;
            do {
                row = rand() % SIZE;
                col = rand() % SIZE;
            } while (square[row][col] != 0);
            square[row][col] = i;
        }

        count++;
        printf("Generated Square %d:\n", count);
        printMagicSquare(square);

        // Check if it's a Lo Shu Magic Square
        if (isMagicSquare(square)) {
            printf("Total squares generated and tested: %d\n", count);
            printf("Magic Square:\n");
            printMagicSquare(square);
            break;
        }
    }

    return 0;
}
