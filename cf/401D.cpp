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

ll dp[1<<19][105], m, n[20];
bool mark[1<<19][105];
int cnt;

ll dfs(int mask, int len, ll md, ll mod, ll dig) {
    if (len == cnt && dig != 0LL && md == 0LL) return 1LL;
    if (len == cnt) return 0LL;

    ll &ans = dp[mask][md];
    if (ans != -1) return ans;

    ans = 0LL;
    int newmask = 1;

    bool can[12];
    memset(can, false, sizeof(can));

    fr(i,0,cnt) {
        if (!(mask & newmask) && !can[n[i]]) {
            ll newmd = md + mod*n[i];
            newmd%=m;
            can[n[i]] = true;
            ans += dfs(mask | newmask, len+1, newmd, mod*10LL, n[i]);
        }
        newmask <<= 1;
    }
    return ans;
}

int main() {

    ll tmp;
    scanf("%lld%lld", &tmp, &m);
    cnt = 0;
    while(tmp > 0) {
        n[cnt++] = tmp%10;
        tmp/=10;
    }
    ms(dp,-1);
    printf("%lld\n", dfs(0,0,0LL,1LL,0));

    return 0;
}
