#include <iostream>

int const KOLONE = 4;
int const MAXCOL = 10;

/*
suma za (0,0) i (i, j)
sum[i][j] = sum[i][j – 1] + sum[i – 1][j] + mat[i][j] – sum[i – 1][j – 1]

suma za (p,q) i (r, s)
total = sum[r][s] – sum[r][q – 1] – sum[p – 1][s] + sum[p – 1][q – 1]
dakle od velikog kvadrata cija je suma sum[r][s] koji ima kordinate (0, 0) i (r, s)
oduzimamo sumu[r][q-1] to ju suma koja je od (0, 0) do (r, q-1) jer je to sve ono sto je visak sa leve strane 
treba jos da se vidi koliki je visag s gornje strane jer uzimajuci na pocetku sumu od (0, 0) do (r, s) oduzeli 
smo mogucnost da postoji visak dole i desno jer je ta tacka (r, s) krajnja donja desna tacka.
Oduzecemo dakle i visak s gornje strane koji ce biti suma od (0, 0) do (p -1, s) jer jer p-1 red iznad 
nase podmatrice a kolona s je sve ono dokele matrica ide u sirinu. Na kraju moracemo da dodamo ono sto smo dva 
puta oduzeli jer radimo samo sa zbirovima za matrice od (0, 0) do neke racke (i, j)
*/

void resenje(int n, int m, int mat[][MAXCOL], int k, int x[], int y[], int z[], int t[]) {
	int sum [3][MAXCOL];
	//za prvi el
	sum[0][0] = mat[0][0];

	//za prvi red - ide od jedan jer imamo sum[0][0]
	// ono sto ovde trazimo je sum[0][1], sum[0][2], ... , sum[0][m- 1] - red je sirok za onoliko koliko kolona ima - m
	for (int i = 1; i < m; i++) {
		sum[0][i] = sum[0][i - 1] + mat[0][i]; 
		/* 
		dakle,
		sum[0][1] = sum[0][0] + mat[0][1]
		sum[0][2] = sum[0][1] + mat[0][2]
		...
		sum[0][m-1] = sum[0][m-2] + mat[0][m-1]
		*/
	}
	// za prvu kolonu - ide od jedan jer iammo sum[0][0]
	//ono sto trazimo je sum[0][0], sum[1][0], ... , sum[n-1][0] - kolona je dugacka za onoliko koliko redova ima - n
	for (int i = 1; i < n; i++) {
		sum[i][0] = sum[i - 1][0] + mat[i][0];
	}

	//krecemo u oba slucaja od jedan jer imamo vrednosti za ceo prvi red i kolonu
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mat[i][j];
		}
	}

	int rez;

	/*
	total = sum[z][t] – sum[z][y – 1] – sum[x – 1][t] + sum[x – 1][y – 1]
	radimo obrnutb postupak
	na pocetku kazemo da je suma svaka0 jednaka rez = sum[z][t]
	pa onda ako je y bar 1 odnosno nije u pitanju koordinata (x, 0) radimo rez -= sum[z][y-1]
	{jer ako racunamo sum[z][y-1] gde je y = 0 dobicemo neki - index a takav rezultat u matrici ne postojki} 
	zatim ako je x bar 1 ondnosno nije u pitanju koordinata (0, x) radimo rez -= sum[x-1][t]
	i na kraju ukoliko isu i x i y bar 1 dodajemo ono sto je bilo zajednicko jer smo ga oduzeli 
	dva puta a to je rez -= sum[x-1][y-1]
	*/
	for (int i = 0; i < k; i++) {
		rez = sum[z[i]][t[i]];

		if (y[i] > 0)
			rez -= sum[z[i]][y[i] - 1];

		if (x[i] > 0)
			rez -= sum[x[i] - 1][t[i]];

		if (x[i] > 0 && y[i] > 0)
			rez -= sum[x[i] - 1][y[i] - 1];

		std::cout << rez << " ";
	}
}

int main() {
	int n = 3, m = 4;
	int mat[3][MAXCOL] = { {1,5,1,0},{2,3,4,5},{7,1,8,2} };
	int k = 3;
	int x[3] = { 1, 0, 0 };
	int y[3] = { 0, 0, 3 };
	int z[3] = { 2, 2, 1 };
	int t[3] = { 2, 3, 3 };

	resenje(n, m, mat, k, x, y, z, t);

	return 0;
}