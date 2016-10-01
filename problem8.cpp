#include <iostream>
#include <string>

using namespace std;

// have a function that takes a positive integer, n, as an (first) argument - this integer looks for n adjacent digits in a string (the second argument)
// we will assume the string contains only digits (no spaces, special characters, etc...)
/*
int quicksort(long long arr[], int sortFrom, int pivot) {
	int numLessThanOrEqualToPivot = 0;
	long long pivotVal = arr[pivot];
	long long temp = 0;
	for (int i = 0; sortFrom+i < pivot; i++) {
		if (arr[sortFrom+i] <= pivotVal) {
			temp = arr[sortFrom+i];
			arr[sortFrom+i] = arr[sortFrom+numLessThanOrEqualToPivot];
			arr[sortFrom+numLessThanOrEqualToPivot] = temp;
			++numLessThanOrEqualToPivot;
		}
	}
	arr[pivot] = arr[sortFrom+numLessThanOrEqualToPivot];
	arr[sortFrom+numLessThanOrEqualToPivot] = pivotVal;
	return sortFrom+numLessThanOrEqualToPivot;
}

void sort(long long arr[], int sortFrom, int sortTo) { // sortFrom and sortTo are indicies in the array
	if (sortFrom < sortTo) {
		int pivot = quicksort(arr, sortFrom, sortTo);
		sort(arr, sortFrom, pivot-1);
		sort(arr, pivot+1, sortTo);
	}
}

*/
// ABOVE CODE IS COMPLETELY USELESS - IT WAS MORE FOR PRACTICE
//

long long largestProductOfNAdjacentDigits(long long n, string input) {
	long long product = 1;
	long long largestProduct = 1;
	string mutableInput = input;
	long long diffBetweenCharAndInt = 48;
	int inputLength = input.length();
//	if (n == 0) { return 0; }
	if (inputLength <= n) {
		while (mutableInput.length() > 0) {
			product = product*(mutableInput[0] - diffBetweenCharAndInt);
			mutableInput.erase(0,1);
		}
		return product;
	}
	for (int i = 0; i < n; i++) {
		product = product*(mutableInput[i] - diffBetweenCharAndInt);
	}
	largestProduct = product;
	for (int j = n; j < inputLength; j++) {
		if ((mutableInput[j-n] - diffBetweenCharAndInt) == 0) {
			product = 1;
			for (int k = j-n+1; k < j; k++) {
				product = product*(mutableInput[k] - diffBetweenCharAndInt);
			}
		}
		else {
			product = product/(mutableInput[j-n] - diffBetweenCharAndInt);
		}
		product = product*(mutableInput[j] - diffBetweenCharAndInt);
		if (product > largestProduct) {
			largestProduct = product;
		}
	}
	return largestProduct;
}


// To make the problem more challenging - we can have the arguments come from the command line (and/or file)
// The string could also contain negative numbers and non-integer characters


int main() {
	string s = "73167176531330624919225119674426574742355349194934"
				"96983520312774506326239578318016984801869478851843"
				"85861560789112949495459501737958331952853208805511"
				"12540698747158523863050715693290963295227443043557"
				"66896648950445244523161731856403098711121722383113"
				"62229893423380308135336276614282806444486645238749"
				"30358907296290491560440772390713810515859307960866"
				"70172427121883998797908792274921901699720888093776"
				"65727333001053367881220235421809751254540594752243"
				"52584907711670556013604839586446706324415722155397"
				"53697817977846174064955149290862569321978468622482"
				"83972241375657056057490261407972968652414535100474"
				"82166370484403199890008895243450658541227588666881"
				"16427171479924442928230863465674813919123162824586"
				"17866458359124566529476545682848912883142607690042"
				"24219022671055626321111109370544217506941658960408"
				"07198403850962455444362981230987879927244284909188"
				"84580156166097919133875499200524063689912560717606"
				"05886116467109405077541002256983155200055935729725"
				"71636269561882670428252483600823257530420752963450";
	cout << largestProductOfNAdjacentDigits(13, s) << endl;
//	getline(cin, s, '\n');
//	cout << s << endl;
	
}