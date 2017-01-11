#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (ll (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, a[10], dp[1000005][10];
string ans;

ll solve(ll k, ll d) {
    if (k == 0) return 0;
    if (k-a[d] < 0) return 0;

    if (dp[k][d] != -1) return dp[k][d];

    ll ans = 0;
    fr(i,1,10) ans = max(ans, solve(k-a[d], i));

    return dp[k][d] = 1 + ans;
}


int main() {

    ll st = 0, d = 0;
    scanf("%lld", &n);
    fr(i,1,10) scanf("%lld", &a[i]);

    ms(dp,-1);

    ll ans = 0;
    fr(i,1,10) ans = max(ans, solve(n, (i)));
    bool none = true;

    while(n > 0) {
        ll tmp = 0, val = 0;
        fr(i,1,10) {
            if (dp[n][i] >= val) val = dp[n][i], tmp = i;
        }
        if (tmp == 0) {
            break;
        }
        printf("%lld", tmp);
        none = false;
        n-=a[tmp];
    }

    printf("%s\n", none?"-1":"");

    return 0;
}
