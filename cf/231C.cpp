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

ll n, k, a[100005], sum[100005];

bool can(ll c) {
    for (int i = 0; i <= n-c; i++) {
        ll x = a[c-1+i]*c;
        ll y = i?(sum[i+c-1] - sum[i-1]):(sum[c-1]);
        if (x - y <= k) return true;
    }
    return false;
}

ll ans(ll c) {
    for (int i = 0; i <= n-c; i++) {
        ll x = a[c-1+i]*c;
        ll y = i?(sum[i+c-1] - sum[i-1]):(sum[c-1]);
        if (x - y <= k) return a[c-1+i];
    }
}

int main() {

    cin >> n >> k;
    fr(i,0,n) cin >> a[i];
    sort(a, a+n);
    fr(i,0,n) sum[i] = i?(a[i]+sum[i-1]):(a[i]);

    ll lo = 1, hi = 10000000000LL, mid;
    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        if (!can(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << lo-1 << " " << ans(lo-1) << endl;

    return 0;
}
