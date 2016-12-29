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

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, a[4006], dp[4006][4005];
map<int,int> f;

int main() {

    scanf("%d", &n); int cur = 1, ans = 1;
    fr(i,0,n) {
        scanf("%d", &a[i]);
        if (f[a[i]] > 0) a[i] = f[a[i]]; //mapping a[] so all elements fit 0-4000
        else a[i] = f[a[i]] = cur++;
    }

    fr(i,1,n+1) fr(j,1,n+1)
        dp[i][j] = 1;

    fr(i,1,n+1) fr(j,1,i) {
        dp[i][a[j-1]] = max(1+dp[j][a[i-1]], dp[i][a[j-1]]);
        ans = max(ans, dp[i][a[j-1]]);
    }

    printf("%d\n", ans);

    return 0;
}
