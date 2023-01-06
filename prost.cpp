#include <iostream>
#include <math.h>
// 1) Proveriti da li je n prost
// Ideja: Ici kroz brojeve 2, 3, ..., n-2, n-1 i proveriti da li neki deli broj n
// => O(n)
// Poboljsanje: Ici kroz brojeve 2, 3, ..., sqrt(n) - 1, sqrt(n) i proveriti da li neki deli broj n
// => O(sqrt(n))

bool isPrime(int n) {
	bool prime = (n > 2 && n % 2 != 0);
	int candidate = 3;

	while (prime && candidate <= sqrt(n)) {
		if (n % candidate == 0) {
			prime = false;
		}
		else {
			candidate += 2;
		}
	}
	return prime;
}

int main() {
	int n = 16;
	if (isPrime(n)) {
		std::cout << "Broj " << n << " je prost broj" << std::endl;
	}
	else {
		std::cout << "Broj " << n << " nije prost broj" << std::endl;
	}
}