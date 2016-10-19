#include <iostream>

int lengthOfCollatzSequence(long long n) {
	int lengthOfSequence = 0;
	while (true) {
		if (n == 1) {
			break;
		}
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n = (3 * n) + 1;
		}
		++lengthOfSequence;
	}
	return lengthOfSequence + 1;
}

int longestCollatzSequence(long long max) {
	int startingNumberBelowMaxWithLongestCS = 1;
	int maxLength = 1;
	int currentLength = 1;
	for (long long i = 1; i < max; i++) {
		currentLength = lengthOfCollatzSequence(i);
		if (currentLength > maxLength) {
			maxLength = currentLength;
			startingNumberBelowMaxWithLongestCS = i;
		}
	}
	return startingNumberBelowMaxWithLongestCS;
}

int main() {
	std::cout << longestCollatzSequence(1000000) << std::endl;
}