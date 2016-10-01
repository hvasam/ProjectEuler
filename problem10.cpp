#include <iostream>
 
using namespace std;

bool isPrime(int n) {
	for (int base = 2; base*base <= n; base++) { // base = 2 since prime numbers start from 2
		if (n%base == 0) {
			return false;
		}
	}
	return true;
}

long long sumOfPrimeBelow(int limit) {
	long long sum = 0;
	for (int i = 2; i < limit; i++) { // i = 2 since prime numbers start from 2
		if (isPrime(i)) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	cout << sumOfPrimeBelow(2000000) << endl;
}

// You made the mistake of using a data type (int) that could not hold values as large as 2mill*2mill