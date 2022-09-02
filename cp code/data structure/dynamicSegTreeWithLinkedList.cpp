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

struct node {
  ll sum, lazy;
  node* left;
  node* right;
  node() : sum(0LL), lazy(0LL), left(NULL), right(NULL) {}
};

void propagate(node* cur, int b, int e) {
  cur->sum += 1LL * (e - b + 1) * cur->lazy;
  if (b != e) {
    if (cur->left == NULL) cur->left = new node();
    if (cur->right == NULL) cur->right = new node();
    cur->left->lazy += cur->lazy;
    cur->right->lazy += cur->lazy;
  }
  cur->lazy = 0;
}

void update(node* cur, int b, int e, int l, int r, int val) {
  if (cur->lazy) propagate(cur, b, e);
  if (r < b or e < l) return;
  if (l <= b and e <= r) {
    cur->sum += 1LL * (e - b + 1) * val;
    if (b != e) {
      if (cur->left == NULL) cur->left = new node();
      if (cur->right == NULL) cur->right = new node();
      cur->left->lazy += val;
      cur->right->lazy += val;
    }
    return;
  }
  int mid = (b + e) >> 1;
  if (cur->left == NULL) cur->left = new node();
  if (cur->right == NULL) cur->right = new node();
  update(cur->left, b, mid, l, r, val);
  update(cur->right, mid + 1, e, l, r, val);
  cur->sum = cur->left->sum + cur->right->sum;
}

ll query(node* cur, int b, int e, int l, int r) {
  if (cur->lazy != 0LL) propagate(cur, b, e);
  if (!cur->sum or r < b or e < l) return 0;
  if (l <= b and e <= r) {
    return cur->sum;
  }
  int mid = (b + e) >> 1;
  ll x = query(cur->left, b, mid, l, r);
  ll y = query(cur->right, mid + 1, e, l, r);
  return x + y;
}

ll get(int l, int r) {
  int h = r - l + 1;
  return 1LL * (l + r) * h / 2LL;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m;
    cin >> n >> m;
    node* root = new node();
    while (m--) {
      int op;
      cin >> op;
      if (op == 1) {
        int l, r, val;
        cin >> l >> r >> val;
        update(root, 1, n, l, r, val);
      } else {
        int l, r;
        cin >> l >> r;
        cout << get(l, r) - query(root, 1, n, l, r) << nl;
      }
    }
  }
  return 0;
}