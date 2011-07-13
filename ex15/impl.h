#ifndef IMPL_H_
#define IMPL_H_

#include <map>
#include <iostream>

long findRoutes(const int limit);
long findRoutesHelper(const int x, const int y);

class RouteMemo {
	private:
		const int limit_;
		long* memo_;
	public:
		explicit RouteMemo(const int limit): limit_(limit), memo_(new long[(limit+1)*(limit+1)]) {
			init();
		}
		~RouteMemo() { delete memo_; }
		void init() {
			set(0, 0, 1);
			for (int z = 1; z <= limit_; z++) {
				set(0, z, 1);
				set(z, 0, 1);
			}
			if (limit_ >= 1) {
				for (int x = 1; x <= limit_; x++) {
					for (int y = 1; y <= limit_; y++) {
						set(x, y, get(x-1, y)+get(x, y-1));
					}
				}	
			}
		}
		inline long get(const int x, const int y) {
			return memo_[(limit_+1)*x+y];
		}
		inline void set(const int x, const int y, const long z) {
			memo_[(limit_+1)*x+y] = z;
		}
		void print() {
			std::cout << "PRINT: " << std::endl;
			for (int i = 0; i <= limit_; i++) {
				for (int k = 0; k <= limit_; k++) {
					std::cout << get(i, k) << " ";	
				}
				std::cout << std::endl;
			}
		}
};

#endif
