#include <iostream>

/*******************************************************************************
**********
********** Problem 2: Even Fib Numbers
**********
*******************************************************************************/

using namespace std;
// Create function to sum all even integers below 4 million in a fibonacci sequence starting from n1 and n2
// sum variable should keep a running total (set to a+b if a and b are even, set to a(b) if a(b) is even, 0 if neither are even)
int fib(int limit, int a, int b, int sum) {
	int c = a + b;
	if ((a%2 == 0) && (sum < a)) {
			sum += a;
	}
	if ((b%2 == 0) && (sum < b)) {
		sum += b;
	}		
	if (c < limit) {
		if ((c%2) == 0) {
			sum += c;
		}
		return fib(limit, b, c, sum);
	}
	else {
		return sum;
	}
}

int main() {
	cout << fib(4000000, 0, 1, 0) << endl; // 
}