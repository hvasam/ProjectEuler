#include <iostream>

using namespace std;

int noRemainder(int n) { // the name of the function could have been better :/
	int lowestEvenlyDivisibleNumber = 0; // start from n and increment by n for unsatisfactory values
	int divisor = n; // satisfactory values of lowestEvenlyDivisibleNumber are evenly divisible by all integers >= 1 and <= n
	bool numberFound = false;
	do {
		divisor = n;
		lowestEvenlyDivisibleNumber = lowestEvenlyDivisibleNumber + n;
		while (lowestEvenlyDivisibleNumber%divisor == 0) {
			--divisor;
			if (divisor <= 1) {
				numberFound = true;
				break;
			}
		}
	}
	while (!numberFound);
	return lowestEvenlyDivisibleNumber;
}

int main() {
	cout << noRemainder(20) << endl;
}

// Fun fact: For all + natural numbers, the lowest number greater than n that is evenly divisible by n and n-1 is (n)*(n-1). With that in mind,
// you could have chosen to increment lowestEvenlyDivisibleNumber by (n)*(n-1) on each iteration of the outer do-while loop. 