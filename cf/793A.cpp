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

int n, k, a[100005], st;

int main() {

    st = INT_MAX;

    scanf("%d%d", &n, &k);
    fr(i,0,n) scanf("%d", &a[i]), st = min(st,a[i]);

    ll ans = 0;
    fr(i,0,n) {
        if ((a[i]-st)%k != 0) {
            ans = -1;
            break;
        }
        ans += ((a[i]-st)/k);
    }

    printf("%lld\n", ans);

    return 0;
}
