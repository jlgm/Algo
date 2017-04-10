//PROBLEM GAVE WRONG ANSWER ON TEST 64

#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

int n, st;
ll p[300005];
vector<int> adj[300005];
bool mark[300005];

void dfs(int v) {
    if (mark[v]) return;
    mark[v] = true;
    int k = adj[v].size();
    p[v] += (v!=st);
    fr(i,0,k) {
        int w = adj[v][i];
        if (!mark[w]) {
            int kk = adj[w].size();
            fr(j,0,kk) {
                int ww = adj[w][j];
                if (!mark[ww]) p[ww]++;
            }
            dfs(w);
        }
    }
}

int main() {

    scanf("%d", &n);
    ll lgt = 0;
    fr(i,0,n) {
        scanf("%lld", &p[i]);
        if (p[i] > lgt) lgt = p[i];//, st = i;
    }

    int x, y;
    fr(i,0,n-1) {
        scanf("%d%d", &x, &y); x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int dg = 0;
    fr(i,0,n) {
        if (p[i] == lgt) {
            int k = adj[i].size();
            if (k > dg) {
                dg = k;
                st = i;
            }
        }
    }

    // db(st)
    dfs(st);

    ll ans = -2000000005;
    fr(i,0,n) {
        ans = max(ans, p[i]);
        // db(p[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
