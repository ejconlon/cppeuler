/*
 * A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 *
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 *
 * Answer:
 * 31875000
 */

#include <iostream>

int main() {
    const int sum = 1000;
    for (int a = 1; a < sum; a++) {
        for (int b = 1; b < sum-a; b++) {
            int c = sum - a - b;
            if (c*c - a*a - b*b == 0) {
                std::cout << a*b*c << std::endl;
                return 0;
            }
        }
    }
    return -1;
}
