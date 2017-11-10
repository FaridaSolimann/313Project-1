#ifndef INC_313PROJECT_1_SOLVING_ROOT_METHODS_H
#define INC_313PROJECT_1_SOLVING_ROOT_METHODS_H

#include <iostream>
#include <math.h>

//TODO: use long double instead of double! (bug occurs at 0.00000%)

void false_position(int EQ_i, double x_l, double x_u, int iters, double percent, int stopping_condition);

void secant(int EQ_i, double x_i_0, double x_i_1, int iters, double percent, int stopping_condition);

void newton_raphson(int EQ_i, double x_i_1, int iters, double percent, int stopping_condition);

void false_position(int EQ_i, double x_l, double x_u, int iters, double percent, int stopping_condition) {
    int i = 0;
    double func_xl, func_xu, func_xr, xr = 0.0, xr_old = 0.0;
    long double root_error = 100.0;

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

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

void secant(int EQ_i, double x_i_0, double x_i_1, int iters, double percent, int stopping_condition) {
    int i = 0;
    double func_xi0, func_xi1, x_i_2 = 0.0;
    long double root_error = 100.0;

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

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

void newton_raphson(int EQ_i, double x_i_1, int iters, double percent, int stopping_condition) {
    int i = 0;
    double func_xi1, dx_func_xi1, x_i_2 = 0.0;
    long double root_error = 100.0;

    switch (EQ_i) {
        case 1:
            // f(x) = X^3 - 8X^2 + 12X - 4
            // f'(x) = 3X^2 - 16X + 12
            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = pow(x_i_1, 3) - 8 * pow(x_i_1, 2) + 12 * x_i_1 - 4;
                dx_func_xi1 = 3 * pow(x_i_1, 2) - 16 * x_i_1 + 12;
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
//            std::cout<< x_i_2 << " || " << x_i_1 <<std::endl;       //for debugging.
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
//            std::cout<< x_i_2 << " || " << x_i_1 <<std::endl;       //for debugging.
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
//            std::cout<< x_i_2 << " || " << x_i_1 <<std::endl;       //for debugging.
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);
            break;

        case 6:
            //y = (Wo/120EIL)(-x^5 + 2L^2x^3 - L^4x)
            //dy/dx = (2.5/120*50000*30000*100)(-x^5 + 2*100^2x^3 - 100^4x)
            int L = 100, E = 50000, I = 30000;
            double w0 = 2.5;

            while ((i < iters and stopping_condition == 1) or (root_error > percent and stopping_condition == 2)) {
                func_xi1 = 0;
                dx_func_xi1 = 0;
                //Newton-Raphson equation.
                x_i_2 = x_i_1 - (func_xi1 / dx_func_xi1);

                root_error = fabs(((x_i_2 - x_i_1) / x_i_2) * 100);

                x_i_1 = x_i_2;
                i++;
            }
//            std::cout<< x_i_2 << " || " << x_i_1 <<std::endl;       //for debugging.
            printf("[Newton-Raphson] Method -> Xi2: %f | iterations: %d | relative error: %Lf%% \n", x_i_2, i,
                   root_error);

        default:
            std::cout << "Default" << std::endl;
            break;
    }
}

#endif //INC_313PROJECT_1_SOLVING_ROOT_METHODS_H
