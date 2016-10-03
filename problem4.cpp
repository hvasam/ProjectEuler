#include <iostream>
#include <string>

bool isPalindrome(std::string input) {
	int strLength = input.length();
	for (int i = 0, j = strLength - 1; i <= j; ++i, --j) {
		if (!(input[i] == input[j])) {
			return false;
		}
	}
	return true;
}

std::string intToString(int n) { // only for non-negative integers
	int r = 0;
	std::string num = "";
	if (n == 0) { return "0"; }
	while (n > 0) {
		r = n % 10;
		n = n / 10;
		num = "0" + num;
		num[0] = r + '0';
	}
	return num;
}

bool evenlyDivisibleByNumberLT1000(int n) {
	int limit = 999;
	while (limit > 0) {
		if ((n % limit) == 0) {
			if ((n / limit) <= 999) {
				return true;
			}
		}
		--limit;
	}
	return false;
}

std::string largestPalindromeProduct(int n) {
	int limit = n * n;
	std::string number = "";
	while (limit > 0) {
		if (evenlyDivisibleByNumberLT1000(limit)) {
			number = intToString(limit);
			if (isPalindrome(number)) {
				return number;
			}
		}
		--limit;
	}
	return number;
}


int main() {
	std::cout << largestPalindromeProduct(999) << std::endl;
}