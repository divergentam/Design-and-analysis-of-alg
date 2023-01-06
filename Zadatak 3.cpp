#include <iostream>

/*
Zadatak 3. Sedlo u matrici je element matrice koji je istovremeno najmanji (ili jedan od najmanjih) u svojoj 
vrsti a najve´ci (ili jedan od najve´cih) u svojoj koloni. Za datu matricu celih brojeva
A dimenzija n × m odrediti poziciju sedla, ukoliko postoji. Ukoliko ima viˇse reˇsenja ˇstampati bilo
koje. Traˇzi se reˇsenje vremenske sloˇzenosti O(nm).
*/

const int MAX_COLUMS = 100;

//vremenska slozenost: O(nm(m + n)) -- kada je m == n onda je O(n^3)	---- kubna
//memorijska slozenost:	O(1)											---- konstantna

bool sedloA(int n, int m, int mat[][MAX_COLUMS], int& pi, int& pj) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mini = mat[i][0]; //minimalni u vrsti
			for (int k = 1; k < m; k++) {
				if (mini > mat[i][k])
					mini = mat[i][k];
			}

			int maxj = mat[0][j]; //najveci u redu
			for (int k = 1; k < n; k++) {
				if (maxj < mat[k][j])
					maxj = mat[k][j];
			}

			if (mat[i][j] == mini && mat[i][j] == maxj) {
				pi = i;
				pj = j;
				return true;
			}
		}
	}
	pi = -1;
	pj = -1;
	return false;
}

//vremenska slozenost: O(n + m + nm + nm) = O(2 * nm) = O(nm)		--- kvadratna
//memoriska slozensot: O(n + m + 2) = O(n + m)						--- linearna  
bool sedloB(int n, int m, int mat[][MAX_COLUMS], int& pi, int& pj) {
	int* mins = new int(n);
	int* maxs = new int(m);
	for (int i = 0; i < n; i++) {
		mins[i] = mat[i][0]; //pretpostavka da je prvi el iz vrste minimalan u vrsti
	}
	for (int j = 0; j < m; j++) {
		maxs[j] = mat[0][j]; //pretpostavka da je prvi el iz kolone maksimalan u koloni
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] < mins[i])
				mins[i] = mat[i][j];
			if (mat[i][j] > maxs[j])
				maxs[j] = mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == mins[i] && mat[i][j] == maxs[j]) {
				pi = i;
				pj = j;
				return true;
			}

		}
	}
	pi = -1;
	pj = -1;
	return false;
}

int main(){
	int n = 3, m = 4;

	int mat[3][MAX_COLUMS] = { {1, 5, 1, 0}, {3,4, 3, 5}, {7, 1, 2, 2} };

	int pi, pj;

	bool rezultat = sedloA(n, m, mat, pi, pj);

	if (rezultat)
		std::cout << "Broj " << mat[pi][pj] << " je sedlo i nalazi se na (" << pi << ", " << pj << ") poziciji" << std::endl;
	else
		std::cout << "Sedlo ne postoji u ovoj matrici" << std::endl;
	
	rezultat = sedloB(n, m, mat, pi, pj);

	if (rezultat)
		std::cout << "Broj " << mat[pi][pj] << " je sedlo i nalazi se na (" << pi << ", " << pj << ") poziciji" << std::endl;
	else
		std::cout << "Sedlo ne postoji u ovoj matrici" << std::endl;

	return 0;
}
