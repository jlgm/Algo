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
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, c[100005], dg[100005], cur, root;
vector<int> adj[100005];
bool mark[100005];

void dfs(int v) {
    if (mark[v]) return;
    mark[v] = true;
    int k = adj[v].size();
    fr(i,0,k) {
        int w = adj[v][i];
        if (c[w] != c[v]) {
            dg[v]++;
            if (dg[v] > cur) {
                cur = dg[v];
                root = v;
            }
        }
        dfs(w);
    }
}

bool differ(int v, int prev) {
    int k = adj[v].size();
    bool ans = false;
    fr(i,0,k) {
        int w = adj[v][i];
        if (w == prev) continue;
        if (c[v] != c[w]) { return true; }
        ans = ans || differ(w, v);
    }
    return ans;
}

bool validate(int v) {
    int k = adj[v].size();
    fr(i,0,k) {
        int w = adj[v][i];
        if (differ(w, v)) { return false;}
    }
    return true;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n-1) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        adj[x].pb(y); adj[y].pb(x);
    }

    fr(i,0,n) scanf("%d", &c[i]);
    root = cur = 0;
    dfs(0);

    if (validate(root)) {
        printf("YES\n%d\n", root+1);
    }

    else puts("NO");

    return 0;
}
