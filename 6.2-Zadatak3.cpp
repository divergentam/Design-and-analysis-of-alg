#include <iostream>
#include <utility>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int l, int r, int left[], int right[]) {
	if (l < r) {
		int pivot = right[r];
		int count = l;
		for (int i = l; i <= r; i++) {
			if (right[i] <= pivot) {
				swap(right[i], right[count]);
				swap(left[i], left[count]);
				count++;
			}
		}
		pivot = count - 1;
		sort(l, pivot - 1, left, right);
		sort(pivot + 1, r, left, right);
	}
}

int solve(int l[], int r[], int n) {
	int counter = 1;
	int rightInterval = r[0];
	std::cout << "[" << l[0] << ", " << r[0] << "]";
	for (int i = 1; i < n; i++) {
		if (l[i] >= rightInterval) {
			counter++;
			rightInterval = r[i];
			std::cout << ", [" << l[i] << ", " << r[i] << "]";
		}
	}
	std::cout << std::endl;
	return counter;
}


void merge(std::pair<int, int> a[], int l, int r, int x[], int y[]) {
	if (l < r) {
		int m = (l + r) / 2;
		merge(a, l, m, x, y);
		merge(a, m + 1, r, x, y);
		int i, j, k, nl, nr;
		// nr - broj el desnog podniza
		// nl - broj el levog podniza
		nl = m - l + 1;
		nr = r - m;
		int* la = new int[nl];
		int* la2 = new int[nl];
		int* ra = new int[nr];
		int* ra2 = new int[nr];

		//kopiramo podnizove iz niza a u nizove la i ra
		for (i = 0; i < nl; i++) {
			la[i] = a[l + i].first;
			la2[i] = a[l + i].second;
		}
		for (i = 0; i < nr; i++) {
			ra[i] = a[m + 1 + i].first;
			ra2[i] = a[m + 1 + i].second;
		}
		
		//Spajamo podnizove odnosno nizove la i ra u niz a
		i = 0;
		j = 0;
		k = l;
		while (i < nl && j < nr) {
			if (la2[i] < ra2[j]) {
				x[k] = la[i];
				y[k] = la2[i];
				i++;
			}
			else {
				x[k] = ra[j];
				y[k] = ra2[j];
				j++;
			}
			k++;
		}
		while (i < nl) {
			x[k] = la[i];
			y[k]  = la2[i];
			i++;
			k++;
		}
		while (j < nr) {
			x[k] = ra[j];
			y[k] = ra2[j];
			j++;
			k++;
		}
	}
}


int main() {
	int n = 5;
	int l[] = { 1,9,7,2,5 };
	int r[] = { 3,11,10,7,7 };
	/*sort(0, n - 1, l, r);
	std::cout << "Mozemo izabrati najvise " << solve(l, r, n) << " intervala tako da nikoja dva nemaju zajednickih tacaka" << std::endl;*/
	
	std::pair<int, int>* array = new std::pair<int, int>[10];
	for (int i = 0; i < n; i++) {
		array[i].first = l[i];
		array[i].second = r[i];
	}
	//merge sort
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++) {
		x[i] = array[i].first;
		y[i] = array[i].second;

	}
	merge(array, 0, n - 1, x, y);
	std::cout << "Mozemo izabrati najvise " << solve(x, y, n) << " intervala tako da nikoja dva nemaju zajednickih tacaka" << std::endl;


	return 0;
}

