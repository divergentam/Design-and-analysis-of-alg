#include <iostream>
#include <vector>
#include <tuple>

// 3) Faktorizacija broja n (n = p_1^{a_1} p_2^{a_2} ... p_k^{a_k})
// Ideja: Idemo po deliocima d = 2, 3, 4, .... i = (sqrt(n)) ako d|n, onda n delimo sa d sve dok mozemo
// JEDINSTVENA REPREZENTACIJA

// Vremenska slozenost: O(sqrt(n))
// Memorijska slozenost: O(sqrt(n))
void faktorizacija(int n, std::vector<int> *p, std::vector<int> *a) {
	int candidate = 2;
	while (candidate <= sqrt(n)) {
		if (n % candidate == 0) {
			int numberOfDiv = 0;
			p->push_back(candidate);
			while (n % candidate == 0)
			{	
				n /= candidate;
				numberOfDiv++;
			}
			a->push_back(numberOfDiv);
		}
		candidate++;
	}
	if (n > 1) {
		p->push_back(n);
		a->push_back(1);
	}
}

int main() {
	 int n = 12;
	 std::vector<int> p;
	 std::vector<int> a;
	 faktorizacija(n, &p, &a);

	 std::cout << n << " = ";
	 for (int i = 0; i < p.size() - 1; i++) {
		 std::cout << p[i] << "^" << a[i] << " + ";
	 }
	 int k = p.size() -1;
	 std::cout << p[k] << "^" << a[k];

	return 0;
}