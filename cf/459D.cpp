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

int n, a[1000006], dp[1000006], pd[1000006], f[1000006];
unordered_map<int,int> h, g;

void update(int p, int val) {
    for (int i = p; i <= n; i += i&-i)
        f[i] += val;
}

int sum(int p) {
    int ret = 0;
    for (int i = p; i; i -= i&-i)
        ret += f[i];
    return ret;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);

    fr(i,0,n) {
        dp[i] = h[a[i]] + 1;
        h[a[i]]++;
    }
    rf(i,n-1,0) {
        pd[i] = g[a[i]] + 1;
        g[a[i]]++;
    }

    ll ans = 0;
    rf(i,n-1,0) { //counts how many pairs (i < j) there are such that dp(i) > pd(j) (uses BIT)
        ans += (ll)sum(dp[i]);
        update(pd[i]+1, 1);
    }

    printf("%lld\n", ans);

    return 0;
}
