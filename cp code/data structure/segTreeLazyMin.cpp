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

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

int ar[N];

class SegTree {
private:
  struct dt {
    int mn, lazy;
    dt() : mn(0), lazy(0) {}
  };
  vector<dt> tree;
  int n;

  void build(int at, int b, int e) {
    if (b == e) {
      tree[at].mn = ar[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at].mn = min(tree[2 * at].mn, tree[2 * at + 1].mn);
  }

  void propagate(int at, int b, int e) {
    tree[at].mn += tree[at].lazy;
    if (b != e) {
      tree[2 * at].lazy += tree[at].lazy;
      tree[2 * at + 1].lazy += tree[at].lazy;
    }
    tree[at].lazy = 0;
  }

  void update(int at, int b, int e, int l, int r, int val) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      tree[at].mn += val;
      if (b != e) {
        tree[2 * at].lazy += val;
        tree[2 * at + 1].lazy += val;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
    tree[at].mn = min(tree[2 * at].mn, tree[2 * at + 1].mn);
  }

  int query(int at, int b, int e, int l, int r) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return INT_MAX;
    if (l <= b and e <= r) return tree[at].mn;
    int mid = (b + e) >> 1;
    int x = query(2 * at, b, mid, l, r);
    int y = query(2 * at + 1, mid + 1, e, l, r);
    return min(x, y);
  }

public:
  SegTree(int n) {
    this->n = n;
    tree.resize(4 * n);
    build(1, 1, n);
  }
  void update(int l, int r, int val) {
    update(1, 1, n, l, r, val);
  }
  int query(int l, int r) {
    return query(1, 1, n, l, r);
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
    for (int i = 1; i <= n; ++i) cin >> ar[i];
    SegTree ds(n);
    int m; cin >> m;
    while (m--) {
      int op;
      cin >> op;
      if (op == 1) {
        int l, r, val;
        cin >> l >> r >> val;
        ds.update(l, r, val);
      } else {
        int l, r;
        cin >> l >> r;
        cout << ds.query(l, r) << nl;
      }
    }
  }
  return 0;
}