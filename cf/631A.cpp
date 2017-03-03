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

ll n, a[1005], b[1005];

int main() {

    scanf("%lld", &n);
    ll ans1 = 0, ans2 = 0;
    fr(i,0,n) scanf("%lld", &a[i]), ans1|=a[i];
    fr(i,0,n) scanf("%lld", &b[i]), ans2|=b[i];

    printf("%lld\n", ans1+ans2);

    return 0;
}
