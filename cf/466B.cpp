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

ll N, n, a, b;
vector<ll> d;

int main() {

    scanf("%lld%lld%lld", &N, &a, &b);
    n = N*6;

    if (a*b >= n) {
        printf("%lld\n%lld %lld\n", a*b, a, b);
        return 0;
    }

    fr(i,1,1000) {
        ll k = sqrt(n);
        for(ll i = 1; i <= k; i++) {
            if (n % i == 0) d.pb(i);
        }
        k = d.size();
        fr(i,0,k) {
            ll w = n/d[i];
            if (d[i] >= a && w >= b) {
                printf("%lld\n%lld %lld\n", n, d[i], w);
                return 0;
            }
            if (d[i] >= b && w >= a) {
                printf("%lld\n%lld %lld\n", n, w, d[i]);
                return 0;
            }
        }
        n++;
        d.clear();
    }

    n = N*6;
    ll ans = 1e10, x, y;

    fr(i,0,1000) fr(j,0,1000) {
        if ((a+i) * (b+j) >= n) {
            ll w = (a+i) * (b+j);
            if (w < ans) {
                ans = w;
                x = (a+i);
                y = (b+j);
            }
            break;
        }
    }

    printf("%lld\n%lld %lld\n", x*y, x, y);

    return 0;
}
