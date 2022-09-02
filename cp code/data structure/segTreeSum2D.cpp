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
// 2D segment tree + DP

class SegTree {
private:
  vector<vector<ll>> tree;
  int n;

  void build(int at, int b, int e, int len) {
    if (b == e) {
      tree[len][at] = 0LL;
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid, len);
    build(2 * at + 1, mid + 1, e, len);
    tree[len][at] = tree[len][2 * at] + tree[len][2 * at + 1];
  }

  void update(int at, int b, int e, int idx, ll val, int len) {
    if (idx < b or idx > e) return;
    if (b == e) {
      tree[len][at] += val;
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, idx, val, len);
    update(2 * at + 1, mid + 1, e, idx, val, len);
    tree[len][at] = tree[len][2 * at] + tree[len][2 * at + 1];
  }

  ll query(int at, int b, int e, int l, int r, int len) {
    if (r < b or e < l) return 0;
    if (l <= b and e <= r) return tree[len][at];
    int mid = (b + e) >> 1;
    ll x = query(2 * at, b, mid, l, r, len);
    ll y = query(2 * at + 1, mid + 1, e, l, r, len);
    return x + y;
  }

public:
  SegTree(int n) {
    this->n = n;
    tree.resize(14, vector<ll>(4 * n, 0));
    for (int i = 0; i <= 12; ++i) build(1, 1, n, i);
    
  }

  void update(int idx, ll val, int len) {
    update(1, 1, n, idx, val, len);
  }

  ll query(int l, int r, int len) {
    return query(1, 1, n, l, r, len);
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
    vll nums(n);
    SegTree ds(n);
    for (auto& x : nums) cin >> x;
    for (auto x : nums) {
      for (int k = 1; k <= (K + 1); ++k) {
        ll value = ds.query(1, x - 1, k - 1);
        if (k == 1) value = 1;
        ds.update(x, value, k);
      }
    }

    cout << ds.query(1, n, K + 1) << nl;
  }
  return 0;
}