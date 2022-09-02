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
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);

/*........................ let's try one more time ........................*/

// problem link: https://vjudge.net/contest/491215#problem/E
// 2D bit + dp

class Bit {
  vector<vll> tree;
  int n;

public:
  Bit(int n) {
    this->n = n;
    tree.resize(12, vll(n + 2, 0));
  }

  void update(int len, int idx, ll val) {
    while (idx <= n) {
      tree[len][idx] += val;
      idx += (idx & -idx);
    }
  }

  ll query(int len, int idx) {
    ll sum = 0;
    while (idx > 0) {
      sum += tree[len][idx];
      idx -= (idx & -idx);
    }
    return sum;
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
    int n, K;
    cin >> n >> K;
    vll nums(n, 0);
    Bit ds(n + 2);
    for (auto& x : nums) cin >> x;
    for (auto x : nums) {
      for (int k = 1; k <= (K + 1); ++k) {
        ll value = ds.query(k - 1, x - 1);
        if (k == 1) value = 1;
        ds.update(k, x, value);
      }
    }
    cout << ds.query(K + 1, n) << nl;
  }
  return 0;
}