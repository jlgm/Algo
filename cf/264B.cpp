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

int n, a[100005], dp[100005];

int main() {

    //puts("?");
    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);//, mark[a[i]]=true;

    if (n==1) {puts("1"); return 0;}

    fr(i,0,n) {
        int m = 0;
        for(int j = 1; (ll)j*j <= a[i]; j++) if (a[i]%j == 0) {
            if (j > 1) m = max(m,dp[j]+1);
            m = max(m, dp[a[i]/j]+1);
        }
        for(int j = 1; (ll)j*j <= a[i]; j++) if (a[i]%j == 0) {
            dp[j] = m;
            dp[a[i]/j] = m;
        }
    }

    printf("%d\n", (int)*max_element(dp, dp+100001));

    return 0;
}
