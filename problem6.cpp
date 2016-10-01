#include <iostream>

using namespace std;

int sumOfSquaresOfFirstKNumbers(int n) {
	int sum = 0;
	int k = n;
	while (k > 0) {
		sum = sum + k*k;
		--k;
	}
	return sum;
}

int squareOfSumOffirstKNumbers(int k) { 
	return ((k*(k+1))/2)*((k*(k+1))/2);
}

int differenceBetweenSumOfSquaresAndSquareOfSum(int k) {
	return squareOfSumOffirstKNumbers(k) - sumOfSquaresOfFirstKNumbers(k);
}

int main() {
	cout << squareOfSumOffirstKNumbers(100) << endl;
	cout << sumOfSquaresOfFirstKNumbers(100) << endl;
	cout << differenceBetweenSumOfSquaresAndSquareOfSum(100) << endl;
}