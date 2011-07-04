/*
 * The sum of the squares of the first ten natural numbers is,
 *
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *
 *
 * Answer:
 * 25164150
 */

#include <iostream>

int main() {

    long sum_of_squares = 0;
    long sum = 0;
    long limit = 100;

    for (long i = 1; i <= limit; i++) {
        sum += i;
        sum_of_squares += i*i;
    }

    long square_of_sum = sum*sum;

    long diff =  square_of_sum - sum_of_squares;

    std::cout << diff << std::endl;

    return 0;
}


