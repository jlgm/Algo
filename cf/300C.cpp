
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (ll (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll a, b, n, f[1000006], ans;

bool isgood(ll k) {
    while(k>0) {
        ll r = k%10;
        if (r != a && r != b) return false;
        k/=10;
    }
    return true;
}

ll fastexp(ll N, ll E) {
    if (E==0) return 1;
    if (E==1) return N;
    if (E&1) return (N*fastexp(N,E-1))%MOD;
    ll ret = fastexp(N, E>>1)%MOD;
    return (ret*ret)%MOD;
}

ll calc(ll N, ll K) {
    return f[N] * fastexp((f[N-K]*f[K])%MOD, MOD-2);
}

int main() {

    scanf("%lld%lld%lld", &a, &b, &n);

    f[0] = 1;
    f[1] = 1;
    fr(i,2,n+1) f[i] = ((f[i-1]%MOD)*(i%MOD))%MOD;

    ans = isgood(b*n);
    fr(i,1,n+1) {
        ll num = ((n-i)*b) + (i*a);
        ans += isgood(num)? calc(n,i) : 0;
        ans%=MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
