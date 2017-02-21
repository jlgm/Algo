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
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

ll n, a, b, k, dp[5002][5002];

ll modsum(ll x, ll y) {
    x += y;
    while(x >= MOD) x-=MOD;
    while(x < 0) x+=MOD;
    return x;
}

int main() {

    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    dp[0][a] = 1;
    fr(i,0,k) {
        fr(j,1,n+1) {
            if (j == b) continue;
            ll d = abs(j-b);
            ll L = max(j-d+1, 1LL), R = min(j+d-1,n);
            dp[i+1][R+1] = modsum(dp[i+1][R+1],-dp[i][j]);
            dp[i+1][L] = modsum(dp[i+1][L],dp[i][j]);
        }
        fr(j,1,n+1) dp[i+1][j] = modsum(dp[i+1][j], dp[i+1][j-1]);
        fr(j,1,n+1) dp[i+1][j] = modsum(dp[i+1][j], -dp[i][j]);
    }
    ll ans = 0;
    fr(j,1,n+1) ans = modsum(ans,(j!=b)?dp[k][j]:0);

    printf("%lld\n", ans);

    return 0;
}
