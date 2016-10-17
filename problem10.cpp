#include <iostream>

bool isPrime(int n) {
	if (n < 2) { return false; }
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long sumOfAllPrimesBelow(int limit) {
	long long sum = 0;
	for (int i = 2; i < limit; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	std::cout << sumOfAllPrimesBelow(2000000) << std::endl;
}