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

int n, mark[105], ans;
pii p[105];

void dfs(int v) {
    if (mark[v]) return;
    mark[v] = true;
    fr(i,0,n) {
        if (p[i].X == p[v].X || p[i].Y == p[v].Y) dfs(i);
    }
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d%d", &p[i].X, &p[i].Y);

    fr(i,0,n) {
        if (!mark[i]) {
            ans++;
            dfs(i);
        }
    }

    printf("%d\n", ans-1);

    return 0;
}
