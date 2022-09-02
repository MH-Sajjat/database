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

// problem link: https://toph.co/p/just-another-range-query

ll sum[35 * N], lazy[35 * N];
int L[35 * N], R[35 * N];

int cnt = 1;
int node(int& u) {
  if (!u) u = ++cnt;
  return u;
}

void propagate(int at, int b, int e) {
  sum[at] += 1LL * (e - b + 1) * lazy[at];
  if (b != e) {
    lazy[node(L[at])] += lazy[at];
    lazy[node(R[at])] += lazy[at];
  }
  lazy[at] = 0LL;
  return;
}

void update(int at, int b, int e, int l, int r, int val) {
  if (lazy[at]) propagate(at, b, e);
  if (r < b or e < l) return;
  if (l <= b and e <= r) {
    sum[at] += 1LL * (e - b + 1) * val;
    if (b != e) {
      lazy[node(L[at])] += val;
      lazy[node(R[at])] += val;
    }
    return;
  }
  int mid = (b + e) >> 1;
  update(node(L[at]), b, mid, l, r, val);
  update(node(R[at]), mid + 1, e, l, r, val);
  sum[at] = sum[L[at]] + sum[R[at]];
}

ll query(int at, int b, int e, int l, int r) {
  if (lazy[at]) propagate(at, b, e);
  if (r < b or e < l) return 0;
  if (l <= b and e <= r) return sum[at];
  int mid = (b + e) >> 1;
  ll x = query(node(L[at]), b, mid, l, r);
  ll y = query(node(R[at]), mid + 1, e, l, r);
  return x + y;
}

ll get(int l, int r) {
  ll up = 1LL * r * (r + 1) / 2LL;
  ll dn = 1ll * l * (l - 1) / 2LL;
  return up - dn;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    while (m--) {
      int op; cin >> op;
      if (op == 1) {
        int l, r, val;
        cin >> l >> r >> val;
        update(1, 1, n, l, r, val);
      } else {
        int l, r; cin >> l >> r;
        cout << get(l, r) - query(1, 1, n, l, r) << nl;
      }
    }
  }
  return 0;
}