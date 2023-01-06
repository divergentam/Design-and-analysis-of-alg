#include <iostream>

// Sllozen broj n je broj koji ima bar jednog delioca d gde d nije 1 ili n!
// Teorema: Svaki broj koji je veci od 11 mozemo predstaviti kao zbir dva slozena broja

bool zadatak3(int n) {
	if (n <= 11) {
		if (n == 8) {
			return true;
		}
		return false;
	}
	return true;
}

int main() {
	return 0;
}