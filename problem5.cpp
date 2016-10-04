#include <iostream>

int evenlyDivisibleByAllNumbers(int from, int to) {
	if (from == to) { return from; }
	int commonFactor = to * (to - 1);
	int answer = commonFactor;
	for (int i = from; i <= to; ++i) {
		if ((answer % i) == 0) { continue; }
		else {
			i = from;
			answer += commonFactor;
		}
	}
	return answer;
}

int main() {
	std::cout << evenlyDivisibleByAllNumbers(1, 20) << std::endl;
}