#include <iostream>

bool isPrime(long long n) {
	long long count = 2;
	while (count * count <= n) {
		if ((n % count) == 0) {
			return false;
		}
		++count;
	}	
	return true;
}

long long largestPrimeFactorOf(long long n) {
	long long count = 1;
	long long largestPrimeFactor = 2;
	while (count * count <= n) {
		if ((n % count) == 0) {
			if (isPrime(count)) {
				largestPrimeFactor = count;
			}
		}
		++count;
	}
	return largestPrimeFactor;
}

int main() {
	std::cout << largestPrimeFactorOf(600851475143) << std::endl;
}