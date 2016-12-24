#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << "; ";
#define LN puts("");
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, k;
ll a[200005], sum[200005], dp[200005], m[200005][20];

int build(int N) {
    for( int i = 0 ; i < N ; i++ ) m[i][0] = i;
    for( int s = 2 , kk = 1 ; s <= N ; kk++ ) {
        for( int i = 0 ; i + s <= N ; i++) {
            if (dp[m[i][kk-1]] >= dp[m[i+s/2][kk-1]]) m[i][kk] = m[i][kk-1];
            else m[i][kk] = m[i+s/2][kk-1];
        }
        s *= 2 ;
    }
}

int query(int i , int j ) { //returns the index of maximum element in the query
    int range = j - i + 1 , s = 1, kk = 0 ;
    for( s = 1 , kk = 0 ; s * 2 <= range ; kk++ , s *= 2 );
    if (dp[m[i][kk]] >= dp[m[i+range-s][kk]]) return m[i][kk];
    else return m[i+range-s][kk];
}

int main() {

    cin >> n >> k;

    fr(i,0,n) {
        cin >> a[i];
        (i)?(sum[i]=(a[i]+sum[i-1])):(sum[i]=a[i]);
    }

    if (n == 2) {
        fr(i,0,n) cout << (i?" ":"") << i+1; LN;
        return 0;
    }

    dp[0] = sum[k-1];

    fr(i,1,n-k+1) dp[i] = (sum[k+i-1] - sum[i-1]);

    build(n);

    ll ans = 0;
    int idx1, idx2;

    fr(i,0,n-k+1) {
        int x = i+k; int y = i-k;
        int q1 = n, q2 = n;
        if (x >= 0) q1 = query(x, n-k+1);
        if (y >= 0) q2 = query(0, y);
        if (dp[i]+max(dp[q1],dp[q2]) > ans) {
            ans = dp[i]+max(dp[q1],dp[q2]);
            idx1 = i;
            if (dp[q1] > dp[q2]) idx2 = q1;
            else idx2 = q2;
        }
    }

    if (idx2 < idx1) swap(idx2, idx1);

    printf("%d %d\n", idx1+1, idx2+1);

    return 0;
}
