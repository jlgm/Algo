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

ll n, m, k, a[5005], s[5005], dp[5005][5005];

ll solve(ll K, ll N) {
    ll &ret = dp[K][N];
    if (ret != -1) return ret;
    if (K >= k) return 0;
    if (N >= n) return 0;
    return ret = max(s[N] + solve(K+1, N+m), solve(K,N+1));
}

int main() {

    scanf("%lld%lld%lld", &n, &m, &k);
    fr(i,0,n) scanf("%lld", &a[i]);

    fr(i,0,n-m+1) fr(j,0,m) s[i] += a[i+j];

    ms(dp,-1);
    printf("%lld\n", solve(0,0));

    return 0;
}
