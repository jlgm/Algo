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
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, d, k;
ll dp[105][105][2];

ll calc(ll N, ll K, ll D) {
    if (N == 0 && D) return 1;
    if (N < 0) return 0;
    if (dp[N][K][D] != -1) return dp[N][K][D];
    int ret = 0;
    fr(i,1,K+1) {
        ret += (calc(N-i,K,(i>=d)||D)%MOD);
        ret%=MOD;
    }
    return dp[N][K][D] = ret%MOD;
}

int main() {

    scanf("%lld%lld%lld", &n, &k, &d);
    ms(dp,-1);

    printf("%lld\n", calc(n,k,0));

    return 0;
}
