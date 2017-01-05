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

ll n, a[2000007], dp[2000007];

bool cmp(ll a, ll b) { return a > b; }

int main() {

    cin >> n;
    fr(i,0,n) scanf("%lld", &a[i]);

    sort(a,a+n,cmp);

    dp[0] = a[0];
    fr(i,1,n) dp[i] = a[i]+dp[i-1];

    ll cur = 1, ans = 0;

    while(cur < n) {
        ans+=dp[cur-1];
        cur*=4;
    }

    ans+=dp[cur-1];

    printf("%lld\n", ans);

    return 0;
}
