#include <iostream>

/*
    1. Kako resiti problem?
    2. Kako analizirati resenje? (Odredivanje kompleksnosti)
    3. Da li se moze poboljsati resenje? (Smanjivanje kompleksnosti)
*/

// Zad 1. Odrediti sumu prirodnih brojeva od 1 do n.
// 1 + 2 + 3 + ... + (n - 1) + n


// O(f(n)) slozenost - za svaki ulaz reda n algoritam (korektno) resava problem u NE VISE od c * f(n) inskrukcija
// Omega(f(n)) slozenost -  za svaki ulaz reda n algoritam (korektno) resava problem u BAREM c * f(n) inskrukcija
// Teta(f(n)) slozenost - za svaki ulaz reda n algoritam (korektno) resava problem u BAREM c1 * f(n) inskrukcija i NE VISE od c2 * f(n) instrukcija
//                                                                                          ( konstante c1 i c2 ne zavise od ulaza n )7

// Vremenska kompleksnost: O(n)
// Memorijska kompleksnost: O(1)

int zbir1(int n) {
    int zbir = 0;
    for (int i = 1; i <= n; i++) {
        zbir += i;
    }
    return zbir;
}

//  Vremenska kompleksnost: O(1)
// Memorijska kompleksnost: O(1)

int zbir2(int n) {
    return (n * (n + 1)) / 2;
}

int main(){
    std::cout << "Zbir1: " << zbir1(5) << std::endl;
    std::cout << "Zbir2: " << zbir2(5) << std::endl;

    return 0;
}


