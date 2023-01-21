#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, k, l, d;
    scanf("%d %d %d %d %d", &m, &n, &k, &l, &d);

    // Create a 2D grid to represent the classroom
    int classroom[m][n];

    // Initialize the 2D array to store the number of students who talk to each other for each cell
    int talk[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            talk[i][j] = 0;
        }
    }

    // Read input and update the 2D array
    for (int i = 0; i < d; i++) {
        int xi, yi, pi, qi;
        scanf("%d %d %d %d", &xi, &yi, &pi, &qi);
        talk[xi][yi]++;
        talk[pi][qi]++;
    }

    // Create a 1D array to store the number of students who talk to each other for each row
    int row_talk[m];
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += talk[i][j];
        }
        row_talk[i] = sum;
    }

    // Create a 1D array to store the number of students who talk to each other for each column
    int col_talk[n];
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += talk[i][j];
        }
        col_talk[j] = sum;
    }

    // Sort the 1D arrays in descending order

    // Select the first K rows and L columns

    // Print the selected rows and columns as the output
    return 0;
}
