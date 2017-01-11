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

int n, dp[100005];
vector<int> adj[100005], ans;
bool mark[100005], p[100005];

void dfs(int v) {
    if (mark[v]) return;
    mark[v] = 1;
    dp[v] = p[v];
    int k = adj[v].size();
    fr(i,0,k) {
        int w = adj[v][i];
        if (!mark[w]) dfs(w), dp[v] += dp[w];
    }
}

int main() {

    int x, y, t;
    scanf("%d", &n); fr(i,0,n-1) {
        scanf("%d%d%d", &x, &y, &t);
        adj[x].pb(y); adj[y].pb(x);
        if (t==2) p[x]=p[y]=1;
    }

    dfs(1);
    //fr(i,0,n) printf("%d: %d\n", i+1, dp[i+1]);
    fr(i,0,n) if (dp[i+1] == 1 && p[i+1]) ans.pb(i+1);

    printf("%d\n", (int)ans.size());
    fr(i,0,ans.size()) printf("%s%d", i?" ":"", ans[i]);

    return 0;
}
