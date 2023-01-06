#include <iostream>

int resiZad2(int a[], int l, int r) {
	if (l < r) {
		//niz ima bar dve el 
		//delimo na pola i racunamo sume
		int m = (l + r) / 2;
		int s1 = resiZad2(a, l, m);
		int s2 = resiZad2(a, m + 1, r);

		int leftSum = a[m];
		int leftMax = a[m];
		for (int i = m - 1; i >= l; i--) {
			leftSum += a[i];
			if (leftSum > leftMax) {
				leftMax = leftSum;
			}
		}

		int rightSum = a[m + 1];
		int rightMax = a[m + 1];
		for (int i = m + 2; i <= r; i++) {
			rightSum += a[i];
			if (rightSum > rightMax) {
				rightMax = rightSum;
			}
		}

		int s3 = rightMax + leftMax;
		int result = s1;
		if (s2 > result)
			result = s2;
		if (s3 > result)
			result = s3;

		return result;
	}
	return a[l];
}

int zadatak2(int a[], int n) {
	return resiZad2(a, 0, n - 1);
}

int main() {
	int n = 7;
	int a[7] = { 1, 5, -10, 5, -2, 6, -4 };
	std::cout << zadatak2(a, n);

	return 0;
}