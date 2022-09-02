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

class Dsu {
private:
  struct dt {
    int par, rank, setsize;
    dt() : par(0), rank(0), setsize(0) {}
  };
  vector<dt> g;
  int n;
  int setNum;

  int root(int x) {
    return g[x].par = g[x].par == x ? x : root(g[x].par);
  }
public:
  Dsu(int n) {
    this->n = n;
    g.resize(n + 2);
    setNum = n;
    for (int i = 0; i <= n; ++i) {
      g[i].par = i;
      g[i].rank = 0;
      g[i].setsize = 1;
    }
  }

  void merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return;
    if (g[x].rank <= g[y].rank) swap(x, y);
    g[y].par = x;
    g[x].setsize += g[y].setsize;
    if (g[x].rank == g[y].rank) g[x].rank++;
    setNum--;
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
    int n; cin >> n;
    Dsu ds(n);
    int m; cin >> m;
    while (m--) {
      int u, v;
      cin >> u >> v;
      ds.merge(u, v);
    }
  }
  return 0;
}