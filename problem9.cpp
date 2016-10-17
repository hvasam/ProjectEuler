#include <iostream>

bool meetsRequirements(int a, int b, int sumLimit) {
	int leftSide = (a * a) + (b * b);
	int rightSide = sumLimit - (a + b);
	rightSide *= rightSide;
	if (leftSide == rightSide) {
		return true;
	}
	else {
		return false;
	}
}

int productOfPythagoreanTriplet(int sumLimit) {
	int limit = sumLimit / 2;
	if (limit % 2 == 0) {
		limit = limit - 1; 
	}
	for (int a = limit; a > 0;  --a) {
		for (int b = limit - 1; b > 0; --b) {
			if (meetsRequirements(a, b, sumLimit)) {
				return a * b * (sumLimit - (a + b));
			}
		}
	}
	return -1;
}

int main() {
	std::cout << productOfPythagoreanTriplet(1000) << std::endl;
}