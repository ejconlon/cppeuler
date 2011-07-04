
/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 *
 * Answer:
 * 6857
 */

#include <iostream>
#include <vector>
#include <math.h>

inline bool divides(long x, long y) {
    return y % x == 0;
}

void print_vector(std::vector<long>* vec) {
    std::vector<long>::const_iterator it;
    for (it = vec->begin(); it != vec->end(); it++) {
        std::cout << *it << std::endl;
    }
}

class RangeIterator {
    long cur;
    public: 
        RangeIterator(long curArg):
            cur(curArg) {
            //std::cout << "Constructing RangeIterator" << std::endl;
        }
        /*~RangeIterator() {
            std::cout << "Destructing RangeIterator " << cur << std::endl;
        }*/
        bool operator==(const RangeIterator& other) {
            return other.cur == this->cur;
        }
        bool operator!=(const RangeIterator& other) {
            return !(operator==(other));
        }
        long operator*() {
            return this->cur;
        }
        RangeIterator operator++(int postfixMarkerUnused) {
            cur++;
            return *this;
        }
};

class Range {
        const long min;
        const long max;
    public:
        Range(long minArg, long maxArg):
            min(minArg), 
            max(maxArg) {
            //std::cout << "Constructing Range" << std::endl;
        }   
        /*~Range() {
            std::cout << "Destructing Range" << std::endl;
        }*/
        RangeIterator begin() const {
            return RangeIterator(min);
        }
        RangeIterator end() const {
            return RangeIterator(max);
        }
};


int main() {
    /*
    std::vector<long> primes;

    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);


    Range r(2, 100);
    for (RangeIterator ri = r.begin(); ri != r.end(); ri++) {
        //std::cout << *ri << std::endl;
        bool prime = true;
        double end = sqrt(*ri);
        for (std::vector<long>::const_iterator pi = primes.begin(); pi != primes.end(); pi++) {
            if (divides(*pi, *ri))  {
                prime = false;
                break;
            } else if (*pi > end) {
                break;
            }
        }
        if (prime) {
            primes.push_back(*ri);
        }
    }
    print_vector(&primes);*/

    //int n = 13195;
    long n = 600851475143;
    Range r2(2, sqrt(n)+1);
    long largest = 1;
    while (true) {
        bool divided = false;
        for (RangeIterator ri = r2.begin(); ri != r2.end(); ri++) {
            if (divides(*ri, n)) {
                n /= *ri;
                if (*ri > largest) {
                    largest = *ri;
                }
                divided = true;
                break;
            }
        }
        if (!divided) {
            break;
        }
    }
    std::cout << largest << std::endl;

    return 0;
}

