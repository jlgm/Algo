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
typedef pair<ll, ll> pll;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, q, a[200005], f[200005], newa[200005], sum[200005];
pll t[200005], qq[200005];

bool cmp(int x, int y) { return x > y; }
bool cmp2(pll x, pll y) { return x.X > y.X; }

int main() {

    scanf("%lld%lld", &n, &q);

    fr(i,0,n) scanf("%lld", &a[i]);
    sort(a,a+n,cmp);

    fr(i,0,q) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        --x; --y;
        f[x]++; f[y+1]--;
        qq[i] = pll(x,y);
    }

    fr(i,0,n) {
        f[i] += i ? f[i-1] : 0;
        t[i] = pll(f[i],(ll)i);
    }

    sort(t,t+n,cmp2);

    fr(i,0,n) newa[t[i].Y] = a[i];
    fr(i,0,n) sum[i] = i ? sum[i-1]+newa[i] : newa[i];

    ll ans = 0;
    fr(i,0,q) {
        ans += (sum[qq[i].Y]) - (qq[i].X ? sum[qq[i].X-1LL] : 0LL);
    }

    printf("%lld\n", ans);

    return 0;
}
