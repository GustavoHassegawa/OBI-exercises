#include <iostream>
#define N 3

using namespace std;

int main(int argc, char* argv[]) {
    int matrix[N][N], i, j , max_sum = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        if ((matrix[i][0] != 0) && (matrix[i][1] != 0) && (matrix[i][2] != 0)) {
            max_sum = matrix[i][0] + matrix[i][1] + matrix[i][2];
            break;
        }

        if ((matrix[0][i] != 0) && (matrix[1][i] != 0) && (matrix[2][i] != 0)) {
            max_sum = matrix[0][i] + matrix[1][i] + matrix[2][i];
            break;
        }
    }

    if (max_sum == 0) {
        if ((matrix[0][0] != 0) && (matrix[1][1] != 0) && (matrix[2][2] != 0)){
            max_sum = matrix[0][0] + matrix[1][1] + matrix[2][2];
        }

        if ((matrix[2][0] != 0) && (matrix[1][1] != 0) && (matrix[0][2] != 0)){
            max_sum = matrix[2][0] + matrix[1][1] + matrix[0][2];
        }
    }
    
    if (max_sum == 0) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                max_sum += matrix[i][j];
            }
        }
        max_sum /= 2;
    }


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matrix[i][j] == 0 && ((matrix[i][0] == 0)+(matrix[i][1] == 0)+(matrix[i][2] == 0)) == 1) {
                matrix[i][j] = max_sum - matrix[i][0] -matrix[i][1] - matrix[i][2];
            }

            if (matrix[i][j] == 0 && ((matrix[0][j] == 0)+(matrix[1][j] == 0)+(matrix[2][j] == 0)) == 1) {
                matrix[i][j] = max_sum - matrix[0][j] -matrix[1][j] - matrix[2][j];
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}