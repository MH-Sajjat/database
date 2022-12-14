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

// problem link: https://vjudge.net/contest/460861#problem/A

struct node {
  int sum;
  node* left;
  node* right;
  node() : sum(0), left(NULL), right(NULL) {}
};

node* build(int b, int e) {
  node* cur = new node();
  if (b == e) return cur;
  int mid = (b + e) >> 1;
  cur->left = build(b, mid);
  cur->right = build(mid + 1, e);
  cur->sum = cur->left->sum + cur->right->sum;
  return cur;
}

node* update(node* pre, int b, int e, int idx, int val) {
  if (idx < b or idx > e) return pre;
  node* cur = new node();
  cur->sum = pre->sum;
  if (b == e) {
    cur->sum += val;
    cur->left = pre->left;
    cur->right = pre->right;
    return cur;
  }
  int mid = (b + e) >> 1;
  cur->left = update(pre->left, b, mid, idx, val);
  cur->right = update(pre->right, mid + 1, e, idx, val);
  cur->sum = cur->left->sum + cur->right->sum;
  return cur;
}

int query(node* cur, node* pre, int b, int e, int k) {
  if (b == e) return b;
  int cnt = cur->left->sum - pre->left->sum;
  int mid = (b + e) >> 1;
  if (cnt >= k) {
    return query(cur->left, pre->left, b, mid, k);
  } else {
    return query(cur->right, pre->right, mid + 1, e, k - cnt);
  }
}

map<int, int> ID, original;
int getID(int x) { return ID[x]; };
int getOriginal(int x) { return original[x]; };

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    vi v(n + 2, 0);
    set<int> s;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
      s.insert(v[i]);
    }
    int p = 0;
    for (auto x : s) {
      ID[x] = ++p;
      original[p] = x;
    }

    node* root[n + 2];
    root[0] = build(1, n);
    for (int i = 1; i <= n; ++i) {
      root[i] = update(root[i - 1], 1, n, getID(v[i]), 1);
    }
    while (m--) {
      int l, r, k; cin >> l >> r >> k;
      cout << getOriginal(query(root[r], root[l - 1], 1, n, k)) << nl;
    }
  }
  return 0;
}