
/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 *
 * Answer:
 * 142913828922
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
    long sum = 2;

    const long limit = 2000000;
    long cand = 3;
    while (cand < limit) {
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
            sum += cand;
        }
        cand+=2;
    }
    //print_vector(&primes);
    std::cout << sum << std::endl;
}
