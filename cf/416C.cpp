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

int n, k;//, sz[1001];
pii g[1001], sz[1001];
bool mark[1001];

bool cmp(pii x, pii y) {
    return x.X < y.X;
}

pii best(int v) {
    int val = 0, id;
    fr(i,0,n) {
        if (mark[i]) continue;
        if (g[i].X > v) continue;
        if (g[i].Y > val) {
            val = g[i].Y;
            id = i;
        }
    }
    if (val) {
        mark[id] = 1;
        return pii(id+1, g[id].Y);
    }
    return pii(-1,-1);
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[i] = pii(x,y);
    }
    scanf("%d", &k);
    fr(i,0,k) {
        int x;
        scanf("%d", &x);
        sz[i] = pii(x,i+1);
    }

    sort(sz,sz+k,cmp);

    vector<pii> ans;
    int tot = 0;

    fr(i,0,k) {
        pii cur = best(sz[i].X);
        if (cur.X == -1) continue;
        tot += cur.Y;
        ans.pb(pii(cur.X, sz[i].Y));
    }

    printf("%d %d\n", (int)ans.size(), tot);
    fr(i,0,(int)ans.size()) printf("%d %d\n", ans[i].X, ans[i].Y);

    return 0;
}
