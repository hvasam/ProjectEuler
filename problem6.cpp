#include <iostream>

long long sumOfSquares(long long from, long long to) {
	long long total = 0;
	for (long long i = from; i <= to; i++) {
		total += i * i;
	}
	return total;
}

long long squareOfSum(long long from, long long to) {
	long long total = 0;
	for (long long i = from; i <= to; i++) {
		total += i;
	}
	total = total * total;
	return total;
}

long long sumSquareDifference(long long from, long long to) {
	return squareOfSum(from, to) - sumOfSquares(from, to);
}

int main() {
	std::cout << sumSquareDifference(1, 100) << std::endl;
}