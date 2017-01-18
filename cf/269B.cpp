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

int n, m, a[5555], dp[5555];//, cnt[5555];

int lis(int v) {
    fr(i,0,n){
        int tmp = (int)(upper_bound(dp,dp+v,a[i])-dp);
        if (tmp == v) ++v;
        dp[tmp] = a[i];
    }
    return v;
}

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) {
        double t;
        cin >> a[i] >> t;
    }

    if (m == 1) { puts("0"); return 0; }

    printf("%d\n", n - lis(0));

    return 0;
}
