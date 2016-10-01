#include <iostream>
#include <string>

using namespace std;

string intToString(int n) {
	int number = n;
	string a = "";
	string b = "";
	int lastDigit = 0;
	while (number > 0) {
		lastDigit = number%10;
		switch (lastDigit) {
			case 0:
				a = "0";
				break;
			case 1:
				a = "1";
				break;
			case 2:
				a = "2";
				break;
			case 3:
				a = "3";
				break;
			case 4:
				a = "4";
				break;
			case 5:
				a = "5";
				break;
			case 6:
				a = "6";
				break;
			case 7:
				a = "7";
				break;
			case 8:
				a = "8";
				break;
			case 9:
				a = "9";
				break;		
		}
		number = number/10;
		b = a+b;
	}
	return b;
}

bool isPalindrome(string str) {
	int length = str.length() - 1;
	for (int i = 0; i <= length; i++) {
		if (str.substr(i, 1) == str.substr(length, 1)) {
			--length;
		}
		else {
			return false;
		}
	}
	return true;
}

int largestPalindrome(int n) { // n represents the limit of the two numbers being multiplied (2 digits => largest palindrome below 99x99)
	int limit = 0;
	int upperLimit = 0;
	while (limit < n) {
		upperLimit = 10*upperLimit + 9;
		++limit;
	}
	int cycle = upperLimit;
	int biggestPalindrome = 0;
	int lowerFactor = 1; // This variable was not necessary; it was only used for efficieny.
	while (upperLimit > 1) {
		while (cycle > 0) {
			int product = upperLimit*cycle;
			if (isPalindrome(intToString(product)) && (biggestPalindrome < product)) {
				biggestPalindrome = product;
				if (upperLimit < cycle) {
					lowerFactor = upperLimit;
				}
				else {
					lowerFactor = cycle;
				}
			}
			--cycle;
		}
		--upperLimit;
		if (upperLimit <= lowerFactor) { 
			break;
		}
		else {
			cycle = upperLimit;
		}
	}
	return biggestPalindrome;
}

int main() {
/*	
	for (int i = 0; i <= 100; i++) {
		cout << intToString(i) << endl;
	}
*/
	cout << largestPalindrome(3) << endl;
}
