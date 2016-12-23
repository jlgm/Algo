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

int n, m, ans;
vector<int> p[105];
bool mark[105];

bool can(int v, int w) {
    fr(i,0,p[v].size()) fr(j,0,p[w].size())
        if (p[v][i] == p[w][j]) return true;
    return false;
}

void dfs(int v) {
    if (mark[v]) return;
    mark[v] = true;
    fr(i,0,n) {
        if (can(v, i)) dfs(i);
    }
}

int main() {

    scanf("%d%d", &n, &m);
    bool ok = false;

    fr(i,0,n) {
        int t, x; scanf("%d", &t);
        fr(j,0,t) {
            scanf("%d", &x);
            p[i].pb(x);
            ok = true;
        }
    }

    fr(i,0,n) {
        if (!mark[i]) {
            ans++;
            dfs(i);
        }
    }

    printf("%d\n", ans-ok);

    return 0;
}
