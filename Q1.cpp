#include <iostream>
#include "solving_root_methods.h"

void point_of_max_deflection();


int main() {

    int eq_num = 0;

    while (eq_num < 1 || eq_num > 6) {
        std::cout << "Please choose one of the following equations: " << std::endl;
        std::cout << "1. x^3 - 8x^2 +12x = 4 " << std::endl;
        std::cout << "2. f(x) = -12 -21x +18x^2 - 2.75x^3 " << std::endl; //Multiple solutions
        std::cout << "3. f(x) = 6x -4x^2 + 0.5x^3 -2 " << std::endl; // multiple roots
        std::cout << "4. ln(x^4) = 0.7 " << std::endl;
        std::cout << "5. 7 sin(x) = e^x " << std::endl;
        std::cout << "6. [Part2] y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x) [Solving with Bisection method]"
                  << std::endl;
        std::cout << "Equation number: ";
        std::cin >> eq_num;
    }
    int stopping_cond = 0, num_iterations = -1;
    float percent_error = 100.0;

    while (stopping_cond < 1 || stopping_cond > 2) {
        std::cout << "Please select the stopping condition: " << std::endl;
        std::cout << "1. Number of iterations" << std::endl;
        std::cout << "2. Relative percentage error" << std::endl;
        std::cout << "Stopping condition: ";
        std::cin >> stopping_cond;
        if (stopping_cond == 1) {
            std::cout << "Please enter the number of iterations: ";
            std::cin >> num_iterations;
        } else if (stopping_cond == 2) {
            std::cout << "Please enter the percentage: ";
            std::cin >> percent_error;
        }

    }

    switch (eq_num) {

        case 1: //1. x^3 - 8x^2 +12x = 4
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, num_iterations, percent_error, stopping_cond);
            secant(eq_num, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        case 2: //2. f(x) = -12 -21x +18x^2 - 2.75x^3
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, num_iterations, percent_error, stopping_cond);
            secant(eq_num, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        case 3: //3. f(x) = 6x -4x^2 + 0.5x^3 -2
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, num_iterations, percent_error, stopping_cond);
            secant(eq_num, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        case 4: //4. ln(x^4) = 0.7
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, num_iterations, percent_error, stopping_cond);
            secant(eq_num, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        case 5: //5. 7 sin(x) = e^x
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, num_iterations, percent_error, stopping_cond);
            secant(eq_num, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        case 6: //  y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x)
            //  dy/dx = (Wo/120EIL)(-5x^4 + 6*L^2x^2 - L^4) = 0
            bisection(eq_num, num_iterations, percent_error, stopping_cond);
            break;

        default:
            std::cout << "Invalid Eq Number." << std::endl;

    }
    return 0;
}

void point_of_max_deflection() {
    long double a = -5.0 / 2160000, b = 1, c = -1 * 60000;
    long double z1, z2, x1, x2;
    long double discriminant = powl(b, 2) - 4 * a * c;

    // since discriminant > 0
    z1 = (-1 * b + sqrtl(discriminant)) / (2 * a);
    z2 = (-1 * b - sqrtl(discriminant)) / (2 * a);

    std::cout << "~~~~~~ Determining the point of maximum deflection (value of x where dy/dx = 0) ~~~~~~" << std::endl;
    std::cout << "dy/dx = ((-5/2160000)x^4 + x^2 - 60000) = 0" << std::endl;
    std::cout << "Letting Z = X^2 ... " << std::endl;
    std::cout << "(-5/60000)Z^2 + Z - 60000 = 0" << std::endl;
    printf("Therefore possible solutions for z...\n 1. z = %Lf \n 2. z = %Lf \n", z1, z2);
    x1 = sqrtl(fabsl(z1)), x2 = sqrtl(fabsl(z2));
    printf("Possible solutions for X where X = sqrt(Z)...\n 1. x = %Lf \n 2. x = %Lf \n 3. x = %Lf \n 4. x = %Lf \n",
           x1, -1.0 * x1, x2, -1.0 * x2);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}