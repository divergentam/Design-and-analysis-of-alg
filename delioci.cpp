#include <iostream>
#include <vector>

// 2) Ispisati sve delioce broja n
// 12 -> Delioci: 1, 2, 3, 4, 6, 12
// 7  -> Delioci: 1, 7
// Ideja: Idemo kroz brojeve 1, 2, 3, ...., n-2, n-1, n i ispisemo one koji dele broj n
// => O(n)
// Poboljsanje: Idemo kroz brojeve 1, 2, ..., sqrt(n)-1, sqrt(n), i ako neki takav d deli n,
// tada ispisujemo brojeve d i n/d
// Primer: n=12, idemo kroz brojeve d = 1, 2, 3, a ispisujemo: 1, 12, 2, 6, 3, 4
// Primer: n=7, idemo kroz brojeve d = 1, 2, a ispisujemo: 1, 7


// Vremenska slozenost: O(sqrt(n))
// Memorijska slozenost: O(sqrt(n))  (max. cap. vectora: 2*sqrt(n))
std::vector<int> AllDivisiors(int n) {
	std::vector<int> divisors;
	int candidate = 1;
	while (candidate < sqrt(n)) {
		if (n % candidate == 0) {
			divisors.push_back(candidate);
			divisors.push_back(n/candidate);
		}
		candidate++;
	}
	// u primeru sa 16 je problem sto 16 deli 4 a onda ispisemo i da 16 deli 16/4 pa se 4 duplira - u ovom slucaju ne dodajemo i candidate i 16/candidate
	if (candidate == sqrt(n)) {
		divisors.push_back(candidate);
	}
	return divisors;
}

int main() {
	int n = 16;
	std::vector<int> divisors = AllDivisiors(n);
	for (int divisor : divisors) {
		std::cout << divisor << " ";
	}


	return 0;
}