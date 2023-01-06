#include <iostream>

/*Zadatak 7. Pera ima gomilu novcanica u vrednosti od x dinara a Mika ima gomilu novcanica
u vrednosti od y dinara.Svako zeli da sa svoje gomile uzme odredeni broj novcanica tako da na
kraju obojica imaju isti iznos a da su ukupno uzeli najmanji moguci broj novcanica.Odrediti taj
najmanji moguci broj. Trazi se resenje vremenske slozenosti O(log min(x, y)).
*/

int nzd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return nzd(b, a % b);
	}
}

int nzs(int a, int b) {
	return (a * b) / nzd(a, b);
}

int zadatak7(int x, int y) {
	int n = nzs(x, y);
	std::cout << "Pera uzme " << n / x << " novcica , a Mika uzme " << n / y << " novcica" << std::endl;
	return n / x + n / y;
}


int main() {
	std::cout << zadatak7(6, 4);
	return 0;
}