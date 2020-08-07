#include <iostream>

using namespace std;

/**
 * The sudoku puzzle we are trying to solve.
 */
int matrix[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
};

/**
 * The size of the sudoku puzzle.
 */
int size = sizeof matrix / sizeof matrix[0];

/**
 * Checks if n is valid at position y, x
 */
bool isValid(int y, int x, int n) {
    // Check Column
    for (int i = 0; i < size; i++) {
        if (matrix[i][x] == n) {
            return false;
        }
    }

    // Check Row
    for (int i = 0; i < size; i++) {
        if (matrix[y][i] == n) {
            return false;
        }
    }

    // The top left corner coordinates of the subgrid
    int y0 = y / 3;
    int x0 = x / 3;
    //Check subgrid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[y0 + i][x0 + j] == n) {
                return false;
            }
        }
    }

    return true;
}

void printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void testValid(int y, int x, int n) {
    cout << n << " at (" << y << "," << x << ")" << endl;
    printMatrix();
    cout << isValid(y, x, n) << endl;
}

int main() {
    testValid(0,0, 1);
    return 0;
}