#include <iostream>

using namespace std;

// VERY INEFFICIENT SOLUTION

bool isSquareRootOfNANaturalNumber(int n, int *c) {
	for (int i = 0; i*i <= n; i++) {
		if (i*i == n) {
			*c = i;
			return true;
		}
	}
	return false;
}

int productOfPythagoreanTriplet(int limit) {
	int c = 0;
	int cSquared = 0;
	for (int a = 1; a <= limit; a++) {
		for (int b = 1; b <= limit; b++) {
			cSquared = a*a + b*b;
			if (isSquareRootOfNANaturalNumber(cSquared, &c) && ((a+b+c) == limit)) {
				return a*b*c;
			}
		}
	}
	return -1; // YA DUN GOOFED
}

int main() {
	cout << productOfPythagoreanTriplet(1000) << endl;
}