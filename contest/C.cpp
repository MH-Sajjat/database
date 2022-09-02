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

bool isValid(int x, int y) {
  return (x > 0 and x <= 8 and y > 0 and y <= 8);
}
vector<vi> grid(10, vi(10, 0)), attack(10, vi(10, 0));
void attackPos(int x, int y) {
  int xx = x, yy = y;
  while (yy <= 8) {
    attack[xx][yy] = 1;
    yy++;
  }
  xx = x, yy = y;
  while (yy > 0) {
    attack[xx][yy] = 1;
    yy--;
  }

  xx = x, yy = y;
  while (xx <= 8) {
    attack[xx][yy] = 1;
    xx++;
  }
  xx = x, yy = y;
  while (xx > 0) {
    attack[xx][yy] = 1;
    xx--;
  }

  xx = x, yy = y;
  while (xx <= 8 and yy <= 8) {
    attack[xx][yy] = 1;
    xx++;
    yy++;
  }
  xx = x, yy = y;
  while (xx > 0 and yy > 0) {
    attack[xx][yy] = 1;
    xx--;
    yy--;
  }

  xx = x, yy = y;
  while (xx <= 8 and yy > 0) {
    attack[xx][yy] = 1;
    xx++;
    yy--;
  }
  xx = x, yy = y;
  while (xx > 0 and yy <= 8) {
    attack[xx][yy] = 1;
    xx--;
    yy++;
  }
}
bool valid(int x, int y) {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) attack[i][j] = 0;
  }
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) if (grid[i][j] == 2) attackPos(i, j);
  }
  int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
  int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
  for (int i = 0; i < 7; ++i) {
    if (isValid(x + dx[i], y + dy[i]) and attack[x + dx[i]][y + dy[i]] == 0) return 0;
  }
  return 1;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  cin >> test;
  while (test--) {
    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) grid[i][j] = 2;
    }
    int x, y; cin >> x >> y;
    grid[x][y] = 1;
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    // for (int i = 0; i < 7; ++i) {
    //   if (isValid(x + dx[i], y + dy[i])) {
    //     grid[x + dx[i]][y + dy[i]] = 0;
    //     bool ok = valid(x, y);
    //     if (!ok) grid[x + dx[i]][y + dy[i]] = 2;
    //   }
    // }

    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) {
        if (grid[i][j] == 2) {
           grid[i]][j] = 0;
          bool ok = valid(x, y);
          if (!ok) grid[i][j] = 2;
        }
      }
    }

    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) cout << grid[i][j] << " ";
      cout << nl;
    }
  }
  return 0;
}