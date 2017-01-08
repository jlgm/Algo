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

int n, m;
string grid[105];
bool mark[105][105];

bool check(char a, int C, int R) {
    fr(i,0,n) {
        if (grid[i][C] == a && i != R) return true;
    }
    fr(i,0,m) {
        if (grid[R][i] == a && i != C) return true;
    }
    return false;
}

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) cin >> grid[i];

    fr(i,0,n) {
        int k = grid[i].size();
        fr(j,0,k) {
            if (check(grid[i][j], j, i)) mark[i][j] = true;
        }
    }

    fr(i,0,n) fr(j,0,m) if (!mark[i][j]) printf("%c", grid[i][j]);
    puts("");

    return 0;
}
