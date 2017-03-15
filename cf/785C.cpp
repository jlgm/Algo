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

ll n, m;

int main() {
    scanf("%lld%lld", &n, &m);

    if (m >= n) {
        printf("%lld\n", n);
        return 0;
    }

    ll res = (1 + (sqrtl(1+8*(n-m-1))))/2;

    printf("%lld\n", res+m);

    return 0;
}
