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

typedef long long ll;
typedef pair<int, int> pii;

ll n, a[200005];

bool cmp(ll x, ll y) {
    return x > y;
}

int main() {

    scanf("%lld", &n);
    fr(i,0,n) {
        scanf("%lld", &a[i]);
    }

    sort(a,a+n,cmp);

    ll dif = 100000000000, ans = 0;

    fr(i,1,n) dif = min(dif, (ll)abs(a[i-1]-a[i]));
    fr(i,1,n) ans += (abs(a[i-1]-a[i]) == dif);

    printf("%lld %lld\n", dif, ans);

    return 0;
}
