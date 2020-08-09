#include <iostream>

using namespace std;

int counter = 0;

/**
 * The sudoku puzzle we are trying to solve.
 */
int matrix[9][9] = {
    // clang-format off    
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},
    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},
    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9},
}; // clang-format on

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
    // Check subgrid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[y0 * 3 + i][x0 * 3 + j] == n) {
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
            if (j % 3 == 2) {
                cout << "| ";
            }
        }
        cout << endl;
        if (i % 3 == 2) {
            cout << "-----------------------" << endl;
        }
    }
    cout << endl;
}

void solve() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0) {              
                for (int n = 1; n <= 9; n++) {
                    if (isValid(i, j, n)) {
                        matrix[i][j] = n;
                        solve();
                        matrix[i][j] = 0;
                    }
                }
                return;
            }
        }
    }

    cout << "Final" << endl;
    printMatrix();
    exit(0);
}

int main() {
    cout << "Initial puzzle" << endl;
    printMatrix();
    solve();
    return 0;
}