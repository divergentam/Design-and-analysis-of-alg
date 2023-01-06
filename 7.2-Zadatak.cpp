#include <iostream>

// uzimamo d[i] kao duzinu najduzeg rastuceg podniza do a[i]-tog elementa
// posmatramo indekse gde je j < i za koje je a[j] < a[i] (to su kandidati za pretposlednji el.)

int zad3(int n, int a[], int p[]) {
	int *d = new int[n];
	d[0] = 1;
	p[0] = 0;

	for (int i = 1; i < n; i++) {
		d[i] = 1; // prvi element smo uzeli u obzir ako negde ima vise el mozemo da kazemo d[i]++
		p[i] = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < 1 + d[j]) { 
				d[i] = 1 + d[j];
				p[i] = j;
			}
		}
	}

	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		max = (max < d[i]) ? d[i] : max;
	}

	return max;
}

int main() {
	int n = 7;
	int a[] = { 3,1,5,12,6,10,8 };
	int p[7];
	std::cout << zad3(n, a, p) << std::endl;


	
	return 0;
}