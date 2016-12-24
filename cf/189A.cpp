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
#define INF 0x3f3f3f

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, a, b, c;
int dp[4005];

int go(int val) {
    if (val == 0) return 0;
    if (val < a && val < b && val < c) return -INF;
    if (dp[val] != -1) return dp[val];
    return dp[val] = 1 + max(go(val-a), max(go(val-b), go(val-c)));
}

int main() {

    scanf("%d%d%d%d", &n, &a, &b, &c);

    ms(dp,-1);
    printf("%d\n", go(n));

    return 0;
}
