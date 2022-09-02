#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair <int, int>    pii;
typedef pair <ll, ll>      pll;
typedef vector <int>       vi;
typedef vector <ll>        vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define debug(x) cerr << #x << " = " << x << '\n';
#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define mp       make_pair
#define PI       acos(-1.0)
#define TN       typename
#define nl       '\n'
#define Fast_IO  ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

// problem link: https://www.spoj.com/problems/NHAY/

class Hashing {
    int power(ll base, ll exp, const int mod) {
        int res = 1;
        base %= mod;
        if (base < 0) base += mod;
        while (exp) {
            if (exp & 1) res = (1LL * res * base) % mod;
            base = (1LL * base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    int get(char ch) { return ch - 'a' + 1; }

    const int MOD1 = 127657753, MOD2 = 987654319;
    const int BASE1 = 137, BASE2 = 277;
    const int inveMod1 = power(BASE1, MOD1 - 2, MOD1);
    const int inveMod2 = power(BASE2, MOD2 - 2, MOD2);
    vector<pii> pw, invPw;
    vector<pii> hash;
    int n;
    string s;

    void build() {
        hash.pb({0, 0});
        for (int i = 0; i < n; ++i) {
            pii p;
            p.ff = add(hash[i].ff, mult(get(s[i]), pw[i].ff, MOD1), MOD1);
            p.ss = add(hash[i].ss, mult(get(s[i]), pw[i].ss, MOD2), MOD2);
            hash.pb(p);
        }
    }

public:
    Hashing(string _s) {
        s = _s;
        n = szof(s);
        pw.assign(n + 2, {1, 1});
        invPw.assign(n + 2, {1, 1});
        for (int i = 1; i <= n; ++i) {
            pw[i].ff = mult(pw[i - 1].ff, BASE1, MOD1);
            pw[i].ss = mult(pw[i - 1].ss, BASE2, MOD2);
            invPw[i].ff = mult(invPw[i - 1].ff, inveMod1, MOD1);
            invPw[i].ss = mult(invPw[i - 1].ss, inveMod2, MOD2);
        }
        build();
    }

    pii getHash(int l, int r) {
        pii p;
        p.ff = mult(add(hash[r].ff, -hash[l - 1].ff, MOD1), invPw[l - 1].ff, MOD1);
        p.ss = mult(add(hash[r].ss, -hash[l - 1].ss, MOD2), invPw[l - 1].ss, MOD2);
        return p;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    Fast_IO
    int test = 1, tc = 0;
    int n;
    while (cin >> n) {
        string s, t;
        cin >> t >> s;
        Hashing ds(s);
        auto hs = Hashing(t).getHash(1, n);
        for (int i = 1; i + n - 1 <= szof(s); ++i) {
            if (ds.getHash(i, i + n - 1) == hs) cout << i - 1 << nl;
        }
        cout << nl;
    }
    return 0;
}