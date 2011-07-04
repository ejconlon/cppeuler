
/*
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 *
 * Answer:
 * 906609
 *
 */

#include <iostream>
#include <sstream>

long lpow(long b, long d);
long find_pali(long d);
bool is_pali(long z);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Need dimension (2 or 3)" << std::endl;
        return -1;
    }
    int d = atoi(argv[1]); 
    std::cout << find_pali(d) << std::endl;
    return 0;
}

long find_pali(long d) {
    long xLow = lpow(10, d);
    long xHi = lpow(10, d+1);
    long largest = -1;
    for (long x = xLow; x < xHi; x++) {
        for (long y = xLow; y <= x; y++) {
            long z = x*y;
            if (is_pali(z)) {
                if (z > largest) {
                    largest = z;
                }
            }
        }
    }
    return largest;
}

long lpow(long b, long d) {
    if (d < 0) return -1;
    long r = 1;
    while (d > 0) {
        r *= b;
        d -= 1;
    }
    return r;
}

bool is_pali(long z) {
    std::ostringstream sin;
    sin << z;
    std::string val = sin.str();
    int len = val.length(); 
    for (int i = 0; i < len/2; i++) {
        char a = val.at(i);
        char b = val.at(len-i-1);
        if (a != b) return false;
    }
    return true;
}
