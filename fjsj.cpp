#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

int s1, s2, m;
vi g[N];
int color = 0;

map<pii, int> cl;
vector<bool> used(N, 0);

void dfs(int u, int par, int parcolor) {
  used[u] = 1;
  int c = 1;
  for (auto v : g[u]) {
    if (v == par) continue;
    if (c == parcolor) c++;
    if (v > s1) {
      cl[{u, v - s1}] = c;
    } else cl[{v, u - s1}] = c;
    c++;
    dfs(v, u, c);
  }
}

int main() {
#ifdef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    cin >> s1 >> s2 >> m;
    vector<pii> edge;
    for (int i = 1; i <= m; ++i) {
      int u, v; cin >> u >> v;
      g[u].pb(v + s1);
      g[v + s1].pb(u);
      edge.pb({u, v});
    }
    for (int i = 1; i <= (s1 + s2); ++i) {
      color = max(color, szof(g[i]));
      dfs(i, -1, -1);
    }
    // dfs(1, -1, -1);
    cout << color << nl;
    for (auto x : edge) {
      int p = x.ff, q = x.ss + s1;
      cout << cl[{x.ff, x.ss}] << " ";
    }
    cout << nl;
  }
  return 0;
}
