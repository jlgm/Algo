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

const int maxn = 105;
const ll INF = 0x3f3f3f3f3f3f;

ll n, grid[maxn][maxn], pd[maxn][maxn];

int main() {

    scanf("%lld", &n);
    n++;
    fr(i,1,n) fr(j,1,n) scanf("%lld", &grid[i][j]);

    pd[0][0] = grid[0][0];
    fr(i,1,n) pd[0][i] = pd[0][i-1]+grid[0][i];
    fr(i,1,n) pd[i][0] = pd[i-1][0]+grid[i][0];

    fr(i,1,n) fr(j,1,n) pd[i][j] = (pd[i-1][j] + pd[i][j-1] - pd[i-1][j-1]) + grid[i][j];

    ll ans = -INF;
    fr(i,1,n) fr(j,1,n) fr(k,i,n) fr(l,j,n)
        ans = max(ans, pd[k][l] - pd[i-1][l] - pd[k][j-1] + pd[i-1][j-1]);

    printf("%lld\n", ans);

    return 0;
}
