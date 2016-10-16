#include <iostream>

bool isPrime(int n) { // Miller-Rabin Test is an alternative for a faster run time 
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int nthPrime(int n) {
	int primeCount = 0;
	int nthPrime = 2;
	while (primeCount < n) {
		if (isPrime(nthPrime)) {
			++primeCount;
		}
		++nthPrime;
	}
	return nthPrime - 1;
}

int main() {
	std::cout << nthPrime(10001) << std::endl;
}