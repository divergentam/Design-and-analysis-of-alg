/*
Zadatak 5. Dat je celobrojni niz a duˇzine n. Odrediti uzastopni podniz niza a sa najve´com sumom
svojih elemenata (ˇstampati sumu). Traˇzi se reˇsenje vremenske sloˇzenosti O(n).
*/
#include <iostream>

int zadatak5a(int n, int a[]) {
	// proci sve podnizove i odrediti im sumu 
	// a[i], a[i+1], ..., a[j];		i = 0, 1, ..., n - 1;		j = i, i + 1, ..., n - 1;
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += a[k];
 			}
			if (sum > maxSum)
				maxSum = sum;
		}
	}
	return maxSum;
}
// Vremenska slozenost: 0(n^3)
// Memorijska slozenost: O(1)


int zadatak5b(int n, int a[]) {
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum > maxSum)
				maxSum = sum;
		}
	}
	return maxSum;
}
// Vremenska slozenost: 0(n^2)
// Memorijska slozenost: O(1)


int zadatak5c(int n, int a[], int &indexi, int &indexj){
	int maxSum = INT_MIN;
	int *s = new int[n];
	s[0] = a[0];
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int min = 0;
	/*
	mi hocemo da prodjemo n puta kroz niz i da vidimo svaki put da li je novo s[j] < prethodnog min
	ako jeste da promenimo da s[j] bude novi min
	u isto vreme dok trazimo min pitamo da li je s[j] - min > maxSum
	*/
	for (int j = 0; j < n; j++) {
		if (s[j] - min > maxSum) {
			maxSum = s[j] - min;
			indexj = j;
		}
		if (s[j] < min) {
			min = s[j];
			indexi = j + 1;
		}
	}
	delete[] s;
	return maxSum;
}
// Vremenska slozenost: 0(n)
// Memorijska slozenost: O(n)

int main() {
	int n = 7;
	int indexi = INT_MIN, indexj= INT_MIN;
	int a[7] = { 1,5,-10,5,-2,6,-4 };

	std::cout << zadatak5a(n, a) << std::endl;
	std::cout << zadatak5b(n, a) << std::endl;
	std::cout << zadatak5c(n, a, indexi, indexj) << "(od "<< indexi << ". do " << indexj << ". pozicije)" << std::endl;

	return 0;
}