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
#define M 100000000

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int N, n1, n2, k[2];
int dp[2][100][100][100];

int solve(bool prev, int cnt, int n, int m) {

    int &ret = dp[prev][cnt][n][m];
    if (ret != -1) return ret;

    if (n+m == N) return ret = (cnt <= k[prev] && n == n1 && m == n2);
    if (cnt > k[prev] || n > n1 || m > n2) return ret = 0;

    if (cnt == k[prev]) return ret = solve(!prev, 1, n+((!prev)==0), m+((!prev)==1))%M;

    else {
        return ret = (solve(prev, cnt+1, n+(prev==0), m+(prev==1))%M
                + solve(!prev, 1, n+((!prev)==0), m+((!prev)==1))%M)%M;
    }
}

int main() {

    scanf("%d%d%d%d", &n1, &n2, &k[0], &k[1]);
    N = n1+n2;

    ms(dp,-1);
    printf("%d\n", solve(0,0,0,0));

    return 0;
}
