#include <iostream>

int sumOfEvenFibNumbersLTOET(int limit) {
	int a = 0;
	int b = 1;
	int total = 0;
	while (b <= limit) {
		b = a + b;
		a = b - a;
		if ((a % 2) == 0) {
			total += a;
		}
	}
	return total;
}

int main() {
	std::cout << sumOfEvenFibNumbersLTOET(4000000) << std::endl;
}