#include <iostream>
#include <math.h>

double bisection(int, double, double, int, float, int);

int main() {

    int eq_num = 0;

    while (eq_num < 1 || eq_num > 5) {
        std::cout << "Please choose one of the following equations: " << std::endl;
        std::cout << "1. x^3 - 8x^2 +12x = 4 " << std::endl;
        std::cout << "2. f(x) = -12 -21x +18x^2 - 2.75x^3 " << std::endl;
        std::cout << "3. f(x) = 6x -4x^2 + 0.5x^3 -2 " << std::endl;
        std::cout << "4. ln(x^4) = 0.7 " << std::endl;
        std::cout << "5. 7 sin(x) = e^x " << std::endl;
        std::cout << "Equation number: ";
        std::cin >> eq_num;
    }
        int stopping_cond=0, num_iterations;
        float percent_error;

    while (stopping_cond < 1 || stopping_cond > 2) {
        std::cout << "Please select the stopping condition: " << std::endl;
        std::cout << "1. Number of iterations" << std::endl;
        std::cout << "2. Relative percentage error" << std::endl;
        std::cout << "Stopping condition: ";
        std::cin >> stopping_cond;
        if (stopping_cond == 1) {
            std::cout << "Please enter the number of iterations: ";
            std::cin >> num_iterations;
        } else
            if (stopping_cond == 2){
            std::cout << "Please enter the percentage: ";
            std::cin >> percent_error;
        }

    }





    switch (eq_num){

        case 1:
        std::cout << "xr: " << bisection(eq_num, 1, 0, num_iterations, 0, stopping_cond) << std::endl;
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 2:
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 3:
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 4:
            // call bisection
            break;
        default:
            ;
            // call bisection

    }
    return 0;
}

double bisection (int equation, double x_upper, double x_lower, int iterations, float percent, int stopping_cond){
    double f_upper, f_lower, xr, fr, error=100;
    double xr_old;

    switch(equation) {
        case 1:
            if (stopping_cond == 1)
                for (int i=0; i < iterations; i++) {
                    f_upper = pow(x_upper, 3) - 8 * pow(x_upper, 2) + 12 * x_upper - 4;
                    f_lower = pow(x_lower, 3) - 8 * pow(x_lower, 2) + 12 * x_lower - 4;
                    if (f_lower * f_upper > 0) {
                        std::cout << "initial upper and lower limits are incorrect" << std::endl;
                        return -1; ///CHANGE?
                    }

                    xr = (x_upper + x_lower) / 2;
                    fr = pow(xr, 3) - 8 * pow(xr, 2) + 12 * xr - 4;

                    if (f_lower*fr < 0)
                        x_upper = xr;
                    else
                        x_lower = xr;

                }
            else
                while (error > percent){
                    f_upper = pow(x_upper, 3) - 8 * pow(x_upper, 2) + 12 * x_upper - 4;
                    f_lower = pow(x_lower, 3) - 8 * pow(x_lower, 2) + 12 * x_lower - 4;
                    if (f_lower * f_upper > 0) {
                        std::cout << "initial upper and lower limits are incorrect" << std::endl; ///Move check to input
                        return -1; ///CHANGE?
                    }

                    xr_old = xr; ///xr is not initialized in first iteration

                    xr = (x_upper + x_lower) / 2;
                    fr = pow(xr, 3) - 8 * pow(xr, 2) + 12 * xr - 4;


                    if (f_lower*fr < 0)
                        x_upper = xr;
                    else
                        x_lower = xr;

                    error = abs((xr - xr_old) / xr);

                }

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        default:;

    }

    return xr;

}