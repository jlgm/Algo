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

int n, ans;
bool mark[2005];
vector<int> adj[2005], roots;

void dfs(int v, int h) {
    if (mark[v]) return;
    mark[v] = true;
    ans = max(ans,h);
    int k = adj[v].size();
    fr(i,0,k) {
        dfs(adj[v][i], h+1);
    }
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) {
        int x; scanf("%d", &x);
        if (x == -1) {
            roots.pb(i);
            continue;
        }
        adj[x-1].pb(i);
    }

    int k = roots.size();
    fr(i,0,k) {
        if (!mark[roots[i]]) {
            dfs(roots[i], 1);
        }
    }

    printf("%d\n", ans);

    return 0;
}
