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
typedef vector<vector<ll> > matrix;
const int K = 3;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, k;

bool can(ll x) {
    return (k+k-x-1)*(x)/2+1>=n;
}

int main() {

    cin >> n >> k;

    if (n == 1) { puts("0"); return 0; }
    if (n<=k) { puts("1"); return 0; }
    if (n>k*(k-1)/2+1) { puts("-1"); return 0; }

    ll lo = 0, hi = k-1, mid;
    while(lo<hi) {
        mid = lo+hi>>1;
        if (can(mid)) hi = mid;
        else lo = mid + 1;
    }

    printf("%lld\n", hi);

    return 0;
}
