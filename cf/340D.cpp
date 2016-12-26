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

int lis(int v) {
    fr(i,0,n){
        int tmp = (int)(lower_bound(dp,dp+v,a[i])-dp);
        if (tmp == v) ++v;
        dp[tmp] = a[i];
    }
    return v;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);
    printf("%d\n", lis(0));
    
    return 0;
}
