
/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 *
 * Answer:
 * 232792560
 */

#include <iostream>
#include <map>
#include <math.h>

typedef std::map<long, long> MAP;
long find_smallest_divisible(long limit);
void do_factor(long value, MAP& map);
void print_map(MAP& map); 
long default_find(long key, long defaultValue, MAP& map);
long lcm(MAP& map);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Need limit (10, 20, etc)" << std::endl;
        return -1;
    } 
    long limit = atol(argv[1]);
    long result = find_smallest_divisible(limit);
    std::cout << "RESULT: " << result << std::endl;
    return 0;
}

long find_smallest_divisible(long limit) {
    MAP limfactors;
    for (long i = 2; i <= limit; i++) {
        MAP factor_map;
        do_factor(i, factor_map);
        for (MAP::const_iterator it = factor_map.begin(); it != factor_map.end(); it++) {
            long factor = it->first;
            long power = it->second;
            long foundPower = default_find(factor, 0, limfactors);
            if (foundPower < power) {
                limfactors[factor] = power;
            }
        }
        std::cout << "Factoring " << i << std::endl;
        print_map(factor_map);
    }
    std::cout << "All factors up to " << limit << std::endl;
    print_map(limfactors);
    return lcm(limfactors);
}

long default_find(long key, long defaultValue, MAP& map){
    MAP::const_iterator it = map.find(key);
    if (it == map.end()) {
        return defaultValue;
    } else {
        return it->second;
    }
}

void print_map(MAP& map) {
    std::cout << "MAP { " << std::endl;
    for (MAP::const_iterator it = map.begin(); it != map.end(); it++) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    std::cout << " }" << std::endl;
}

void do_factor(long value, MAP& map) {
    long lim = sqrt(value)+1;
    while (true) {
        if (value == 1) { break; }
        bool divided = false;
        for (long i = 2; i <= lim; i++) {
            if (value % i == 0) {
                value /= i;
                map[i] = default_find(i, 0, map) + 1; 
                divided = true;
                break;
            }
        }
        if (!divided) {
            if (value != 1) {
                map[value] = default_find(value, 0, map) + 1;
            }
            break;
        }
    }
}

long lcm(MAP& map) {
    long m = 1;
    for (MAP::const_iterator it = map.begin(); it != map.end(); it++) {
        long factor = it->first;
        long power = it->second;
        for (; power > 0; power--) {
            m *= factor; 
        }
    }
    return m;
}

