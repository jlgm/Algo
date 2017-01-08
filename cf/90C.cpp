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

ll n, m, k, a[10004];

int main() {

    scanf("%lld%lld%lld", &n, &m, &k);
    fr(i,0,n) scanf("%lld", &a[i]);

    if (n%2==0) {
        puts("0");
        return 0;
    }

    if (m < (n+1)/2) {
        puts("0");
        return 0;
    }

    ll ans = k*(m/((n+1)/2)); //db(ans);
    for(int i = 0; i < n; i+=2) {
        ans = min(ans, a[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
