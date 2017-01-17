#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, c[100005];
vector<ll> adj[100005];

pll solve(ll v, ll prev) {
    int k = adj[v].size();

    bool leaf = true;
    pll ret = pll(0LL,0LL);

    fr(i,0,k) {
        if (adj[v][i] == prev) continue;
        pll tmp = solve(adj[v][i], v);
        ret.X = max(ret.X, tmp.X);
        ret.Y = max(ret.Y, tmp.Y);
        leaf = false;
    }

    if (leaf) {
        if (c[v] > 0) ret.Y = c[v];
        else ret.X = -c[v];
    }
    else {
        c[v] -= ret.Y;
        c[v] += ret.X;
        if (c[v] > 0) ret.Y += c[v];
        else ret.X += -c[v];
    }
    return ret;
}

int main() {

    scanf("%lld", &n);
    fr(i,0,n-1) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        adj[x-1].pb(y-1); adj[y-1].pb(x-1);
    }
    fr(i,0,n) scanf("%lld", &c[i]);

    pll ans = solve(0,-1);
    printf("%lld\n", ans.X + ans.Y);

    return 0;
}
