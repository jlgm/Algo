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

int n, k, a[200005], dp[200005];

int main() {

    scanf("%d%d", &n, &k);

    fr(i,0,n) {
        scanf("%d", &a[i]);
        (i)?(dp[i]=(a[i]+dp[i-1])):(dp[i]=a[i]);
    }

    int ans = dp[k-1], idx = 0;

    for (int i = k; i < n; i++) {
        int tmp = dp[i] - dp[i-k];
        if (tmp < ans) {
            ans = tmp;
            idx = i-k+1;
        }
    }

    printf("%d\n", idx+1);

    return 0;
}
