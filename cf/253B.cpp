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

int n, a[100005], dp[100005];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);

    sort(a,a+n);

    dp[0] = 0;
    fr(i,1,n) dp[i] = min(dp[i-1]+1, lower_bound(a, a+i, (a[i]+1)/2)-a);

    printf("%d\n", dp[n-1]);

    return 0;
}
