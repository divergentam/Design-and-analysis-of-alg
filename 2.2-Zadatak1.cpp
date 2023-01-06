#include <iostream>

/*
Zadatak 1. Prirodan broj zovemo poluprost ukoliko je jednak proizvodu dva (ne nuzno razlicita)
prosta broja. Ispitati da li je dati prirodan broj n poluprost. Trazi se resenje vremenske slozenosti O(sqrt(n))
*/

// Gledamo brojeve od 2 do sqrt(n)
// Ako nadjemo delioc p iz [2, sqrt(n)], onda je delioc i broj q = n / p (p <= sqrt(n) <= q)
// Ako p nije prost delioc => p = p_1 * p_2, gde su p_1, p_2 razliciti od p   p_1 < p <= sqrt(n), p_2 < p <= sqrt(n)
//     =>   Imamo delioce {p1,p2,p} iz segmenta [2, sqrt(n)]
// Ako p jeste prost delioc => p je jedini delioc iz segmenta [2, sqrt(n)]

// Broj n je poluprost ako ima samo dva delioca i ti delioci nisu 1 i n

/*Dakle ako broj p pripada segmentu [2, sqrt(n)] i p|n onda i q|n gde je q = n/p
* p <= sqrt(n)
* q >= sqrt(n)
* to znaci da q svakako nece da se broji u delioce ukoliko je veci od sqrt(n) - 
* pa znaci da je p prost delioc ukloiko je jedini delioc iz segmenta [2, sqrt(n)]
*/

// ************ako broj p moze da se zapise kao proizvod dva broja onda on nije prost!************

bool zadatak1(int n) {
	int numOfDiv = 0; 
	int candidate = 2;
	while (candidate <= sqrt(n))
	{
		if (n % candidate == 0) {
			numOfDiv++;
		}
		candidate++;
	}
	return numOfDiv == 1;
}


int main() {
	std::cout << zadatak1(49); // za kvadrate isto radi jer proverava samo jednom za 7 pa posle je 49/7 = 7 a za 7 smo vec proverili pa se ne duplira
	return 0;
}