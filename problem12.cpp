#include <iostream>

int numOfFactors(int n) {
	int i = 1;
	int count = 0;
	while (i * i < n) {
		if (n % i == 0) {
			count += 2;
		}
		i++;
	}
	if (n % i == 0) {
		++count;
	}
	return count;
}

int triangleNumberWithOverNDivisors(int n) {
	int squareRoot = n/2 + 1;
	int minimumNumber = squareRoot * squareRoot;
	int triangleNumber = 1;
	int currentNumber = 2;
	if (n == 0) { return 1; } 
	while (triangleNumber < minimumNumber) {
		triangleNumber += currentNumber;
		++currentNumber;
	}
	while (numOfFactors(triangleNumber) <= n) {
		triangleNumber += currentNumber;
		++currentNumber;		
	}
	return triangleNumber;
}

int main() {
	std::cout << triangleNumberWithOverNDivisors(500) << std::endl;
}