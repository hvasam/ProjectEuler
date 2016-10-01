#include <iostream>

using namespace std;

bool isPrime(long long n) {
	long long divisor = 2;
	while ((divisor*divisor) <= n) {
		if (n%divisor == 0) {
			return false;
		}
		++divisor;
	}
	return true;
}

long long largestPrimeFactor(long long n) {
	long long i = 1;
	long long greatestPrimeFactor = 1;
	long long otherFactor;
	while ((i*i) <= n) {
		if (n%i == 0) {
			if ((isPrime(i)) && (i > greatestPrimeFactor)) {
				greatestPrimeFactor = i;
			}
			otherFactor = n/i;
			if ((isPrime(otherFactor)) && (otherFactor > greatestPrimeFactor)) {
				greatestPrimeFactor = otherFactor; 
				return greatestPrimeFactor; // otherFactor is always >= i and any subsequent otherFactor will be less than the first prime otherFactor 
			}
		}
		++i;
	}
	if (greatestPrimeFactor == 1) {
		return -1; // no prime factors
	}
	else {
		return greatestPrimeFactor;
	}
}

int main() {
	cout << largestPrimeFactor(13195) << endl;
	cout << largestPrimeFactor(600851475143) << endl;
	cout << largestPrimeFactor(74449) << endl;
}