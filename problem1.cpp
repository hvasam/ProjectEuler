#include <iostream>

int sumOfMultiplesBelow(int limit, int a, int b) {
	int total = 0;
	int count = 0;
	while (count < limit) {
		if (((count%a) == 0) || ((count%b) == 0)) {
			total += count;
		}
		++count;
	}
	return total;
}

int main() {
	std::cout << sumOfMultiplesBelow(1000, 3, 5) << std::endl;
}