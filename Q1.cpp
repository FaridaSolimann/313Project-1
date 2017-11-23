#include <iostream>
#include "solving_root_methods.h"

int main() {

    int eq_num = 0;

    while (eq_num < 1 || eq_num > 5) {
        std::cout << "Please choose one of the following equations: " << std::endl;
        std::cout << "1. x^3 - 8x^2 +12x = 4 " << std::endl;
        std::cout << "2. f(x) = -12 -21x +18x^2 - 2.75x^3 " << std::endl; //Multiple solutions
        std::cout << "3. f(x) = 6x -4x^2 + 0.5x^3 -2 " << std::endl; // multiple roots
        std::cout << "4. ln(x^4) = 0.7 " << std::endl;
        std::cout << "5. 7 sin(x) = e^x " << std::endl;
        std::cout << "6. [Part2] y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x) [Solving with Newton-Raphson]" << std::endl;
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

    //TODO: add x upper and lower as inputs?
    // That would be cute!

    switch (eq_num) {

        case 1: //1. x^3 - 8x^2 +12x = 4
            bisection(eq_num, 1, 0, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, 0, 1, num_iterations, percent_error, stopping_cond);
            secant(eq_num, 0, 1, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, 0, num_iterations, percent_error, stopping_cond);
            break;

        case 2: //2. f(x) = -12 -21x +18x^2 - 2.75x^3
            bisection(eq_num, 0, -1, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, -1, 0, num_iterations, percent_error, stopping_cond);
            secant(eq_num, -1, 0, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, -1, num_iterations, percent_error, stopping_cond);
            break;

        case 3: //3. f(x) = 6x -4x^2 + 0.5x^3 -2
            bisection(eq_num, 1, 0, num_iterations, percent_error, stopping_cond);
            false_position(eq_num, 0, 1, num_iterations, percent_error, stopping_cond);
            secant(eq_num, 0, 1, num_iterations, percent_error, stopping_cond);
            newton_raphson(eq_num, 0, num_iterations, percent_error, stopping_cond);
            break;

        case 4: //4. ln(x^4) = 0.7
            bisection(eq_num, -1, -2, num_iterations, percent_error, stopping_cond);
            // call bisection
            break;

        case 5: //5. 7 sin(x) = e^x
            bisection(eq_num, 2, 1, num_iterations, percent_error, stopping_cond);
            break;

        case 6: //y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x)
            newton_raphson(eq_num, 0, num_iterations, percent_error, stopping_cond);
            break;

        default:
            std::cout << "Invalid Eq Number." << std::endl;

    }
    return 0;
}

