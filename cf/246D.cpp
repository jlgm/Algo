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

int n, m, c[100005];
vector<int> adj[100005];
map<int, vector<int> > v;

int main() {

    scanf("%d%d", &n, &m);
    int resp = 1000005;
    fr(i,0,n) scanf("%d", &c[i]), resp = min(resp,c[i]);
    fr(i,0,m) {
        int a, b;
        scanf("%d%d", &a, &b); a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;//, resp = 0;

    fr(i,0,n) {
        int k = adj[i].size();
        fr(j,0,k) {
            int w = adj[i][j];
            if (c[i] != c[w]) {
                v[c[i]].pb(c[w]);
            }
        }
    }

    for (map<int,vector<int> >::iterator i = v.begin(); i != v.end(); i++) {
        vector<int> tmp = i->second;
        sort(tmp.begin(), tmp.end());
        vector<int>::iterator it = unique(tmp.begin(), tmp.end());
        tmp.resize(distance(tmp.begin(), it));

        int k = tmp.size();

        if (k > ans) {
            ans = k;
            resp = i->first;
        }
        if (k == ans) resp = min(resp, i->first);
    }

    printf("%d\n", resp);

    return 0;
}
