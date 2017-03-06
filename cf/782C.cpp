#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>
#include <unordered_set>

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

int n, ans, c[200005];
vector<int> adj[200005];

void color(int v, int x) {
    if (c[v]) return;
    c[v] = x;
    int k = adj[v].size();
    ans = max(ans,k+1);

    unordered_set<int> av;
    fr(i,1,k+2) {
        if (i == x) continue;
        av.insert(i);
    }
    fr(i,0,k) {
        int w = adj[v][i];
        if (c[w]) av.erase(c[w]);
    }
    unordered_set<int>::iterator it = av.begin();
    fr(i,0,k) {
        int w = adj[v][i];
        if (!c[w]) {
            int tmp = *it;
            color(w,tmp);
            it++;
        }
    }
}

int main() {

    scanf("%d", &n);
    fr(i,0,n-1) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ans = 0;
    color(0,1);

    printf("%d\n", ans);
    fr(i,0,n) printf("%s%d", i?" ":"", c[i]);

    return 0;
}
