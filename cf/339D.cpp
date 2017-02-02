//http://codeforces.com/problemset/problem/339/D
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

int n, m, a[1<<18], A[1<<18][20];

void build() {
    fr(i,0,(1<<n)) A[i][0] = a[i];
    fr(k,1,n+1) {
        fr(i,0,(1<<(n-k))) {
            if (k&1) A[i][k] = (A[2*i][k-1]|A[2*i+1][k-1]);
            else A[i][k] = (A[2*i][k-1]^A[2*i+1][k-1]);
        }
    }
}

void update(int x, int y) {
    A[x][0] = y;
    fr(k,1,n+1) {
        x>>=1;
        if (k&1) A[x][k] = (A[2*x][k-1]|A[2*x+1][k-1]);
        else A[x][k] = (A[2*x][k-1]^A[2*x+1][k-1]);
    }
}

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,1<<n) scanf("%d", &a[i]);//, puts("ok");

    build();
    fr(i,0,m) {
        int x, y;
        scanf("%d%d", &x, &y); x--;
        update(x,y);
        printf("%d\n", A[0][n]);
    }

    return 0;
}
