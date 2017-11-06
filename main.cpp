#include <iostream>

int main() {

    int input_eq = 0;

    while (input_eq < 1 || input_eq > 5) {
        std::cout << "Please choose one of the following equations: " << std::endl;
        std::cout << "1. x^3 - 8x^2 +12x = 4 " << std::endl;
        std::cout << "2. f(x) = -12 -21x +18x^2 - 2.75x^3 " << std::endl;
        std::cout << "3. f(x) = 6x -4x^2 + 0.5x^3 -2 " << std::endl;
        std::cout << "4. ln(x^4) = 0.7 " << std::endl;
        std::cout << "5. 7 sin(x) = e^x " << std::endl;

        std::cin >> input_eq;
    }


    switch (input_eq){

        case 1:
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
            // call bisection

    }
    return 0;
}