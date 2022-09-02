#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(nullptr);

/*........................ let's try one more time ........................*/

template <typename type> class Bit {
private:
  vector<type> tree;
  int n;
public:
  Bit(int n) {
    this->n = n;
    tree.assign(n + 2, 0);
  }
  // O(logn)
  void update(int idx, type val) {
    while (idx <= n) {
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
  // O(logn)
  type query(int idx) {
    type sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }
  type query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n;
    cin >> n;
    int ar[n + 2];
    for (int i = 1; i <= n; ++i) cin >> ar[i];
    Bit<int> ds(n);
    for (int i = 1; i <= n; ++i) {
      ds.update(i, ar[i]);
    }
    int m;
    cin >> m;
    while (m--) {
      int l, r;
      cin >> l >> r;
      cout << ds.query(l, r) << nl;
    }
  }
  return 0;
}