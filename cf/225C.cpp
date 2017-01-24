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
#define INF 1e8

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, m, x, y, cost[1005][2], memo[2][1005][1005];
char grid[1005][1005];

int solve(bool prev, int cnt, int v) {
    int &ret = memo[prev][cnt][v];
    if (ret != -1) return ret;
    if (v == m) return (cnt < x || cnt > y) ? INF : 0;
    if (cnt < x) return ret = cost[v][prev] + solve(prev, cnt+1, v+1);
    else {
        ret = cost[v][!prev] + solve(!prev, 1, v+1);
        if (cnt < y) ret = min(ret, cost[v][prev] + solve(prev, cnt+1, v+1));
        return ret;
    }
}

int main() {

    scanf("%d%d%d%d\n", &n, &m, &x, &y);
    fr(i,0,n) fr(j,0,m) {
        scanf("%c", &grid[i][j]);
        cost[j][0] += (grid[i][j] == '#');
        cost[j][1] += (grid[i][j] == '.');
        if (j==m-1) scanf("\n");
    }

    //fr(i,0,m) printf("%d : %d\n", cost[i][0], cost[i][1]);
    ms(memo,-1);
    printf("%d\n", min(solve(0,0,0), solve(1,0,0)));

    return 0;
}
