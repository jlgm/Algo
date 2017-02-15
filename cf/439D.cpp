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

int n, m, a[100005], b[100005];

bool cmp(int x, int y) { return x > y; }

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) scanf("%d", &a[i]);
    fr(i,0,m) scanf("%d", &b[i]);

    sort(a,a+n);
    sort(b,b+m,cmp);

    ll ans = 0;
    fr(i,0,n) {
        if (b[i] > a[i]) ans += (ll)abs(a[i]-b[i]);
        else break;
    }

    printf("%lld\n", ans);

    return 0;
}
