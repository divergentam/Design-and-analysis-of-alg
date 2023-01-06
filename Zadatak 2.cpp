#include <iostream>

/*
Zadatak 2. Rotacija niza za jedno mesto ulevo predstavlja modifikaciju niza u kome se svaki
element niza pomeri za jednu poziciju ulevo, pri ˇcemu prvi element ode na poslednje mesto (npr.
5 8 1 0 → 8 1 0 5). Dat je celobrojni niz a duˇzine n i prirodan broj m. Rotirati niz a za m mesta
ulevo. Traˇzi se reˇsenje vremenske sloˇzenosti O(n).
*/

// Vremenska slozenost: O(n*m)
// Memorijska slozenost: O(1)
void zadatak2a(int n, int m, int a[]) {
	for (int k = 1; k <= m; k++) { // m puta rotiramo u jeno mesto u levo
		int t = a[0];
		for (int i = 0; i < n - 1; i++)
			a[i] = a[i + 1];
		a[n - 1] = t;
	}
}

//	Vremenska slozenost: O(n)
//	Memorijska slzoenost: O(n)
void zadatak2b(int n, int m, int a[]) {
	m = m % n; // smanjujemo m ako je potrebno odnosno ako je n < m
	int* b = new int[n];
	for (int i = 0; i < n - m; i++) {
		b[i] = a[m + i];
	}
	for (int i = n - m; i < n; i++) {
		b[i] = a[i - (n - m)];
	}
	for (int i = 0; i < n; i++){
		a[i] = b[i];
	}
	delete[] b;
}

/*Uspeli smo da smanjimo vremensku slozenost sa O(n*m) na O(n) ali
imamo trade off jer je sada memorijska slozenost sa O(1) otisla na O(n)
ali je to prihvatljivo*/

int main(){
	int n = 6, m = 4;
	int a[6] = { 3, 8, -2, 10, -7, 5 };

	zadatak2a(n, m, a);
	std::cout << "Niz nakon prvog resenja - O(n*m): " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	int b[6] = { 3, 8, -2, 10, -7, 5 };
	zadatak2b(n, m, b);
	std::cout << "\nNiz nakon drugog resenja - O(n): " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << b[i] << " ";
	}


	return 0;
}


