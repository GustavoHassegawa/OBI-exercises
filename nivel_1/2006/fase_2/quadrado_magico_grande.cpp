#include <iostream>
#define N 3

using namespace std;

int** read_matrix() {
    int** matrix = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>matrix[i][j];
        }
    }
    return matrix;     
}

void print_matrix(int** matrix, int line_size, int cols_size) {
    for (int i = 0; i < line_size; i++) {
        for (int j = 0; j < cols_size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int sum_matrix_line(int** matrix, int line, int cols_size) {
    int total = 0;

    for (int j = 0; j < cols_size; j++) {
        total += matrix[line][j];
    }

    return total;
}

int sum_matrix_col(int** matrix, int col, int line_size) {
    int total = 0;

    for (int i = 0; i < line_size; i++) {
        total += matrix[i][col];
    }

    return total;
}

int sum_main_diagonal(int** matrix, int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += matrix[i][i];
    }

    return total;
}

int sum_secondary_diagonal(int** matrix, int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += matrix[i][n-i-1];
    }

    return total;
}

int sum_matrix(int** matrix, int line_size, int cols_size) {
    int total = 0;

    for (int i = 0; i < line_size; i++) {
        for (int j = 0; j < cols_size; j++) {
            total += matrix[i][j];
        }
    }

    return total;
}

bool check_zero_in_line(int** matrix, int line, int cols_size) {
    for (int j = 0; j < cols_size; j++) {
        if (matrix[line][j] == 0) {
            return true;
        }
    }

    return false;
}

bool check_zero_in_col(int** matrix, int col, int line_size) {
    for (int i = 0; i < line_size; i++) {
        if (matrix[i][col] == 0) {
            return true;
        }
    }

    return false;
}

bool check_zero_main_diagonal(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            return true;
        }
    }

    return false;
}

bool check_zero_secondary_diagonal(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][n-1-i] == 0) {
            return true;
        }
    }

    return false;
}

int count_zeros_line(int** matrix, int line, int cols_size) {
    int n_zeros = 0;

    for (int j = 0; j < cols_size; j++) {
        if (matrix[line][j] == 0) {
            n_zeros++;
        }
    }

    return n_zeros;
}

int count_zeros_col(int** matrix, int col, int line_size) {
    int n_zeros = 0;

    for (int i = 0; i < line_size; i++) {
        if (matrix[i][col] == 0) {
            n_zeros++;
        }
    }

    return n_zeros;
}

int main(int argc, char* argv[]) {
    int** matrix;
    int max_sum = 0;

    matrix = read_matrix();

    for(int i = 0; i < N; i++) {
        if (!check_zero_in_line(matrix, i, N)) {
            max_sum = sum_matrix_line(matrix, i, N);
            break;
        }

        if (!check_zero_in_col(matrix, i , N)) {
            max_sum = sum_matrix_col(matrix, i , N);
            break;
        }
    }

    if (max_sum == 0) {
        if (!check_zero_main_diagonal(matrix, N)) {
            max_sum = sum_main_diagonal(matrix, N);
        }

        if (!check_zero_secondary_diagonal(matrix, N)) {
            max_sum = sum_secondary_diagonal(matrix, N);
        }
    }
    
    if (max_sum == 0) {
        max_sum = sum_matrix(matrix, N, N)/2;
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 0 && count_zeros_line(matrix, i, N) == 1) {
                matrix[i][j] = max_sum - sum_matrix_line(matrix, i, N);
            }

            if (matrix[i][j] == 0 && count_zeros_col(matrix, j, N) == 1) {
                matrix[i][j] = max_sum - sum_matrix_col(matrix, j, N);
            }
        }
    }
    
    
    print_matrix(matrix,N,N);

    return 0;
}