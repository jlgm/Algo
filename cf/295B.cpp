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

ll n, adj[505][505], d[505][505], v[505], ans[505];
bool mark[505];

int main() {

    scanf("%lld", &n);
    fr(i,0,n) fr(j,0,n) scanf("%lld", &adj[i][j]);
    fr(i,0,n) scanf("%lld", &v[i]), v[i]--;

    fr(i,0,n) fr(j,0,n) d[i][j] = adj[i][j];
    fr(k,0,n) {
        ll t = v[n-1-k];
        mark[t] = 1;

        fr(i,0,n) fr(j,0,n)
            d[i][j] = min(d[i][j], d[i][t] + d[t][j]);

        ll sum = 0;
        fr(i,0,n) fr(j,0,n)
            if (mark[i] && mark[j]) sum += d[i][j];

        ans[n-1-k] = sum;
    }

    fr(i,0,n) printf("%s%lld", i?" ":"", ans[i]);
    puts("");
    return 0;
}
