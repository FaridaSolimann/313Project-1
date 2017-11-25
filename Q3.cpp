#include <iostream>

void jacobi_method();

void gauss_jordan_method();

int main() {
    int choice;

    std::cout << "Which method you want to solve this equation? " << std::endl;
    std::cout << " 10x1 + 2x2 - x3 = 27" << std::endl;
    std::cout << " -3x1 - 6x2 + 2x3 = -61.5" << std::endl;
    std::cout << " x1 + x2 + 5x3 = -21.5" << std::endl;
    std::cout << "1 -> Gauss Jordan's Elimination Method" << std::endl;
    std::cout << "2 -> Jacobi Method" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            gauss_jordan_method();
            break;

        case 2:
            jacobi_method();
            break;

        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }

    return 0;
}

void gauss_jordan_method() {
    const int N = 3, M = 4;
    int p = 0;
    // A is 3x4 Augmented matrix
    double A[N][M] = {{10, 2,  -1, 27},
                      {-3, -6, 2,  -61.5},
                      {1,  1,  5,  -21.5}};
    //no need for partial pivoting in this equation.

    // Reducing Top-Bottom
    for (int j = 0; j < M - 2; j++) {
        p = 0;
        for (int i = j; i < N - 1; i++) {
            int sign = 1;
            // make A[i][j] the pivot.
            double a = A[i + 1][j] / A[i - p][j];
            if ((a + A[i + 1][j]) > 0 || (a + A[i + 1][j]) < 0)
                sign = -1;
            for (int k = 0; k < M; k++)
                A[i + 1][k] += ((A[i - p][k]) * a * sign);

            p++;
        }
    }

    // Reducing Bottom-Top
    for (int j = M - 2; j > 0; j--) {
        p = 0;
        for (int i = j; i > 0; i--) {
            int sign = 1;
            //make A[i][j] the pivot.
            double a = A[i - 1][j] / A[i + p][j];
            if ((a + A[i - 1][j] > 0) || (a + A[i - 1][j] < 0))
                sign = -1;
            for (int k = 0; k < M; k++)
                A[i - 1][k] += ((A[i + p][k]) * a * sign);
            p++;
        }
    }

// Show matrix after Gauss-Jordan Elimination.
    std::cout << "\nShowing the Augmented Matrix after Gauss-Jordan Elimination" <<
              std::endl;
    for (int i = 0; i < N; i++) {
        printf(" | ");
        for (
                int j = 0;
                j < M;
                j++)
            printf(" %f ", A[i][j]);
        printf(" | ");
        printf("\n\n");
    }

    printf("X1 = %f \n", A[0][3] / A[0][0]);
    printf("X2 = %f \n", A[1][3] / A[1][1]);
    printf("X3 = %f \n", A[2][3] / A[2][2]);

    return;
}

void jacobi_method() {
    double a11 = 10, a12 = 2, a13 = -1,
            a21 = -3, a22 = -6, a23 = 2,
            a31 = 1, a32 = 1, a33 = 5;
    double b1 = 27, b2 = -61.5, b3 = -21.5;

    double x1_old, x2_old, x3_old, x1_new, x2_new, x3_new, e1, e2, e3;
    e1 = e2 = e3 = 100;

    std::cout << "Please enter the initial guesses: " << std::endl;
    std::cout << "x1: ";
    std::cin >> x1_old;
    std::cout << "x2: ";
    std::cin >> x2_old;
    std::cout << "x3: ";
    std::cin >> x3_old;

    while (e1 > 0.01 || e2 > 0.01 || e3 > 0.01) {
        x1_new = (b1 - a12 * x2_old - a13 * x3_old) / a11;
        x2_new = (b2 - a21 * x1_old - a23 * x3_old) / a22;
        x3_new = (b3 - a31 * x1_old - a32 * x2_old) / a33;

        e1 = ((x1_new - x1_old) / x1_new) * 100;
        e2 = ((x2_new - x2_old) / x2_new) * 100;
        e3 = ((x3_new - x3_old) / x3_new) * 100;

        x1_old = x1_new;
        x2_old = x2_new;
        x3_old = x3_new;
    }

    std::cout << "x1: " << x1_old << std::endl;
    std::cout << "x2: " << x2_old << std::endl;
    std::cout << "x3: " << x3_old << std::endl;

    return;
}
