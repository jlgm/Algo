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
#define L 22

typedef long long ll;
typedef pair<int, int> pii;

int n, a[300010], m[300010][L], g[300010][L];

int gcd(int x, int y) {
    return y ? gcd(y,x%y) : x;
}

void pre() {
    int i, j;
    for(i=1; i<=n; i++) m[i][0] = g[i][0] = a[i];
    for(j=1;(1<<j)<=n;j++)
        for(i=1;i+(1<<j)-1<=n;i++) {
            m[i][j] = min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
            g[i][j] = gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
        }
}

int mingcd(int x, int y) {
    int k = log2(y-x+1);
    return gcd(g[x][k], g[y-(1<<k)+1][k]);
}

int rmq(int x, int y) {
    int k = log2(y-x+1);
    return min(m[x][k], m[y-(1<<k)+1][k]);
}

bool can(int k) {
    for (int i = 1; i <= n-k; i++)
        if (rmq(i,i+k) == mingcd(i,i+k)) return true;
    return false;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i+1]);

    pre();

    int lo = 1, hi = n, mid = lo;
    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        if (!can(mid)) hi = mid;
        else lo = mid+1;
    }

    vector<int> ans;
    int amt = 0, k = hi-1;

    for (int i = 1; i <= n-k; i++) {
        if (rmq(i,i+k) == mingcd(i,i+k))
            ans.pb(i), amt++;
    }

    printf("%d %d\n", amt, k);
    k = ans.size();
    fr(i,0,k) printf("%s%d", i?" ":"", ans[i]);

    puts("");
    return 0;
}
