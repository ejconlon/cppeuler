/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 *
 *
 * Answer:
 * 104743
 */

#include <iostream>
#include <vector>
#include <math.h>

void print_vector(std::vector<long>* vec) {
    std::cout << "VECTOR: [ " << std::endl;
    std::vector<long>::const_iterator it;
    for (it = vec->begin(); it != vec->end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << " ] " << std::endl;
}

int main() {
    std::vector<long> primes;

    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);

    int nprimes = 3;
    long limit = 10001;
    long cand = 6;
    for (; nprimes < limit; cand++) {
        bool prime = true;
        long end = sqrt(cand) + 1;
        for (std::vector<long>::const_iterator pi = primes.begin(); pi != primes.end(); pi++) {
            if (cand % *pi == 0)  {
                prime = false;
                break;
            } else if (*pi > end) {
                break;
            }
        }
        if (prime) {
            primes.push_back(cand);
            nprimes++;
        }
    }
    print_vector(&primes);
}
