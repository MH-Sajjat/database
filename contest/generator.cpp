#include <bits/stdc++.h>
using namespace std;

const int N     = (int) 1e6;
const int INF   = (int) 1e9;

int main() {
    ofstream file_write;
    file_write.open("input.txt");
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> A(1, N);
    uniform_int_distribution <int> Test(3, 10);
    uniform_int_distribution <int> Nmax(5, 100);
    uniform_int_distribution <int> K(1, 20);
    int test = 1;
    cin >> test;
    if (test > 1) {
        file_write << test << '\n';
    }
    while (test--) {
        int n = Nmax(rng);
        file_write << n << '\n';
        while (n--) {
            int v = A(rng);
            file_write << v << (n == 0 ? '\n' : ' ');
        }
    }
    file_write.close();
    return 0;
}