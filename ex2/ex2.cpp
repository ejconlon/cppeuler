
/*
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 *
 *
 * Answer:
 * 4613732
 */

#include <iostream>
#include "fib.h"

#define LIMIT 4000000

int main() {
    int s = 0;

    for (int i = 0; i < LIMIT; i++) {
        int f = fib(i);
        if (f >= LIMIT) {
            break;
        } else if (f % 2 == 0) {
            s += f;
        }

    }

    std::cout << "s = " << s << std::endl;
    
    return 0;
}
