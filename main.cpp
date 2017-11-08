#include <iostream>
#include <math.h>

double bisection(int, double, double, int, float, int);

int main() {

    int eq_num = 0;

    while (eq_num < 1 || eq_num > 5) {
        std::cout << "Please choose one of the following equations: " << std::endl;
        std::cout << "1. x^3 - 8x^2 +12x = 4 " << std::endl;
        std::cout << "2. f(x) = -12 -21x +18x^2 - 2.75x^3 " << std::endl; //Multiple solutions
        std::cout << "3. f(x) = 6x -4x^2 + 0.5x^3 -2 " << std::endl; // multiple roots
        std::cout << "4. ln(x^4) = 0.7 " << std::endl;
        std::cout << "5. 7 sin(x) = e^x " << std::endl;
        std::cout << "Equation number: ";
        std::cin >> eq_num;
    }
    int stopping_cond = 0, num_iterations;
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
        } else if (stopping_cond == 2) {
            std::cout << "Please enter the percentage: ";
            std::cin >> percent_error;
        }

    }

    ///DO: add x upper and lower as inputs?


    switch (eq_num) {

        case 1:
            std::cout << "xr: " << bisection(eq_num, 1, 0, num_iterations, percent_error, stopping_cond) << std::endl;
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 2:
            std::cout << "xr: " << bisection(eq_num, 0, -1, num_iterations, percent_error, stopping_cond) << std::endl;
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 3:
            std::cout << "xr: " << bisection(eq_num, 1, 0, num_iterations, percent_error, stopping_cond) << std::endl;
            // call bisection, falsePos, secant, NewtonRaphson
            break;
        case 4:
            std::cout << "xr: " << bisection(eq_num, -1, -2, num_iterations, percent_error, stopping_cond) << std::endl;
            // call bisection
            break;
        default:;
            std::cout << "xr: " << bisection(eq_num, 2, 1, num_iterations, percent_error, stopping_cond) << std::endl;

            // call bisection

    }
    return 0;
}

double bisection(int equation, double x_upper, double x_lower, int iterations, float percent, int stopping_cond) {
    double f_upper, f_lower, xr, fr, error = 100;
    double xr_old;
    int i =0;

    switch (equation) {
        case 1:

            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = pow(x_upper, 3) - 8 * pow(x_upper, 2) + 12 * x_upper - 4;
                f_lower = pow(x_lower, 3) - 8 * pow(x_lower, 2) + 12 * x_lower - 4;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return -1; ///CHANGE?
                }

                if(i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = pow(xr, 3) - 8 * pow(xr, 2) + 12 * xr - 4;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if(i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            break;
        case 2: //"2. f(x) = -12 -21x +18x^2 - 2.75x^3 "

            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                    f_upper = -12 - 21 * x_upper + 18 * pow(x_upper, 2) - 2.75 * pow(x_upper, 3);
                    f_lower = -12 - 21 * x_lower + 18 * pow(x_lower, 2) - 2.75 * pow(x_lower, 3);
                    if (f_lower * f_upper > 0) {
                        std::cout << "initial upper and lower limits are incorrect" << std::endl;
                        return -1; ///CHANGE?
                    }

                    if(i > 0)
                        xr_old = xr;

                    xr = (x_upper + x_lower) / 2;
                    fr = -12 - 21 * xr + 18 * pow(xr, 2) - 2.75 * pow(xr, 3);

                    if (f_lower * fr < 0)
                        x_upper = xr;
                    else
                        x_lower = xr;

                if(i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

                }

            break;
        case 3: //"3. f(x) = 6x -4x^2 + 0.5x^3 -2 "
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = 6*x_upper - 4*pow(x_upper, 2) + 0.5*pow(x_upper, 3) -2;
                f_lower = 6*x_lower - 4*pow(x_lower, 2) + 0.5*pow(x_lower, 3) -2;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return -1; ///CHANGE?
                }

                if(i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = 6*xr - 4*pow(xr, 2) + 0.5*pow(xr, 3) -2;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if(i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }

            break;
        case 4:
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = log(pow(x_upper, 4)) - 0.7;
                f_lower = log(pow(x_lower, 4)) - 0.7;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return -1; ///CHANGE?
                }

                if(i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = log(pow(xr, 4)) - 0.7;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if(i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            break;
        default: //"5. 7 sin(x) = e^x "
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = 7*sin(x_upper) - exp(x_upper);
                f_lower = 7*sin(x_lower) - exp(x_lower);
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return -1; ///CHANGE?
                }

                if(i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = 7*sin(xr) - exp(xr);

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if(i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }



    }

    return xr;

}