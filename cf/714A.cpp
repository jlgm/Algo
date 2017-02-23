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

ll l1, l2, r1, r2, k;

int main() {

    cin >> l1 >> r1 >> l2 >> r2 >> k;

    ll L = max(l1,l2);
    ll R = min(r1,r2);

    if (L > R) puts("0");
    else printf("%lld\n", R-L+1LL - (L <= k && k <= R));

    return 0;
}
