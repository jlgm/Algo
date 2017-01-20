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

int n;
int a[3333], b[3333], c[3333], dp[2][3333];

int solve(bool fed, int cur) {
    if (cur == n-1) return fed ? b[cur] : a[cur];
    if (dp[fed][cur] != -1) return dp[fed][cur];
    if (fed) {
        return dp[fed][cur] = max(c[cur]+solve(0,cur+1), b[cur]+solve(1,cur+1));
    }
    else return dp[fed][cur] = max(a[cur]+solve(1,cur+1), b[cur]+solve(0,cur+1));
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);
    fr(i,0,n) scanf("%d", &b[i]);
    fr(i,0,n) scanf("%d", &c[i]);

    ms(dp,-1);

    printf("%d\n", solve(0,0));

    return 0;
}
