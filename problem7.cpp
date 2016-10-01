#include <iostream>

using namespace std;

bool isPrime(int k) {
	int divisor = 2; // All prime numbers are divisible by 1
	while (divisor*divisor <= k) { // the <= is important for when k = 4
		if (k%divisor == 0) {
			return false;
		}
		++divisor;
	}
	return true;
}

int findIthPrimeNumber(int i) { // i must be >= 1
	if (i == 1) { return 2; }
	int k = i-1;
	int Prime = 3; // by starting at 3, we can increment by 2 each time
	int desiredPrime = 3;
	while (k > 0) {
		if (isPrime(Prime)) {
			--k;
			desiredPrime = Prime;
		}
		Prime = Prime + 2; // all prime numbers are odd
	}
	return desiredPrime;
}

int main() {
	cout << findIthPrimeNumber(10001) << endl;
}