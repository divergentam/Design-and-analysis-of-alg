#include <iostream>
using namespace std;

// Problem: Sortiranje niza
// Ulaz: Niz a od n elemenata
// Izlaz: Niz gde su elementi poredjani u nekom poretku (pp. rastucem)

// Naivna ideja: SELECTION SORT - uporediti svaka dva elementa i poredjati ih u dobrom poretku

void print(int n, int a[])
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int& a, int& b)
{
	int t = a; a = b; b = t;
}

void selectionSort(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
// Vremenska slozenost: O(n^2)
// Memorijska slozenost: O(1)



int main()
{
	int n = 6;
	int a[6] = { 6, 5, 12, 10, 9, 1 };

	cout << "Pre sortiranja: ";
	print(n, a);

	selectionSort(n, a);

	cout << "Nakon sortiranja: ";
	print(n, a);
	return 0;
}