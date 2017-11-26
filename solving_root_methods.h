#ifndef INC_313PROJECT_1_SOLVING_ROOT_METHODS_H
#define INC_313PROJECT_1_SOLVING_ROOT_METHODS_H

#include <iostream>
#include <math.h>


void bisection(int EQ_i, int iters, float percent, int stopping_cond);

void false_position(int EQ_i, int iters, double percent, int stopping_condition);

void secant(int EQ_i, int iters, double percent, int stopping_condition);

void newton_raphson(int EQ_i, int iters, double percent, int stopping_condition);

void bisection(int equation, int iterations, float percent, int stopping_cond) {

    double f_upper, f_lower, xr, fr;
    double x_upper, x_lower;
    long double error = 100;
    double xr_old;
    int i = 0;
    long double _6_func_xl, _6_func_xu, _6_func_xr, _6_xr = 0.0, _6_xr_old = 0.0, _6_xu, _6_xl;
    double long y;
    std::cout << "Enter X lower value: ";
    std::cin >> x_lower;
    std::cout << "Enter X upper value: ";
    std::cin >> x_upper;

    switch (equation) {
        case 1:

            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = pow(x_upper, 3) - 8 * pow(x_upper, 2) + 12 * x_upper - 4;
                f_lower = pow(x_lower, 3) - 8 * pow(x_lower, 2) + 12 * x_lower - 4;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = pow(xr, 3) - 8 * pow(xr, 2) + 12 * xr - 4;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if (i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            printf("[Bisection] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   error);
            break;
        case 2: //"2. f(x) = -12 -21x +18x^2 - 2.75x^3 "

            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = -12 - 21 * x_upper + 18 * pow(x_upper, 2) - 2.75 * pow(x_upper, 3);
                f_lower = -12 - 21 * x_lower + 18 * pow(x_lower, 2) - 2.75 * pow(x_lower, 3);
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = -12 - 21 * xr + 18 * pow(xr, 2) - 2.75 * pow(xr, 3);

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if (i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            printf("[Bisection] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   error);
            break;
        case 3: //"3. f(x) = 6x -4x^2 + 0.5x^3 -2 "
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = 6 * x_upper - 4 * pow(x_upper, 2) + 0.5 * pow(x_upper, 3) - 2;
                f_lower = 6 * x_lower - 4 * pow(x_lower, 2) + 0.5 * pow(x_lower, 3) - 2;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = 6 * xr - 4 * pow(xr, 2) + 0.5 * pow(xr, 3) - 2;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if (i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            printf("[Bisection] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   error);
            break;
        case 4:
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = log(pow(x_upper, 4)) - 0.7;
                f_lower = log(pow(x_lower, 4)) - 0.7;
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = log(pow(xr, 4)) - 0.7;

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if (i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;

            }
            printf("[Bisection] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   error);
            break;

        case 6:
            //dy/dx = (-5/216000x^4 + x^2 - 60000)
            _6_xu = x_upper;
            _6_xl = x_lower;
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                _6_func_xl = (-5.0 / 2160000) * powl(_6_xl, 4) + powl(_6_xl, 2) - (60000);
                _6_func_xu = (-5.0 / 2160000) * powl(_6_xu, 4) + powl(_6_xu, 2) - (60000);

                if (_6_func_xl * _6_func_xu > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    _6_xr_old = _6_xr;

                _6_xr = (_6_xu + _6_xl) / 2.0;
                _6_func_xr = (-5.0 / 2160000) * powl(_6_xr, 4) + powl(_6_xr, 2) - (60000);

                if (_6_func_xl * _6_func_xr < 0.0)
                    _6_xu = _6_xr;
                else
                    _6_xl = _6_xr;

                if (i > 0)
                    error = fabsl((_6_xr - _6_xr_old) / _6_xr) * 100.0;
                i++;

            }
            //  y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x)
            y = ((2.5) / (50000 * 30000 * 600 * 120) *
                 ((-1.0 / 720000) * powl(_6_xr, 5) + powl(_6_xr, 3) - 180000 * _6_xr));
            printf("[Bisection] Method -> Xr: %Lf | maximum deflection (y): %Lf | iterations: %d | relative error: %Lf%% \n",
                   _6_xr, y, i,
                   error);
            break;

        default: //"5. 7 sin(x) = e^x "
            while ((stopping_cond == 1 && i < iterations) || (stopping_cond == 2 && error > percent)) {
                f_upper = 7 * sin(x_upper) - exp(x_upper);
                f_lower = 7 * sin(x_lower) - exp(x_lower);
                if (f_lower * f_upper > 0) {
                    std::cout << "initial upper and lower limits are incorrect" << std::endl;
                    return; ///CHANGE?
                }

                if (i > 0)
                    xr_old = xr;

                xr = (x_upper + x_lower) / 2;
                fr = 7 * sin(xr) - exp(xr);

                if (f_lower * fr < 0)
                    x_upper = xr;
                else
                    x_lower = xr;

                if (i > 0)
                    error = fabs((xr - xr_old) / xr) * 100;
                i++;
            }
            printf("[Bisection] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   error);
            break;
    }

}

void false_position(int EQ_i, int iters, double percent, int stopping_condition) {

    int i = 0;
    double x_l, x_u;
    double func_xl, func_xu, func_xr, xr = 0.0, xr_old = 0.0;
    long double root_error = 100.0;
    std::cout << "Enter X lower value: ";
    std::cin >> x_l;
    std::cout << "Enter X upper value: ";
    std::cin >> x_u;

    switch (EQ_i) {
        case 1:
            //f(x) = X^3 - 8X^2 + 12X - 4
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                //False-Position equation.
                func_xl = pow(x_l, 3) - 8 * pow(x_l, 2) + 12 * x_l - 4;
                func_xu = pow(x_u, 3) - 8 * pow(x_u, 2) + 12 * x_u - 4;
                xr = x_u - ((func_xu * (x_l - x_u))) / (func_xl - func_xu);
                func_xr = pow(xr, 3) - 8 * pow(xr, 2) + 12 * xr - 4;

                // Check region where root lies. f(xl)f(xr) < 0 then xu = xr
                func_xl * func_xr < 0.0 ? x_u = xr : x_l = xr;

                if (i > 0)
                    root_error = fabs(((xr - xr_old) / xr) * 100);

                xr_old = xr;
                i++;
            }
            printf("[False Position] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   root_error);
            break;

        case 2:
            //f(x) = -12 -21x +18x^2 - 2.75x^3
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                //False-Position equation.
                func_xl = -12 - 21 * x_l + 18 * pow(x_l, 2) - 2.75 * pow(x_l, 3);
                func_xu = -12 - 21 * x_u + 18 * pow(x_u, 2) - 2.75 * pow(x_u, 3);
                xr = x_u - ((func_xu * (x_l - x_u))) / (func_xl - func_xu);
                func_xr = -12 - 21 * xr + 18 * pow(xr, 2) - 2.75 * pow(xr, 3);

                // Check region where root lies. f(xl)f(xr) < 0 then xu = xr
                func_xl * func_xr < 0.0 ? x_u = xr : x_l = xr;

                if (i > 0)
                    root_error = fabs(((xr - xr_old) / xr) * 100);

                xr_old = xr;
                i++;
            }
            printf("[False Position] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   root_error);
            break;

        case 3:
            //f(x) = 6x -4x^2 + 0.5x^3 -2
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                //False-Position equation.
                func_xl = 6 * x_l - 4 * pow(x_l, 2) + 0.5 * pow(x_l, 3) - 2;
                func_xu = 6 * x_u - 4 * pow(x_u, 2) + 0.5 * pow(x_u, 3) - 2;
                xr = x_u - ((func_xu * (x_l - x_u))) / (func_xl - func_xu);
                func_xr = 6 * xr - 4 * pow(xr, 2) + 0.5 * pow(xr, 3) - 2;

                // Check region where root lies. f(xl)f(xr) < 0 then xu = xr
                func_xl * func_xr < 0.0 ? x_u = xr : x_l = xr;

                if (i > 0)
                    root_error = fabs(((xr - xr_old) / xr) * 100);

                xr_old = xr;
                i++;
            }
            printf("[False Position] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   root_error);
            break;

        case 4:
            //ln(x^4) = 0.7
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                //False-Position equation.
                func_xl = log(pow(x_l, 4)) - 0.7;
                func_xu = log(pow(x_u, 4)) - 0.7;
                xr = x_u - ((func_xu * (x_l - x_u))) / (func_xl - func_xu);
                func_xr = log(pow(xr, 4)) - 0.7;

                // Check region where root lies. f(xl)f(xr) < 0 then xu = xr
                func_xl * func_xr < 0.0 ? x_u = xr : x_l = xr;

                if (i > 0)
                    root_error = fabs(((xr - xr_old) / xr) * 100);

                xr_old = xr;
                i++;
            }
            printf("[False Position] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   root_error);
            break;

        case 5:
            //7sin(x) = e^x
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                //False-Position equation.
                func_xl = 7 * sin(x_l) - exp(x_l);
                func_xu = 7 * sin(x_u) - exp(x_u);
                xr = x_u - ((func_xu * (x_l - x_u))) / (func_xl - func_xu);
                func_xr = 7 * sin(xr) - exp(xr);

                // Check region where root lies. f(xl)f(xr) < 0 then xu = xr
                func_xl * func_xr < 0.0 ? x_u = xr : x_l = xr;

                if (i > 0)
                    root_error = fabs(((xr - xr_old) / xr) * 100);

                xr_old = xr;
                i++;
            }
            printf("[False Position] Method -> Xr: %f | iterations: %d | relative error: %Lf%% \n", xr, i,
                   root_error);
            break;

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

void secant(int EQ_i, int iters, double percent, int stopping_condition) {
    int i = 0;
    double x_i_0, x_i_1;
    double func_xi0, func_xi1, x_i_2 = 0.0;
    long double root_error = 100.0;
    std::cout << "Enter first initial guess (Xo): ";
    std::cin >> x_i_0;
    std::cout << "Enter second initial guess (x1): ";
    std::cin >> x_i_1;

    switch (EQ_i) {
        case 1:
            //f(x) = X^3 - 8X^2 + 12X - 4
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi0 = pow(x_i_0, 3) - 8 * pow(x_i_0, 2) + 12 * x_i_0 - 4;
                func_xi1 = pow(x_i_1, 3) - 8 * pow(x_i_1, 2) + 12 * x_i_1 - 4;
                //Secant equation.
                x_i_2 = x_i_1 - ((func_xi1 * (x_i_0 - x_i_1))) / (func_xi0 - func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_0 = x_i_1;
                x_i_1 = x_i_2;
                i++;
            }
            printf("[Secant] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i, root_error);
            break;

        case 2:
            //f(x) = -12 -21x +18x^2 - 2.75x^3
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {

                func_xi0 = -12 - 21 * x_i_0 + 18 * pow(x_i_0, 2) - 2.75 * pow(x_i_0, 3);
                func_xi1 = -12 - 21 * x_i_1 + 18 * pow(x_i_1, 2) - 2.75 * pow(x_i_1, 3);
                //Secant equation.
                x_i_2 = x_i_1 - ((func_xi1 * (x_i_0 - x_i_1))) / (func_xi0 - func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_0 = x_i_1;
                x_i_1 = x_i_2;
                i++;
            }
            printf("[Secant] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i, root_error);
            break;

        case 3:
            //f(x) = 6x -4x^2 + 0.5x^3 -2
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi0 = 6 * x_i_0 - 4 * pow(x_i_0, 2) + 0.5 * pow(x_i_0, 3) - 2;
                func_xi1 = 6 * x_i_1 - 4 * pow(x_i_1, 2) + 0.5 * pow(x_i_1, 3) - 2;
                //Secant equation.
                x_i_2 = x_i_1 - ((func_xi1 * (x_i_0 - x_i_1))) / (func_xi0 - func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_0 = x_i_1;
                x_i_1 = x_i_2;
                i++;
            }
            printf("[Secant] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i, root_error);
            break;

        case 4:
            //ln(x^4) = 0.7
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi0 = log(pow(x_i_0, 4)) - 0.7;
                func_xi1 = log(pow(x_i_1, 4)) - 0.7;
                //Secant equation.
                x_i_2 = x_i_1 - ((func_xi1 * (x_i_0 - x_i_1))) / (func_xi0 - func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_0 = x_i_1;
                x_i_1 = x_i_2;
                i++;
            }
            printf("[Secant] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i, root_error);
            break;

        case 5:
            //7sin(x) = e^x
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi0 = 7 * sin(x_i_0) - exp(x_i_0);
                func_xi1 = 7 * sin(x_i_1) - exp(x_i_1);
                //Secant equation.
                x_i_2 = x_i_1 - ((func_xi1 * (x_i_0 - x_i_1))) / (func_xi0 - func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_0 = x_i_1;
                x_i_1 = x_i_2;
                i++;
            }
            printf("[Secant] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i, root_error);
            break;

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

void newton_raphson(int EQ_i, int iters, double percent, int stopping_condition) {
    int i = 0;
    double x_i_1;
    double func_xi1, dx_func_xi1, x_i_2 = 0.0;
    long double root_error = 100.0;
    std::cout << "Enter initial guess: ";
    std::cin >> x_i_1;

    switch (EQ_i) {
        case 1:
            // f(x) = X^3 - 8X^2 + 12X - 4
            // f'(x) = 3X^2 - 16X + 12
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = (pow(x_i_1, 3)) - (8 * pow(x_i_1, 2)) + (12 * x_i_1) - 4;
                dx_func_xi1 = (3 * pow(x_i_1, 2)) - (16 * x_i_1) + 12;
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        case 2:
            // f(x) = -12 -21x +18x^2 - 2.75x^3
            // f'(x) = -21 + 36x - 8.25x^2
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {

                func_xi1 = -12 - 21 * x_i_1 + 18 * pow(x_i_1, 2) - 2.75 * pow(x_i_1, 3);
                dx_func_xi1 = -21 + 36 * x_i_1 - 8.25 * pow(x_i_1, 2);
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        case 3:
            // f(x) = 6x -4x^2 + 0.5x^3 -2
            // f'(x) = 6 - 8x + 1.5x^2
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = 6 * x_i_1 - 4 * pow(x_i_1, 2) + 0.5 * pow(x_i_1, 3) - 2;
                dx_func_xi1 = 6 - 8 * x_i_1 + 1.5 * pow(x_i_1, 2);
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        case 4:
            // f(x) = ln(x^4) - 0.7
            // f'(x) = 4/x;
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = log(pow(x_i_1, 4)) - 0.7;
                dx_func_xi1 = 4.0 / x_i_1;
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        case 5:
            // f(x) = 7sin(x) - e^x
            // f'(x) = 7cos(x) - e^x
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = 7 * sin(x_i_1) - exp(x_i_1);
                dx_func_xi1 = 7 * cos(x_i_1) - exp(x_i_1);
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

#endif //INC_313PROJECT_1_SOLVING_ROOT_METHODS_H
