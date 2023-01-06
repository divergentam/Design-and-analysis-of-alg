#include <iostream>

void swap(int &a1, int &a2) {
	int temp = a1;
	a1 = a2;
	a2 = temp;
}

void domaci02(int a[], int l, int r) {
	//proveravamo da li je leva granica manja od desne
	if (l < r) {
		//algoritam bira pivot element sa kraja niza
		int pivot = a[r];
		int count = l; // brojac koji vodi racuna o premestanju elemenata
		for (int i = l; i <= r; i++) { // algoritam prolazi kroz ceo zadat interval odnosno od leve granice do desne
			if (a[i] <= pivot) { // svaki element koji je manji ili jednak pivot-elementu premesta na prvo, drugo itd. mesto u nizu
				swap(a[count], a[i]); // fja koja premesta elemente odnosno menja im vrednosti
				count++; // brojac povecavamo za 1
			}
		}
		pivot = count - 1;
		//rekurzivno pozivamo fju za sortiranje tako sto niz delimo na dva dela:
		//1. je deo od leve granice do (pivot - 1) elementa
		domaci02(a, l, pivot - 1);
		//2. je deo od (pivot + 1) elementa do desne granice
		domaci02(a, pivot + 1, r);
	}
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int n = 5;
	int a[5] = {7, -9, 2, 0, 5 };
	domaci02(a, 0, n - 1);
	printArray(a, n);

	return 0;
}