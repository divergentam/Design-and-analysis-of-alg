/* Zadatak 4.cpp :  Dat je niz realnih brojeva a du?zine n i m upita tipa : kolika je suma brojeva na
pozicijama od Li do Ri u nizu a.Za svaki upit ?stampati odgovaraju´cu sumu.Tra?zi se re?senje
vremenske slo?zenosti O(n + m).
*/
#include <iostream>

//Vremenska slozenost: O(m * (r[i]-l[i])) -> u najgorem slucaju to bi bio opseg n => O(mn)
//Memorijska slozenost: O(1)
void zadatak4a(int n, int m, double a[], int l[], int r[]) {
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = l[i]; j < r[i]; j++) {
            sum += a[j];
        }
        std::cout << sum << std::endl;
    }
}

void zadatak4b(int n, int m, double a[], int l[], int r[]) {
    double* sum = new double[n + 1];
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int s;
    for (int i = 0; i < m; i++) {
        s =sum[r[i]];
        if (l[i] - 1 >= 0)
            s -= sum[l[i] - 1];
        std::cout << s << " ";
    }
}

int main(){
    int n = 5, m = 3;
    double a[5] = { 5, 11, 22, 10, 50 };
    int l[3] = { 1, 2, 0 };
    int r[3] = { 2, 4, 4};
    zadatak4b(n, m, a, l, r);
    return 0;
}

