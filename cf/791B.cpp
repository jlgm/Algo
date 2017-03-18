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

int n, m;
vector<int> adj[200000], tmp;
bool mark[200000];

int dfs(int v) {
    if (mark[v]) return 0;
    mark[v] = 1;
    tmp.pb(v);
    int k = adj[v].size();
    int ret = 1;
    fr(i,0,k) {
        int w = adj[v][i];
        if (!mark[w]) ret += dfs(w);
    }
    return ret;
}

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,m) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--; //0-indexing
        adj[x].pb(y); adj[y].pb(x);
    }

    fr(i,0,n) {
        if (!mark[i]) {
            tmp.clear();
            int amt = dfs(i); //count nodes in this cc
            int k = tmp.size();
            fr(i,0,k) {
                if (adj[tmp[i]].size() != amt-1) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("YES");

    return 0;
}
